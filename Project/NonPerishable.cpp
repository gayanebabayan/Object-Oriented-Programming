#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include <iomanip>

// include header files
#include "NonPerishable.h"

using namespace std;

namespace ict {

   /************************************************************/
   // PROTECTED METHOD - ok
   // returns true if m_err clear and has no messages 
   /************************************************************/
   bool NonPerishable::ok() const {
      return m_err.isClear();
   }

   // PROTECTED method: sets error message to an argument "message"

   /************************************************************/
   // PROTECTED METHOD - SETTER - error 
   /************************************************************/
   void NonPerishable::error(const char * message) {
      m_err.message(message);
   }

   /************************************************************/
   // PROTECTED METHOD - signature - returns 'N'
   /************************************************************/
   char NonPerishable::signature() const {
      return 'N';
   }

   /************************************************************/
   // PROTECTED METHOD - save
   //                  writes the appropriate data into the file
   /************************************************************/
   std::fstream& NonPerishable::save(std::fstream& file) const {
      file << signature() << "," << sku() << ","
         << name() << "," << price() << ","
         << taxed() << "," << quantity();
      return file;
   }

   // LOAD method
   std::fstream & NonPerishable::load(std::fstream & file) {
      char t_sku[MAX_SKU_LEN + 1];
      char t_name[101];
      double t_price;
      bool t_taxed;
      int t_quantity;

      file.getline(t_sku, MAX_SKU_LEN + 1, ',');
      sku(t_sku);

      file.getline(t_name, 100, ',');
      name(t_name);

      file >> t_price;
      file.ignore();
      price(t_price);

      file >> t_taxed;
      file.ignore();
      taxed(t_taxed);

      file >> t_quantity;
      quantity(t_quantity);

      return file;
   }

   //WRITE method
   std::ostream & NonPerishable::write(std::ostream & os, bool linear) const {
      if (!ok()) {
         os << m_err;
      }
      else
      {
         if (linear)
         {
            os << std::setw(MAX_SKU_LEN) << left << sku() << "|"
               << std::setw(20) << left << name() << "|"
               << std::setw(7) << right << fixed << setprecision(2) << price() << "|";
            if (taxed())
               os << " T";
            else
               os << "  ";

            os << signature() << "|"
               << std::setw(4) << right << quantity() << "|"
               << std::setw(9) << right << fixed << cost() * quantity() << "|";
         }
         else
         {
            os << "Name:" << endl << name() << endl;
            os << "Sku: " << sku() << endl;
            os << "Price: " << fixed << price() << endl;
            os << "Price after tax: ";
            if (taxed())
               os << cost() << endl;
            else
               os << "N/A" << endl;
            os << "Quantity: " << quantity() << endl;
            os << "Total Cost: " << fixed << cost() * quantity() << endl;
         }
      }
      return os;
   }

   //READ method
   std::istream & NonPerishable::read(std::istream & is)
   {
      char t_sku[MAX_SKU_LEN + 1];
      char t_name[101];
      double t_price;
      char t_taxed;
      int t_quantity;

      if (!is.fail()) {
         cout << "Item Entry:" << endl;
         cout << "Sku: ";
         is.getline(t_sku, MAX_SKU_LEN, '\n');
         cout << "Name:" << endl;
         is.getline(t_name, 100, '\n');
         cout << "Price: ";
         is >> t_price;

         if (is.fail())
            m_err.message("Invalid Price Entry");
         else {
            cout << "Taxed: ";
            is >> t_taxed;

            if (t_taxed != 'N' && t_taxed != 'n' && t_taxed != 'Y' && t_taxed != 'y') {
               is.setstate(ios::failbit);
               m_err.message("Invalid Taxed Entry, (y)es or (n)o");
            }
            else {
               cout << "Quantity: ";
               is >> t_quantity;

               if (is.fail())
                  m_err.message("Invalid Quantity Entry");
               else
                  m_err.message(nullptr);

               if (!is.fail() && m_err.isClear())
               {
                  sku(t_sku);
                  name(t_name);
                  price(t_price);
                  taxed(t_taxed == 'y' || t_taxed == 'Y');
                  quantity(t_quantity);
               }
            }
         }
      }
      return is;
   }
}
