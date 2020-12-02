#pragma once

#include <iostream>
#include <map>

// Use ugly macros because I like to overengineer my code.
#define ADD_SOLUTION(X) \
    inline bool initialize_##X() { \
        SolutionManager::get_singleton()->add_day(X, day##X##_part2); \
        return true; \
    } \
    static const bool initializer_##X = initialize_##X(); \

class SolutionManager
{
public:
    void add_day(uint day, int (*function)(std::ifstream &input));

    static SolutionManager* get_singleton();
    std::map<uint, int (*)(std::ifstream &input)> days;

private:
    SolutionManager() = default;
};