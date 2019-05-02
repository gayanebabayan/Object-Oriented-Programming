// OOP244_B: Workshop4-atHome
// File:     w4_at_home.cpp
// Date:     11-Feb-2017
// Author:   Gayane Babayan
// ID:       107-061-160 
// email:    gbabayan@myseneca.ca


// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "passenger.h"

// TODO: add the namespaces that you will be using here
using namespace std;

// TODO: holiday namespace here
namespace holiday {
   
   // TODO: add the default constructor here
   Passenger::Passenger() {
	  setEmpty();
   }
   void Passenger::setEmpty() {
	   m_name[0] = '\0';
      m_destination[0] = '\0';
	   m_departureYear = 0;
	   m_departureMonth = 0;
	   m_departureDay = 0;
   }
      
   Passenger::Passenger(const char name[], const char destination[], int year, int month, int day) {
      if ((name != nullptr && name[0] != 0) && (destination != nullptr && destination[0] != 0) &&
          (year >= 2017) && (year <= 2020) && (month >= 1) && (month <= 12) && (day >= 1) && (day <= 31)) {
         strcpy(m_name, name);
         strcpy(m_destination, destination);
         m_departureYear = year;
         m_departureMonth = month;
         m_departureDay = day;
      }
      else
         setEmpty();
   }
   
   void Passenger::travelWith(const Passenger* arrPassenger, int size) {
      int i;
      int count = 0;
      int friendsCanTravel[10];
      
      for (i = 0; i < size; i++) {
         if (canTravelWith(arrPassenger[i])) {
            friendsCanTravel[count] = i;
            count++;
         }
      }
   
      if(count == 0) {
         cout << "Nobody can join ";
         display(true);
         cout << " on vacation!" << endl;
      }
      else if (count == size) {
         cout << "Everybody can join ";
         display(true);
         cout << " on vacation!" << endl;
         display(true);
         cout << " will be accompanied by ";
         
         for (i = 0; i < count; i++) {
            cout << arrPassenger[friendsCanTravel[i]].m_name;
            
            if (i < (count-1))
               cout << ", ";
            else
               cout << "." << endl;
         }  
      }
      else {
         display(true);
         cout << " will be accompanied by ";
         
         for (i = 0; i < count; i++) {
            cout << arrPassenger[friendsCanTravel[i]].m_name;

            if (i < (count-1))
               cout << ", ";
            else
               cout << "." << endl;
         }
      } 
   }
   
   // TODO: add the canTravelWith(...) function here
   bool Passenger::canTravelWith(const Passenger& P) const {
   
	   bool travel;
	    
	   if (strcmp (P.m_destination, m_destination) == 0)
		   travel = true;
	   else
		   travel = false;
	   
	   return travel;
   }
   
   // TODO: add the isEmpty() function here
   bool Passenger::isEmpty() const {
      
	   return ((m_name[0] == '\0') && (m_destination[0] == '\0') && (m_departureYear == 0) && (m_departureMonth == 0) && (m_departureDay == 0));
		       
   }
   
   // below is the member function already provided
   // TODO: read it and understand how it accomplishes its task
   void Passenger::display(bool nameOnly) const
   {
      if (false == this->isEmpty())
      {
         cout << this->m_name;
         if (false == nameOnly)
         {
            cout << " will travel to " << this->m_destination << ". "
               << "The journey will start on "
               << this->m_departureYear << "-"
               << this->m_departureMonth << "-"
               << this->m_departureDay
               << "." << endl;
         }
      }
      else
      {
         cout << "Invalid passenger!" << endl;
      }
   }
}
