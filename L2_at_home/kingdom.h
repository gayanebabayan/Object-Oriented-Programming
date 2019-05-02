// OOP244_B: Workshop -2
// Date:     23-Jan-2017
// Author:   Gayane Babayan
// ID:       107-061-160 
// email:    gbabayan@myseneca.ca


// TODO: header safeguards
#ifndef SICT_KINGDOM_H_
#define SICT_KINGDOM_H_


   // TODO: westeros namespace
namespace westeros {
   
	// TODO: define the class Kingdom in the westeros namespace
   struct Kingdom {
   char m_name[32];
   int m_population;
   };

   // TODO: add the declaration for the function display(...),
   //         also in the westeros namespace

   void display(Kingdom&);
   void display(Kingdom K[], int count);
   void display(Kingdom K[], int count, int min_Num);
   void display(Kingdom K[], int count, char* name);
}

#endif
