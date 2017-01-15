#include "cpp_behave/test_step.h"

#include <memory>


// Example

class Calculator
{
public:
    template<typename T>
    T add(T rhs, T lhs)
    {
        return rhs + lhs;
    }

    template<typename T>
    T subtract(T rhs, T lhs)
    {
        return {};
    }
};

using namespace cpp_behave;

namespace
{
    SPEC(A_Calculator, should_add_correctly)
    {
        const auto x = 3;
        const auto y = 6;
        auto result = 0;
        const auto expected_res = 9;

        std::unique_ptr<Calculator> calculator;

        "Given a Calculator"_
                .f([&] { calculator = std::unique_ptr<Calculator>(new Calculator{}); });
        " and the Number %"_
                .f([](const auto) {}, x);
        " and the Number %"_
                .f([&](const auto) {}, y);
        "When I add the numbers together"_
                .f([&]() { result = calculator->add(x, y); });
        "Then the result should be %"_
                .f([&](const auto expected_result) { ASSERT_EQ(expected_result, result); }, expected_res);
    }


    SPEC(A_Calculator, should_subtract_correctly)
    {
        const auto x = 3;
        const auto y = 6;
        auto result = 0;
        const auto expected_res = 3;

        std::unique_ptr<Calculator> calculator;


        "Given a Calculator"_
                .f([&] { calculator = std::unique_ptr<Calculator>(new Calculator{}); });
        " and the Number %"_
                .f([](const auto) {}, x);
        " and the Number %"_
                .f([&](const auto) {}, y);
        "When I subtract the first from the second"_
                .f([&]() { result = calculator->subtract(y, x); });
        "Then the result should be %"_
                .f([&](const auto expected_result) { ASSERT_EQ(expected_result, result); }, expected_res);
    }
}

