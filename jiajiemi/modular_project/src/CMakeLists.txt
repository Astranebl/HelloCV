add_library(crypto_lib
    crypto/Crypto.cpp
    crypto/FileHandler.cpp
    crypto/Menu.cpp
)

target_include_directories(crypto_lib
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/crypto
)

add_executable(cryptotool main.cpp)

target_link_libraries(cryptotool crypto_lib)

target_include_directories(cryptotool
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(cryptotool PROPERTIES
    OUTPUT_NAME "cryptotool"
    VERSION 1.0.0
)