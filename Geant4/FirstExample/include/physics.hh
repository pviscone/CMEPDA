#pragma once
#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4DecayPhysics.hh"

class MyPhysicsList : public G4VModularPhysicsList{
    public:
        MyPhysicsList();
        ~MyPhysicsList();
};