#include "cpp_behave/spec_listener.h"
#include <regex>

using namespace ::testing;

namespace
{
    std::string replace_underscores(const char* cstr)
    {
        std::string str{cstr};
        const auto new_str = std::regex_replace(str, std::regex("_"), " ");
        return new_str;
    }


    void print_failed_tests(const UnitTest& unit_test)
    {
        const int failed_test_count = unit_test.failed_test_count();
        if (failed_test_count == 0)
        {
            return;
        }

        for (int i = 0; i < unit_test.total_test_case_count(); ++i)
        {
            const TestCase& test_case = *unit_test.GetTestCase(i);
            if (!test_case.should_run() || (test_case.failed_test_count() == 0))
            {
                continue;
            }
            for (int j = 0; j < test_case.total_test_count(); ++j)
            {
                const TestInfo& test_info = *test_case.GetTestInfo(j);
                if (!test_info.should_run() || test_info.result()->Passed())
                {
                    continue;
                }
                std::cout << "  - Specification '" << replace_underscores(test_case.name())
                          << " " << replace_underscores(test_info.name())
                          << "' FAILED." << "\n";
            }
        }
    }
}

namespace cpp_behave
{
    void SpecListener::OnTestProgramStart(const UnitTest& unit_test)
    {
        std::cout << "-----------------------------------------------------\n";
    };

    void SpecListener::OnTestCaseStart(const TestCase& test_case)
    {
        std::cout << "Specification:\n\n";
    }

    void SpecListener::OnTestStart(const TestInfo& test_info)
    {
        std::cout << " - '"
                  << replace_underscores(test_info.test_case_name())
                  << " "
                  << replace_underscores(test_info.name()) << "':\n";
    }

    void SpecListener::OnTestPartResult(const TestPartResult& test_part_result)
    {
        std::cout << (test_part_result.failed() ? "*** Failure" : "Success")
                  << " in " << test_part_result.file_name()
                  << ":" << test_part_result.line_number() << "\n"
                  << test_part_result.summary() << "\n";
    }

    void SpecListener::OnTestEnd(const TestInfo& testInfo)
    {
        std::cout << (testInfo.result()->Passed() ? " -> Passed" : "") << "\n\n";
    }

    void SpecListener::OnTestCaseEnd(const TestCase& test_case)
    {
        std::cout << "Executed " << test_case.test_to_run_count()
                  << " scenarios from Specification in "
                  << test_case.elapsed_time() << "ms total\n"
                  << "-----------------------------------------------------\n";

    }

    void SpecListener::OnTestIterationEnd(const UnitTest& unit_test,
                                          int /*iteration*/)
    {
        std::cout << unit_test.test_to_run_count() << " scenarios from " << unit_test.test_case_to_run_count()
                  << " specification ran.";
        if (GTEST_FLAG(print_time))
        {
            std::cout << " (" << internal::StreamableToString(unit_test.elapsed_time()) << " ms total)";
        }
        std::cout <<
                  "\n"
                  << unit_test.successful_test_count()
                  << " Passed";

        int num_failures = unit_test.failed_test_count();
        if (!unit_test.Passed())
        {
            const int failed_test_count = unit_test.failed_test_count();
            std::cout <<
                      "\n"
                      << failed_test_count
                      << " Failed, listed below:\n";
            print_failed_tests(unit_test);
            std::cout << "\n" << num_failures << " FAILED " << (num_failures == 1 ? "TEST" : "TESTS")
                      << "\n";
        }
    }

}