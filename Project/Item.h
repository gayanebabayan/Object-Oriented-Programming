#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__

// inlcude PosIO and POS header files
#include "POS.h"
#include "PosIO.h"

namespace ict {
   // class Item
   class Item : public PosIO {
   private:
      char m_sku[MAX_SKU_LEN + 1];
      char* m_name;
      double m_price;
      bool m_taxed;
      int m_quantity;
      void alloCopy(const char* sku, const char* name, double price, int quantity, bool taxed);
      void setEmpty();
   public:
      Item();								      // default constructor
      Item(const char* sku, const char* name, double price, bool taxed = true);  // 4 argument constructor
      Item(const Item& I);				   	// copy constructor

      Item& operator= (const Item& I);		// assignment operator
      virtual ~Item();						   //destructor

      void sku(const char* sku);		   // setter for the SKU
      void price(double price);			// setter for the price 
      void name(const char* name);		// setter for the name
      void taxed(bool taxed);			   // setter for the taxed
      void quantity(int quantity);		// setter for the quantity

      const char* sku() const;			// getter for the SKU
      double price() const;				// getter for the price
      const char* name() const;			// getter for the name
      bool taxed() const;				   // getter for the taxed
      int quantity() const;				// getter for the quantity
      bool isEmpty() const;
      double cost() const;

      // member operator overloads
      bool operator==(const char* string) const;
      int operator+=(int addNum);
      int operator-=(int subNum);
   };
   // end class Item

   // operator += 
   double operator+=(double& d, const Item& I);

   // operator << and operator >>
   std::ostream& operator<<(std::ostream& ostr, const Item& I);
   std::istream& operator >> (std::istream& istr, Item& I);
}

#endif
