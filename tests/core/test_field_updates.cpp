#include "gtest/gtest.h"
#include "core/field_updates.h"

// test_field_updates.cpp
TEST(FieldUpdatesTest, UpdateElectricField) {
  // Test updating the electric field
  FDTD::FieldUpdates field_updates;
  field_updates.updateElectricField();
  // Add assertions to check if the electric field was updated correctly
}

TEST(FieldUpdatesTest, UpdateMagneticField) {
  // Test updating the magnetic field
  FDTD::FieldUpdates field_updates;
  field_updates.updateMagneticField();
  // Add assertions to check if the magnetic field was updated correctly
}

