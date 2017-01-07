#include "cpp_behave/cpp_behave_main.h"
#include "cpp_behave/spec_listener.h"

namespace cpp_behave
{
    int main_impl(int argc, char** argv)
    {
        ::testing::InitGoogleTest(&argc, argv);
        // Gets hold of the event listener list.
        ::testing::TestEventListeners& listeners =
                ::testing::UnitTest::GetInstance()->listeners();
        // Adds a listener to the end.  Google Test takes the ownership.
        delete listeners.Release(listeners.default_result_printer());
        listeners.Append(new cpp_behave::SpecListener);
        return RUN_ALL_TESTS();
    }
}

