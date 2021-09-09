#pragma once

#include "MovieData.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "Encoder.h"

class MovieSerializer
{
    Encoder &encoder_;

protected:
    virtual void saveDetails(const MovieData &movie_data, const std::string data) = 0;

public:
    MovieSerializer(Encoder &encoder) : encoder_(encoder) {}
    virtual ~MovieSerializer() = default;
    virtual void WriteMovieDetails(const MovieData &movie_data)
    {
        const auto encoded_string = encoder_.encode(movie_data);
        saveDetails(movie_data, encoded_string);
    }
};

class ConsoleMovieSerializer : public MovieSerializer
{

protected:
    void saveDetails(const MovieData &movie_data, const std::string data) override
    {
        std::cout << data;
    }

public:
    ConsoleMovieSerializer(Encoder &encoder) : MovieSerializer(encoder) {}
};

class FileMovieSerializer : public MovieSerializer
{
    std::string root_dir_;

protected:
    void saveDetails(const MovieData &movie_data, const std::string data) override
    {
        std::ofstream output(root_dir_ + "movie_" + movie_data.GetImdbId() + ".txt");
        output << data;
    }

public:
    FileMovieSerializer(Encoder &encoder, std::string root_dir) : MovieSerializer(encoder), root_dir_(std::move(root_dir_)) {}
};
