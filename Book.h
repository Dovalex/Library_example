#pragma once
#include <string>
#include <iostream>
#include <vector>



class Book
{

public:

	std::string bookName;
	std::string bookAuthor;
	std::string genreName;

	Book(std::string bookName, std::string bookAuthor, std::string genreName);

	void setBookName(std::string newBookName);
	void setAuthor(std::string newAuthor);


	std::string const getBookName();
	std::string const getAuthor();

	std::ostream& operator<<(std::ostream& stream);

};

