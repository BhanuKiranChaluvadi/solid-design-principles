#pragma once

#include "MovieData.h"
#include <iostream>
#include <fstream>

class MovieSerializer
{
public:
    virtual ~MovieSerializer() = default;
    virtual void WriteMovieDetails(const MovieData &movie_data) = 0;
};

class ConsoleMovieSerializer : public MovieSerializer
{
public:
    void WriteMovieDetails(const MovieData &movie_data) override
    {
        std::cout << "Id: " << movie_data.GetImdbId() << std::endl;
        std::cout << "Title: " << movie_data.GetTitle() << std::endl;
        std::cout << "Length: " << movie_data.GetLengthMin() << std::endl
                  << std::endl;
    }
};

class FileMovieSerializer : public MovieSerializer
{
    std::string root_dir_;

public:
    FileMovieSerializer(std::string root_dir) : root_dir_(std::move(root_dir_)) {}

    void WriteMovieDetails(const MovieData &movie_data) override
    {
        std::ofstream output(root_dir_ + "movie_" + movie_data.GetImdbId() + ".txt");

        output << "Id: " << movie_data.GetImdbId() << std::endl;
        output << "Title: " << movie_data.GetTitle() << std::endl;
        output << "Length: " << movie_data.GetLengthMin() << std::endl
               << std::endl;
    }
};
