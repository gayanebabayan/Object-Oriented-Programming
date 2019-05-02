// OOP244_B: Final Project - Milestone4
// File:     Perishable.h
// Date:     31-March-2017
// Author:   Gayane Babayan
// ID:       107-061-160 
// email:    gbabayan@myseneca.ca


#ifndef ICT_PERISHABLE_H__
#define ICT_PERISHABLE_H__

#include "NonPerishable.h"
#include "Date.h"

namespace ict {

   class Perishable : public NonPerishable {
   private:
      Date m_expiry;
   protected:
      char signature() const;
   public:
      Perishable();    // default constructor

      // pure virtual methods of the class PosIO
      std::fstream& save(std::fstream& file)const;
      std::fstream& load(std::fstream& file);
      std::ostream& write(std::ostream& os, bool linear)const;
      std::istream& read(std::istream& is);
   };
}

#endif
