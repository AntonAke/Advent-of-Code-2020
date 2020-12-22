#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int main(int arg, char** argv){
  char passport[1000];
  char* desired[10] = {"byr:(19[2-9][0-0]|200[0-2])]", "iyr:(20(1[0-9]|20))", "eyr:(20(2[0-9]|30))", "hgt:()", "hcl", "ecl", "pid"};

  int counter;
  int valid = 0;
  char line[100];
  boolean ok = true;
  while(fgets (line, 100, stdin)!=NULL){
    if(strcmp(line, "\n")==0){
      if(counter == 7){
        printf("%s %d\n", "valid", valid);
        valid++;
      }
      counter = 0;
      containsCID = false;
      ok = true;

    }
    for(int i = 0; i<7; i++){
      if(strstr(line, desired[i])!=NULL){
        counter++;
        if(i==0){
          containsCID = true;
        }
      }
    }
  }
  printf("The number of valid passports is %d\n", valid);
}
