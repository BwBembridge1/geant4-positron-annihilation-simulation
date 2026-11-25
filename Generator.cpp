#include "Generator.hh"

#include "G4GeneralParticleSource.hh"
#include "G4Event.hh"
#include "G4ThreeVector.hh"
#include "G4SystemOfUnits.hh"

Generator::Generator() {
    particleSource = new G4GeneralParticleSource();
}

Generator::~Generator() {
    delete particleSource;
}

void Generator::GeneratePrimaries(G4Event* event) {

    G4ThreeVector start =
        particleSource->GetCurrentSource()->GetPosDist()->GetCentreCoords();

    G4ThreeVector target(0*mm, 0*mm, 3*mm);

    G4ThreeVector direction = (target - start).unit();

    particleSource->GetCurrentSource()->GetAngDist()
        ->SetParticleMomentumDirection(direction);

    particleSource->GeneratePrimaryVertex(event);
}