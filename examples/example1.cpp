#include "core/fdtd_solver.h"

int main() {
    // Instantiate the FDTD solver with required parameters
    FDTD::FDTDSolver solver;

    // Initialize the grid (1D grid with 200 cells)
    solver.initializeGrid(200);

    // Set up the point source at cell 100 with a frequency of 2 GHz
    solver.addSource(100, 2e9);

    // Set up the boundary conditions (absorbing boundaries)
    solver.applyBoundaryConditions(FDTD::BoundaryCondition::ABC);

    // Run the simulation for 1000 time steps
    solver.runSimulation(1000);

    // Visualize or output the results
    // ...

    return 0;
}
