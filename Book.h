#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Genre.h"



class Book
{

protected:
	std::string bookName;
	std::string bookAuthor;
	std::string genreName;
public:



	Book(std::string bookName, std::string bookAuthor, std::string genreName);

	void setBookName(std::string newBookName);
	void setAuthor(std::string newAuthor);


	std::string const getBookName();
	std::string const getAuthor();


	virtual void bookAvailibility() = 0;



	~Book();

};

