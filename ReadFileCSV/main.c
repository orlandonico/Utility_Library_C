#include "Read_File_CSV.h"

int main(void) {
  
  uint8_t array_size;
  dict_float values_float[MAX_SIZE];
  char sepatatore[] = ";" ;
  
  array_size = read_from_csv_file("CH4.csv",values_float,";");

  printf("\nPrint read values\n");
  printValueFloat(array_size, values_float);
  printf("\n");
  

  return 0;
}