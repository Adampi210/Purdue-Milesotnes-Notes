#include <stdio.h>
#include <math.h>

/*
    Why do we need Biomedical Instrumentation?
        - Biosignals usually very small (mV to uV)
        - Oftern a lot of noise larger than the actual signals
    Biosignals have both AC and DC components:
        - We can represent any sginal as a sum of sine waves with varying frequencies
        - Each sine cintains different information about the signal
        - Information of signal depends on the frequencies of interest
    Key Idea:
        - Design circuits that can isolate frequencies of interest and amplify these small signals
    ECG example:
        - ECG has a frequency range of 0.1 to 250Hz
        - The rest of the other frequencies are noise
        - Noise: unwanted disturbance
            - caused by many many things -> we have to account for noise
            - To reduce noise we use FILTERS
            - Filters - components that pass or bloc signals of certain frequencies
                - Passing signals -> unaffected
                - Blocking signals -> attenuated (blocked, magnitude greately reduced)
            - Filters depend on resistors and capacitors -> cutoff frequency
                - passive filters require no power to function - rely only on RC properties
                - For this week - just passive 1st order low pass filter - R and C in series
                - Bode plot - gain vs freq plot
                - Gain = 20 * log(Vout / Vin)
                - Frequency formula f_c = 1 / (2 * PI * R * C) - set one value of R and calculate C (or another way around)
                - f_c is the same for high pass and low pass equations (but the order matters)
    LTSpice:
        - Simulation command: .ac dec 100 start_freq end_freq
            - start frequency should be 100x less than cutoff frequency
            - end frequency should always be 100x more than cutoff requency
*/

// This function shows possible capacitor values for different resistances that result in a desired cutoff frequency
// Also the answer is shown with desired units as specified by c_order_specifier 
void show_possible_capacitor_values(double cutoff_freq, char c_order_specifier) {
    double capacitance;   // Declare capacitance
    long value_to_divide; // Declare value to scale the units by (ex 10e6 = uF units, 10e9 = nF, 10e12 = pf)

    // Depending on the c order specifier, set different scale to value_to_divide
    switch (c_order_specifier) {
    case 'u':
        value_to_divide = 1e6; // if its u, set 10e6
        break;
    case 'n':
        value_to_divide = 1e9; // if its n, set 10e9
        break;
    case 'p':
        value_to_divide = 1e12; // if its p, set 10e12
        break;
    default:
        value_to_divide = 1e9; // set n by default
        c_order_specifier = 'n'; // set the specifier to n by default
        break;
    }
    // Declare an array of possible resistance values
    const double resistor_values[] = {10, 22, 47, 100, 220, 470, 1000, 2200, 4700, 10000, 22000, 47000, 100000, 220000, 470000, 1000000, 0};
    int i = 0; // Initialize loop i variable to 0, and go through all resistance values
    while(resistor_values[i] != 0) {
        // For a given resistance, calculate the corresponding capacitance and print it to the user
        capacitance = value_to_divide / (2 * M_PI * resistor_values[i] * cutoff_freq);
        printf("For resitance: %.0lf Ohm, capacitance should be: %lf%cF\n", resistor_values[i], capacitance, c_order_specifier);
        ++i;
    }
}

int main(int argc, char const *argv[])
{
    show_possible_capacitor_values(1000, 'n'); // Print possible capacitances for 1000Hz cutoff freq in nF
    return 0;
}
