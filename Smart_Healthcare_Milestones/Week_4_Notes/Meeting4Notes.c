/*
    How to make a BME instrument:
        - Sensor + Transducer
        - Pre-Amplifier
        - Signal-Conditioning Stage
        - Digital Measurement

    Sensor + Transducer:
        - Sensor - element that measures physical property
        - Transducer - element that converts one form of energy to another
        - We use them to have a way to obtain real world data
        - We will use photodiode which converts light to electric current

    Pre-Amplifier:
        - most closely associated with the sensor/transducer pair
        - it interacts with the signal prior to being filtered
        - Mostly acts as a voltage buffer or an instrumentation amplifier (INA)

        - Voltage buffer/follower:
            - Voltage Buffer - an amplifier that results in unity gain
            - Prevents one part of the circuit from loading onto the other
            - Vout = - Vin
            - Loading = drawing current away from
        - Instrumentation amplifier:
            - Essentially a differential amplifier that can have a really high gain
            - Finds voltage difference between two points
            - Vout = (Vin+ - Vin-) * Gain
            - Gain depends on the INA chip used
            - We'll use AD623 which is a single chip
            - Gain = 1 + 200k / Rg
            - Can set the gain using a single resistor
    
    Digital Measurement:
        - Arduino UNO microcontroller
        - Just used to to read and view our signal
        - Note: Arduino can only take 5V and GND, it CANNOT handle negative voltages
        - Fix -> use a voltage divider to offset our signal
        
        - Voltage dividers - splits up the voltage between 2 resistors
        - Use voltage dividers to change reference (GND) voltage for our circuit 
            (We shift it up -> from -1 to 1 to 0 to 2)
        - Also use voltage follower to make sure the divider doesn't load the circuit

    Time to put everything together:
        - For this workshop we can make a PPG or EXG:
        - PPG: photoplethysmogram
            - Photo -> light
            - Plethysmography -> volume measurement
            - Heart pumps blood and the volume of blood coursing through the vessels varies periodically
            - Able to correlate heart activity and the light passing through
            - volume of blood in the vessel vs amount of received light
            - this results in figures that reflect heartbeats
            - Transmittance (Pulse Ox) Reflectance (Smartwatch)
    
        - EXG: biopotential measurements:
            - differential measurements
            - measuring the potential between two parts of your body

            - Components of EXG:
                - Sensor/Transducer: Electrodes
                - Pre-Amp - Instrumentation Amplifier
                - We differentiate the kind of EXG by the location of the electrodes and the freq range we're interested in:
                    - ECG: 0.5Hz - 30Hz
                    - EMG: 80Hz - 1kHz
                    - EOG: 0.5Hz - 10Hz

    Me: EMG
*/       