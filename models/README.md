# models

complete mosfet model implementations combining multiple physical effects

each model is organized in its own subdirectory for clean separation

## current models

### square_law/
- basic long-channel model
- three regions: cutoff, triode, saturation
- ideal behavior without short-channel effects
- files: `mos_model.h`, `mos_model.cpp`

## planned models

### level_1/
- square-law with channel-length modulation and body effect

### level_2/
- includes velocity saturation

### level_3/
- adds subthreshold conduction

### bsim/
- industry-standard compact model
