#include <stdio.h>
#include <math.h>

/*
 * Cascading amplifiers:
 *      - output of one amplifier goes the input of the next one
 *      - gains multiply (10X * 10X = 100)
 *      - decibel gains add: -20 db + -20db = 40db
 * 
 * Active filter: filter that needs power to run:
 *      - simultaneous filtering and amplification
 * Active filter amplifier:
 *      - -3dB point is relative to the pass band - there is a new gain
 * 
 * Active band pass filter:
 *      - cascaded active low pass and active high pass filter - one option
 *      - second option - combine both in one:
 *          - Fc_high_pass = 1 / (2 * PI * R_in * C_in)
 *          - Fc_high_pass = 1 / (2 * PI * Rf * C_f)
 */

double find_capacitor_value(double, char, double);

int main(int argc, char const *argv[]) {
    
    find_capacitor_value(500, 'n', 22000);
    return 0;
}

double find_capacitor_value(double cutoff_freq, char c_order_specifier, double resistor_val) {
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

    capacitance = value_to_divide / (2 * M_PI * cutoff_freq * resistor_val);
    printf("Capacitance value for a %.0lf Ohm resistor and %.1lf Hz cutoff frequency: %lf%cF\n", resistor_val, cutoff_freq, capacitance, c_order_specifier);
    return capacitance;
}