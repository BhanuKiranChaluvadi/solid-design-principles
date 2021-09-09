#include "MyClass.h"
#include <iostream>

class MyClass::Impl
{
public:
    void function1(const MyClass& myClass)
    {
        std::cout << myClass.name_ << " Running Function 1" << std::endl;
    }
    void function2(const MyClass& myClass)
    {
        std::cout << myClass.name_ << " Running Function 2" << std::endl;
    }
};

MyClass::MyClass(std::string name) : pImpl(std::make_unique<Impl>()), name_(std::move(name)) {}

MyClass::~MyClass() {}

void MyClass::function1()
{
    pImpl->function1(*this);
}

void MyClass::function2()
{
    pImpl->function2(*this);
}