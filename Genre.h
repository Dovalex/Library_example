#pragma once
#include <string>
#include <iostream>
#include <vector>

class Genre
{
public:

	std::string genreName;
	static int numOfGenres;

	Genre(std::string _genreName);




	~Genre();
};

