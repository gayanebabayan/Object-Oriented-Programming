// OOP244_B: Final Project - Milestone4
// File:     Perishable.cpp
// Date:     31-March-2017
// Author:   Gayane Babayan
// ID:       107-061-160 
// email:    gbabayan@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include "Perishable.h"

using namespace std;

namespace ict {

   // DEAFAULT CONSTRUCTOR
   Perishable::Perishable() {
      m_expiry.dateOnly(true);
   }

   // PROTECTED method
   char ict::Perishable::signature() const {
      return 'P';
   }

   // SAVE method
   std::fstream & Perishable::save(std::fstream & file) const {
      NonPerishable::save(file) << "," << m_expiry;
      return file;
   }

   // LOAD method
   std::fstream & Perishable::load(std::fstream & file) {
      NonPerishable::load(file);
	  file.ignore();
      m_expiry.read(file);
      //file.ignore();
      return file;
   }

   // WRITE method
   std::ostream & Perishable::write(std::ostream & os, bool linear) const {
      NonPerishable::write(os, linear);
      if (ok() && !linear) {
         os << "Expiry date: " << m_expiry << endl;
      }
      return os;
   }

   //READ method
   std::istream & Perishable::read(std::istream & is) {
      cout << "Perishable ";
      NonPerishable::read(is);
      if (!is.fail())
      {
         cout << "Expiry date (YYYY/MM/DD): ";

		 m_expiry.read(is);
         if (m_expiry.bad())
         {
            if (m_expiry.errCode() == CIN_FAILED)
               error("Invalid Date Entry");
            if (m_expiry.errCode() == YEAR_ERROR)
               error("Invalid Year in Date Entry");
            if (m_expiry.errCode() == MON_ERROR)
               error("Invalid Month in Date Entry");
            if (m_expiry.errCode() == DAY_ERROR)
               error("Invalid Day in Date Entry");
            is.setstate(ios::failbit);
         }
      }
      return is;
   }
}
