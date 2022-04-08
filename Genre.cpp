#pragma once
#include "Genre.h"
#include <string>
#include <iostream>
int Genre::numOfGenres = 0;

Genre::Genre(std::string _genreName) {
	genreName = _genreName;

	++numOfGenres;
}




Genre::~Genre() {
	--numOfGenres;
}



