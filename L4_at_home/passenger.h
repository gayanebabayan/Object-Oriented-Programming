// OOP244_B: Workshop4-atHome
// File:     w4_at_home.cpp
// Date:     11-Feb-2017
// Author:   Gayane Babayan
// ID:       107-061-160 
// email:    gbabayan@myseneca.ca


//TODO: add header guards here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

// TODO: holiday namespace here
namespace holiday {

	// TODO: declare the class Passenger here
	class Passenger {
	private:
		char m_name[32];
		char m_destination[32];
		int m_departureYear;
		int m_departureMonth;
		int m_departureDay;
		void setEmpty();
	public:
		// TODO: add the class the attributes,
		//       the member function already provided,
		//       and the member functions that you must implement
		void display(bool nameOnly = false) const;
		Passenger();
	   Passenger(const char name[], const char destination[], int year, int month, int day);
      void travelWith(const Passenger* arrPassenger, int size);
		bool isEmpty() const;
      bool canTravelWith(const Passenger&) const;
	};
}
#endif
