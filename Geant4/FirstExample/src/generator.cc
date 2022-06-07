#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
    //numero di particelle per evento
    fParticleGun = new G4ParticleGun(1);
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition* particle = particleTable->FindParticle("mu+");

    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleEnergy(4*GeV);
    fParticleGun->SetParticlePosition(G4ThreeVector(0,0,-0.3*m));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *event)
{
    //G4cout<< "======== NEW BEAM =======" << G4endl;
    fParticleGun->GeneratePrimaryVertex(event);
}