#pragma once

#include "Book.h"
#include "DigitalBook.h"
#include <string>
#include <iostream>

DigitalBook::DigitalBook(std::string _bookName, std::string _bookAuthor, std::string _genreName) : Book(_bookName, _bookAuthor, _genreName) {
	domainName = "www.somelibrary.xyz/" + _bookName;
}

void DigitalBook::setDomainName(std::string _domainName) {
	domainName = _domainName;
}

std::string DigitalBook::getDomainName() {
	return domainName;
}

void DigitalBook::bookAvailibility() {
	std::cout << "The book is available online at " << this->domainName << std::endl;
}