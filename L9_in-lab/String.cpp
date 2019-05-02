// Name: Gayane Babayan
// Date: 27-March-2017
// File: String.cpp
// Workshop: 9-inLab
// ID:   107-061-160

#include <cstring>
#include <iostream>
#include "String.h"


using namespace std;

namespace sict {
	//////////////////////////////////////////////////////
	//
	// Default Constructor
	// String::String();
	//
	// initialize the string to ""
	//
	// 
	String::String() {
		// initialize the string to ""    
		setEmpty();
	}

	//////////////////////////////////////////////////////
	//
	// String::String(const char* p);
	//
	// Construct a String from a char array
	// You may assume the input string pSource 
	// has a length of < 50, and the internal buffer has enough
	// space to hold it.
	//
	// 
	String::String(const char* pSource) {
		string(pSource);
	}

	/***********************************/
	// SetEmpty method
	void String::setEmpty() {
		m_pString[0] = '\0';
	}

	/***********************************/
	// Setter
	void String::string(const char* string) {
		strcpy(m_pString, string);
	}

	/***********************************/
	// Getter
	const char* String::string() const {
		return m_pString;
	}

	//////////////////////////////////////////////////////
	//
	// String::String(const String &s, int capacity);
	//
	// Copy constructor
	//
	// Construct a String from another String
	//
	// 
	String::String(const String& other)
	{
		string(other.m_pString); 
	}

	//////////////////////////////////////////////////////
	//
	// String::operator=(const String& other)
	// 
	// Assignment operator
	// copy string "other" to this object
	//   
	//     
	String& String::operator=(const String& other)
	{
		if (this != &other) {
			string(other.m_pString);
		}
		return *this;
	}

	//////////////////////////////////////////////////////
	//
	// String::~String
	// 
	// destructor
	// 
	// clean up the internal string buffer  
	// 
	String::~String()
	{
		setEmpty();
	}

	//////////////////////////////////////////////////////
	//
	// String::length()
	// 
	// return the length of the string
	// 
	// 
	int String::length() const
	{
		return strlen(string());
	}

	//////////////////////////////////////////////////////
	//
	// String::operator const char*() const
	// 
	// convert the String to a char*
	// 
	// 
	String::operator const char *() const
	{
		return string();
	}

	//////////////////////////////////////////////////////
	//
	// String::empty()
	// 
	// 
	// returns true if the string is empty
	// i.e. either the first char is \0, or 
	// length is 0.
	bool String::empty() const
	{
		return (m_pString[0] == '\0');
	}

	//////////////////////////////////////////////////////
	//
	// String::operator bool()
	// 
	// same as empty(), just wrapped in an operator
	// 
	//         
	String::operator bool() const
	{
		return (m_pString[0] != '\0');
	}

	//////////////////////////////////////////////////////
	//
	// String::operator==(const String& s2) const
	// 
	// returns true if *this == s2.
	// You can use the strcmp function to check if 
	// two strings are equal, or write your own
	// treating the string as a char-array
	//           
	bool String::operator==(const String& s2) const
	{
		return (strcmp(string(), s2.string()) == 0);
	}

	//////////////////////////////////////////////////////
	//
	// String::operator+=(const String& s2)
	// 
	// Concatenates s2 to the end of *this
	//
	// implements *this = (*this + s2)
	// return *this
	// 
	//         
	String& String::operator+=(const String& s2)
	{
		strcat(this->m_pString, s2.m_pString);
		return *this;
	}

	//////////////////////////////////////////////////////
	//
	// String::operator+(const String& s2) const
	// 
	// implements the operator (*this + s2)
	// returns the expression
	// DOES NOT MODIFY *this
	// 
	//     
	String String::operator+(const String& s2) const
	{
		String temp;
		strcpy(temp.m_pString, string());
		strcat(temp.m_pString, s2.string());
		return temp;
	}

	//////////////////////////////////////////////////////
	//
	// String::operator+=(char c)
	// 
	// Adds a single char c to the end of the string in *this
	// 
	//        
	String& String::operator+= (char c)
	{
		int size = strlen(string());
		if (size < STRING_BUFFERSIZE) {
			m_pString[size] = c;
			m_pString[size + 1] = '\0';
		}
		return *this;
	}

	//////////////////////////////////////////////////////
	//
	// operator<<
	// 
	// Print the string to the output stream
	// 
	// clean up the internal string buffer  
	//     
	std::ostream& operator<<(std::ostream& ostream, const String &s)
	{
		return ostream << s.string();
	}

	//////////////////////////////////////////////////////
	//
	// operator>>
	// 
	// Input a string from an input stream into the String s
	// 
	// Note: the input can be ANY length in character. You will need to 
	// read it one char at a time. 
	// 
	std::istream& operator >> (std::istream& istream, String &s)
	{
		s = "";
		char tempC = 0;
		do
		{
			tempC = istream.get();
			if (tempC != '\n')
			{
				s += tempC;
			}
			else
				break;
		} while (1);
		return istream;
	}
}
