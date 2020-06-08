#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  /*
   * Thisfunction reverses the string passed to it.
   * This function doesn't return anything.
   * Modifies the string passed into it in place.
   */
  if( str != NULL ){
    int len = strlen(str);
    if (len != 0){
      char str1[len];
      strcpy(str1, str);
      for(int i = 0; i < len; i++) {
	str[i] = str1[len-i-1];
      }
    }
    else{
      str = "";
    }
  }  
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
