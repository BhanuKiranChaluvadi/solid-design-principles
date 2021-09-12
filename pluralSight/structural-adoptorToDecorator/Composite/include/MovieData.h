#pragma once

#include "MovieInfo.h"
#include <utility>
#include <string>

class MovieData : public MovieInfo
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

    unsigned GetTotalWatchingTime() const override
    {
        return length_;
    }

    unsigned GetHighestScore() const override
    {
        return score_;
    }

    const MovieData *GetMovieWithHighestScore() const override
    {
        return this;
    }
};