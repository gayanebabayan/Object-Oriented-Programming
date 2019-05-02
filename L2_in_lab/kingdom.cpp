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
