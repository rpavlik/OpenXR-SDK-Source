if (-not $env:VULKAN_SDK_VERSION) {
    $env:VULKAN_SDK_VERSION = "1.1.106.0"
}

$SDK_VER = $env:VULKAN_SDK_VERSION

if (-not (Test-Path env:VULKAN_SDK)) {
    $env:VULKAN_SDK = "c:\VulkanSDK\$SDK_VER"
}

$FN = "VulkanSDK-$SDK_VER-Installer.exe"
$URL = "https://sdk.lunarg.com/sdk/download/$SDK_VER/windows/$FN"
if (-not (Test-Path "$env:VULKAN_SDK/Include/vulkan/vulkan.h")) {
    $wc = New-Object System.Net.WebClient
    $wc.DownloadFile($URL, $FN)
    Start-Process $FN -ArgumentList "/S" -Wait
}
