#pragma once

#include <string>
#include <list>

#include "MovieData.h"

class MovieGroup : public MovieInfo
{
    std::string title_;
    std::list<MovieInfo *> movies_info_;

public:
    MovieGroup(std::string title) : title_(std::move(title)) {}

    void Add(MovieInfo &group)
    {
        movies_info_.push_back(&group);
    }

    void Remove(MovieInfo &group)
    {
        movies_info_.remove(&group);
    }

    unsigned GetTotalWatchingTime() const override
    {
        unsigned total_watching_time = 0;
        for (auto movie_info : movies_info_)
        {
            total_watching_time += movie_info->GetTotalWatchingTime();
        }
        return total_watching_time;
    }
};