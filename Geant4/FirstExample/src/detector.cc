#include "detector.hh"

//name è il mome del detector
MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name){
    G4cout << "MySensitiveDetector::MySensitiveDetector" << G4endl;
}


MySensitiveDetector::~MySensitiveDetector(){

}

G4bool MySensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory* R0hist){
    G4Track *track = aStep->GetTrack();
    G4StepPoint *preStepPoint = aStep -> GetPreStepPoint();
    G4StepPoint *postStepPoint = aStep -> GetPostStepPoint();

    G4ThreeVector prePos = preStepPoint->GetPosition();

    G4cout << "position: " << prePos <<  G4endl;
}