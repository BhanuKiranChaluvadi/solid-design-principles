#pragma once

class MovieData;

class MovieInfo
{
public:
	virtual unsigned GetTotalWatchingTime() const = 0;
	virtual unsigned GetHighestScore() const = 0;
	virtual const MovieData *GetMovieWithHighestScore() const = 0;

	virtual void Add(MovieInfo &movie_info) {}
	virtual void Remove(MovieInfo &movie_info) {}
};