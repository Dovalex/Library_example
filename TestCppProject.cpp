#pragma once
#include "Book.h"
#include "Genre.h"
#include "PhysicalBook.h"
#include "DigitalBook.h"

#include <limits>
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>


/*
void* operator new(size_t size) {
	std::cout << "on heap" << std::endl;
    return malloc(size);
}
*/

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




int HomePage() {
    int choice;

    std::cout << "Choose an option:\n";
    std::cout << "1. New book\n";
    std::cout << "2. List of genres\n";
    std::cout << "3. List of books\n";
    std::cout << "0. End\n";


    std::cout << "Please enter your choice: ";
 
    std::cin >> choice;
    while (choice > 3 || choice < 0) {
        std::cout << "Please enter a valid choice!\n";
        std::cin >> choice;
    }


    return choice;
}

int BookCreation() {
    int choice;


    std::cout << "Do you want to add a:\n1.Physical book\n2.Digital book\n";
    std::cout << "Please enter your choice: ";

    std::cin >> choice;
    while (choice != 1 && choice != 2) {
        std::cout << "\nPlease enter a valid choice!\n";
        std::cin >> choice;
    }

    return choice;
}


void listOfGenres(std::vector <std::shared_ptr<Genre>>& genres) {
    if (genres.size() != 0)
    {
        for (size_t i = 0; i < genres.size(); i++)
        {
            std::cout << i + 1 << ". " << genres[i]->genreName << "\n";
        }
    }
    else
    {
        std::cout << "There are no books in the library" << std::endl;
    }

}

void listOfBooks(std::vector <std::shared_ptr<Book>>& books) {
    if (books.size() != 0)
    {
        for (size_t i = 0; i < books.size(); i++)
        {
            std::cout << i + 1 << ". " << books[i]->getBookName() << "\n";
        }
    }
    else
    {
        std::cout << "There are no books in the library" << std::endl;
    }
}

std::shared_ptr<Genre> createNewGenre() {
    std::string genreName;
    std::cout << "Please enter genre name: ";
    std::cin >> genreName;
    std::shared_ptr<Genre> genre (new Genre(genreName));
    return genre;
}

std::string genreChoice(std::vector <std::shared_ptr<Genre>>& genres) {
    std::string genre;
    int choice;

    std::cout << "Please choose a genre\n";
    std::cout << "0: new genre\n";

    for (size_t i = 0; i < genres.size(); i++)
    {
        std::cout << i + 1 << ": " << genres[i]->genreName << "\n";
    }
    std::cout << "Genre coice: ";
    do
    {
        choice = validateInput(choice);
    } while ((size_t)choice > genres.size() || choice < 0);

    if (choice == 0)
    {
        std::shared_ptr<Genre> newGenre = createNewGenre();
        genres.push_back(newGenre);
        genre = newGenre->genreName;
    }
    else
    {
        genre = genres[choice - 1]->genreName;
    }

    return genre;
}

void physicalBookCreation(std::vector <std::shared_ptr<PhysicalBook>> &phyisicalBooks, std::vector <std::shared_ptr<Genre>>& genres, std::vector <std::shared_ptr<Book>>& books) {
    std::string bookName, authorName, genre;
    int bookId, bookCount;


    std::cout << "Please enter the name of the book: ";
    std::cin >> bookName;
    std::cout << "Please enter the name of the author: ";
    std::cin >> authorName;

    genre = genreChoice(genres);

    std::cout << "Please enter book ID: ";
    bookId = validateInput(bookId);
    std::cout << "Please enter book count: ";
    bookCount = validateInput(bookCount);

    std::shared_ptr<PhysicalBook> newPhysBook (new PhysicalBook(bookName, authorName, genre, bookId, bookCount, phyisicalBooks));
    phyisicalBooks.push_back(newPhysBook);
    books.push_back(newPhysBook);
}

void digitalBookCreation(std::vector <std::shared_ptr<DigitalBook>> &digitalBooks, std::vector <std::shared_ptr<Genre>>& genres, std::vector <std::shared_ptr<Book>> &books) {
    std::string bookName, authorName, genre;

    std::cout << "Please enter the name of the book: ";
    std::cin >> bookName;
    std::cout << "Please enter the name of the author: ";
    std::cin >> authorName;
    genre = genreChoice(genres);

    std::shared_ptr<DigitalBook> newDigBook(new DigitalBook(bookName, authorName, genre));
    digitalBooks.push_back(newDigBook);
    books.push_back(newDigBook);
}



int main()
{
	std::vector <std::shared_ptr<PhysicalBook>> phyisicalBooks;
	std::vector <std::shared_ptr<DigitalBook>> digitalBooks;
    std::vector <std::shared_ptr<Book>> books;
    std::vector <std::shared_ptr<Genre>> genres;




    int homePageChoice;
    int bookCreationChoice;
	do
	{
        homePageChoice = HomePage();
        if (homePageChoice == 1)
        {
            bookCreationChoice = BookCreation();
            if (bookCreationChoice == 1)
            {
                physicalBookCreation(phyisicalBooks, genres, books);
            }
            else //BookCreation() == 2, since there is validation (bug prone)
            {
                digitalBookCreation(digitalBooks, genres, books);
            }
        }
        else if (homePageChoice == 2)
        {
            listOfGenres(genres);
        }
        else if (homePageChoice == 3)
        {
            listOfBooks(books);
        }
        
	} while (homePageChoice != 0);


    return 0;
}


