#pragma once
#include "Book.h"
#include "Library.h"

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

int homePage() {
    int option;
    std::cout << "Please choose what to do:\n"
        << "1. add a new book\n"
        << "2. get a list of books\n"
        << "3. change book count\n"
        << "4. save the library\n"
        << "0. exit the program\n"
        << "Option: ";
    validateInput(option);

    while (option > 4 || option < 0)
    {
        std::cout << "Invalid input!" << std::endl;
        validateInput(option);
    }

    return option;
}


std::shared_ptr<Book> newBook() {
    std::string bookName;
    std::string authorName;
    std::string GenreName;
    
    std::cout << "Please enter the name of the book: ";
    validateInput(bookName);
    std::cout << "Please enter the name of the author: ";
    validateInput(authorName);
    std::cout << "Please enter the name of the genre: ";
    validateInput(GenreName);
    std::cout << std::endl;


    std::shared_ptr<Book> book = std::make_shared<Book>(bookName, authorName, GenreName);
    return book;
}




int main()
{
    Library library("Library Name", "Library adress");
    library.loadLibrary();
    int homePageNum = 0;
    int bookCount = 0;

    do
    {
        homePageNum = homePage();
        if (homePageNum == 1)
        {
            std::cout << "Please enter how many books you wish to add: ";
            do
            {
                validateInput(bookCount);
            } while (bookCount <= 0);
            library.addBook(newBook(), bookCount);
        }


        if (homePageNum == 2)
        {
            library.listAllBooks();
        }


        if (homePageNum == 3)
        {
            int choice = 0;    
            int count = 0;

            library.listAllBooks();
            do
            {
                std::cout << "Choice: ";
                validateInput(choice);
            } while (choice > library.listOfBooks.size() && choice < 0);


            do
            {
                std::cout << "Enter how many books are available: ";
                validateInput(count);
            } while (count <= 0);

            library.changeBookCount(choice, count);
        }


        if (homePageNum == 4)
        {
            library.saveLibrary();
        }
    } while (homePageNum != 0);
    

    return 0;
}


