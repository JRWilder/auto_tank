///////////////////////// ADC /////////////////////////
extern unsigned int channel;//Used to select between the ADC channels of thumb wheel, left detector, and right detector.
extern volatile unsigned int v_thumb;//Used to store the value the ADC reads from the thumb wheel.
extern volatile unsigned int v_detect_left;//Used to store the value the ADC reads from the left detector.
extern volatile unsigned int v_detect_right;//Used to store the value the ADC reads from the right detector.
