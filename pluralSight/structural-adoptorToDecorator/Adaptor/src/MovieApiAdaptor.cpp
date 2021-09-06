#include "MovieApiAdaptor.h"

#include <memory> 
#include <string>
#include "rapidjson/document.h"

#include "ErrorParsingMovieDataException.h"

std::shared_ptr<MovieData> MovieApiAdaptor::GetById(const std::string& movie_id)
{
    const auto json = api_.GetMovieDetails(movie_id);   

    rapidjson::Document jsonDocument;
    jsonDocument.Parse(json.c_str());
    if(!jsonDocument.IsObject()) 
    {
        throw ErrorParsingMovieDataException();
    }

    auto imdb_id = jsonDocument["imdb_id"].GetString();
    auto title = jsonDocument["title"].GetString();
    auto plot = jsonDocument["overview"].GetString();
    auto length_min = jsonDocument["runtime"].GetString();

    auto result = std::make_shared<MovieData>(imdb_id, title, plot, length_min);

    return result;
}