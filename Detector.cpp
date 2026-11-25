#include "Detector.hh"

#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"

G4VPhysicalVolume* Detector::Construct() {

    auto nist = G4NistManager::Instance();

    auto air = nist->FindOrBuildMaterial("G4_AIR");
    auto tissue = nist->FindOrBuildMaterial("G4_TISSUE_SOFT_ICRP");

    auto solidAir = new G4Box("Air", 10*mm, 10*mm, 10*mm);
    auto solidTissue = new G4Box("Human Tissue", 1*mm, 1*mm, 1*mm);

    auto logicAir = new G4LogicalVolume(solidAir, air, "Air");
    auto logicTissue = new G4LogicalVolume(solidTissue, tissue, "Human Tissue");

    auto physAir = new G4PVPlacement(
        nullptr, G4ThreeVector(),
        logicAir, "Air",
        nullptr, false, 0
    );

    new G4PVPlacement(
        nullptr, G4ThreeVector(0*mm, 0*mm, 3*mm),
        logicTissue, "Human Soft Tissue",
        logicAir, false, 0
    );

    return physAir;
}