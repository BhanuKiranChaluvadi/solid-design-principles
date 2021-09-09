#pragma once

#include <memory>
#include <string>
class MyClass
{
    std::string name_;

    class Impl;
    std::unique_ptr<Impl> pImpl;

public:
    MyClass(std::string name);
    ~MyClass();
    void function1();
    void function2();
};