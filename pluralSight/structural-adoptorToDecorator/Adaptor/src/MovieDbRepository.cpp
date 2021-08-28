#include "MovieDbRepository.h"

std::shared_ptr<MovieData> MovieDbRepository::GetById(const std::string& movie_id) {
    return std::make_shared<MovieData>(
        movie_id,
        "movie name",
        123,
        "Let me tell you what happened"
    );
}