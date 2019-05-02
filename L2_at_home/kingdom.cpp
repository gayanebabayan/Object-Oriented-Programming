#include <iostream>
#include <cstring>
#include "kingdom.h"
using namespace std;

// TODO: the westeros namespace
namespace westeros {

	// TODO:definition for display(...) 
	void display(Kingdom& K) {
		cout << K.m_name << ", population " << K.m_population << endl;
	}

   //testing that the 1st overload of "display(...)" works 
	void display(Kingdom K[], int count) {
		cout << "------------------------------" << endl
			<< "Kingdoms of Westeros" << endl
			<< "------------------------------" << endl;
		int i;
		int totalPopul = 0;
		for (i = 0; i < count; i++) {
         cout << i + 1 << ". ";
         display(K[i]);
			totalPopul = totalPopul + K[i].m_population;
		}
		cout << "------------------------------" << endl
			<< "Total population of Westeros: " << totalPopul << endl
			<< "------------------------------" << endl;
	}

   //testing that the 2nd overload of "display(...)" works
	void display(Kingdom K[], int count, int min_Num) {
		cout << "------------------------------" << endl
			<< "Kingdoms of Westeros with more than " << min_Num << " people " << endl
			<< "------------------------------" << endl;
		int i;
		for (i = 0; i < count; i++) {
         if (K[i].m_population >= min_Num)
            display(K[i]);
		}
      cout << "------------------------------" << endl;
	}

   //testing that the 3rd overload of "display(...)" works
	void display(Kingdom K[], int count, char name[]) {
		int i;
      int exist = 0;

      cout << "------------------------------" << endl
         << "Searching for kingdom " << name << " in Westeros" << endl
         << "------------------------------" << endl;

		for (i = 0; i < count; i++) {
         if (strcmp(K[i].m_name, name) == 0) {
            //cout << K[i].m_name << ", population " << K[i].m_population << endl;
            display(K[i]);
            exist++;
         }
      }
      if (exist == 0)
         cout << name << " is not part of Westeros." << endl;
      cout << "------------------------------" << endl << endl;
      }
}
