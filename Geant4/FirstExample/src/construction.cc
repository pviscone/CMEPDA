#include "construction.hh"
#include <iostream>

MyDetectorConstruction::MyDetectorConstruction(){}

MyDetectorConstruction::~MyDetectorConstruction(){}

G4VPhysicalVolume *MyDetectorConstruction::Construct(){
    G4Box *solidWorld = new G4Box("World",0.5*m,0.5*m,0.5*m);
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld,MyMaterials.Air,"World");
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),logicWorld,"World",0,false,0,true);

    G4Box *solidPanel = new G4Box("Panel",0.25*m,0.25*m,0.1*m);
    G4LogicalVolume *logicPanel = new G4LogicalVolume(solidPanel,MyMaterials.Pb,"Panel");
    G4VPhysicalVolume *physPanel = new G4PVPlacement(0,G4ThreeVector(),logicPanel,"Panel",logicWorld,false,0,true);


    return physWorld;
}