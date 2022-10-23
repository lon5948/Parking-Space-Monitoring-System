################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include xip/subdir.mk
-include wifi/wlcmgr/subdir.mk
-include wifi/wifidriver/subdir.mk
-include wifi/port/os/subdir.mk
-include wifi/port/lwip/subdir.mk
-include wifi/dhcpd/subdir.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include sdmmc/src/subdir.mk
-include sdmmc/osa/subdir.mk
-include sdmmc/host/subdir.mk
-include mbedtls/port/ksdk/subdir.mk
-include mbedtls/library/subdir.mk
-include lwip/src/netif/ppp/subdir.mk
-include lwip/src/netif/subdir.mk
-include lwip/src/core/ipv6/subdir.mk
-include lwip/src/core/ipv4/subdir.mk
-include lwip/src/core/subdir.mk
-include lwip/src/api/subdir.mk
-include lwip/port/subdir.mk
-include freertos/vendors/nxp/wifi/nxp/subdir.mk
-include freertos/vendors/nxp/secure_sockets/lwip/subdir.mk
-include freertos/vendors/nxp/pkcs11/common/subdir.mk
-include freertos/libraries/logging/subdir.mk
-include freertos/libraries/freertos_plus/standard/utils/src/subdir.mk
-include freertos/libraries/freertos_plus/standard/tls/src/subdir.mk
-include freertos/libraries/freertos_plus/standard/crypto/src/subdir.mk
-include freertos/libraries/device_shadow_for_aws/source/subdir.mk
-include freertos/libraries/coreMQTT/source/subdir.mk
-include freertos/libraries/coreJSON/source/subdir.mk
-include freertos/libraries/c_sdk/standard/common/taskpool/subdir.mk
-include freertos/libraries/c_sdk/standard/common/subdir.mk
-include freertos/libraries/abstractions/transport/secure_sockets/subdir.mk
-include freertos/libraries/abstractions/platform/freertos/subdir.mk
-include freertos/libraries/abstractions/pkcs11/corePKCS11/source/portable/mbedtls/subdir.mk
-include freertos/libraries/abstractions/pkcs11/corePKCS11/source/subdir.mk
-include freertos/libraries/abstractions/backoff_algorithm/source/subdir.mk
-include freertos/libraries/3rdparty/mbedtls_utils/subdir.mk
-include freertos/freertos_kernel/portable/MemMang/subdir.mk
-include freertos/freertos_kernel/portable/GCC/ARM_CM4F/subdir.mk
-include freertos/freertos_kernel/subdir.mk
-include freertos/demos/network_manager/subdir.mk
-include freertos/demos/dev_mode_key_provisioning/src/subdir.mk
-include freertos/demos/demo_runner/subdir.mk
-include freertos/demos/common/pkcs11_helpers/subdir.mk
-include freertos/demos/common/mqtt_demo_helpers/subdir.mk
-include flash/mflash/mimxrt1062/subdir.mk
-include flash/mflash/subdir.mk
-include drivers/subdir.mk
-include device/subdir.mk
-include component/uart/subdir.mk
-include component/silicon_id/subdir.mk
-include component/serial_manager/subdir.mk
-include component/osa/subdir.mk
-include component/lists/subdir.mk
-include component/gpio/subdir.mk
-include board/subdir.mk
-include accel/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := evkmimxrt1060_aws_remote_control_wifi_nxp
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: evkmimxrt1060_aws_remote_control_wifi_nxp.axf

# Tool invocations
evkmimxrt1060_aws_remote_control_wifi_nxp.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="evkmimxrt1060_aws_remote_control_wifi_nxp.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -T evkmimxrt1060_aws_remote_control_wifi_nxp_Debug.ld -o "evkmimxrt1060_aws_remote_control_wifi_nxp.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) evkmimxrt1060_aws_remote_control_wifi_nxp.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "evkmimxrt1060_aws_remote_control_wifi_nxp.axf"; # arm-none-eabi-objcopy -v -O binary "evkmimxrt1060_aws_remote_control_wifi_nxp.axf" "evkmimxrt1060_aws_remote_control_wifi_nxp.bin" ; # checksum -p MIMXRT1062xxxxA -d "evkmimxrt1060_aws_remote_control_wifi_nxp.bin";
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
