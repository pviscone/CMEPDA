#pragma once
#include  "G4VSensitiveDetector.hh"
//QUESTO SCRIVILO NEL FILE MARKDOWN
class MySensitiveDetector : public G4VSensitiveDetector{
    public:
        MySensitiveDetector(G4String name);
        ~MySensitiveDetector();
    private:
        void Initialize(G4HCofThisEvent*);
        G4bool ProcessHits(G4Step*, G4TouchableHistory*);
        void EndOfEvent(G4HCofThisEvent*);
};