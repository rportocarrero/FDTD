#include "core/fdtd_solver.h"

int main() {
    // Instantiate the FDTD solver with required parameters
    FDTD::FDTDSolver solver;

    // Initialize the grid (2D grid with dimensions 200x200)
    solver.initializeGrid(200, 200);

    // Set up a Gaussian pulse source at position (100, 100) with a frequency of 1 GHz
    solver.addGaussianPulseSource(100, 100, 1e9);

    // Set up the boundary conditions (absorbing boundaries)
    solver.applyBoundaryConditions(FDTD::BoundaryCondition::ABC);

    // Run the simulation for 1000 time steps
    solver.runSimulation(1000);

    // Visualize or output the results
    // ...

    return 0;
}
