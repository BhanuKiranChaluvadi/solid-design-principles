#pragma once

#include <memory>
#include "MovieData.h"

class MovieRepository {

public:
    virtual std::shared_ptr<MovieData> GetById(const std::string& movie_id) = 0;

};


class MovieDbRepository : public MovieRepository {

public:
    std::shared_ptr<MovieData> GetById(const std::string& movie_id) override;

};