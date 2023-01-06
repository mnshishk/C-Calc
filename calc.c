#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isinteger(char *str);
int parseint(char *str);

int main(int argc, char *argv[]) {
    if(argc == 2){
      if(isinteger(argv[1])){
        printf("%d\n", parseint(argv[1]));
      }
    }
    /*logic for 3 arguments which returns an int after proper operation*/
    else if(argc == 4){
       if(isinteger(argv[1]) && isinteger(argv[3])){
      	 if(strchr(argv[2], '+')){
      	   printf("%d\n", parseint(argv[1]) + parseint(argv[3]));
      	 }
      	 else if(strchr(argv[2], '-')){
      	   printf("%d\n", parseint(argv[1]) - parseint(argv[3]));
      	 }
      	 else if(strchr(argv[2], 'x')){
            printf("%d\n", parseint(argv[1]) * parseint(argv[3]));
      	 }
      	 else if(strchr(argv[2], '/')){
      	   if(strchr(argv[3], '0')){
      	     printf("Can not divide by zero!\n");
      	     return 1;
      	   }
      	   printf("%d\n", parseint(argv[1]) / parseint(argv[3]));
      	 }
        else {
      	  printf("%s is not a valid operator.\n", argv[2]);
      	  return 1;
      	}
      }
    }
    else{
      printf("No action can be performed, check your input.\n");
      return 1;
    }
    
    return 0;
}

bool isinteger(char *str){    
  int index = 0;
  if(str[0] == '-'){
    index = 1;
  }
  for(int i = index; str[i] != '\0'; i++){
    if(isdigit(str[i])){
      continue;
    }
    else{
      printf("%s is not a proper input.\n", str); 
      return false;
    }
  }
  return true;
}

int parseint(char *str)
{   
    int number = 0;
    int negative = 1;
    int parsed_number = 0;
    int index = 0;
	
    if(str[0] == '-'){
      negative = -1;
      index = 1; 
    }

    for(int i = index; str[i] != '\0'; i++){
     number = str[i] - '0';
     parsed_number *= 10;
     parsed_number += number;
    }
    return parsed_number * negative;
}
