#ifndef __CIRCUIT_DESIGN_USEFUL_FUNCTIONS_H__
#define __CIRCUIT_DESIGN_USEFUL_FUNCTIONS_H__

void show_possible_capacitor_values(double cutoff_freq, char c_order_specifier);
void print_possible_feedback_resistor_vals(double input_voltage, double output_voltage);
double find_output_inverting_op_amp(double input_value, double R_in, double R_f);

#endif