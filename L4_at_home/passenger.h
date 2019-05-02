#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace holiday {

	class Passenger {
	private:
		char m_name[32];
		char m_destination[32];
		int m_departureYear;
		int m_departureMonth;
		int m_departureDay;
		void setEmpty();
	public:
		void display(bool nameOnly = false) const;
		Passenger();
	   Passenger(const char name[], const char destination[], int year, int month, int day);
      void travelWith(const Passenger* arrPassenger, int size);
		bool isEmpty() const;
      bool canTravelWith(const Passenger&) const;
	};
}
#endif
