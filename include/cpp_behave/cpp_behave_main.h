#ifndef CPPBEHAVE_CPP_BEHAVE_MAIN_H
#define CPPBEHAVE_CPP_BEHAVE_MAIN_H

#define SPEC_MAIN int main(int argc, char** argv) { return cpp_behave::main_impl(argc, argv);}

namespace cpp_behave
{
    int main_impl(int argc, char** argv);
}

#endif //CPPBEHAVE_CPP_BEHAVE_MAIN_H
