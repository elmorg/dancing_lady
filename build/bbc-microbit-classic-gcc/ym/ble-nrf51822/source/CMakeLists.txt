# NOTE: This file is generated by yotta: changes will be overwritten!

cmake_minimum_required(VERSION 2.8.11)

include_directories("/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source")


set(YOTTA_AUTO_BLE-NRF51822_CPP_FILES
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xn.cpp"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/btle/custom/custom_helper.cpp"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/btle/btle_security.cpp"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xGap.cpp"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/btle/btle_gap.cpp"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xGattServer.cpp"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xCharacteristicDescriptorDiscoverer.cpp"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xGattClient.cpp"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xDiscoveredCharacteristic.cpp"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xServiceDiscovery.cpp"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/btle/btle.cpp"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/btle/btle_advertising.cpp"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/btle/btle_discovery.cpp"
)
# force dependency on the config header for cpp files, which CMake otherwise wouldn't track:
set_property(SOURCE ${YOTTA_AUTO_BLE-NRF51822_CPP_FILES} PROPERTY OBJECT_DEPENDS "/Users/emorgan/GitHub/dancing_lady/build/bbc-microbit-classic-gcc/yotta_config.h")
set(YOTTA_AUTO_BLE-NRF51822_HEADER_FILES
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xServiceDiscovery.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xGap.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/btle/btle_advertising.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/btle/btle_security.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/common/binary.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xGattClient.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xCharacteristicDescriptorDiscoverer.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xDiscoveredCharacteristic.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xGattServer.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/common/assertion.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xn.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/btle/btle.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/btle/btle_discovery.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/common/compiler.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/common/common.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/common/ansi_escape.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/common/ble_error.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/projectconfig.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/btle/btle_gap.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/nRF5xSecurityManager.h"
    "/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/btle/custom/custom_helper.h"
)
# force dependency on the config header for header files, which CMake otherwise wouldn't track:
set_property(SOURCE ${YOTTA_AUTO_BLE-NRF51822_HEADER_FILES} PROPERTY OBJECT_DEPENDS "/Users/emorgan/GitHub/dancing_lady/build/bbc-microbit-classic-gcc/yotta_config.h")


add_library(ble-nrf51822
    ${YOTTA_AUTO_BLE-NRF51822_CPP_FILES}
    ${YOTTA_AUTO_BLE-NRF51822_HEADER_FILES}
)

yotta_postprocess_target(LIBRARY ble-nrf51822)



target_link_libraries(ble-nrf51822
    ble
    nrf51-sdk
)

include("/Users/emorgan/GitHub/dancing_lady/yotta_modules/ble-nrf51822/source/supress-warnings.cmake")
