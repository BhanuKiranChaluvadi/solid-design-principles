#pragma once

#include "MovieData.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

class MovieSerializer
{
public:
    virtual ~MovieSerializer() = default;
    virtual void WriteMovieDetails(const MovieData &movie_data) = 0;
};

class ConsoleMovieSerializer : public MovieSerializer
{
protected:
    virtual std::string GetMovieDataAsText(const MovieData &movie_data)
    {
        std::stringstream sstream;
        sstream << "Id: " << movie_data.GetImdbId() << std::endl;
        sstream << "Title: " << movie_data.GetTitle() << std::endl;
        sstream << "Length: " << movie_data.GetLengthMin() << std::endl
                << std::endl;
        return sstream.str();
    }

public:
    void WriteMovieDetails(const MovieData &movie_data) override
    {
        std::cout << GetMovieDataAsText(movie_data);
    }
};

class JsonConsoleMovieSerializer : public ConsoleMovieSerializer
{
protected:
    virtual std::string GetMovieDataAsText(const MovieData &movie_data)
    {
        rapidjson::StringBuffer string_buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(string_buffer);
        writer.StartObject();
        writer.Key("Id");
        writer.String(movie_data.GetImdbId().c_str());

        writer.Key("Title");
        writer.String(movie_data.GetTitle().c_str());

        writer.Key("Length");
        writer.Uint(movie_data.GetLengthMin());

        writer.EndObject();

        return string_buffer.GetString();
    }

public:
    void WriteMovieDetails(const MovieData &movie_data) override
    {
        std::cout << GetMovieDataAsText(movie_data);
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
