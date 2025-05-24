//
//  RestApiService.swift
//  MetaMapSDK
//
//  Created by Avo Sukiasyan on 22.06.22.
//  Copyright © 2022 Mati. All rights reserved.
//

import Foundation

class MetaMapRequest: NSObject {

    private lazy var session: URLSession = URLSession(configuration: {
        let config = URLSessionConfiguration.default
        config.timeoutIntervalForRequest = 50
        return config
    }(), delegate: self, delegateQueue: nil)

    var progressHandler: ((_ progress: CGFloat) -> Void)?

    func makeRequest(targetType: GenericTargetType, completion: ((_ status: ResponseStatus, _ data: Any?) -> Void)? = nil,
                     progressHandler: ((_ progress: CGFloat) -> Void)? = nil) {
        self.progressHandler = progressHandler
        let request = targetType.asRequest

        MetaMapLogger.log(request: request)

        let dataTask = session.dataTask(with: request) { (data, response, error) in
            MetaMapLogger.log(response: response as? HTTPURLResponse, data: data, error: error)

            if let httpResponse = response as? HTTPURLResponse {
                DispatchQueue.main.async {
                    if ResponseStatus.isSuccessResponse(code: httpResponse.statusCode) {
                        completion?(.success, data)
                    } else {
                        MetaMapLogger.log("HTTP \(httpResponse.statusCode) error: \(error?.localizedDescription ?? "Unknown")", tag: "MetaMapRequest", level: .error)
                        completion?(.error(error: NSError(domain: error?.localizedDescription ?? "", code: httpResponse.statusCode)), data)
                        NotificationCenter.default.post(name: .uploadFailed, object: nil, userInfo: ["errorCode": httpResponse.statusCode.description])
                    }
                }
            } else {
                DispatchQueue.main.async {
                    MetaMapLogger.log("No HTTPURLResponse received. Error: \(error?.localizedDescription ?? "nil")", tag: "MetaMapRequest", level: .error)
                    completion?(.error(error: error as? NSError), nil)
                    NotificationCenter.default.post(name: .uploadFailed, object: nil, userInfo: nil)
                }
            }
        }
        dataTask.resume()
    }
}

extension MetaMapRequest: URLSessionTaskDelegate {

    func urlSession(
        _ session: URLSession,
        task: URLSessionTask,
        didSendBodyData bytesSent: Int64,
        totalBytesSent: Int64,
        totalBytesExpectedToSend: Int64) {
        progressHandler?((CGFloat(Float(totalBytesSent) / Float(totalBytesExpectedToSend)) * 100))
    }
}
