#pragma once
#include "Book.h"
#include <string>
#include <iostream>

class DigitalBook : public Book
{
private:
	std::string domainName;
		

public:
	DigitalBook(std::string _bookName, std::string _bookAuthor, std::string _genreName);

	void setDomainName(std::string _domainName);

	std::string getDomainName();

	void bookAvailibility();



};

