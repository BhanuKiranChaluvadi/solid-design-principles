#include "MyClass.h"
#include <iostream>

class MyClass::Impl
{
    std::string name_;

public:
    Impl(std::string name) :name_(name) {}

    void function1()
    {
        std::cout << name_ << " Running Function 1" << std::endl;
    }
    void function2()
    {
        std::cout << name_ << " Running Function 2" << std::endl;
    }
};

MyClass::MyClass(std::string name) : pImpl(std::make_unique<Impl>(name)) {}

MyClass::~MyClass() {}

void MyClass::function1()
{
    pImpl->function1();
}

void MyClass::function2()
{
    pImpl->function2();
}