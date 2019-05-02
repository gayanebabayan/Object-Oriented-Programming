// OOP244_B: Final Project - Milestone5
// File:     PosApp.cpp
// Date:     11-April-2017
// Author:   Gayane Babayan
// ID:       107-061-160 
// email:    gbabayan@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS

// include libraries
#include <iostream>
#include <cstring>
#include <time.h>

using namespace std;

// inclue headerfiles
#include "PosApp.h"

namespace ict {

   /************************************************************/
   // Default Constructor   
   /************************************************************/
   PosApp::PosApp(const char * filename, const char * billfname)
   {
      // instantiate the name of the m_filename
      int length = strlen(filename);
      strncpy(m_filename, filename, length);
      m_filename[length] = '\0';

      // instantiate the name of the m_billfname
      length = strlen(billfname);
      strncpy(m_billfname, billfname, length);
      m_billfname[length] = '\0';

      m_noOfItems = 0;
      loadRecs();
   }

   /************************************************************/
   // Private Member Function - MENU
   /************************************************************/
   int PosApp::menu()
   {
      // temp variable for holding the menu choice
      int menuChoice;

      // print the menu choice list
      cout << "The Sene-Store" << endl;
      cout << "1- List items" << endl;
      cout << "2- Add Perishable item" << endl;
      cout << "3- Add Non-Perishable item" << endl;
      cout << "4- Update item quantity" << endl;
      cout << "5- Show Item" << endl;
      cout << "6- POS" << endl;
      cout << "0- exit program" << endl;
      cout << "> ";
      cin >> menuChoice;

      // check the entered value, or readability of that value
      if ((cin.fail()) || ((menuChoice < 0) && (menuChoice > 6))) {
         menuChoice = -1;
      }

      // flush the keyboard
      cin.clear();
      cin.ignore(2000, '\n');
      cout << endl;

      return menuChoice;
   }

   /************************************************************/
   // Private Member Function - DE_ALLOCATE_ITEMS
   /************************************************************/
   void PosApp::deallocateItems()
   {
      int i;

      // dynamically deallocate items inside the m_item array 
      for (i = 0; i < m_noOfItems; i++) {
         delete m_item[i];
      }
      m_noOfItems = 0;
   }

   /************************************************************/
   // Private Member Function - LOAD_ITEMS
   /************************************************************/
   void PosApp::loadRecs()
   {
      char id;

      deallocateItems();

      // open the file
      fstream file(m_filename, ios::in);

      // check if file fails or not
      if (file.fail())
      {
         file.clear();
         file.close();
         file.open(m_filename, ios::out);
      }

      // read the information from the file
      else {
         while (!file.eof()) {

            file.get(id);  // REFERENCE: I had "file >> id", which gave me a trouble, so Eudenir Scheffer Junior gave me the idea of "file.get(id)"  

            if (id == 'P' || id == 'N') {

               // dynamically create a Perishable item
               if (id == 'P') {
                  m_item[m_noOfItems] = new Perishable();
               }
               // dynamically create a Perishable item
               else if (id == 'N') {
                  m_item[m_noOfItems] = new NonPerishable();
               }
               // ignore the comma (,)
               file.ignore();
               // load the data from the file into the new created item & increment the noOfItems by 1
               m_item[m_noOfItems++]->load(file);
            }
         }
         file.close();
      }
   }

   /************************************************************/
   // Private Member Function - Save Records
   /************************************************************/
   void PosApp::saveRecs()
   {
      int i;
      // open the file
      fstream file;
      file.open(m_filename, ios::out);

      // save only those items who has more than 0 quantity in m_item array
      for (i = 0; i < m_noOfItems; i++) {
         if (m_item[i]->quantity() > 0)
         {
            m_item[i]->save(file);
         }
      }
      file.close();
      // update of the Items
      loadRecs();
   }

   /************************************************************/
   // Private Member Function - searchItem
   /************************************************************/
   int PosApp::searchItems(const char * sku) const
   {
      int index = -1;

      // search for the sku, if it's found return the index of the item
      for (int i = 0; i < m_noOfItems; i++) {
         if (*m_item[i] == sku)
            index = i;
      }
      return index;
   }

   /************************************************************/
   // Private Member Function - updateQTY
   /************************************************************/
   void PosApp::updateQty()
   {
      // temp variables for the sku and the adding quantity
      char sku[MAX_SKU_LEN + 1];
      int number;

      // ask user for the sku
      cout << "Please enter the SKU: ";
      cin >> sku;

      // search for the sku and return the index number of the item, or -1 if not found
      int index = searchItems(sku);

      // if SKU is found then update the quantity in the m_item array
      if (index != -1) {

         // display item in a non-linear format
         m_item[index]->write(cout, false);

         cout << endl << "Please enter the number of purchased items: ";
         cin >> number;

         // increment the quantity of the item
         *m_item[index] += number;

         // save changes
         saveRecs();
         cout << "Updated!" << endl << endl;
      }
      else
         cout << "Not found!" << endl << endl;
   }

