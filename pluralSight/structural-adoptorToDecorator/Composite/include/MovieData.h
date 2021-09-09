#pragma once

#include <utility>
#include <string>

class MovieData
{
    std::string title_;
    unsigned length_;
    unsigned score_;

public:
    MovieData(std::string title, const unsigned length, const unsigned score)
        : title_(std::move(title)),
          length_(length),
          score_(score)
    {
    }
    std::string GetTitle() const { return title_; }
    unsigned GetLengthMin() const { return length_; }
    unsigned GetScore() const { return score_; }
};