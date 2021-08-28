#pragma once

#include <string>
#include <utility>

class MovieApi {

public:
    virtual ~MovieApi() = default;
    virtual std::string GetMovieDetails(const std::string& movie_id) const = 0;
};

class TheMovieDbApi : public MovieApi   {
    const std::string m_api_key;

public:
    TheMovieDbApi(std::string api_key) : m_api_key(std::move(api_key)) {}


    std::string GetMovieDetails(const std::string& movie_id) const override;
};