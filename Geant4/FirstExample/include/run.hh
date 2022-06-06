#pragma once
#include "G4UserRunAction.hh"

//Wrapper a root interno a geant. Non c'è bisogno di importare separatamente root
#include "G4AnalysisManager.hh"

class MyRunAction : public G4UserRunAction {
    public:
        MyRunAction();
        virtual ~MyRunAction();
        virtual void BeginOfRunAction(const G4Run*);
        virtual void EndOfRunAction(const G4Run*);
};