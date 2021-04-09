/*
* Include Library
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

/*
* Define
*/

/*
This is the maximum number of characters to be read (including the final null-character). Usually, the length of the array passed as str is used.
*/
#define MAX_FLOAT_NUMBER 17 

/*
Maximum size of structure arrays
*/
#define MAX_SIZE 50

/*
* Definition of Structures
*/

typedef struct float_Read{
  float first_parameter_float;
  float second_parameter_float;
} dict_float;

/*
* Definition of Enum
*/


/*
* Function declarations
*/

uint8_t read_from_csv_file(char * namefile, dict_float values_float[], char * data_separator);

void printValueFloat(uint8_t num, dict_float values_float[]);
