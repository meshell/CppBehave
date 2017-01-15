cmake_minimum_required(VERSION 3.2)
cmake_policy(SET CMP0048 NEW)

add_executable(cpp_behave_example
        ${CMAKE_CURRENT_SOURCE_DIR}/example.cpp
        )

target_link_libraries(cpp_behave_example
        PRIVATE
        cpp_behave::main
        )
