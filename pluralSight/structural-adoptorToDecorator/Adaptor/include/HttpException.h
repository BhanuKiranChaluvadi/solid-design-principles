#pragma once

#include <exception>

class HttpException : public std::exception {
	const int code_;

public:
	explicit HttpException(const int code) : code_(code) {}
	int GetCode()const { return code_; }
};