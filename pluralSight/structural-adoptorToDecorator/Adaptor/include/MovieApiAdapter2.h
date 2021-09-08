#pragma once

#include "MovieDbRepository.h"
#include "TheMovieDbApi.h"

class MovieApiAdapter2 : public MovieRepository, public TheMovieDbApi
{
public:
    MovieApiAdapter2(std::string api_key) : TheMovieDbApi(api_key) {}

    std::shared_ptr<MovieData> GetById(const std::string &movie_id) override;
};