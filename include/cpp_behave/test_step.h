#ifndef CPPBEHAVE_TEST_STEP_H_H
#define CPPBEHAVE_TEST_STEP_H_H

#include <gtest/gtest.h>
#include <iostream>

#define SPEC(test_case_name, test_name) GTEST_TEST(test_case_name, test_name)

constexpr auto intent = "     ";

namespace
{
    static void tprintf(const char* format)
    {
        std::cout << format << "\n";
    }

    template<typename T, typename ...Targs>
    static void tprintf(const char* format, T value, Targs... args)
    {
        for (; *format != '\0'; format++)
        {
            if (*format == '%')
            {
                std::cout << value;
                tprintf(format + 1, args...);
                return;
            }
            std::cout << *format;
        }
        std::cout << "\n";
    };
}

namespace cpp_behave
{
    class test_step
    {
    public:
        test_step() = default;

        explicit test_step(const std::string& step_text)
                : step_text_(step_text)
        {}

        template<typename T, typename ...Targs>
        void f(const T& fnc, Targs&& ... args)
        {
            const auto step_text = std::string(intent) + step_text_;
            tprintf(step_text.c_str(), std::forward<Targs>(args)...);
            fnc(std::forward<Targs>(args)...);
        }

    private:
        std::string step_text_;
    };

    static test_step operator "" _(const char* text, std::size_t)
    {
        return test_step(text);
    }
}

#endif //CPPBEHAVE_TEST_STEP_H_H
