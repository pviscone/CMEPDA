#include "construction.hh"
#include "physics.hh"
#include "action.hh"
#include "G4UImanager.hh"
#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4VisExecutive.hh"
#include "G4VisManager.hh"
#include "G4UIExecutive.hh"
#include <thread>




int main(int argc, char **argv){


    #ifdef G4MULTITHREADED
        G4int nThreads = std::thread::hardware_concurrency();
        G4MTRunManager* runManager = new G4MTRunManager;
        runManager->SetNumberOfThreads(nThreads);
        G4cout << "Using " << runManager->GetNumberOfThreads() << " threads" << G4endl;
    #else
        G4RunManager *runManager=new G4RunManager();
        G4cout << "NO threads" << G4endl;
    #endif


    runManager->SetUserInitialization(new MyDetectorConstruction());
    runManager->SetUserInitialization(new MyPhysicsList());

    runManager->SetUserInitialization(new MyActionInitialization);
    runManager->Initialize();

    G4UIExecutive *ui = new G4UIExecutive (argc,argv);
    G4VisManager *visManager= new G4VisExecutive();
    visManager->Initialize();
    G4UImanager *UImanager = G4UImanager::GetUIpointer();


    //Se non passi argomenti esegue la macro vis altrimenti esegue le macro che passi
    G4String command = "/control/execute ";
    if(argc==1){
        std::cout << "No input file specified. Using default macro." << std::endl;
        UImanager->ApplyCommand(command+"./vis.mac");
        UImanager->ApplyCommand(command+"./run.mac");
        //ui->SessionStart();
        //delete ui;
    }
    else{
        G4String key;
        for (int i=1; i<argc; ++i){
            key=argv[i];
            G4cout << "Executed macro:" << i << "  "<< key << G4endl;
            G4cout <<command+key<< G4endl;
            UImanager->ApplyCommand(command+key);
        }
    }
    //UImanager->ApplyCommand("/control/execute vis.mac"); //Definire la macro per la visualizzazione
    //ui->SessionStart();

    delete ui;
    delete visManager;
    delete runManager;

    return 0;
}
