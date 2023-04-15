#include "core/fdtd_solver.h"

int main() {
    // Instantiate the FDTD solver with required parameters
    FDTD::FDTDSolver solver;

    // Initialize the grid (3D grid with dimensions 100x100x100)
    solver.initializeGrid(100, 100, 100);

    // Set up a plane wave source at position z = 10 with a frequency of 1 GHz
    solver.addPlaneWaveSource(10, 1e9);

    // Set up the boundary conditions (absorbing boundaries)
    solver.applyBoundaryConditions(FDTD::BoundaryCondition::ABC);

    // Add a dielectric object (a sphere with radius 20 and relative permittivity of 4) at position (50, 50, 50)
    solver.addDielectricSphere(50, 50, 50, 20, 4.0);

    // Run the simulation for 1000 time steps
    solver.runSimulation(1000);

    // Visualize or output the results
    // ...

    return 0;
}
