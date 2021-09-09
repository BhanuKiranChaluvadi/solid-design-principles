#pragma once

#include "MovieData.h"
#include <iostream>
class MovieSerializer
{
public:
    virtual ~MovieSerializer() = default;

    void WriteMovieDetails(const MovieData &movie_data)
    {
        std::cout << "Id: " << movie_data.GetImdbId() << std::endl;
        std::cout << "Title: " << movie_data.GetTitle() << std::endl;
        std::cout << "Length: " << movie_data.GetLengthMin() << std::endl;
    }
};
