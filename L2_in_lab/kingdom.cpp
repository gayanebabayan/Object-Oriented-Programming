// OOP244_B: Workshop -2
// Date:     23-Jan-2017
// Author:   Gayane Babayan
// ID:       107-061-160 
// email:    gbabayan@myseneca.ca



// TODO: include the necessary headers
#include <iostream>
#include "kingdom.h"
using namespace std;

// TODO: the westeros namespace
namespace westeros {
   
   // TODO:definition for display(...) 
   void display(struct Kingdom& K) {
      
      cout << K.m_name << ", population " << K.m_population << endl;
   
   }
}