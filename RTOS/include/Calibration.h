///////////////////////// Calibrate Operation /////////////////////////
#define SUBTRACT_VALUE						(0x32)//Used to subtract 50 from the average reading of the detectors to account for slight variences.
extern unsigned int left_white_value;//Used to store the average value read from the left detector off of the black tape.
extern unsigned int right_white_value;//Used to store the average value read from the right detector off of the black tape.
extern unsigned int left_black_value;//Used to store the average value read from the left detector on the black tape.
extern unsigned int right_black_value;//Used to store the average value read from the right detector on the black tape.
extern unsigned int read_count;//Used to keep track of how many readings are taken from the detectors.
