#include "MovieGroup.h"

#include <iostream>

unsigned getTotalWatchingTime(const std::list<MovieData *> &movies)
{
	unsigned total_watching_time = 0;
	for (const auto &movie : movies)
	{
		total_watching_time += movie->GetLengthMin();
	}
	return total_watching_time;
}

unsigned getTotalWatchingTime(const std::list<MovieGroup *> &groups)
{
	unsigned total_watching_time = 0;
	for (const auto &group : groups)
	{
		total_watching_time += getTotalWatchingTime(group->getMovies());
		total_watching_time += getTotalWatchingTime(group->getSubGroups());
	}
	return total_watching_time;
}

int main()
{
	MovieGroup action_movies("Action");
	MovieGroup military_action_movies("Military Action");
	MovieGroup martial_arts_movies("Martial Arts");
	action_movies.addSubGroup(military_action_movies);
	action_movies.addSubGroup(martial_arts_movies);

	MovieData movie_1("Generic racing movie #3", 120, 6);
	MovieData movie_2("Zombie movie remake", 80, 7);
	MovieData movie_3("Yet another war movie", 180, 9);
	MovieData movie_4("Dragon master 5", 90, 3);
	MovieData movie_5("Kendo Kid 2", 46, 8);

	action_movies.addMovie(movie_1);
	action_movies.addMovie(movie_2);

	military_action_movies.addMovie(movie_3);

	martial_arts_movies.addMovie(movie_4);
	martial_arts_movies.addMovie(movie_5);

	/*
        Action
        |
        -> movie_1
        -> movie_2
        -> military_action_movies
            | 
            -> movie_3
        -> martial_arts_movies
            |
            -> movie_4
            -> movie_5
    */

	unsigned total_watching_time = getTotalWatchingTime(action_movies.getMovies());
	total_watching_time += getTotalWatchingTime(action_movies.getSubGroups());

	/*
		std::list<MovieGroup *> groups_;
		groups_.push_back(&action_movies);
		unsigned total_watching_time = getTotalWatchingTime(groups_);
	*/

	std::cout << "Total watching time: " << total_watching_time << std::endl;
	return 0;
}