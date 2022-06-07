#include "detector.hh"

//name è il mome del detector
MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name){
    //G4cout << "MySensitiveDetector::MySensitiveDetector" << G4endl;
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
    std::string particle=particleName;
    G4int trackID = track->GetTrackID();
    const G4VTouchable* touchable = preStepPoint->GetTouchable();
    G4int copyNo = touchable->GetCopyNumber();
    G4ThreeVector pos = (touchable->GetVolume())->GetTranslation();

    //G4cout << "EVENTO: " << evID << G4endl;
    //G4cout << std::setw(20) << "ID" << std::setw(20) << "copy#" << std::setw(20) << "Particle" << std::setw(20) << "position" << std::setw(50) << "Pixel center" << std::setw(40) << "Energy deposit" << G4endl;
    //G4cout << std::setw(20) << trackID << std::setw(20) << copyNo << std::setw(20) << particleName << std::setw(5) << prePos/m << " m" << std::setw(20) << pos/m<< " m" << std::setw(40) << edep << " MeV" << G4endl;

    //G4cout << std::setw(6) << "ID: " << trackID << " | copy#: " << copyNo <<" | Particle: " << particleName << " |  position: " << prePos/m << " m | Energy deposit: "<< edep/MeV << " MeV" <<  G4endl;


    //Possiamo anche ritornare la posizione del centro del pixel colpito

    //G4cout << "Pixel center: " << pos/m << " m" << G4endl;

    //Nel sensitive detector vengono killate tutte le tracce di particelle secondarie che non siano gamma
    G4double layer = touchable->GetCopyNumber();


    G4double particleID;
    if(particle=="gamma"){
        particleID=1;
    }
    else if(particle=="e-"){
        particleID=2;
    }
    else if(particle=="e+"){
        particleID=3;
    }
    else if(particle=="mu+"){
        particleID=0;
    }
    else{
        particleID=-1;
    }

    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    analysisManager->FillNtupleIColumn( 0,  evID);
    analysisManager->FillNtupleIColumn( 1, trackID);
    analysisManager->FillNtupleDColumn( 2, particleID);
    analysisManager->FillNtupleDColumn( 3, edep/MeV);
    analysisManager->FillNtupleDColumn( 4, pos.x()/m);
    analysisManager->FillNtupleDColumn( 5, pos.y()/m);
    analysisManager->FillNtupleDColumn( 6, layer);
    analysisManager->AddNtupleRow(0);

/*     track->SetTrackStatus(fStopAndKill);
    if (trackID != 1 && particleName != "gamma"){
        track->SetTrackStatus(fStopAndKill);
    } */

    return true;
}