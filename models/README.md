# models

complete mosfet model implementations combining multiple physical effects

## current models

### square_law (mos_model.h, mos_model.cpp)
- basic long-channel model
- three regions: cutoff, triode, saturation
- ideal behavior without short-channel effects

## planned models

- level-1: square-law with channel-length modulation and body effect
- level-2: includes velocity saturation
- level-3: adds subthreshold conduction
- bsim: industry-standard compact model
