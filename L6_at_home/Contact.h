// OOP244_B: Workshop6-inLab
// File:     Contact.h
// Date:     27-Feb-2017
// Author:   Gayane Babayan
// ID:       107-061-160 
// email:    gbabayan@myseneca.ca


// TODO: add header guard
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

// TODO: add namespace here
namespace communication {

	class Contact
	{
	private:
		char m_name[21];
		long long* m_phoneNumbers;
		int m_noOfPhoneNumbers;
		void setEmpty();
		bool isPhoneValid(long long phoneNum, int power) const;
		void alloCopy(const char name[], long long* phoneNumbers, int noOfPhoneNumbers);
	public:
		// TODO: add the default constructor here
		Contact();

		// TODO: add the constructor with parameters here
		Contact(const char name[], long long* phoneNumbers, int noOfPhoneNumbers);     

		// TODO: add the destructor here
		~Contact();

		// add phone numbers
		void addPhoneNumber(long long phoneNumber);

		// TODO: add the display function here
		void display() const;

		// TODO: add the isEmpty function here
		bool isEmpty() const;

		Contact(const Contact& other);
		Contact& operator=(const Contact& other);
	};

}

#endif