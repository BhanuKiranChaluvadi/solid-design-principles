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

    unsigned GetHighestScore() const override
    {
        unsigned highest_score = 0;
        for (auto movie_info : movies_info_)
        {
            unsigned score = movie_info->GetHighestScore();
            if (score > highest_score)
            {
                highest_score = score;
            }
        }
        return highest_score;
    }

    const MovieData *GetMovieWithHighestScore() const override
    {
        const MovieData *current_highest = nullptr;
        unsigned highest_score = 0;

        for (auto movie_info : movies_info_)
        {
            const auto temp_highest = movie_info->GetMovieWithHighestScore();
            if (temp_highest != nullptr)
            {
                if (current_highest == nullptr || current_highest->GetScore() < temp_highest->GetScore())
                {
                    current_highest = temp_highest;
                }
            }
        }
        return current_highest;
    }
};