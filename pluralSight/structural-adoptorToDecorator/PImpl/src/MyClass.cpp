#include "MyClass.h"
#include <iostream>

class MyClass::Impl
{
public:
    void function1()
    {
        std::cout << "Running Function 1" << std::endl;
    }
    void function2()
    {
        std::cout << "Running Function 2" << std::endl;
    }
};

MyClass::MyClass() : pImpl(std::make_unique<Impl>()) {}

MyClass::~MyClass() {}

void MyClass::function1()
{
    pImpl->function1();
}

void MyClass::function2()
{
    pImpl->function2();
}