   /************************************************************/
   // Private Member Function - addItem
   /************************************************************/
   void PosApp::addItem(bool isPerishable)
   {
      // create either Perishable or NonPerishable instance
      if (isPerishable)
         m_item[m_noOfItems] = new Perishable;
      else
         m_item[m_noOfItems] = new NonPerishable;

      // receive an Item's values from the user
      m_item[m_noOfItems]->read(cin);

      // if not fails, it saves a new item
      if (!cin.fail())
      {
         m_noOfItems++;
         saveRecs();
         cout << "Item added." << endl << endl;
      }
      //otherwhise it clear, flush the keyboard, and show the error
      else
      {
         cout << *m_item[m_noOfItems] << endl << endl;
         cin.clear();
         cin.ignore(2000, '\n');
      }
   }

   /************************************************************/
   // Private Member Function - listItems
   /************************************************************/
   void PosApp::listItems() const
   {
      // temp variable for the total
      double total = 0.0;

      cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
      cout << "-----|--------|--------------------|-------|---|----|---------|" << endl;

      // loop through the array and write the items in a linear format
      for (int i = 0; i < m_noOfItems; i++) {
         cout << std::setw(4) << right << i + 1 << " | ";
         m_item[i]->write(cout, true);
         total += m_item[i]->quantity()*m_item[i]->cost();
         cout << endl;
      }

      cout << "-----^--------^--------------------^-------^---^----^---------^" << endl;
      cout << "                               Total Asset: $  |" << setw(14) << fixed << setprecision(2) << total << "|" << endl;
      cout << "-----------------------------------------------^--------------^" << endl << endl;
   }

   /************************************************************/
   // Private Member Function - truncateBillFile
   /************************************************************/
   void PosApp::truncateBillFile()
   {
      // open the file with tuncate for emptying it
      fstream file;
      file.open(m_billfname, ios::out | ios::trunc);
      // close the file
      file.close();
   }

   /************************************************************/
   // Private Member Function - showBill
   /************************************************************/
   void PosApp::showBill()
   {
      char id;
      double total = 0.0;

      // REFERENCE: because Eudenir Scheffer Junior already had searched for date/time, I saved my time and took it from him, only that part of Date/Time
      time_t timer;
      timer = time(NULL);
      struct tm *now = localtime(&timer);

      // open the file
      fstream file;
      file.open(m_billfname, ios::in);

      // shows the current time
      cout << "v--------------------------------------------------------v" << endl;
      cout << "| " << now->tm_year + 1900 << "/"
         << setfill('0') << setw(2) << now->tm_mon + 1 << "/"
         << setw(2) << now->tm_mday + 1
         << ", " << now->tm_hour << ":" << now->tm_min
         << "                                      |" << endl;
      cout << "| SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
      cout << "|--------|--------------------|-------|---|----|---------|" << endl;
      cout << setfill(' ');

      // loads all the items from the file
      while (!file.eof()) {

         file.get(id); // REFERENCE: I had "file >> id", which gave me a trouble, so Eudenir Scheffer Junior gave me the idea of "file.get(id)"

         if (id == 'P' || id == 'N') {
            // ignore the comma (,)
            file.ignore();

            // create a Perishable instance
            if (id == 'P') {
               Perishable item;
               // print the item in linear format
               item.load(file);
               // calculate total price
               total += item.quantity() * item.cost();
               cout << "| " << item << endl; // REFERENCE: I had "item.write(cout, true)", which gave me a trouble, so Eudenir Scheffer Junior gave me the idea of "cout << "| " << item << endl;"
            }
            // create a NonPerishable instance
            else if (id == 'N') {
               NonPerishable item;
               // print the item in linear format
               item.load(file);
               // calculate total price
               total += item.quantity() * item.cost();
               cout << "| " << item << endl; // REFERENCE: I had "item.write(cout, true)", which gave me a trouble, so Eudenir Scheffer Junior gave me the idea of "cout << "| " << item << endl;"
            }
         }
      }
      // close the file
      file.close();

      // make the file empty, truncate it
      truncateBillFile();

      cout << "^--------^--------------------^-------^---^----^---------^" << endl;
      cout << "|                               Total: $  |" << setw(14) << right << total << "|" << endl;
      cout << "^-----------------------------------------^--------------^" << endl << endl;
   }

   /************************************************************/
   // Private Member Function - addBill
   /************************************************************/
   void PosApp::addToBill(Item & I)
   {
      // open the file
      fstream file;
      file.open(m_billfname, ios::out | ios::app);

      //save the quantity in a temp variable
      int quantity = I.quantity();

      //add quantity to the bill file
      I.quantity(1);
      I.save(file);

      // decrease the quantity by 1 and save the records
      I.quantity(quantity - 1);
      saveRecs();
   }

