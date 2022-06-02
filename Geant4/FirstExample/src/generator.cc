#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
    //numero di particelle per evento
    fParticleGun = new G4ParticleGun(1);
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition* particle = particleTable->FindParticle("proton");

    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleEnergy(100*TeV);
    fParticleGun->SetParticlePosition(G4ThreeVector(0,0,-0.5*m));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *event)
{
    fParticleGun->GeneratePrimaryVertex(event);
}