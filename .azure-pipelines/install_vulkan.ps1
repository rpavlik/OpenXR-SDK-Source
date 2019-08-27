if (-not $env:VULKAN_SDK_VERSION) {
    $env:VULKAN_SDK_VERSION = "1.1.106.0"
}

$SDK_VER = $env:VULKAN_SDK_VERSION

if (-not (Test-Path env:VULKAN_SDK)) {
    if ($env:SYSTEM_DEFAULTWORKINGDIRECTORY) {
        $env:VULKAN_SDK = "$env:SYSTEM_DEFAULTWORKINGDIRECTORY\vulkan_sdk\$SDK_VER"
    } else {
        $env:VULKAN_SDK = "c:\VulkanSDK\$SDK_VER"
    }
}
Write-Output "Trying for Vulkan SDK $SDK_VER"
$FN = "VulkanSDK-$SDK_VER-Installer.exe"
$URL = "https://sdk.lunarg.com/sdk/download/$SDK_VER/windows/$FN"
if (-not (Test-Path "$env:VULKAN_SDK/Include/vulkan/vulkan.h")) {
    Write-Output "Downloading $URL"
    $wc = New-Object System.Net.WebClient
    $wc.DownloadFile($URL, $FN)

    Write-Output "Running $FN in silent, blocking mode"
    Start-Process $FN -ArgumentList "/S" -Wait "/D=$env:VULKAN_SDK"
}
