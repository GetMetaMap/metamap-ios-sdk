// swift-tools-version:5.3
import PackageDescription
let package = Package(
    name: "MetaMapSDK",
    platforms: [
        .iOS(.v12)
    ],
    products: [
        .library(
            name: "MetaMapSDK", 
            targets: ["MetaMapSDK"])
    ],
    targets: [
        .binaryTarget(
            name: "MetaMapSDK", 
            path: "MetaMapSDK.xcframework")
    ])
