#pragma once

#include <utility>
#include <string>

class MovieData
{
	std::string id_;
	std::string title_;
	unsigned length_;
	std::string plot_;

public:
	MovieData(std::string id, std::string title, unsigned length)
		: id_(std::move(id)),
		  title_(std::move(title)),
		  length_(length)
	{
	}
	std::string GetImdbId() const { return id_; }
	std::string GetTitle() const { return title_; }
	unsigned GetLengthMin() const { return length_; }
};