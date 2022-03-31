#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGHT 1024

/*Enumerator (set of constants that are predefined)
  Using are written in CAPS
*/
typedef enum{
  ERROR_SUCCESS = 0,
  ERROR_OPEN,
  ERROR_ARGS,
  ERROR_READ,
  ERROR_WRITE
} error_t;

int main(int argc, char *argv[]){
  if(argc != 2){
    //fprintf is printed to print only the files
    fprintf(stderr, "I need 2 arguments!\n");
    return ERROR_ARGS;
  }

  char *filename = argv[1];
  fprintf(stdout, "My filename is: %s\n", filename);

  //Start reading our file
  {
    FILE *f = fopen(filename, "w"); //READ OPTION r, if we put "w" it creates a file with this name!
    // if(f == NULL){
    //   fprintf(stderr, "I cannot open the file!\n");
    //   return ERROR_OPEN;
    // }

    fprintf(f, "I'm a line\n");
    fprintf(f, "I'm another line\n");
    fprintf(f, "I'm a number: %8.3f\n", 20.0f);

    fclose(f);
  
  }

  //To print the content of each line
  {
    FILE *f = fopen(filename, "r");
    char buffer[MAX_LINE_LENGHT];

    while(fgets(buffer, MAX_LINE_LENGHT, f)){
      fprintf(stdout, "%s", buffer);
    }
  }


}