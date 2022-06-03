#include "construction.hh"
#include <iostream>

MyDetectorConstruction::MyDetectorConstruction(){}

MyDetectorConstruction::~MyDetectorConstruction(){}

G4VPhysicalVolume *MyDetectorConstruction::Construct(){
    //World filled with Air
    G4Box *solidWorld = new G4Box("World",0.5*m,0.5*m,0.5*m);
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld,MyMaterials.Air,"World");
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),logicWorld,"World",0,false,0,true);

    //Lead Shield
    G4Box *solidPanel = new G4Box("Panel",0.25*m,0.25*m,0.1*m);
    G4LogicalVolume *logicPanel = new G4LogicalVolume(solidPanel,MyMaterials.Pb,"Panel");
    G4VPhysicalVolume *physPanel = new G4PVPlacement(0,G4ThreeVector(),logicPanel,"Panel",logicWorld,false,0,true);

    //Silicon pixel detector
    G4Box *solidPixel = new G4Box("Pixel",0.0025*m,0.0025*m,0.005*m);
    logicDetector= new G4LogicalVolume(solidPixel,MyMaterials.Si,"Pixel");

    //Creare array di sensitive detector con for loop
    for (int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            G4String name = "Pixel"+std::to_string(i)+std::to_string(j);
            //nota che ora abbiamo dei numeri che indicizzano i pixel come j+i*100
            G4VPhysicalVolume *physPixel = new G4PVPlacement(0,G4ThreeVector(-0.25*m+2*i*0.0025*m,-0.25*m+2*j*0.0025*m,0.3*m),logicDetector,name,logicWorld,false,j+i*100,true);
        }
    }

    return physWorld;
}