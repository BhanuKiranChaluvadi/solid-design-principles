#include <cstring>

#include <rapidjson/document.h>
#include "MovieApiAdapter2.h"

#include <memory>
#include "api_key.h"
#include "ErrorParsingMovieDataException.h"

std::shared_ptr<MovieData> MovieApiAdapter2::GetById(const std::string& movie_id)
{
	const auto json = GetMovieDetails(movie_id);

	rapidjson::Document jsonDocument;
	jsonDocument.Parse(json.c_str());
	if (!jsonDocument.IsObject())
	{
		throw ErrorParsingMovieDataException();
	}

	auto imdb_id = jsonDocument["imdb_id"].GetString();
	auto title = jsonDocument["title"].GetString();
	auto plot = jsonDocument["overview"].GetString();
	auto length_min = jsonDocument["runtime"].GetUint();

	auto result = std::make_shared<MovieData>(imdb_id, title, length_min, plot);

	return result;
}