   /************************************************************/
   // Private Member Function - POS
   /************************************************************/
   void PosApp::POS()
   {
      // temp variables
      int index;
      char sku[2000];     //char sku[MAX_SKU_LEN + 1]; >>>>>
      bool exit = false;

      // ask for the sku until exit is false
      do {
         cout << "Sku: ";
         cin.get(sku, MAX_SKU_LEN); // REFERENCE: I had "cin >> sku", which gave me a trouble, so Eudenir Scheffer Junior gave me the idea of "cin.get"
         cin.ignore();

         // if sku is an empty string then it shows the bill and exits the loop
         if (!strcmp(sku, "")) {  //es>>>>>>>>>>>
            showBill();
            exit = true;
         }
         // if sku is found, shows the name of the item and adds to the bill
         else {
            index = searchItems(sku);
            if (index != -1) {

               cout << "v------------------->" << endl << "| ";
               cout << m_item[index]->name() << endl;
               cout << "^------------------->" << endl;

               addToBill(*m_item[index]);
            }
            else {
               cout << "Not found!" << endl;
            }
         }
      } while (!exit);

      // flush the keyboard
      cin.clear();
      cin.ignore(2000, '\n');

   }

   /************************************************************/
   // Public Member Function - run
   /************************************************************/
   void PosApp::run()
   {
      // temp variables for controlling the process
      int choice = 0;
      int found = -1;
      bool control = true;

      char sku[MAX_SKU_LEN + 1];

      // while the control is true, show the menu list
      do {
         // returns the choice number from the user
         choice = menu();

         // calls appropriate method
         switch (choice) {
         case 1:
            listItems();
            break;
         case 2:
            addItem(true);
            break;
         case 3:
            addItem(false);
            break;
         case 4:
            updateQty();
            break;
         case 5:
            cout << "Please enter the SKU: ";
            cin >> sku;
            found = searchItems(sku);

            if (found != -1) {
               cout << "v-----------------------------------v" << endl;
               m_item[found]->write(cout, false);
               cout << "^-----------------------------------^" << endl << endl;
            }
            else
               cout << "Not found!" << endl;
            break;
         case 6:
            POS();
            break;
         case 0:
            cout << "Goodbye!" << endl;
            control = false;
            break;
            // anything else but the menu choice, gives an error message
         default:
            cout << "===Invalid Selection,try again===" << endl << endl;
            break;
         }
      } while (control == true);
   }
}

/*
ouputs:
-------------------------------------
update:
Please enter the SKU: 1313
Name:
Paper Tissue
Sku: 1313
Price: 1.22
Price after tax: 1.38
Quantity: 194
Total Cost: 267.45

Please enter the number of purchased items: 12
Updated!

------------------------------
Please enter the SKU: 3434
Not found!

-------------------------------------
add item:
Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 1200/10/12
Invalid Year in Date Entry

Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 2017/5/15
Item added.

--------------------------------------------
list item:
 Row | SKU    | Item Name          | Price |TX |Qty |   Total |
-----|--------|--------------------|-------|---|----|---------|
   1 | 1234   |Milk                |   3.99|  P|   2|     7.98|
   2 | 3456   |Paper Cups          |   5.99| TN|  38|   257.21|
   3 | 4567   |Butter              |   4.56| TP|   9|    46.38|
   4 | 1212   |Salted Butter       |   5.99|  P| 111|   664.89|
   5 | 1313   |Paper Tissue        |   1.22| TN| 206|   283.99|
   6 | 5656   |Honey               |  12.99| TP|  12|   176.14|
-----^--------^--------------------^-------^---^----^---------^
                        Total Asset: $  |       1436.59|
-----------------------------------------------^--------------^


--------------------------------------
printbill:
v--------------------------------------------------------v
| 2017/04/02, 12:42                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         22.05|
^-----------------------------------------^--------------^

-------------------------------------------------------
POS:
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1313
v------------------->
| Paper Tissue
^------------------->
Sku: 1234
v------------------->
| Milk
^------------------->
Sku: 7654
Not found!
Sku: 5656
v------------------->
| Honey
^------------------->
Sku:
v--------------------------------------------------------v
| 2017/04/02, 12:58                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 1234   |Milk                |   3.99|  P|   1|     3.99|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         32.03|
^-----------------------------------------^--------------^

------------------------------------------------------
run:
The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 5656
v-----------------------------------v
Name:
Honey
Sku: 5656
Price: 12.99
Price after tax: 14.68
Quantity: 10
Total Cost: 146.79
Expiry date: 2017/05/15
^-----------------------------------^

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 12345
Not found!

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> five

===Invalid Selection, try again===

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 0

Goodbye!

*/