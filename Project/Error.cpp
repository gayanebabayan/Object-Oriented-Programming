#define _CRT_SECURE_NO_WARNINGS 

#include <cstring>
#include "Error.h"

namespace ict {

   /************************************************************/
   // DEFAULT CONSTRUCTOR
   /************************************************************/
   Error::Error() {
      m_message = nullptr;
   }

   /************************************************************/
   // 1 ARGUMENT CONSTRUCTOR
   /************************************************************/
   Error::Error(const char* errorMessage) {
      m_message = nullptr;
      message(errorMessage);
   }

   /************************************************************/
   // DECONSTRUCTOR
   /************************************************************/
   Error::~Error() {
      delete[] m_message;
   }

   /************************************************************/
   // PUBLIC METHODS - clear
   /************************************************************/
   void Error::clear() {
      delete[] m_message;
      m_message = nullptr;
   }

   /************************************************************/
   // PUBLIC METHODS - isClear
   /************************************************************/
   bool Error::isClear()const {
      return (m_message == nullptr);
   }

   /************************************************************/
   // PUBLIC METHODS - message
   /************************************************************/
   void Error::message(const char* value) {
      if (value == nullptr) {
         m_message = nullptr;
      }
      else {
         clear();
         m_message = new char[strlen(value) + 1];
         strcpy(m_message, value);
      }
   }

   /************************************************************/
   // PUBLIC METHODS - CAST OVERLOADS CHAR
   /************************************************************/
   Error::operator const char*() const {
      return m_message;
   }

   /************************************************************/
   // PUBLIC METHODS - CAST OVERLOADS BOOL
   /************************************************************/
   Error::operator bool()const {
      return isClear();
   }

   /************************************************************/
   // PUBLIC METHODS - operator= for c-style strings 
   /************************************************************/
   void Error::operator=(const char* errorMessage) {
      clear();
      message(errorMessage);
   }

   /************************************************************/
   // OPERATOR OVERLOAD - operator<< 
   /************************************************************/
   std::ostream& operator<<(std::ostream& ostr, const Error& D) {
      if (!D.isClear()) {
         ostr << (const char*)D;
      }
      return ostr;
   }
}
