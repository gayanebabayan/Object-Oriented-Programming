#ifndef SICT_KINGDOM_H_
#define SICT_KINGDOM_H_

namespace westeros {
   struct Kingdom {
   char m_name[32];
   int m_population;
   };

   void display (struct Kingdom& K);
}

#endif
