#pragma once

#include <memory>

class MyClass {
    class Impl;
    std::unique_ptr<Impl> pImpl;

public:
    MyClass();
    ~MyClass();
    void function1();
    void function2();
};