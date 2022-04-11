#pragma once
#include "Book.h"
#include <string>
#include <iostream>
#include <vector>

Book::Book(std::string _bookName, std::string _bookAuthor, std::string _genre){
	bookName = _bookName;
	bookAuthor = _bookAuthor;
	genreName = _genre;
}



void Book::setBookName(std::string newBookName) {
	bookName = newBookName;
}

void Book::setAuthor(std::string newAuthor) {
	bookAuthor = newAuthor;
}





std::string const Book::getBookName() {
	return bookName;
}
std::string const Book::getAuthor() {
	return bookAuthor;
}

std::ostream& Book::operator<<(std::ostream& stream) {
	stream << bookName << " By: " << bookAuthor;
	return stream;
}



