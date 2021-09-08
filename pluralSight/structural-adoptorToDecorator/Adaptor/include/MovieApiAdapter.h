#pragma once

#include "MovieDbRepository.h"
#include "TheMovieDbApi.h"

class MovieApiAdapter : public MovieRepository
{
	TheMovieDbApi api_;	
public:
	MovieApiAdapter(TheMovieDbApi api);
	std::shared_ptr<MovieData> GetById(const std::string& movie_id) override;

};