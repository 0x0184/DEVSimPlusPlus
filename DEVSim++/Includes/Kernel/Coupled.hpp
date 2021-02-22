#ifndef __COUPLED_HPP__
#define __COUPLED_HPP__

#include "Model.hpp"
#include "MList.hpp"

class Coupled : public Model {
protected:
   MList Children;
public:
   Coupled(std::string entity_name);

   void AddChild(Model*);
   void AddChild(Model*, double);
   int IsDevsChild(Model*);
   int NumOfChild(void);
};

#endif   // __COUPLED_HPP__