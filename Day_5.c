#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
int main(int arg, char** argv){
  char line[10000];
  int row;
  int col;
  int max = 0;
  int seat = 0;
  bool taken[1000];
  for(int i = 0;i<1000;i++){
    taken[i] = false;
  }
  while(fgets (line, 10000, stdin)!=NULL){
    row = 0;
    col = 0;
    for(int i=0; i<10; i++){
      if(line[i] == 'B'){
        row += round(pow(2.0,(double)(6-i)));
      } else if(line[i]=='R'){
        col+= round(pow(2.0, (double)(9-i)));
      }
    }
    seat=8*row+col;
    if(seat>max){
      max = seat;
      printf("%d%s",max, line);
    }
    taken[seat] = true;
  }

  for(int i=max-1;i>0;i--){
    if(!taken[i]){
      printf("The free seat is %d\n", i);
      break;
    }
  }
  printf("The highest seat ID is %d\n", max);
}
