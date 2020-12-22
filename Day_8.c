#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int run(char* strInt[1000], int intInt[1000], int change, int end){
  bool infinite = false;
  int index = 0;
  int counter = 0;
  bool used[1000];
  for(int i = 0;i<1000;i++){
    used[i] = false;
  }
  while(!infinite &&index<end){
    used[index] = true;
    if((index != change && strcmp(strInt[index],"nop"))==0||(index==change && strcmp(strInt[index],"jmp")==0)){
      index++;
    } else if (strcmp(strInt[index],"acc")==0){
      counter=counter + intInt[index];
      index++;
    } else if (strcmp(strInt[index],"jmp")==0||(index==change && strcmp(strInt[index],"nop")==0)){
      index =index+ intInt[index];
    }
    infinite = used[index];
  }
  if(index >=end){
    printf("There was no infinite loop for %d\n", change);
    return counter;
  } else {
    return -1;
  }
}



int main(int arg, char** argv){
  char* strInt[1000];
  for(int i = 0;i<1000;i++){
    strInt[i] = malloc(3);
  }
  int intInt[1000];
  int total = 0;
  char line [100];
  while(fgets (line, 100, stdin)!=NULL && line[0]!='\n'){
    memcpy(strInt[total], line, 3);
    char rest[strlen(line)-6];
    int numlength = strlen(line)-6;
    memcpy(&rest, &line[5], numlength);
    int num = 0;
    for(int i = 0;i<numlength;i++){
      num += (rest[i]-'0')*(int)pow(10,numlength-i-1);
    }
    if(line[4] == '+'){
      intInt[total] = num;
    } else {
      intInt[total] = -num;
    }
    total++;
  }
  int acc = -1;
  int temp;
  for(int i = 0;i<total;i++){
    if(strcmp("jmp",strInt[i])==0||strcmp("nop",strInt[i])==0){
      temp = run(strInt, intInt, i, total);
      if(temp>0){
        acc = temp;
        printf("The value is %d\n", acc);
      }
    }
  }
}
