cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()

set(sdkVersion 2.3.1)
set(toolchainVersion 15_2_Rel1)
set(picotoolVersion 2.3.1)

set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)

if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

set(PICO_BOARD pico2 CACHE STRING "Board type")

include(pico_sdk_import.cmake)

project(rastro C CXX ASM)

pico_sdk_init()

add_executable(rastro
    main.cpp

    src/controls/Button.cpp
    src/controls/SteeringWheel.cpp
    src/controls/PID.cpp
    src/controls/TimeStep.cpp

    src/motors/Motor.cpp
    src/sensors/AnalogSensor.cpp
    src/sensors/LinePosition.cpp
)

target_include_directories(rastro PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

pico_set_program_name(rastro "rastro")
pico_set_program_version(rastro "0.4")

pico_enable_stdio_usb(rastro 1)
pico_enable_stdio_uart(rastro 0)

target_link_libraries(rastro
    pico_stdlib
    hardware_adc
    hardware_pwm
)

pico_add_extra_outputs(rastro)