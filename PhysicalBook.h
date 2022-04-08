#pragma once
#include "Book.h"
#include <string>
#include <iostream>
#include <vector>

class PhysicalBook : public Book
{
private:
	int bookId = 0;
	int bookCount = 0;



public:

	PhysicalBook(std::string _bookName, std::string _bookAuthor, std::string _genreName, int _bookId, int _bookCount, std::vector <std::shared_ptr<PhysicalBook>> &allBooks);


	void setBookId(int newBookId, std::vector <std::shared_ptr<PhysicalBook>> allBooks);
	void setBookCount(int newBookCount);


	int const getBookId();
	int const getBookCount();

	void bookAvailibility();


};

