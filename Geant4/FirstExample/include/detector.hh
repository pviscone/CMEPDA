#pragma once
#include  "G4VSensitiveDetector.hh"
#include "G4SystemOfUnits.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
//QUESTO SCRIVILO NEL FILE MARKDOWN
class MySensitiveDetector : public G4VSensitiveDetector{
    public:
        MySensitiveDetector(G4String name);
        ~MySensitiveDetector();
    private:
        virtual G4bool ProcessHits(G4Step*, G4TouchableHistory*);

};
