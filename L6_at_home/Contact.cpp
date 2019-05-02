#include <iostream>
#include <cstring>
#include <cmath>
#include "Contact.h"

using namespace std;

namespace communication {

   // sets into safe empty state 
	void Contact::setEmpty() {
		m_name[0] = '\0';
		m_phoneNumbers = nullptr;
		m_noOfPhoneNumbers = -1;
	}

   // checks if the instance is in the safe empty state
	bool Contact::isEmpty() const {
		return (m_noOfPhoneNumbers == -1);
	}

   // default constructor
	Contact::Contact() {
		setEmpty();
	}

	// ALLOCOPY member function which checks numbers and allocates the memory for the array
	void Contact::alloCopy(const char name[], long long* phoneNumbers, int noOfPhoneNumbers) {

		if ((name != nullptr) && (name[0] != '\0'))
		{
			strncpy(m_name, name, 20);
			m_name[20] = '\0';

			//count valid numbers
			int i;
			int count = 0;

			for (i = 0; i < noOfPhoneNumbers; i++) {
				// check if the number has 11 or 12 digits
				if (phoneNumbers[i] < 1000000000000 && phoneNumbers[i]>9999999999) {
					// checks if the area code and the number don't start with 0
					if (isPhoneValid(phoneNumbers[i], 6) && isPhoneValid(phoneNumbers[i], 9))
						count++;
				}
			}

			// allocate exactly amount of memory for the valid phoneNumbers
			m_noOfPhoneNumbers = count;
			m_phoneNumbers = new long long[m_noOfPhoneNumbers];

			//copy valid phoneNumbers
			int j = 0;
			for (i = 0; i < noOfPhoneNumbers; i++) {
				if (phoneNumbers[i] < 1000000000000 && phoneNumbers[i]>9999999999) {
					if (isPhoneValid(phoneNumbers[i], 6) && isPhoneValid(phoneNumbers[i], 9)) {
						m_phoneNumbers[j] = phoneNumbers[i];
						j++;
					}
				}
			}
		}
		else
			setEmpty();
	}
	
   // Constructor with 3 parameters
	Contact::Contact(const char name[], long long* phoneNumbers, int noOfPhoneNumbers) {
		alloCopy(name, phoneNumbers, noOfPhoneNumbers);
	}

	// Copy constructor
	Contact::Contact(const Contact& C) {
		alloCopy(C.m_name, C.m_phoneNumbers, C.m_noOfPhoneNumbers);
	}	
	
	// Assignment operator
	Contact& Contact::operator=(const Contact& C) {  
		
		if (this != &C) {
			delete[] m_phoneNumbers;
			alloCopy(C.m_name, C.m_phoneNumbers, C.m_noOfPhoneNumbers);
		}
		return *this;
	}

	// Add phone Number and resize the array
	void Contact::addPhoneNumber(long long phoneNumber) {
	
		// check if the number has 11 or 12 digits
		if (phoneNumber < 1000000000000 && phoneNumber > 9999999999) {
			// check if the area code and the number don't start with 0
			if (isPhoneValid(phoneNumber, 6) && isPhoneValid(phoneNumber, 9)) {
				// create a temp array
				long long *temp;
				temp = new long long[m_noOfPhoneNumbers];

					// copy the current array into the temp array
					for (int i = 0; i < m_noOfPhoneNumbers; i++) {
						temp[i] = m_phoneNumbers[i];
					}

					// delete the current array
					delete[] m_phoneNumbers;

					// resize the current array
					m_phoneNumbers = new long long[m_noOfPhoneNumbers + 1];

					// copy back from temp to the current array
					for (int i = 0; i < m_noOfPhoneNumbers; i++) {
						m_phoneNumbers[i] = temp[i];
					}
				
				// add the new number to the current array
				m_phoneNumbers[m_noOfPhoneNumbers] = phoneNumber;
				
				// fix/update the size of the current array 
				m_noOfPhoneNumbers++;
			}
		}
	}

   // check if the area code or phone number starts with 0 or not
   bool Contact::isPhoneValid(long long phoneNum, int power) const {
      long long a = phoneNum / pow(10, power);
      a = a % 10;
      return (a != 0);
   }

   // display contact name and the phone numbers
	void Contact::display() const {
		if (isEmpty())
			cout << "Empty contact!" << endl;
		else
		{
         int i;
         cout << m_name << endl;

			for (i = 0; i < m_noOfPhoneNumbers; i++) {
				cout << "(+" << (int)(m_phoneNumbers[i] / pow(10, 10)) << ") " 
                 << (int)((m_phoneNumbers[i] % 10000000000) / pow(10, 7)) << " "
                 << (int)((m_phoneNumbers[i] % 10000000) / pow(10, 4)) << "-"
                 << m_phoneNumbers[i] % 10000 << endl;
			}
		}
	}

   // destructor
	Contact::~Contact() {
      delete[] m_phoneNumbers;
	}
}
