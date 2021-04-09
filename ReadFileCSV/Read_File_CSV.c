#include "Read_File_CSV.h"

/**
  * @brief  This function reads data from a .csv file.
  * @param  char * namefile: Indicates the name of the .csv file to read.
  * @param  dict_float values_float[]: indicates an array of structures where we want to save the read files, this must be initialized in "main". 
  * @param  char * data_separator: indicates the symbol that separates the various data in the file, in our case it is ";".
  * @function atof: The C library function double atof(const char * str) converts the string argument str to a floating-point number (type double).
  * @retval uint8_t row_count: number of row read in the file.
*/

uint8_t read_from_csv_file(char * namefile, dict_float values_float[], char * data_separator){

  char buff[MAX_FLOAT_NUMBER];
  uint8_t row_count = 0;
  uint8_t field_count = 0;
  uint8_t array_size = 0;
  
  FILE *fp = fopen(namefile, "r");
  if(!fp){
    printf("File open error\n");
    fclose(fp);
    exit(1);
    }

  /*
  The C library function char *fgets(char *str, int n, FILE *stream) reads a line from the specified stream and stores it into the string pointed to by str. It stops when either (n-1) characters are read, the newline character is read, or the end-of-file is reached, whichever comes first.
  */

  while(fgets(buff, MAX_FLOAT_NUMBER, fp)){
    field_count = 0;
    row_count++;
    
    /*
    The C library function char *strtok(char *str, const char *delim) breaks string str into a series of tokens using the delimiter delim.

    This function returns a pointer to the first token found in the string. A null pointer is returned if there are no tokens left to retrieve.
    */
    char * field = strtok(buff, data_separator);

    while(field){
      if(field_count == 0){
        values_float[array_size].first_parameter_float = atof (field);
      }
      if(field_count == 1){
        values_float[array_size].second_parameter_float = atof (field);
      }
      field = strtok(NULL, ";");
      field_count ++;
    }
    array_size++;
  }
  fclose(fp);
  return row_count;
}

void printValueFloat(uint8_t num, dict_float values_float[]){
  for(uint8_t i = 0; i< num; i++){
    printf("%d: f -> %.2f, s -> %.5f\n", i, values_float[i].first_parameter_float, values_float[i].second_parameter_float);
  }
}