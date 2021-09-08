#include "MovieDbRepository.h"
#include "MovieManager.h"
#include "api_key.h"
#include "MovieApiAdapter.h"
#include "MovieApiAdapter2.h"

using namespace std;

int main(int argc, char * argv[]) {

    TheMovieDbApi api(MY_API_KEY);
    MovieApiAdapter adapter(api);

    MovieApiAdapter2 adapter2(MY_API_KEY);

    MovieDbRepository repository;

    // const MovieManager manager(adapter);
    const MovieManager manager(adapter2);
    // const MovieManager manager(repository);

    manager.ShowMovieDetails("141052");

}