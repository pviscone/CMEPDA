#pragma once
#include "G4VUserDetectorConstruction.hh"
#include "MyMaterials.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4PVPlacement.hh"
#include "G4ThreeVector.hh"
#include "G4Box.hh"



class MyDetectorConstruction : public G4VUserDetectorConstruction{
    private:
        //Il logical volum del detector va tenuto fuori dalla funzione construc
        //Poichè poi viene usato per definire il sensitive volume
        G4LogicalVolume *logicDetector;
    
    public:
        MyDetectorConstruction();
        ~MyDetectorConstruction();

        G4VPhysicalVolume *Construct();
};
