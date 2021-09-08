#include "MovieDbRepository.h"
#include "MovieManager.h"
#include "api_key.h"
#include "MovieApiAdapter.h"
#include "MovieApiAdapter2.h"
#include "FileBasedApi.h"
#include "MovieApiAdapter3.h"

using namespace std;

int main(int argc, char * argv[]) {

    MovieDbRepository repository;

    TheMovieDbApi api(MY_API_KEY);
    MovieApiAdapter adapter(api);

    MovieApiAdapter2 adapter2(MY_API_KEY);

    FileBasedApi fileApi("../Data/");
    MovieApiAdapter3 adapter3(fileApi);

    // const MovieManager manager(repository);
    // const MovieManager manager(adapter);
    // const MovieManager manager(adapter2);
    const MovieManager manager(adapter3);

    manager.ShowMovieDetails("141052");

}