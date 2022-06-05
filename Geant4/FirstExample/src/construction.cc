#include "construction.hh"
#include "detector.hh"
#include <iostream>

MyDetectorConstruction::MyDetectorConstruction(){}

MyDetectorConstruction::~MyDetectorConstruction(){}

G4VPhysicalVolume *MyDetectorConstruction::Construct(){
    //World filled with Air
    G4MagneticField *magField =new G4UniformMagField(G4ThreeVector(0.,0*kilogauss,0.));
    G4FieldManager* localFieldMgr = new G4FieldManager(magField);
    G4Box *solidWorld = new G4Box("World",0.5*m,0.5*m,0.5*m);
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld,MyMaterials.Air,"World",localFieldMgr);
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),logicWorld,"World",0,false,0,true);


    //Lead Shield
    G4Box *solidPanel = new G4Box("Panel",0.25*m,0.25*m,0.005*m);
    G4LogicalVolume *logicPanel = new G4LogicalVolume(solidPanel,MyMaterials.C,"Panel");
    G4VPhysicalVolume *physPanel = new G4PVPlacement(0,G4ThreeVector(),logicPanel,"Panel",logicWorld,false,0,true);


    G4double thickness= 0.2*m;
    G4int nbOfPixelperAxis=4;
    G4double pixelDim = (0.25/nbOfPixelperAxis)*m;

/*
    G4Box *solidDetector = new G4Box("Detector",0.25*m,0.25*m,thickness);
    G4LogicalVolume *logicDetector = new G4LogicalVolume(solidDetector,MyMaterials.Air,"Detector");
    G4VPhysicalVolume *physDetector = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.3*m),logicDetector,"Detector",logicWorld,false,0,true);


    G4Box *solidPixel = new G4Box("Pixel",pixelDim,0.25*m,thickness);
    G4LogicalVolume *logicPixel= new G4LogicalVolume(solidPixel,MyMaterials.Si,"Pixel");
    G4VPhysicalVolume *physPixelX= new G4PVReplica ("PanelX",logicPixel,logicDetector,kXAxis,nbOfPixelperAxis,pixelDim*2,0);

    G4Box *solidPixelY = new G4Box("Pixel",pixelDim,pixelDim,thickness);
    logicDetector= new G4LogicalVolume(solidPixelY,MyMaterials.NaI,"logicDetector");
    G4VPhysicalVolume *physPixelY= new G4PVReplica ("PanelY",logicDetector,logicPixel,kYAxis,nbOfPixelperAxis,pixelDim*2,0);
*/


    //Silicon pixel detector
    G4Box *solidPixel = new G4Box("Pixel",pixelDim,pixelDim,thickness);
    logicDetector= new G4LogicalVolume(solidPixel,MyMaterials.NaI,"Pixel");

    //Creare array di sensitive detector con for loop
    for (int i=0; i<nbOfPixelperAxis; i++){
        for(int j=0; j<nbOfPixelperAxis; j++){
            G4String name = "Pixel"+std::to_string(i)+std::to_string(j);
            //nota che ora abbiamo dei numeri che indicizzano i pixel come j+i*100
            G4VPhysicalVolume *physPixel = new G4PVPlacement(0,G4ThreeVector((-0.25*m+pixelDim)+2*i*pixelDim,(-0.25*m+pixelDim)+2*j*pixelDim,0.3*m),logicDetector,name,logicWorld,false,j+i*100,true);
        }
    }

    return physWorld;
}


void MyDetectorConstruction::ConstructSDandField(){
    MySensitiveDetector *sensDet = new MySensitiveDetector("Sensitive");
    logicDetector->SetSensitiveDetector(sensDet);

    }