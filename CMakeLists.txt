cmake_minimum_required(VERSION 3.6)
project(CppBehave)

set(CMAKE_CXX_STANDARD 11)

set(GTEST_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(GTEST_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(GTEST_LIBRARY_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/lib)

find_package(GTest REQUIRED)

set(SOURCE_FILES example.cpp include/cpp_behave/test_step.h include/cpp_behave/spec_listener.h src/spec_listener.cpp include/cpp_behave/cpp_behave_main.h src/cpp_behave_main.cpp)
add_executable(CppBehave ${SOURCE_FILES})

target_link_libraries(CppBehave
        GTest::GTest
    #    GTest::Main
        )

target_compile_features(CppBehave
        PUBLIC
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
