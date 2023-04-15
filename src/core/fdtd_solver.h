#pragma once

namespace FDTD {

class FDTDSolver {
public:
    FDTDSolver(/*constructor arguments*/);
    ~FDTDSolver();

    void initializeGrid(/*grid parameters*/);
    void applyBoundaryConditions();
    void updateElectricField();
    void updateMagneticField();
    void addSource(/*source parameters*/);
    void runSimulation(/*simulation parameters*/);
};

} // namespace FDTD
