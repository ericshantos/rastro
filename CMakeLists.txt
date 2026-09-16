# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

<<<<<<< HEAD
# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
=======
>>>>>>> 28bf920 (feat: add new features in main)
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()

<<<<<<< HEAD
set(sdkVersion 2.3.0)
set(toolchainVersion 15_2_Rel1)
set(picotoolVersion 2.3.0)
=======
set(sdkVersion 2.3.1)
set(toolchainVersion 15_2_Rel1)
set(picotoolVersion 2.3.1)

>>>>>>> 28bf920 (feat: add new features in main)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)

if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
<<<<<<< HEAD
# ====================================================================================

set(PICO_BOARD pico2 CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK
=======

set(PICO_BOARD pico2 CACHE STRING "Board type")

>>>>>>> 28bf920 (feat: add new features in main)
include(pico_sdk_import.cmake)

project(rastro C CXX ASM)

<<<<<<< HEAD
# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable
add_executable(rastro
    src/main.cpp
    src/Engine.cpp
    src/Sensor.cpp
    src/AnalogSensor.cpp
)

# Program name and version
pico_set_program_name(rastro "rastro")
pico_set_program_version(rastro "0.2.1")

# Enable/disable output over UART/USB
pico_enable_stdio_uart(rastro 0)
pico_enable_stdio_usb(rastro 0)

# Link libraries
target_link_libraries(rastro
    pico_stdlib
    hardware_adc
)

# Include directories
=======
pico_sdk_init()

add_executable(rastro
    main.cpp
    src/controls/Button.cpp
    src/controls/SteeringWheel.cpp
    src/motors/Motor.cpp
    src/sensors/AnalogSensor.cpp
)


>>>>>>> 28bf920 (feat: add new features in main)
target_include_directories(rastro PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

<<<<<<< HEAD
# Generate extra outputs (.uf2, .hex, etc.)
=======
pico_set_program_name(rastro "rastro")
pico_set_program_version(rastro "0.4")


pico_enable_stdio_usb(rastro 1)
pico_enable_stdio_uart(rastro 0)


target_link_libraries(rastro
    pico_stdlib
    hardware_adc
    hardware_pwm
)

>>>>>>> 28bf920 (feat: add new features in main)
pico_add_extra_outputs(rastro)