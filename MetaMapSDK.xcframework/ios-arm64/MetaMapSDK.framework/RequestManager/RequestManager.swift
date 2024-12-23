//
//  MatiRequestManager.swift
//  MatiGlobalIDSDK
//
//  Created by Andrey Posnov on 1/25/21.
//  Copyright © 2021 Mati. All rights reserved.
//

import Foundation

class RequestManager {
    private static var sharedInstance: RequestManager?
      class var shared: RequestManager {
          guard let sharedInstance = self.sharedInstance else {
              let sharedInstance = RequestManager()
              self.sharedInstance = sharedInstance
              return sharedInstance
          }
          return sharedInstance
      }

    private let socketManager = MetaMapSocketManager()
    private let apiManager = MetaMapApiManager()

    func subscribeReusage(event: @escaping () -> Void) {
        socketManager.reusageManager.subscribe {
            DispatchQueue.main.async {
                event()
            }
        }
    }

    func getToken(completion: @escaping (IdTokenResponseModel?) -> Void) {
        apiManager.getToken(completion: { (oauth) in
            if let oauth = oauth {
                if let token = oauth.accessToken {
                    StorageManager.shared.set(token, for: .accessToken)
                }
                if let idToken = oauth.idToken?.components(separatedBy: ".") {
                    if idToken.count > 1 {
                        let payloadEncoded = idToken[1]
                        if let payloadFix = payloadEncoded.base64JwtDecode() {
                            let jsonData = Data(payloadFix.utf8)
                            if let idTokenModel = try? IdTokenResponseModel.decode(from: jsonData) {
                                completion(idTokenModel)
                            } else {
                                completion(nil)
                            }
                        } else {
                            completion(nil)
                        }
                    }
                } else { // idtoken slice from whole
                    completion(nil)
                }
            } else { // oauth
                completion(nil)
            }
        })
    }

    func uploadFile(fileData: FileUploadModelProtocol, completion: @escaping (ResponseStatus) -> Void, progressHandler: ((_ progress: CGFloat) -> Void)? = nil) {
        apiManager.uploadFileRequest(fileData: fileData, completion: completion, progressHandler: progressHandler)
    }

    func creditCheckSubmit(data: CreditCheck, completion: @escaping (ResponseStatus) -> Void) {
        apiManager.creditCheckRequest(data: data, completion: completion)
    }

    func customDocSkip(data: SkipHeaderData, completion: @escaping (ResponseStatus) -> Void) {
        apiManager.skipStepsRequest(data: data, type: .customDocumentSkip, completion: completion)
    }

    func docBackSideSkip(data: DocBackSideSkip, completion: @escaping (ResponseStatus) -> Void) {
        apiManager.skipStepsRequest(data: data, type: .documentSkip, completion: completion)
    }

    func skipInput(input: InputId, completion: @escaping (ResponseStatus) -> Void) {
        apiManager.skipStepsRequest(data: nil, type: .skip(subType: input.rawValue), completion: completion)
    }
    
    func termCondition(data: ConsentDetails, completion: @escaping (ResponseStatus, Data?) -> Void) {
        apiManager.termConditionRequest(data: data, completion: completion)
    }

    func downloadPDF(path: String, completion: @escaping (ResponseStatus, Data?) -> Void) {
        apiManager.downloadPDF(path: path, completion: completion)
    }

    func sendSignalData(data: [String: Any]) {
        socketManager.sendSignalData(body: data)
    }

    func vpnRetry(completion: @escaping (ResponseStatus) -> Void) {
        apiManager.vpnTryAgain(completion: completion)
    }

    func uploadDynamicInputs(inputData: MatiDynamicInputsRequest, completion: @escaping (ResponseStatus) -> Void) {
        apiManager.uploadDynamicInputsRequest(inputData: inputData, completion: completion)
    }
    
    func dynamicInputsTitleLocalization(completion: @escaping (_ dict: [String: String]) -> Void) {
        apiManager.dynamicInputsTitleLocalization(completion: completion)
    }
    
    func dynamicErrorsLocalization(completion: @escaping (_ dict: [String: String]) -> Void) {
        apiManager.dynamicErrosLocalization(completion: completion)
    }

    func uploadInput(inputData: InputDataProtocol, completion: @escaping (ResponseStatus) -> Void) {
        apiManager.uploadInputRequest(inputData: inputData, completion: completion)
    }

    func sendLocationData(inputData: InputDataProtocol, completion: @escaping (ResponseStatus) -> Void) {
        apiManager.sendLoation(inputData: inputData, completion: completion)
    }

    func downloadImagefromUrl(path: String?, completion: @escaping (ResponseStatus, UIImage?) -> Void) {
        guard let path = path, !path.isEmpty, let url = URL(string: path) else {
            completion(.error(error: nil), nil)
            return
        }
        socketManager.getData(from: url) { data, _, error in
            guard let data = data, let image = UIImage(data: data) else {
                completion(.error(error: error as? NSError), nil)
                return
            }
            completion(.success, image)
        }
    }

    func closeWebSocketConnection() {
        socketManager.closewWsConnection()
    }

    func sendAnalyticEvent(eventName: String, details: Codable) {
        socketManager.sendAnalyticEvent(eventName: eventName, details: details)
    }

    func sendSignalData(body: [String: Any]) {
        socketManager.sendSignalData(body: body)
    }
    
    func socketconnection(flowId: String?, verificationId: String?, identityId: String?, inputs: [Input]?, completion: @escaping (Bool) -> Void ) {
        if let flowId = flowId {
            MetaMapGlobalManager.instance.verificationId = verificationId
            MetaMapGlobalManager.instance.identity = identityId
            MetaMapGlobalManager.instance.checkCreditCard(inputs: inputs)
            self.socketManager.openWsConnection(flowId: flowId,
                                                method: API.Path.wsVerificationFlow.value,
                                                completion: completion)
        }
    }

    func createVerification(flowId: String,
                            completion: @escaping (Bool) -> Void,
                            statusCompletion: @escaping (CreateVerificationStatus?) -> Void) {
        if  let verificationId = MetaDataHandler.shared.data.verificationId, let identityId = MetaDataHandler.shared.data.identityId {
            self.socketconnection(flowId: flowId, verificationId: verificationId, identityId: identityId, inputs: [], completion: completion)
        } else {
            apiManager.createVerificationRequest(flowId: flowId) { model, _, errorMode in
                switch errorMode {
                case .blocked(let data):
                    statusCompletion(.blocked(data))
                case .block_custom(let data):
                    statusCompletion(.block_custom(data))
                case .error:
                    completion(false)
                case .successed:
                    self.socketconnection(flowId: flowId, verificationId: model?.id, identityId: model?.identity, inputs: model?.inputs, completion: completion)
                }
            }
        }
    }
    
    func checkStatus(inputId: String, group: Int?, completion: @escaping (ResponseStatus) -> Void) {
        let apiRequest = MetaMapRequest()
        let targetType = MetaMapTargetType.verificationStatus(inputId: inputId, group: group)
        apiRequest.makeRequest(targetType: targetType) { status, _ in
            completion(status)
        }
    }
}
