#pragma once
#include "G4VUserActionInitialization.hh"
#include "generator.hh"

class MyActionInitialization : public G4VUserActionInitialization{
    public:
        MyActionInitialization();
        ~MyActionInitialization();

        //Runna la particle gun e si occupa dello stepping
        virtual void Build() const;
};