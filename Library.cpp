#include "Library.h"
#include "Book.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

Book testBook("Test1", "Test2", "Test3");
std::shared_ptr <Book> pTestBook = std::make_shared<Book>(testBook);
Library::Library(std::string  _libraryName, std::string  _libraryAdress) {
	libraryName = _libraryName;
	libraryAdress = _libraryAdress;
}

template<typename T>
T& validateInput(T& val)
{
	while (true) {
		if (std::cin >> val) {
			break;
		}
		else {
			std::cout << "Enter a valid value!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return val;
}

std::shared_ptr<int> Library::calculateID(std::shared_ptr<Book> book) {
	int id = 0;
	for (int i = 0; i < listOfAuthors.size(); i++)
	{
		if (listOfAuthors[i]->compare(book->bookAuthor) == 0)
		{
			id = i * 11;
		}
	}
	for (int i = 0; i < listOfGenres.size(); i++)
	{
		if (listOfGenres[i]->compare(book->genreName) == 0)
		{
			id += i * 7;
		}
	}
	id += (int)listOfBooks.size() * 3;
	std::shared_ptr <int> pId (new int (id));
	return pId;
}

std::shared_ptr<int> addBookCount(int &count) {
	if (count <= 0)
	{
		validateInput(count);
	}
	else
	{
		std::shared_ptr <int> pCount(new int(count));
		return pCount;
	}

}

void newAuthor(std::shared_ptr<Book> book, std::vector<std::shared_ptr<std::string>> listofauthors) {
	bool sameAuthor = false;
	for (int i = 0; i < listofauthors.size(); i++)
	{
		if (book->bookAuthor == *listofauthors[i])
		{
			sameAuthor = true;
		}
	}
	if (!sameAuthor)
	{
		listofauthors.push_back(std::make_shared<std::string>(book->bookAuthor));
	}

}

void newGenre(std::shared_ptr<Book> book, std::vector<std::shared_ptr<std::string>> listofgenres) {
	bool sameGenre = false;
	for (int i = 0; i < listofgenres.size(); i++)
	{
		if (book->genreName == *listofgenres[i])
		{
			sameGenre = true;
		}
	}
	if (!sameGenre)
	{
		listofgenres.push_back(std::make_shared<std::string>(book->genreName));
	}

}

void Library::addBook(std::shared_ptr<Book> book, int count) {
	listOfBooks.push_back(std::make_shared <Book> (*book));
	newAuthor(book, listOfAuthors);
	newGenre(book, listOfGenres);
	bookIds.push_back(calculateID(book));
	bookCount.push_back(addBookCount(count));
}


void Library::changeBookCount() {
	int choice;
	int count;
	std::cout << "Which book do you want to change the number of available books for?" << std::endl;

	for (int i = 0; i < listOfBooks.size(); i++)
	{
		std::cout << i + 1 << ". " << listOfBooks[i]->bookAuthor << " "
			<< listOfBooks[i]->bookName << " "
			<< listOfBooks[i]->genreName << " "
			<< std::endl;
	}

	do
	{
		std::cout << "Choice: ";
		validateInput(choice);
	} while (choice > listOfBooks.size() && choice < 0);


	do
	{
		std::cout << "Enter how much books are available: ";
		validateInput(count);
	} while (count <= 0);
	*bookCount[choice] = count;

}

void Library::listAllBooks() {
	for (int i = 0; i < listOfBooks.size(); i++)
	{
		std::cout << listOfBooks[i]->bookAuthor << " "
			<< listOfBooks[i]->bookName << " "
			<< listOfBooks[i]->genreName << " "
			<< std::endl;
	}
}




void Library::saveLibrary() {
	std::fstream fout;
	fout.open("library.csv", std::ios::out);
	

	//assumes the same library is always loaded
	//too many problems with IDs and saving without a proper database
	for (int i = 0; i < listOfBooks.size(); i++)
	{
		fout << listOfBooks[i]->bookAuthor << ","
			<< listOfBooks[i]->bookName << ","
			<< listOfBooks[i]->genreName << ","
			<< *bookCount[i] << "\n";
	}

	fout.close();
}


void Library::loadLibrary() {
	std::fstream fin;
	fin.open("library.csv", std::ios::in);

	std::string line, colname, word;
	std::vector<std::string> row;
	row.reserve(4);
	int bookCount = 0;
	while (std::getline(fin, line))
	{

		row.clear();
		std::stringstream s(line);
		while (getline(s, word, ',')) {
			row.emplace_back(word);
		}
		std::shared_ptr<Book> book = std::make_shared<Book>(row[0], row[1], row[2]);
		bookCount = std::stoi(row[3]);


		addBook(book, bookCount);
	}

	fin.close();
}


