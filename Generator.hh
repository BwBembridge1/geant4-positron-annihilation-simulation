#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"

class G4GeneralParticleSource;

class Generator : public G4VUserPrimaryGeneratorAction {
private:
    G4GeneralParticleSource* particleSource;

public:
    Generator();
    ~Generator() override;

    void GeneratePrimaries(G4Event* event) override;
};

#endif