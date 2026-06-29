# FaceEnrollmentController Architecture Diagram

Auto Capture Diagram
```mermaid
sequenceDiagram
    participant I as IncdOnboardingDelegate
    participant U as User
    participant C as FaceEnrollmentController

    Note over I, C: Configuration
    I -->> U: func onSelfieScanStarted(controller)
    U -->> C: controller.delegate = self

    Note over U,C: Starting Face Enrollment
    U -->> C: start(in:)
    C -->> U: delegate.faceEnrollmentControllerDidStart(_:)

    Note over U,C: Receiving Feedback
    C -->> U: delegate.faceEnrollmentController(_:didReceive:)

    Note over U,C: Auto Capture
    C -->> U: delegate.faceEnrollmentControllerDidDetectFace(_:)
    C -->> U: delegate.faceEnrollmentControllerDidCaptureFace(_:result:)

    Note over U,C: Upload
    U -->> C: func startUpload()
    C -->> U: delegate.faceEnrollmentControllerDidStartUploading(_:)
    C -->> U: delegate.faceEnrollmentController(_:, didUpdateUploadProgress:)
    C -->> U: delegate.faceEnrollmentController(_:, didFinishUploading result:, canRetry:)

    Note over U,C: Upload is Successful
    C -->> U: faceEnrollmentControllerDidCompleteFaceEnrollment(_:)
    U -->> C: finish()

    Note over U,C: Upload Failed
    U -->> C: continueAnalyzing()
    C -->> U: Same Delegate Methods to Detect and Capture Face

    Note over I, C: Module Finished
    I -->> U: onSelfieScanCompleted(result:)
```
---
Manual Capture Diagram
```mermaid
sequenceDiagram
    participant I as IncdOnboardingDelegate
    participant U as User
    participant C as FaceEnrollmentController

    Note over I, C: Configuration same as Auto Capture

    Note over U,C: Starting Face Enrollment same as Auto Capture

    Note over U,C: Manual Capture
    U -->> C: switchToManualCapture()
    C -->> U: delegate.faceEnrollmentControllerDidSwitchToManualCapture(_:)
    U -->> C: triggerManualCapture()
    C -->> U: delegate.faceEnrollmentControllerDidCaptureFace(_:, result:)

    Note over U,C: Upload same as Auto Capture

    Note over I, C: Module Finished same as Auto Capture
```

## Key Interactions

### 1. User → FaceEnrollmentController (Direct Method Calls)
- `start(in:)` - Begin face enrollment process
- `pauseAnalyzing()` / `continueAnalyzing()` - Control analysis state
- `switchToManualCapture()` - Switch from auto to manual mode
- `triggerManualCapture()` - Manually capture face image
- `upload()` - Upload captured face data
- `stop()` / `finish()` - End the enrollment process

### 2. FaceEnrollmentController → FaceEnrollmentControllerDelegate (Callbacks)
- `faceEnrollmentControllerDidStart(_:)` - Process started
- `faceEnrollmentController(_:didReceive:)` - Real-time feedback
- `faceEnrollmentControllerDidDetectFace(_:)` - Face detected
- `faceEnrollmentControllerDidCaptureFace(_:result:)` - Face captured
- `faceEnrollmentControllerDidSwitchToManualCapture(_:)` - Mode switched
- `faceEnrollmentControllerDidCompleteFaceEnrollment(_:)` - Process completed
- Upload progress and completion callbacks

### 3. Data Flow
- User sets delegate on controller
- User calls controller methods directly
- Controller performs operations and notifies delegate
- Delegate receives real-time updates and final results
