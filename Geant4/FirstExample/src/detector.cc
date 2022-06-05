#include "detector.hh"
#include "G4RunManager.hh"
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

    G4int evID=G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();


    G4ThreeVector prePos = preStepPoint->GetPosition();
    G4double edep= aStep->GetTotalEnergyDeposit();
    G4String particleName = track->GetDefinition()->GetParticleName();
    G4int trackID = track->GetTrackID();
    const G4VTouchable* touchable = preStepPoint->GetTouchable();
    G4int copyNo = touchable->GetCopyNumber();
    G4ThreeVector pos = (touchable->GetVolume())->GetTranslation();

    G4cout << "EVENTO: " << evID << G4endl;
    G4cout << std::setw(20) << "ID" << std::setw(20) << "copy#" << std::setw(20) << "Particle" << std::setw(20) << "position" << std::setw(50) << "Pixel center" << std::setw(40) << "Energy deposit" << G4endl;
    G4cout << std::setw(20) << trackID << std::setw(20) << copyNo << std::setw(20) << particleName << std::setw(5) << prePos/m << " m" << std::setw(20) << pos/m<< " m" << std::setw(40) << edep << " MeV" << G4endl;

    //G4cout << std::setw(6) << "ID: " << trackID << " | copy#: " << copyNo <<" | Particle: " << particleName << " |  position: " << prePos/m << " m | Energy deposit: "<< edep/MeV << " MeV" <<  G4endl;


    //Possiamo anche ritornare la posizione del centro del pixel colpito

    //G4cout << "Pixel center: " << pos/m << " m" << G4endl;

    //Nel sensitive detector vengono killate tutte le tracce di particelle secondarie che non siano gamma

    if (trackID != 1 && particleName != "gamma"){
        track->SetTrackStatus(fStopAndKill);
    }





    return true;
}