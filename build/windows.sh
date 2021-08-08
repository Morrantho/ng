rm main.exe
gcc -IC:\\VulkanSDK\\1.2.182.0\\Include -LC:\\VulkanSDK\\1.2.182.0\\Lib -lvulkan-1 -O3 main.c -o main
./main.exe