# analysis

tools for analyzing mosfet characteristics and generating plots

each model has its own subdirectory with analysis tools

## square_law/

analysis tools for the square-law model:
- `iv_curves.cpp` - generate i_d vs v_ds for multiple v_gs values
- `transfer_characteristics.cpp` - i_d vs v_gs for multiple v_ds values
- `gm_vs_vgs.cpp` - transconductance vs gate voltage
- `operating_point.cpp` - detailed operating point analysis with region detection

## planned subdirectories

additional analysis tools will be added as new models are implemented
