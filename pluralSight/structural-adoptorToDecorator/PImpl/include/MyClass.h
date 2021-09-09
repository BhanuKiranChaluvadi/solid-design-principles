#pragma once

#include <memory>
#include <string>
class MyClass
{
    class Impl;
    Impl* pImpl;

public:
    MyClass(std::string name);
    ~MyClass();
    void function1();
    void function2();
};