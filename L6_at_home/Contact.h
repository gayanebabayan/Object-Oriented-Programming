#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

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
		Contact();
		Contact(const char name[], long long* phoneNumbers, int noOfPhoneNumbers);     
		~Contact();
		void addPhoneNumber(long long phoneNumber);
		void display() const;
		bool isEmpty() const;
		Contact(const Contact& other);
		Contact& operator=(const Contact& other);
	};
}
#endif
