#include "detector.hh"


MySensitiveDetector::MySensitiveDetector(G4String name){

}

MySensitiveDetector::~MySensitiveDetector(){

}

G4bool MySensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory*){
    return true;
}