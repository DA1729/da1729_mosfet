# validation

test cases, benchmarks, and validation against reference models

each model has its own subdirectory with validation tests

## square_law/

validation tests for the square-law model:
- `test_regions.cpp` - verify cutoff, triode, and saturation regions
- `test_gm_gds.cpp` - validate small-signal parameters using numerical derivatives
- `test_edge_cases.cpp` - test boundary conditions and edge cases

## planned subdirectories

additional validation tests will be added as new models are implemented
