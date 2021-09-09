#include "MovieData.h"
#include "MovieSerializer.h"

int main()
{

    MovieData movie1("1", "Summer blockbuster", 90);
    MovieData movie2("2", "Generic romantic comedy", 72);
    MovieData movie3("3", "See paint dry", 1440);
    MovieData movie4("4", "Periodic drama", 180);

    // MovieSerializer *serializer = new ConsoleMovieSerializer();
    // MovieSerializer *serializer = new FileMovieSerializer("./");
    MovieSerializer *serializer = new JsonConsoleMovieSerializer();

    serializer->WriteMovieDetails(movie1);
    serializer->WriteMovieDetails(movie2);
    serializer->WriteMovieDetails(movie3);
    serializer->WriteMovieDetails(movie4);

    delete serializer;
}
