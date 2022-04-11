#pragma once
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "Book.h"

class Library
{
public:
	std::string libraryName;
	std::string libraryAdress;


	std::vector<std::shared_ptr<Book>> listOfBooks;
	std::vector<std::shared_ptr<std::string>> listOfAuthors;
	std::vector<std::shared_ptr<std::string>> listOfGenres;
	std::vector<std::shared_ptr<int>> bookIds;
	std::vector<std::shared_ptr<int>> bookCount;

	Library(std::string  _libraryName, std::string _libraryAdress);


	std::shared_ptr<int> calculateID(std::shared_ptr<Book>book);
	void addBook(std::shared_ptr<Book>book, int count);
	void changeBookCount();
	void listAllBooks();
	void saveLibrary();
	void loadLibrary();


};

