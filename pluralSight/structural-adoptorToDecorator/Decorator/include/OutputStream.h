#pragma once

#include <string>
#include <iostream>
#include <fstream>

class OutputStream
{
public:
    virtual ~OutputStream() = default;
    virtual void write(const std::string &str) = 0;
};

class ConsoleStream : public OutputStream
{
public:
    void write(const std::string &str) override
    {
        std::cout << str;
    }
};