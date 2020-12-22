#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>


int main(int arg, char** argv){
  int ints[1001];
  bool full = false;
  int index = 0;
  bool first = true;
  int new;
  char line [100];
  bool possible;
  int target = 0;
  while(fgets (line, 100, stdin)!=NULL){
    if (index==25){
      full = true;
    }
    new = 0;
    for(int i = 0;i<strlen(line)-1; i++){
      new += (line[i]-'0')*pow(10, strlen(line)-2-i);
    }
    possible = false;
    if(full){
      for(int i = index-25; i<index;i++){
        for(int j = index-25;j<index;j++){
          if(first && ints[j]!=ints[i]&&ints[i]+ints[j]==new){
            possible = true;
          }
        }
      }
    }
    if(!possible && first&&full){
      first = false;
      printf("The first contradiction is %d\n", new);
      target = new;
    }
    ints[index] = new;
    index++;
  }
  int count = 0;
  int j;
  int start;
  int end;
  for(int i = 0;i<1001;i++){
    j = i+1;
    count = ints[i] + ints[j];
    j++;
    while(count<target&&j<1001){
      count += ints[j];
      j++;
      }
    if(count == target){
      start = i;
      end = j;
    }
  }
  int min = INT_MAX;
  int max = -1;
  for(int i =start;i<end+1;i++){
    if(ints[i]<min){
      min = ints[i];
    } if(ints[i]>max){
      max = ints[i];
    }
  }
  printf("Max + min = %d\n", min+max);
}
