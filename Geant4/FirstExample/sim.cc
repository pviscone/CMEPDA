#include "construction.hh"
#include "physics.hh"
#include "G4UImanager.hh"
#include "G4RunManager.hh"
#include "G4VisExecutive.hh"
#include "G4VisManager.hh"
#include "G4UIExecutive.hh"
#include <iostream>



int main(int argc, char **argv){
    G4RunManager *runManager=new G4RunManager();

    runManager->SetUserInitialization(new MyDetectorConstruction());
    runManager->SetUserInitialization(new MyPhysicsList());
    /*
    runManager->SetUserInitialization(new MyPhysicsList);
    runManager->SetUserInitialization(new MyG4ActionInitialization);

    */
    runManager->Initialize();

    G4UIExecutive *ui = new G4UIExecutive (argc,argv);
    G4VisManager *visManager= new G4VisExecutive();
    visManager->Initialize();
    G4UImanager *UImanager = G4UImanager::GetUIpointer();


    /*
    if(argc==1){
        std::cout << "No input file specified. Using default macro." << std::endl;
        G4UImanager::GetUIpointer()->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
        delete ui;
    }
    else{
        std::cout << "Using input file: " << argv[1] << std::endl;
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    }*/
    UImanager->ApplyCommand("/control/execute vis.mac"); //Definire la macro per la visualizzazione
    ui->SessionStart();


    return 0;
}
