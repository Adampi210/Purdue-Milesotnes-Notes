#include <stdio.h>
#include <math.h>
#include "circuit_design_useful_functions.h"

// This function shows possible capacitor values for different resistances that result in a desired cutoff frequency
// Also the answer is shown with desired units as specified by c_order_specifier
void show_possible_capacitor_values(double cutoff_freq, char c_order_specifier)
{
    double capacitance;   // Declare capacitance
    long value_to_divide; // Declare value to scale the units by (ex 10e6 = uF units, 10e9 = nF, 10e12 = pf)

    // Depending on the c order specifier, set different scale to value_to_divide
    switch (c_order_specifier)
    {
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
        value_to_divide = 1e9;  // set n by default
        c_order_specifier = 'n'; // set the specifier to n by default
        break;
    }
    // Declare an array of possible resistance values
    const double resistor_values[] = {10, 22, 47, 100, 220, 470, 1000, 2200, 4700, 10000, 22000, 47000, 100000, 220000, 470000, 1000000, 0};
    int i = 0; // Initialize loop i variable to 0, and go through all resistance values
    while (resistor_values[i] != 0)
    {
        // For a given resistance, calculate the corresponding capacitance and print it to the user
        capacitance = value_to_divide / (2 * M_PI * resistor_values[i] * cutoff_freq);
        printf("For resitance: %.0lf Ohm, capacitance should be: %lf%cF\n", resistor_values[i], capacitance, c_order_specifier);
        ++i;
    }
}

// This function prints out possible R_f and R_in resistor combinations that result in a specified gain
// Gain is calculated as a ratio of output to input
void print_possible_feedback_resistor_vals(double input_voltage, double output_voltage)
{
    double gain = output_voltage / input_voltage; // Declare and initialize gain as ratio of output to input
    double R_f;                                   // Declare R_f - value corresponding to the feedback resistor
    // Declare array of possible resistor values (in Ohmes)
    const double resistor_values[] = {10, 22, 47, 100, 220, 470, 1000, 2200, 4700, 10000, 22000, 47000, 100000, 220000, 470000, 1000000, 0};
    int i = 0; // Initialize loop variable i to 0
    // Go through all the resistor values for R_in
    while (resistor_values[i] != 0)
    {
        R_f = -1 * gain * resistor_values[i]; // For every R_in calculate R_f value
        printf("For given R_in = %.0lf Ohm, the R_f value should be R_f = %.0lf Ohm\n", resistor_values[i], R_f);
        ++i;
    }
}

// This function returns the output of an inverting amplifier circuit given input voltage, R_in, and R_f
double find_output_inverting_op_amp(double input_value, double R_in, double R_f)
{
    double output_value;                            // Declare output variable
    output_value = -1 * (R_f / R_in) * input_value; // calculate output value using the formula
    printf("Output voltage: %lfV\n", output_value); // Print the output value in Ohms
    return output_value;
}
