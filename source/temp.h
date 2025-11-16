#include <cmath>
#include <algorithm> // For std::max/min if needed

// Structure to hold the model's calculated outputs
struct ModelOutput {
    double ID;  // Drain Current
    double Gm;  // Transconductance: dID/dVGS
    double Gds; // Output Conductance: dID/dVDS
};

class MosfetModel {
private:
    // Core parameters (simplified set)
    const double VTH;   // Threshold Voltage
    const double K;     // Transconductance Parameter: (uCox * W/L)

public:
    // Constructor: Initialize the device with its process/geometry parameters
    MosfetModel(double vth, double uCox_WL) : VTH(vth), K(uCox_WL) {}

    // Main function: Calculates Current and Conductances
    ModelOutput calculate(double Vgs, double Vds);
};
