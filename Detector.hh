#ifndef DETECTOR_HH
#define DETECTOR_HH
#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;

class Detector : public G4VUserDetectorConstruction {
    public:
        G4VPhysicalVolume* Construct() override;
};

#endif