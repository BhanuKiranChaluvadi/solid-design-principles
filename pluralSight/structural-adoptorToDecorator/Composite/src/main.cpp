#include "MovieGroup.h"

#include <iostream>

int main()
{
	MovieGroup action_movies("Action");
	MovieGroup military_action_movies("Military Action");
	MovieGroup martial_arts_movies("Martial Arts");
	action_movies.Add(military_action_movies);
	action_movies.Add(martial_arts_movies);

	MovieData movie_1("Generic racing movie #3", 120, 6);
	MovieData movie_2("Zombie movie remake", 80, 7);
	MovieData movie_3("Yet another war movie", 180, 9);
	MovieData movie_4("Dragon master 5", 90, 3);
	MovieData movie_5("Kendo Kid 2", 46, 8);

	action_movies.Add(movie_1);
	action_movies.Add(movie_2);

	military_action_movies.Add(movie_3);

	martial_arts_movies.Add(movie_4);
	martial_arts_movies.Add(movie_5);

	unsigned total_watching_time = action_movies.GetTotalWatchingTime();	

	std::cout << "Total watching time: " << total_watching_time << std::endl;
	return 0;
}