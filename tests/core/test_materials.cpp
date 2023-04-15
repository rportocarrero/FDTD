#include "gtest/gtest.h"
#include "core/materials.h"

TEST(MaterialsTest, AddMaterial) {
  // Test adding a material to the FDTD grid
  // Assuming you have a class Grid with addMaterial() method
  FDTD::Grid grid;
  FDTD::Material material; // Assuming you have a Material class
  grid.addMaterial(material);
  // Add assertions to check if the material was added correctly
}()
