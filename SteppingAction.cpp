#include "SteppingAction.hh"

#include "G4Step.hh"
#include "G4Track.hh"
#include "G4VProcess.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"

void SteppingAction::UserSteppingAction(const G4Step* step) {

    auto track = step->GetTrack();

    auto process = step->GetPostStepPoint()->GetProcessDefinedStep();

    if (!process) return;

    G4String processName = process->GetProcessName();

    if (processName == "annihil") {

        G4cout << "\n--- POSITRON ANNIHILATION ---" << G4endl;

        G4cout << "Particle: "
               << track->GetDefinition()->GetParticleName()
               << G4endl;

        G4cout << "Track ID: "
               << track->GetTrackID()
               << G4endl;

        G4cout << "Parent ID: "
               << track->GetParentID()
               << G4endl;

        G4cout << "Process: "
               << processName << G4endl;

        G4cout << "Position: "
               << step->GetPostStepPoint()->GetPosition()
               << G4endl;

        G4cout << "Energy before interaction: "
               << step->GetPreStepPoint()->GetKineticEnergy() / keV
               << " keV" << G4endl;

        auto secondaries = step->GetSecondaryInCurrentStep();

        G4cout << "Secondary particles:" << G4endl;

        for (const auto* secondary : *secondaries) {

            G4cout << "  "
                   << secondary->GetDefinition()->GetParticleName()
                   << " | Energy: "
                   << secondary->GetKineticEnergy() / keV
                   << " keV" << G4endl;
        }

        G4cout << "------------------------------\n" << G4endl;
    }
}