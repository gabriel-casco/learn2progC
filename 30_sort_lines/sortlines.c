#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void print_arrayOfString(char **Array, size_t lenght){
  assert(lenght>0);
  for(int i=0; i<lenght; i++){
    fprintf(stdout, "%s\n", Array[i]);
  }
}

int final_part(char ** Array_string, size_t lenght, int argc, FILE *f){
  if(argc != 1){
    if(lenght > 0){
      print_arrayOfString(Array_string, lenght);
      for(int i=0; i< lenght; i++){
	free(Array_string[i]);
      }
      free(Array_string);
      if(fclose(f)!=0){
	fprintf(stderr, " failed to close the file\n");
	return EXIT_FAILURE;
      }
      return EXIT_SUCCESS;
    }
    else{
      fprintf(stderr, "ERROR! your file was empty\n");
      if(fclose(f)!=0){
	fprintf(stderr, " failed to close the file\n");
	return EXIT_FAILURE;
      }
      return EXIT_FAILURE;
    }
  }
  else{
    if(lenght > 0){
      print_arrayOfString(Array_string, lenght);
      for(int i=0; i<lenght; i++){
	free(Array_string[i]);
      }
      free(Array_string);
      return EXIT_SUCCESS;
    }
    else{
      fprintf(stderr, "ERROR! your file was empty\n");
      return EXIT_FAILURE;
    }
  }
}

int main(int argc, char ** argv) {
  if(argc == 1){
    // fprintf(stdout, "Please enter the lines of your text\n");
    char **Array_string= NULL;
    char *line=NULL;
    size_t size=0;
    int i=0;
    while(getline(&line, &size, stdin)>=0){
      Array_string= realloc(Array_string, (i+1)*sizeof(*Array_string));
      Array_string[i] = line;
      line = NULL;
      i++;
    }
    free(line);
    if(Array_string[0]==NULL){
      fprintf(stderr, " your did not type anything\n");
      return EXIT_FAILURE;
    }
    sortData(Array_string, i);
    FILE *f = NULL;
    return final_part(Array_string, i, argc, f);
  }
  else{
    for(int j=1; j<argc; j++){
      char **Array_string= NULL;
      FILE *f = fopen(argv[j], "r");
      if(f == NULL){
	perror("could not open the file\n");
	return EXIT_FAILURE;
      }
      char *line =NULL;
      size_t x, count =0;
      ssize_t len_line=0;
      while((len_line=getline(&line, &x, f))>=0){
	Array_string = realloc(Array_string, (count+1)*sizeof(*Array_string));
	Array_string[count]=line;
	count++;
	line =NULL;
      }
      free(line);
      sortData(Array_string, count);
      if( final_part(Array_string, count, argc, f)==EXIT_FAILURE){
	return EXIT_FAILURE;
      }
    }
  }
  return EXIT_SUCCESS;
}
