if(NOT DEFINED BOARD)
    set(BOARD "ESP32")
endif()

message(STATUS "Building MCAL for board: ${BOARD}")

if(BOARD STREQUAL "ESP32")
    set(MCAL_SOURCES
        src/ESP32/dio.cpp
    )
elseif(BOARD STREQUAL "STM32")
    set(BOARD "STM32")
    set(MCAL_SOURCES
        src/stm32/dio.cpp
        src/stm32/port.cpp
        src/common/utils.cpp
    )
else()
    message(FATAL_ERROR "Unknown BOARD: ${BOARD}")
endif()

if(DEFINED ENV{IDF_PATH})
    # ESP-IDF build
    idf_component_register(
        SRCS ${MCAL_SOURCES}
        INCLUDE_DIRS "include" "include/${BOARD}"
        REQUIRES esp_http_server esp_netif esp_wifi driver esp_timer esp_eth nvs_flash
    )

    target_compile_definitions(${COMPONENT_LIB} PUBLIC BOARD_ESP32)

else()
    # Non ESP-IDF build (e.g. STM32 standalone)
    add_library(MCAL STATIC ${MCAL_SOURCES})

    target_include_directories(MCAL PUBLIC
        include
        include/${BOARD}
    )

   target_compile_definitions(${COMPONENT_LIB} PUBLIC BOARD_STM32)

endif()