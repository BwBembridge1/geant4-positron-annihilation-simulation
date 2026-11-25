#include "ActionInitialization.hh"

#include "Generator.hh"
#include "SteppingAction.hh"

void ActionInitialization::Build() const {

    SetUserAction(new Generator());
    SetUserAction(new SteppingAction());
}