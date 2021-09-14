// swift-tools-version:5.3

import PackageDescription

let package = Package(
    name: "MatiSDK",
    platforms: [
        .iOS(.v11)
    ],
    products: [
        .library(
            name: "MatiSDK",
            targets: ["MatiSDK"]),
    ],
    targets: [
        .binaryTarget(
            name: "MatiSDK", 
            path: "MatiSDK.xcframework")
    ])
