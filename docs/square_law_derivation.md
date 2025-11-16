# square-law model derivation

## basic assumptions

- long-channel device (l >> λ)
- gradual channel approximation
- constant mobility
- uniform doping
- no velocity saturation

## triode region (v_ds < v_ds_sat)

channel charge per unit area:
```
q_n(x) = -c_ox × (v_gs - v_th - v(x))
```

drain current (constant along channel):
```
i_d = w × μ × q_n(x) × e(x)
    = w × μ × c_ox × (v_gs - v_th - v(x)) × dv/dx
```

integrate from source (x=0, v=0) to drain (x=l, v=v_ds):
```
i_d × ∫₀ˡ dx = w × μ × c_ox × ∫₀^v_ds (v_gs - v_th - v) dv

i_d × l = w × μ × c_ox × [(v_gs - v_th) × v_ds - v_ds²/2]
```

solve for i_d:
```
i_d = (μ × c_ox × w/l) × [(v_gs - v_th) × v_ds - v_ds²/2]
    = k × (v_ov × v_ds - 0.5 × v_ds²)
```

where:
- v_ov = v_gs - v_th (overdrive voltage)
- k = μ × c_ox × w/l

## saturation region (v_ds ≥ v_ds_sat)

saturation occurs when channel pinches off at drain:
```
v_ds_sat = v_ov
```

current saturates at:
```
i_d = k × (v_ov × v_ds_sat - 0.5 × v_ds_sat²)
    = k × (v_ov² - 0.5 × v_ov²)
    = 0.5 × k × v_ov²
```

## cutoff region (v_gs ≤ v_th)

no inversion channel exists:
```
i_d = 0
```

## region boundaries

- cutoff: v_gs ≤ v_th
- triode: v_gs > v_th and v_ds < v_ov
- saturation: v_gs > v_th and v_ds ≥ v_ov
