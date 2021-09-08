#include "MovieDbRepository.h"
#include "MovieManager.h"
#include "api_key.h"
#include "MovieApiAdapter.h"

using namespace std;

int main(int argc, char * argv[]) {

    TheMovieDbApi api(MY_API_KEY);
    MovieApiAdapter adapter(api);

    MovieDbRepository repository;

    // const MovieManager manager(adapter);
    const MovieManager manager(repository);

    manager.ShowMovieDetails("141052");

}