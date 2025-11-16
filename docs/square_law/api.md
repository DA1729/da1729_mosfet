# api documentation

## mosfet_output

output structure containing calculated device characteristics

### members

```cpp
double i_d;    // drain current (a)
double g_m;    // transconductance (a/v)
double g_ds;   // output conductance (a/v)
```

## mosfet_model

square-law mosfet model class

### constructor

```cpp
mosfet_model(double v_th, double k)
```

parameters:
- `v_th`: threshold voltage (v)
- `k`: process transconductance parameter μ × c_ox × w/l (a/v²)

### methods

```cpp
mosfet_output calculate(double v_gs, double v_ds)
```

calculates drain current and small-signal parameters for given bias conditions

parameters:
- `v_gs`: gate-source voltage (v)
- `v_ds`: drain-source voltage (v)

returns:
- `mosfet_output` structure containing i_d, g_m, g_ds

## usage example

```cpp
#include "models/square_law/mos_model.h"

double v_th = 0.5;  // threshold voltage
double k = 1e-3;    // process parameter

mosfet_model nmos(v_th, k);

double v_gs = 1.0;
double v_ds = 1.5;

mosfet_output out = nmos.calculate(v_gs, v_ds);

// access results
double drain_current = out.i_d;
double transconductance = out.g_m;
double output_conductance = out.g_ds;
```

## region determination

the model automatically determines operating region:
- cutoff: v_gs ≤ v_th
- triode: v_gs > v_th and v_ds < (v_gs - v_th)
- saturation: v_gs > v_th and v_ds ≥ (v_gs - v_th)
