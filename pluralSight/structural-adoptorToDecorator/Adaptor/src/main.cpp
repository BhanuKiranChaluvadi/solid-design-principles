#include "MovieDbRepository.h"
#include "MovieManager.h"

using namespace std;

int main(int argc, char * argv[]) {

    MovieDbRepository repository;
    const MovieManager manager(repository);

    manager.ShowMovieDetails("141052");

}