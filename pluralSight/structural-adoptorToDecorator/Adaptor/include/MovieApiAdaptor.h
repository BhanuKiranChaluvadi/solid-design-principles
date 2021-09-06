#pragma once

#include "MovieDbRepository.h"
#include "TheMovieDbApi.h"

class MovieApiAdaptor : public MovieRepository
{
	TheMovieDbApi api_;
public:
	std::shared_ptr<MovieData> GetById(const std::string& movie_id) override;

}