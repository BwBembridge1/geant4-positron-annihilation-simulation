positron-particle-simulation

Overview:
This project was made to model the interaction of a positron and a soft tissue medium. It includes the simulation, rendering, and calculations of the particle interactions.

Technology
- C++
- Geant 11.4
- Make 4.5.1
- Visual Studio 2026 (ver 18.x)
- MSVC compiler
- Powershell for Developers

Features:
- 3D environnment, containing air and soft tissue.
- General Particle Source (GPS), configuring primary particles
- Configurable starting particle location
- Visualization of particle Trajectories
- Calculation, and report on positron annhilation incidents

Physics:
- FTFP_BERT physics dataset

Requirements:
- Geant4 11.4, or other compatible install
- CMake 4.5.1 or other compatible version
- C++ compiler (Visual Studio 2026)

Configuration:

- Configure CMake : >>> cmake -S . -B build
- Compile : >>> cmake --build build --config Release
- Run : >>> .\build\Release\GeantIV.exe

Structure:
- main.cpp -> Simulation initialization and runManager
- Detector.cpp/hh -> Geometry and Material creation
- Generator.cpp/hh -> Particle generation
- SteppingAction.cpp/hh ->  Particle Tracking 
- ActionInitialization.cpp/hh -> Registration of simulation
- vis.mac -> macro configuration and visual configuration

Status:
- Project is in an early release state, fundamentals work however codebase is not clean or well organized. Also missing comments and proper documentation.
- Will be updated semi regularly

License:
- This projet utilizes the Geant4 software is is licensed for open source use under the Geant4 Software License, which can be found here:
 https://geant4.web.cern.ch/download/license.

 - We greatly appreciate the dedication and indivudals who contributed to the creation of Geant4. Without them this project would not have been possible.

 - This project is licensed under the MIT license, free for open source use.