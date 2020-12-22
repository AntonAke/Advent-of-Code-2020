#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv){
  int valid = 0;
  int min;
  int max;
  char letter;
  char* password;
  password = calloc(100, sizeof(char));
  while(!feof(stdin)){
    scanf("%d-%d %c: %s\n", &min, &max, &letter, password);
    int count = 0;
    for(int i = 0; i<strlen(password); i++){
      if (password[i] == letter){
        count++;
      }
    }
    if((password[min-1]==letter) != (password[max-1]== letter)){
      valid++;
    }
  }
  printf("There are %d valid passwords\n", valid);
}
