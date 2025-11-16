# da1729_mosfet

advanced mosfet modeling project - incrementally building complexity for accurate device simulation

## project structure

```
models/        - complete mosfet model implementations
effects/       - isolated physical effect implementations
parameters/    - parameter extraction and technology files
analysis/      - iv curve generation and characteristic analysis
validation/    - tests and benchmarks
examples/      - usage demonstrations
utils/         - shared utilities and helpers
docs/          - theory, derivations, and documentation
```

## current implementation

### basic square-law model

- implements fundamental long-channel mosfet behavior
- models three regions of operation: cutoff, triode, and saturation
- calculates drain current and small-signal parameters

#### equations

drain current:
- cutoff (v_ov ≤ 0): i_d = 0
- triode (v_ds < v_ds_sat): i_d = k(v_ov × v_ds - 0.5 × v_ds²)
- saturation (v_ds ≥ v_ds_sat): i_d = k(v_ov × v_ov - 0.5 × v_ov²) = 0.5 × k × v_ov²

where:
- v_ov = max(0, v_gs - v_th) (overdrive voltage)
- v_ds_sat = v_ov (saturation voltage)
- k = μ × c_ox × w/l (process transconductance parameter)
- v_th = threshold voltage

transconductance (g_m = ∂i_d/∂v_gs):
- cutoff: g_m = 0
- triode: g_m = k × v_ds
- saturation: g_m = k × v_ov

output conductance (g_ds = ∂i_d/∂v_ds):
- cutoff: g_ds = 0
- triode: g_ds = k × (v_ov - v_ds)
- saturation: g_ds = 0

### implementation details

- location: `models/square_law/mos_model.h`, `models/square_law/mos_model.cpp`
- `mosfet_model` class with parameters v_th and k
- `mosfet_output` struct containing i_d, g_m, g_ds
- smooth transitions between operating regions using std::min/max

## progress log

### iteration 1: basic square-law model
- initial implementation of ideal long-channel mosfet
- square-law i-v characteristics
- small-signal parameters for ac analysis
- no channel-length modulation, subthreshold conduction, or velocity saturation yet
