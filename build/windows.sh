# Link to vulkan-1.dll, since mingw64 hates us.
rm ng.exe
gcc -IC:/VulkanSDK/1.2.182.0/Include C:/Windows/System32/vulkan-1.dll -O3 ng.c -o ng
./ng.exe