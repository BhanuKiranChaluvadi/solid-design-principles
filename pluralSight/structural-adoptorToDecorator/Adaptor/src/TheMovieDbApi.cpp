#include "TheMovieDbApi.h"
#include "restclient-cpp/restclient.h"

using namespace std;

#include "HttpException.h"

std::string TheMovieDbApi::GetMovieDetails(const std::string& movie_id) const
{
	const string get_movie_details_url = "http://api.themoviedb.org/3/movie/" + movie_id + "?api_key=" + m_api_key_;
    
	const auto response = RestClient::get(get_movie_details_url);

	if (response.code != 200) {
		throw HttpException(response.code);
	}

	return response.body;
}	