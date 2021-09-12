#pragma once

#include "OutputStream.h"

class StreamDecorator : public OutputStream
{
    OutputStream *stream_;

public:
    StreamDecorator(OutputStream *stream) : stream_(stream) {}

    ~StreamDecorator() override = default;

    virtual std::string Encode(const std::string &str) = 0;

    void write(const std::string &str) override
    {
        const auto encoded = Encode(str);
        stream_->write(encoded);
    }
};

class EncryptedStreamDecorator : public StreamDecorator
{
    char key_;

public:
    EncryptedStreamDecorator(OutputStream *stream, char key) : StreamDecorator(stream), key_(key) {}

    std::string Encode(const std::string &str) override
    {
        std::string result;

        for (char c : str)
        {
            result.push_back(c + key_);
        }
        return result;
    }
};