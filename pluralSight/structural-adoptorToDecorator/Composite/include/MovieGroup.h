#include <string>
#include <list>

#include "MovieData.h"

class MovieGroup
{
    std::string title_;
    std::list<MovieGroup *> sub_groups_;
    std::list<MovieData *> movies_;

public:
    MovieGroup(std::string title) : title_(std::move(title)) {}

    void addSubGroup(MovieGroup &group)
    {
        sub_groups_.push_back(&group);
    }

    void removeSubGroup(MovieGroup &group)
    {
        sub_groups_.remove(&group);
    }

    std::list<MovieGroup *> getSubGroups() const
    {
        return sub_groups_;
    }

    void addMovie(MovieData &movie)
    {
        movies_.push_back(&movie);
    }

    void removeMovie(MovieData &movie)
    {
        movies_.remove(&movie);
    }

    std::list<MovieData *> getMovies() const
    {
        return movies_;
    }
};