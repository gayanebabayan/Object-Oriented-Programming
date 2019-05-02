// OOP244_B: Workshop6-inLab
// File:     w6_at_home.cpp
// Date:     27-Feb-2017
// Author:   Gayane Babayan
// ID:       107-061-160 
// email:    gbabayan@myseneca.ca


#include <iostream>
#include "Contact.h"

using namespace std;
using namespace communication;

int main() {
   communication::Contact theContact("John Doe", nullptr, 0);
   theContact.addPhoneNumber(14161234567);
   theContact.addPhoneNumber(14162345678);
   theContact.addPhoneNumber(14163456789);
   theContact.addPhoneNumber(114164567890);
   theContact.display();

   cout << endl << "Testing! Please wait:" << endl;

   for (int i = 1; i <= 5000000; i++)
   {
      Contact temp = theContact;
      theContact = temp;
      theContact = theContact;
      if (!(i % 10000))
         cout << ".";
      if (!(i % 500000))
         cout << endl;
   }
   cout << endl;
   theContact.display();
   return 0;
}