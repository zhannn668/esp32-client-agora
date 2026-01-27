# Agora ESP32 LLM Intelligent Conversation

*[简体中文](README.cn.md) | English*

## Project Introduction

This example demonstrates how to simulate a typical LLM (Large Language Model) intelligent conversation scenario using the ReSpeaker XMOS XVF3800 with XIAO ESP32S3 development board, enabling real-time intelligent conversations with large language models.

### File Structure
```
├── CMakeLists.txt
├── components                                  Agora iot sdk component
│   ├── agora_iot_sdk
│   │   ├── CMakeLists.txt
│   │   ├── include                             Agora iot sdk header files
│   │   │   ├── agora_rtc_api.h
│   │   └── libs                                Agora iot sdk libraries                      
│   │       ├── libagora-cjson.a
│   │       ├── libahpl.a
│   │       ├── librtsa.a
|   ├── esp32-camera                           esp32-camera component submodule
├── main                                        LLM Demo code
│   ├── ai_agent.h
│   ├── app_config.h
│   ├── common.h
│   ├── audio_proc.h
│   ├── rtc_proc.h
│   ├── CMakeLists.txt
│   ├── Kconfig.projbuild
|   ├── ai_agent.c
|   ├── audio_proc.c
|   ├── rtc_proc.c
│   └── llm_main.c
├── partitions.csv                              partition table
├── README.en.md
├── README.md
├── sdkconfig.defaults
└── sdkconfig.defaults.esp32s3
```

## Environment Setup

### Hardware Requirements

This example currently only supports the ` ReSpeaker XMOS XVF3800 with XIAO ESP32S3 ` development board.

## Build and Flash

### esp32-camera

Building and running this example requires the esp32-camera component.  
This component is already included in the `components/esp32-camera` directory of this repository.  
After cloning this repository, you can use it directly without additional downloads or git submodule operations.

The dependency components of esp32-camera (such as esp_jpeg, etc.) will be automatically downloaded by the ESP-IDF Component Manager during the first build.

### Agora IOT SDK

Building and running this example requires the Agora IoT SDK.  
Due to licensing and distribution restrictions, the Agora IoT SDK is not included in this repository and must be downloaded manually by users.

Please download `agora_iot_sdk.tar` from [here](https://rte-store.s3.amazonaws.com/agora_iot_sdk.tar),  
and extract it to the `esp32-client/components/agora_iot_sdk` directory:

```bash
cd esp32-client/components
tar -xvf agora_iot_sdk.tar
```

If complete Agora IoT SDK files already exist in this directory, no repeated operation is necessary.

### Linux Operating System

#### Default IDF Branch

This example supports IDF tag v[5.2.3] and later. The example uses IDF tag v[5.2.3] by default (commit id: c9763f62dd00c887a1a8fafe388db868a7e44069).

To select the IDF branch, run the following commands:

```bash
cd $IDF_PATH
git checkout v5.2.3
git pull
git submodule update --init --recursive
```

This example supports ADF v2.7 tag (commit id: 9cf556de500019bb79f3bb84c821fda37668c052)

#### Apply IDF Patch

This example requires applying 1 patch to IDF. Use the following commands:

```bash
export ADF_PATH=~/esp/esp-adf
cd $IDF_PATH
git apply $ADF_PATH/idf_patches/idf_v5.2_freertos.patch
```

#### Build Firmware

Copy the esp32-client directory to the ~/ten-framework/ai_agents directory. Run the following commands:

```bash
$ . $HOME/esp/esp-idf/export.sh
$ cd ~/esp/esp32-client
$ idf.py set-target esp32s3
$ idf.py menuconfig	--> Agora Demo for ESP32 --> (Configure WIFI SSID and Password)
$ idf.py build
```
Configure FreeRTOS backward compatibility:
In menuconfig, go to Component config --> FreeRTOS --> Kernel and set configENABLE_BACKWARD_COMPATIBILITY

### Windows Operating System

#### Default IDF Branch

Download IDF, select v5.2.3 offline version for download. The example uses IDF tag v[5.2.3] by default.
https://docs.espressif.com/projects/esp-idf/en/v5.2.3/esp32/get-started/windows-setup.html

Download ADF to Espressif/frameworks directory, supporting ADF v2.7 tag (commit id: 9cf556de500019bb79f3bb84c821fda37668c052)
https://docs.espressif.com/projects/esp-adf/en/latest/get-started/index.html#step-2-get-esp-adf


#### Apply IDF Patch

Method 1: Add ADF_PATH to environment variables in system settings
E:\esp32s3\Espressif\frameworks\esp-adf

Method 2: Add ADF_PATH to environment variables via command line

```bash
$ setx ADF_PATH Espressif/frameworks/esp-adf
```

Note: After setting the ADF_PATH environment variable, restart ESP-IDF 5.2 PowerShell for it to take effect.

This example requires applying 1 patch to IDF. Use the following commands:

```bash
cd $IDF_PATH
git apply $ADF_PATH/idf_patches/idf_v5.2_freertos.patch
```

#### Build Firmware

Copy the esp32-client directory to the \ten-framework\ai_agents directory. Run the following commands:
```bash
$ cd ../esp32-client
$ idf.py set-target esp32s3
$ idf.py menuconfig	--> Agora Demo for ESP32 --> (Configure WIFI SSID and Password)
$ idf.py build
```
Configure FreeRTOS backward compatibility:
In menuconfig, go to Component config --> FreeRTOS --> Kernel and set configENABLE_BACKWARD_COMPATIBILITY


### Flash Firmware

Run the following command:

```bash
$ idf.py -p /dev/ttyUSB0 flash monitor
```
Note: On Linux systems, you may encounter permission issues with /dev/ttyUSB0. Please execute `sudo usermod -aG dialout $USER`

After successful flashing, this example will run automatically. After the device joins the RTC channel, you will see the serial port output: "Agora: Press [SET] key to Join the Ai Agent ...".


### Configure Your Own AI Agent

1. Please configure your own AI Agent in the `app_config.h` file.
2. Modify `TENAI_AGENT_URL` to your own TEN-Agent server URL (typically the port 8080 service you started with `task run`).
3. Modify `AI_AGENT_CHANNEL_NAME` to your own AI Agent Channel name.
4. Recompile and flash to the chip.

## About Agora

The Agora Audio and Video IoT platform solution relies on Agora's self-built underlying real-time transmission network, Agora SD-RTN™ (Software Defined Real-time Network), providing audio and video stream real-time transmission capabilities over the Internet for all Linux/RTOS devices with network functionality. This solution fully utilizes Agora's global network nodes and intelligent dynamic routing algorithms, while supporting various combined anti-weak network strategies such as forward error correction, intelligent retransmission, bandwidth prediction, and stream smoothing. It can still deliver the best audio and video network experience with high connectivity, high real-time performance, and high stability in various uncertain network environments where devices are located. In addition, this solution has an extremely small package size and memory footprint, making it suitable for running on any resource-constrained IoT device, including all Espressif ESP32 series products.

## Technical Support

Please follow the links below to get technical support:

- If you find bugs in the example code or have other questions, you can directly contact the community manager

We will reply as soon as possible.