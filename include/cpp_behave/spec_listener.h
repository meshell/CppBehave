#ifndef CPPBEHAVE_SPEC_LISTENER_H
#define CPPBEHAVE_SPEC_LISTENER_H

#include <gtest/gtest.h>

namespace cpp_behave
{
    using ::testing::UnitTest;
    using ::testing::TestCase;
    using ::testing::TestInfo;
    using ::testing::TestPartResult;

    class SpecListener : public ::testing::EmptyTestEventListener
    {

        void OnTestProgramStart(const UnitTest& unit_test) override;

        void OnTestCaseStart(const TestCase& test_case) override;

        void OnTestStart(const TestInfo& test_info) override;

        void OnTestPartResult(const TestPartResult& test_part_result) override;

        void OnTestEnd(const TestInfo& test_info) override;

        void OnTestCaseEnd(const TestCase& test_case) override;

        void OnTestIterationEnd(const UnitTest& unit_test,
                                int iteration) override;

    };
}
#endif //CPPBEHAVE_SPEC_LISTENER_H
