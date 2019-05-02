#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
#include "POS.h"

namespace ict {

   /************************************************************/
   // DEFAULT CONSTRUCTOR
   /************************************************************/
   Date::Date() {
      m_dateOnly = false;
      set();
   }

   /************************************************************/
   // 3 ARGUMENT CONSTRUCTOR
   /************************************************************/
   Date::Date(int year, int mon, int day) {
      m_dateOnly = true;
      m_year = year;
      m_mon = mon;
      m_day = day;
      m_hour = 0;
      m_min = 0;
      errCode(NO_ERROR);
   }

   /************************************************************/
   // 5 ARGUMENT CONSTRUCTOR
   /************************************************************/
   Date::Date(int year, int mon, int day, int hour, int min) {
      m_dateOnly = false;
      m_year = year;
      m_mon = mon;
      m_day = day;
      m_hour = hour;
      m_min = min;
      errCode(NO_ERROR);
   }

   /************************************************************/
   // PRIVATE METHODS - set
   /************************************************************/
   void Date::set() {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      m_day = lt.tm_mday;
      m_mon = lt.tm_mon + 1;
      m_year = lt.tm_year + 1900;
      if (dateOnly()) {
         m_hour = m_min = 0;
      }
      else {
         m_hour = lt.tm_hour;
         m_min = lt.tm_min;
      }
   }

   /************************************************************/
   // PRIVATE METHODS - value
   /************************************************************/
   int Date::value()const {
      return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
   }

   /************************************************************/
   // PRIVATE METHODS - mdays
   /************************************************************/
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }

   /************************************************************/
   // PRIVATE METHODS - errCode
   /************************************************************/
   void Date::errCode(int errorCode) {
      m_readErrorCode = errorCode;
   }

   /************************************************************/
   // PRIVATE METHODS - set(int, int, int, int,int)
   /************************************************************/
   void Date::set(int year, int mon, int day, int hour, int min) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      m_hour = hour;
      m_min = min;
      errCode(NO_ERROR);
   }

   /************************************************************/
   // PUBLIC METHODS - GETTERS - errCode
   /************************************************************/
   int Date::errCode() const {
      return m_readErrorCode;
   }

   /************************************************************/
   // PUBLIC METHODS - GETTERS - bad
   /************************************************************/
   bool Date::bad() const {
      return (m_readErrorCode != 0);
   }

   /************************************************************/
   // PUBLIC METHODS - GETTERS - dateOnly
   /************************************************************/
   bool Date::dateOnly() const {
      return m_dateOnly;
   }

   /************************************************************/
   // PUBLIC METHODS - GETTERS - dateOnly(bool)
   /************************************************************/
   void Date::dateOnly(bool value) {
      if (value) {
         m_dateOnly = value;
         m_hour = 0;
         m_min = 0;
      }
   }

   /************************************************************/
   // PUBLIC METHODS - read
   /************************************************************/
   std::istream& Date::read(std::istream& istr) {
      int year, mon, day, hour = 0, min = 0;
      istr >> year;
      istr.ignore();
      istr >> mon;
      istr.ignore();
      istr >> day;
      if (!m_dateOnly) {
         istr.ignore(2);
         istr >> hour;
         istr.ignore();
         istr >> min;
      }
      if (!istr.eof() && !istr.good()) {
         errCode(CIN_FAILED);
      }
      else {
         set(year, mon, day, hour, min);
         if (year < MIN_YEAR || year > MAX_YEAR) {
            errCode(YEAR_ERROR);
         }
         else if (mon < 1 || mon > 12) {
            errCode(MON_ERROR);
         }
         else if (day < 1 || day > mdays()) {
            errCode(DAY_ERROR);
         }
         else if (hour < 0 || hour > 23) {
            errCode(HOUR_ERROR);
         }
         else {
            if (min < 0 || min > 59) {
               errCode(MIN_ERROR);
            }
         }
      }
      return istr;
   }

   /************************************************************/
   // PUBLIC METHODS - write
   /************************************************************/
   std::ostream& Date::write(std::ostream& ostr) const {
      ostr << std::setfill('0') << m_year << "/" << std::setw(2) << m_mon << "/" << std::setw(2) << m_day << std::setfill(' ');
      if (!m_dateOnly)
         ostr << ", " << std::setfill('0') << std::setw(2) << m_hour << ":" << std::setw(2) << m_min;
      return ostr;
   }

   /************************************************************/
   // PUBLIC METHODS - OPERATOR OVERLOADS - operator=
   /************************************************************/
   bool Date::operator==(const Date& D) const {
      return(this->value() == D.value());
   }

   /************************************************************/
   // PUBLIC METHODS - OPERATOR OVERLOADS - operator!=
   /************************************************************/
   bool Date::operator!=(const Date& D) const {
      return(this->value() != D.value());
   }

   /************************************************************/
   // PUBLIC METHODS - OPERATOR OVERLOADS - operator<
   /************************************************************/
   bool Date::operator<(const Date& D) const {
      return(this->value() < D.value());
   }

   /************************************************************/
   // PUBLIC METHODS - OPERATOR OVERLOADS - operator>
   /************************************************************/
   bool Date::operator>(const Date& D) const {
      return(this->value() > D.value());
   }

   /************************************************************/
   // PUBLIC METHODS - OPERATOR OVERLOADS - operator<=
   /************************************************************/
   bool Date::operator<=(const Date& D) const {
      return(this->value() <= D.value());
   }

   /************************************************************/
   // PUBLIC METHODS - OPERATOR OVERLOADS - operator>=
   /************************************************************/
   bool Date::operator>=(const Date& D) const {
      return(this->value() >= D.value());
   }

   /************************************************************/
   // IO OPERATOR OVERLOADS(HELPERS) - operator<<
   /************************************************************/
   std::ostream& operator<<(std::ostream& ostr, const Date& D) {
      D.write(ostr);
      return ostr;
   }

   /************************************************************/
   // IO OPERATOR OVERLOADS(HELPERS) - operator<<
   /************************************************************/
   std::istream& operator >> (std::istream& istr, Date& D) {
      D.read(istr);
      return istr;
   }
}
