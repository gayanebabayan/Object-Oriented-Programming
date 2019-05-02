// OOP244_B: Final Project - Milestone4
// File:     NonPerishable.h
// Date:     31-March-2017
// Author:   Gayane Babayan
// ID:       107-061-160 
// email:    gbabayan@myseneca.ca



#ifndef ICT_NONPERISHABLE_H__
#define ICT_NONPERISHABLE_H__

// include Item
#include "Item.h"
#include "Error.h"

namespace ict {
   class NonPerishable : public Item {
   private:
      Error m_err;
   protected:
      bool ok() const;
      void error(const char* message);
      virtual char signature() const;
   public:
      std::fstream& save(std::fstream& file)const;
      std::fstream& load(std::fstream& file);
      std::ostream& write(std::ostream& os, bool linear)const;
      std::istream& read(std::istream& is);
   };
}

#endif