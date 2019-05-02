#pragma once
// OOP244_B: Final Project - Milestone5
// File:     PosApp.h
// Date:     11-April-2017
// Author:   Gayane Babayan
// ID:       107-061-160 
// email:    gbabayan@myseneca.ca

// compilation safeguards
#ifndef ICT_POSAPP_H_
#define ICT_POSAPP_H_

#include <iostream>
#include <iomanip>

#include "Date.h"
#include "Error.h"
#include "Item.h"
#include "NonPerishable.h"
#include "Perishable.h"
#include "POS.h"
#include "PosIO.h"

namespace ict {
   class PosApp {
   private:
      // private member variables
      char   m_filename[128];
      char   m_billfname[128];
      Item*  m_item[MAX_NO_ITEMS];
      int    m_noOfItems;

      // private member functions
      int menu();
      void deallocateItems();
      void loadRecs();
      void saveRecs();
      int searchItems(const char* sku)const;
      void updateQty();
      void addItem(bool isPerishable);
      void listItems()const;
      void truncateBillFile();
      void showBill();
      void addToBill(Item& I);
      void POS();
   public:
      PosApp(const char* filename, const char* billfname);
      PosApp(const PosApp&) = delete;
      PosApp& operator=(const PosApp&) = delete;
      void run();
   };
}

#endif

