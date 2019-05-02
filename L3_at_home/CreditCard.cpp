#include <iostream>
#include <cstring>
#include "CreditCard.h"
using namespace std;

namespace sict {
   void CreditCard::name(const char* cardHolderName) {
      strcpy_s(m_cardHolderName, cardHolderName);
   }

   void CreditCard::initialize(unsigned long long creditCardNumber,
      int instCode,
      int expiryYear,
      int expiryMonth,
      int numberInTheBack) {
      m_cardNumber = creditCardNumber;
      m_institutionCode = instCode;
      m_expiryYear = expiryYear;
      m_expiryMonth = expiryMonth;
      m_numberInTheBack = numberInTheBack;
   }

   bool CreditCard::isValid()const {
      bool valid = true;

      valid = valid && (m_cardHolderName[0] != 0);
      valid = valid && (m_cardNumber >= MIN_CARD_NUMBER) && (m_cardNumber <= MAX_CARD_NUMBER);
      valid = valid && (m_institutionCode >= MIN_INST_NUMBER) && (m_institutionCode <= MAX_INST_NUMBER);
      valid = valid && (m_expiryYear >= MIN_EXP_YEAR) && (m_expiryYear <= MAX_EXP_YEAR);
      valid = valid && (m_expiryMonth >= 1) && (m_expiryMonth <= 12);
      valid = valid && (m_numberInTheBack > 0) && (m_numberInTheBack <= 999);

      return valid;
   }

   void CreditCard::write(bool displayName, bool displayCardInfo) const {
      if (isValid()) {
         if (displayName && displayCardInfo) {
            writeName();
            cout << endl;
            writeCardInfo();
         }
         else if (displayName)
            writeName();
         else if(displayCardInfo)
            writeCardInfo();
      }
   }
   
   void CreditCard::writeName() const {
      cout << "Cardholder: " << m_cardHolderName;
   }

   void CreditCard::writeCardInfo() const {
      cout << "Card Number: " << m_cardNumber << endl
           << "Institution: " << m_institutionCode << endl
           << "Expires: " << m_expiryMonth << "/" << m_expiryMonth << endl
           << "Number at the back: " << m_numberInTheBack;
   }
}
