// OOP244_B: Final Project - Milestone3
// File:     Item.cpp
// Date:     31-March-2017
// Author:   Gayane Babayan
// ID:       107-061-160 
// email:    gbabayan@myseneca.ca


#define _CRT_SECURE_NO_WARNINGS  
// Lib includes
#include <iostream>
#include <cstring>

// inlcude Item and POS header files
#include "Item.h"
#include "POS.h"

using namespace std;
namespace ict {

   /************************************************************/
   // DEFAULT CONSTRUCTOR
   /************************************************************/
   Item::Item() {
      setEmpty();
   }

   /************************************************************/
   // 4 ARGUMENT CONSTRUCTOR
   /************************************************************/
   Item::Item(const char* sku, const char* name, double price, bool taxed) {
      int quantity = 0;
      alloCopy(sku, name, price, quantity, taxed);
   }

   /************************************************************/
   // COPY CONSTRUCTOR
   /************************************************************/
   Item::Item(const Item& I) {
      alloCopy(I.m_sku, I.m_name, I.m_price, I.m_quantity, I.m_taxed);
   }

   /************************************************************/
   // DECONSTRUCTOR
   /************************************************************/
   Item::~Item() {
      delete[] m_name;
   }

   /************************************************************/
   // PRIVATE METHODS - setEmpty
   /************************************************************/
   void Item::setEmpty() {
      price(0);
      quantity(0);
      taxed(true);
      m_name = nullptr;
      m_sku[0] = '\0';
   }

   /************************************************************/
   // PRIVATE METHODS - alloCopy
   /************************************************************/
   void Item::alloCopy(const char* a_sku, const char* a_name, double a_price, int a_quantity, bool a_taxed) {

      if ((a_sku[0] == '\0' || a_sku == nullptr) || (a_name == '\0' || a_name == nullptr) || a_price < 0 || a_quantity < 0)
      {
         setEmpty();
      }
      else
      {
         if (a_sku != nullptr && a_sku != '\0')
            sku(a_sku);
         if (a_name != nullptr && a_name != '\0')
            name(a_name);

         quantity(a_quantity);
         price(a_price);
         taxed(a_taxed);
      }
   }

   /************************************************************/
   // PUBLIC METHODS - ASSIGNMENT OPERATOR - operator=
   /************************************************************/
   Item& Item::operator= (const Item& I) {

      if (!I.isEmpty() && this != &I)
      {
         delete[] m_name;
         alloCopy(I.m_sku, I.m_name, I.m_price, I.m_quantity, I.m_taxed);
      }
      return *this;
   }

   /************************************************************/
   // PUBLIC METHODS - SETTER - sku
   /************************************************************/
   void Item::sku(const char* sku) {
      strncpy(m_sku, sku, MAX_SKU_LEN);
      m_sku[MAX_SKU_LEN] = '\0';
   }

   /************************************************************/
   // PUBLIC METHODS - SETTER - price
   /************************************************************/
   void Item::price(double price) {
      m_price = price;
   }

   /************************************************************/
   // PUBLIC METHODS - SETTER - name
   /************************************************************/
   void Item::name(const char* name) {
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);
   }

   /************************************************************/
   // PUBLIC METHODS - SETTER - taxed
   /************************************************************/
   void Item::taxed(bool taxed) {
      m_taxed = taxed;
   }

   /************************************************************/
   // PUBLIC METHODS - SETTER - quantity
   /************************************************************/
   void Item::quantity(int quantity) {
      m_quantity = quantity;
   }

   /************************************************************/
   // PUBLIC METHODS - GETTER - sku
   /************************************************************/
   const char* Item::sku() const {
      return m_sku;
   }

   /************************************************************/
   // PUBLIC METHODS - GETTER - price
   /************************************************************/
   double Item::price() const {
      return m_price;
   }

   /************************************************************/
   // PUBLIC METHODS - GETTER - name
   /************************************************************/
   const char* Item::name() const {
      return m_name;
   }

   /************************************************************/
   // PUBLIC METHODS - GETTER - taxed
   /************************************************************/
   bool Item::taxed() const {
      return m_taxed;
   }

   /************************************************************/
   // PUBLIC METHODS - GETTER - quantity
   /************************************************************/
   int Item::quantity() const {
      return m_quantity;
   }

   /************************************************************/
   // PUBLIC METHODS - isEmpty
   /************************************************************/
   bool Item::isEmpty() const {
      return (m_sku[0] == '\0' && m_name == nullptr && price() == 0 && quantity() == 0);
   }

   /************************************************************/
   // PUBLIC METHODS - cost - returns cost after the tax
   /************************************************************/
   double Item::cost() const {
      double cost = price();
      if (taxed())
         cost = price() * double(TAX + 1);
      return cost;
   }

   /************************************************************/
   // PUBLIC METHODS - OPERATOR OVERLOADS - operator==
   /************************************************************/
   bool Item::operator==(const char* string) const {
      return (strcmp(sku(), string) == 0);
   }

   /************************************************************/
   // PUBLIC METHODS - OPERATOR OVERLOADS - operator+=
   /************************************************************/
   int Item::operator+=(int addNum) {
      quantity(quantity() + addNum);
      return (quantity());
   }

   /************************************************************/
   // PUBLIC METHODS - OPERATOR OVERLOADS - operator-=
   /************************************************************/
   int Item::operator-=(int subNum) {
      quantity(quantity() - subNum);
      return (quantity());
   }

   /************************************************************/
   // NON-MEMBER OPERATOR OVERLOADS - OPERATOR +=
   /************************************************************/
   double operator+=(double & d, const Item & I) {
      d += (I.quantity() * I.cost());
      return d;
   }

   /************************************************************/
   // NON-MEMBER OPERATOR OVERLOADS - operator<< 
   /************************************************************/
   std::ostream& operator<<(std::ostream& ostr, const Item& I) {
      I.write(ostr, true);
      return ostr;
   }

   /************************************************************/
   // NON-MEMBER OPERATOR OVERLOADS - operator>>
   /************************************************************/
   std::istream& operator >> (std::istream& istr, Item& I) {
      I.read(istr);
      return istr;
   }
}