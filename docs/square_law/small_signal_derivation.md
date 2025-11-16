# small-signal parameter derivation

## transconductance (g_m)

definition:
```
g_m = ∂i_d/∂v_gs |_(v_ds constant)
```

### cutoff region

```
i_d = 0
g_m = 0
```

### triode region

```
i_d = k × (v_ov × v_ds - 0.5 × v_ds²)

∂i_d/∂v_gs = k × v_ds × ∂v_ov/∂v_gs
           = k × v_ds × 1
           = k × v_ds

g_m = k × v_ds
```

### saturation region

```
i_d = 0.5 × k × v_ov²

∂i_d/∂v_gs = 0.5 × k × 2 × v_ov × ∂v_ov/∂v_gs
           = k × v_ov × 1
           = k × v_ov

g_m = k × v_ov
```

## output conductance (g_ds)

definition:
```
g_ds = ∂i_d/∂v_ds |_(v_gs constant)
```

### cutoff region

```
i_d = 0
g_ds = 0
```

### triode region

```
i_d = k × (v_ov × v_ds - 0.5 × v_ds²)

∂i_d/∂v_ds = k × (v_ov - v_ds)

g_ds = k × (v_ov - v_ds)
```

### saturation region

ideal long-channel model assumes current independent of v_ds in saturation:
```
i_d = 0.5 × k × v_ov²

g_ds = 0
```

note: real devices exhibit finite g_ds in saturation due to channel-length modulation

## important relations

### saturation region

```
g_m = k × v_ov = √(2 × k × i_d)

g_m/i_d = 2/v_ov
```

### transition from triode to saturation

at v_ds = v_ds_sat = v_ov:
```
g_ds_triode = k × (v_ov - v_ov) = 0
```

smooth transition to saturation where g_ds = 0
