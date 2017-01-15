cmake_minimum_required(VERSION 3.6)
project(CppBehave)

option(DISABLE_EXAMPLE "Do not build the example" FALSE)

set(GTEST_ROOT ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Path to google test root")

# set default built type to Debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

# Check for clang compiler
if(CMAKE_CXX_COMPILER MATCHES ".*clang")
    set(CMAKE_COMPILER_IS_CLANGCXX 1)
endif()


set(LIB_HEADER_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_behave/test_step.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_behave/spec_listener.h
        )

if(MSVC_IDE)
    source_group("Header Files" FILES ${PROJECTLIB_HEADER_FILES})
endif(MSVC_IDE)


set(LIB_SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/spec_listener.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/cpp_behave_main.cpp
        )

add_library(cpp_behave STATIC
        ${LIB_SOURCE_FILES}
        ${LIB_HEADER_FILES}
        )

add_library(cpp_behave::main ALIAS cpp_behave)

find_package(GTest REQUIRED)

target_link_libraries(cpp_behave
        PUBLIC
        GTest::GTest
        )

target_include_directories(cpp_behave
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(cpp_behave
            PUBLIC
            -pedantic
            -Wall
            -Wextra
            PRIVATE
            -Werror
            -Wcast-align
            -Wcast-qual
            -Wctor-dtor-privacy
            -Wdisabled-optimization
            -Wformat=2
            -Winit-self
            -Wlogical-op
            -Wmissing-declarations
            -Wmissing-include-dirs
            -Wnoexcept
            -Wold-style-cast
            -Woverloaded-virtual
            -Wredundant-decls
            -Wshadow
            -Wsign-conversion
            -Wsign-promo
            -Wstrict-null-sentinel
            -Wstrict-overflow=5
            -Wswitch-default
            -Wundef
            )

elseif(CMAKE_COMPILER_IS_CLANGCXX)
    target_compile_options(cpp_behave
            PUBLIC
            -Weverything
            -Wno-c++98-compat
            -Wno-padded
            PRIVATE
            -Werror
            )
endif(CMAKE_COMPILER_IS_GNUCXX)

target_compile_features(cpp_behave
        INTERFACE
        cxx_auto_type
        cxx_constexpr
        cxx_decltype_auto
        cxx_defaulted_functions
        cxx_defaulted_move_initializers
        cxx_delegating_constructors
        cxx_deleted_functions
        cxx_final
        cxx_generic_lambdas
        cxx_lambdas
        cxx_nullptr
        cxx_override
        cxx_range_for
        cxx_rvalue_references
        cxx_static_assert
        cxx_strong_enums
        cxx_variable_templates
        cxx_variadic_macros
        cxx_variadic_templates
        )


if(NOT DISABLE_EXAMPLE)
    add_subdirectory(Examples)
endif()