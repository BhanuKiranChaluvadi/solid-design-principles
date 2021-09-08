#pragma once

#include "MovieDbRepository.h"
#include "TheMovieDbApi.h"

class MovieApiAdapter3 : public MovieRepository
{
    MovieApi &api_;

public:
    MovieApiAdapter3(MovieApi &api) : api_(api){};
    std::shared_ptr<MovieData> GetById(const std::string &movie_id) override;
};