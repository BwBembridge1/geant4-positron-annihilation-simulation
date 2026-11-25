#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "FTFP_BERT.hh"

#include "Detector.hh"
#include "ActionInitialization.hh"

int main(int argc, char** argv) {

    auto runManager =
        G4RunManagerFactory::CreateRunManager();

    runManager->SetUserInitialization(new ActionInitialization());
    runManager->SetUserInitialization(new Detector());
    runManager->SetUserInitialization(new FTFP_BERT());

    auto visManager = new G4VisExecutive();
    visManager->Initialize();

    auto ui = new G4UIExecutive(argc, argv);

    // Initialize simulation
    runManager->Initialize();

    G4UImanager::GetUIpointer()->ApplyCommand("/control/execute vis.mac");

    ui->SessionStart();

    // Generate 10 particle events
    runManager->BeamOn(10);

    delete ui;
    delete visManager;
    delete runManager;

    return 0;
}