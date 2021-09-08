#include <cstring>

#include <rapidjson/document.h>
#include "MovieApiAdapter.h"

#include <memory>

#include "ErrorParsingMovieDataException.h"

std::shared_ptr<MovieData> MovieApiAdapter::GetById(const std::string& movie_id)
{
	const auto json = api_.GetMovieDetails(movie_id);

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
