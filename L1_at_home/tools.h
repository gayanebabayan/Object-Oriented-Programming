#ifndef SICT_TOOLS_H_
#define SICT_TOOLS_H_

namespace sict{
   // Performs a fool-proof integer entry
   int getInt(int min, int max);
   // Fills the samples array with the statistic samples
   int menu();
   // Finds the largest sample in the samples array, if it is larger than 70,
   // therwise it will return 70.
}

#endif
