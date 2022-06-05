#pragma once
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4Element.hh"
#include "G4SystemOfUnits.hh"



struct{

        G4NistManager* nist = G4NistManager::Instance();
        G4Material* Air = (this->nist)->FindOrBuildMaterial("G4_AIR");
        G4Material* Pb = (this->nist)->FindOrBuildMaterial("G4_Pb");
        G4Material* Si = (this->nist)->FindOrBuildMaterial("G4_Si");
        G4Material* NaI = (this->nist)->FindOrBuildMaterial("G4_SODIUM_IODIDE");
        G4Material* C = (this->nist)->FindOrBuildMaterial("G4_C");




} MyMaterials;
