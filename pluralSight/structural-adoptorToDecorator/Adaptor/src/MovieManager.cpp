#include "MovieManager.h"

#include <iostream>
#include <ostream>

void MovieManager::PrintMovieData(const std::shared_ptr<MovieData>& movie)
{
	std::cout << "Title: " << movie->GetTitle() << std::endl;
	std::cout << "IMDB Id: " << movie->GetImdbId() << std::endl << std::endl;
	std::cout << "--------------- Plot --------------" << std::endl;
	std::cout << movie->GetPlot() << std::endl << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Length (min.) " << movie->GetLengthMin() << std::endl << std::endl;
}