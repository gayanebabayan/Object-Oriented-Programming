#ifndef SICT_KINGDOM_H_
#define SICT_KINGDOM_H_

namespace westeros {
   
   struct Kingdom {
   char m_name[32];
   int m_population;
   };

   void display(Kingdom&);
   void display(Kingdom K[], int count);
   void display(Kingdom K[], int count, int min_Num);
   void display(Kingdom K[], int count, char* name);
}

#endif
