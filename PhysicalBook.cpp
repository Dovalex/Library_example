#pragma once
#include "PhysicalBook.h"
#include "Genre.h"

#include <string>
#include <iostream>
#include <vector>

PhysicalBook::PhysicalBook(std::string _bookName, std::string _bookAuthor, std::string _genreName, int _bookId, int _bookCount, std::vector<std::shared_ptr<PhysicalBook>> &allBooks) : Book(_bookName, _bookAuthor, _genreName){

	bool goodIdInput = true;



	if (allBooks.size() == 0)
	{
		bookId = _bookId;
	}
	else
	{
		do
		{
			for (size_t i = 0; i < allBooks.size(); i++)
			{
				if (_bookId == allBooks[i]->bookId)
				{
					std::cout << "There is already a book with the same ID, please choos another ID!\n";
					std::cout << "New ID: ";
					goodIdInput = false;
					std::cin >> _bookId;
				}
				else
				{
					goodIdInput = true;
					bookId = _bookId;
				}

			}
		} while (goodIdInput == false);
	}



	bool goodCountInput = false;
	while (goodCountInput == false)
	{
		if (_bookCount >= 0)
		{
			bookCount = _bookCount;
			goodCountInput = true;
		}
		else
		{
			std::cout << "The number of books can't be negative or 0!\n please enter a new value: ";
			std::cin >> _bookCount;
		}
	}





}


void PhysicalBook::setBookId(int newId, std::vector <std::shared_ptr<PhysicalBook>> allBooks) {
	bool goodIdInput = true;

	do
	{
		for (size_t i = 0; i < allBooks.size(); i++)
		{
			if (newId == allBooks[i]->bookId)
			{
				goodIdInput = false;
				std::cin >> newId;

			}
			else
			{
				goodIdInput = false;
				bookId = newId;
			}

		}
	} while (goodIdInput == false);
}



void PhysicalBook::setBookCount(int newCount) {
	bool goodCountInput = false;
	while (goodCountInput == false)
	{
		if (newCount >= 0)
		{
			bookCount = newCount;
			goodCountInput = true;
		}
		else
		{
			std::cout << "The number of books can't be negative or 0!\n please enter a new value: ";
			std::cin >> newCount;
		}
	}

}

int const PhysicalBook::getBookId() {
	return bookId;
}
int const PhysicalBook::getBookCount() {
	return bookCount;
}

void PhysicalBook::bookAvailibility() {

	std::cout << "There are " << this->bookCount << " books available" << std::endl;
}