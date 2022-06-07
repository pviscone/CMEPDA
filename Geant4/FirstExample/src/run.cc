#include "run.hh"

//nel costruttore bisogna creare il file che andremo a scrivere
MyRunAction::MyRunAction(){}

MyRunAction::~MyRunAction(){}

void MyRunAction::BeginOfRunAction(const G4Run*){
    //L'analysis manager, come tutto il resto, è un singleton.
    //Definirne uno nuovo torna solo il puntatore al manager già creato.
    // Per questo lo istanzio 20 volte, puntano tutti allo stesso manager
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(2);
    analysisManager->OpenFile("output.root");


    analysisManager->CreateNtuple("ntuple", "ntuple");
    analysisManager->CreateNtupleIColumn("EventID");
    analysisManager->CreateNtupleIColumn("TrackID");
    analysisManager->CreateNtupleDColumn("ParticleID");
    analysisManager->CreateNtupleDColumn("EnergyDeposites");
    analysisManager->CreateNtupleDColumn("XPixel");
    analysisManager->CreateNtupleDColumn("YPixel");
    analysisManager->CreateNtupleDColumn("Layer");
    analysisManager->FinishNtuple(0);
}


void MyRunAction::EndOfRunAction(const G4Run*){
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    analysisManager->Write();
    analysisManager->CloseFile();

}