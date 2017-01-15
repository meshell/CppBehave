# CppBehave
An addition to the googletest test framework to allow to write more fluent human readable test specs.

## Description
This small library provides additions to the googletest framework to allow writting better human readable test specifications.
See the examples to get an idea.

__Please Note__: This is an experimental project recently started and not mature yet.

## How to use
Cpp Behave is based on [googletest](https://github.com/google/googletest) but provides its own main methode with a customized test result printer attached. To use it you simply need to link to CppBehave in your test executable instead of to the gtest_main.
