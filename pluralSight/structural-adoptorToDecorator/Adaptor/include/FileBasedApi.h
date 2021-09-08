#pragma once

#include <fstream>
#include <utility>
#include "TheMovieDbApi.h"

class FileBasedApi : public MovieApi
{
    std::string root_dir_;

public:
    explicit FileBasedApi(std::string root_dir) : root_dir_(std::move(root_dir)) {}

    std::string GetMovieDetails(const std::string &movie_id) const override
    {
        std::ifstream input(root_dir_ + movie_id + ".json");

        std::string content((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));

        input.close();

        return content;
    }
};