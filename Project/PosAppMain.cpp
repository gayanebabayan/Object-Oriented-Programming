// OOP244_B: Final Project - Milestone5
// File:     PosAppMain.cpp
// Date:     11-April-2017
// Author:   Gayane Babayan
// ID:       107-061-160 
// email:    gbabayan@myseneca.ca

#include "PosApp.h"
int main() {
   ict::PosApp app("posapp.txt", "bill.txt");
   app.run();
   return 0;
}