#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
bool flip(char* lines[98], int height, int width){
  int count;
  int full;
  bool changed = false;
  char* temp[98];
  for(int i = 0;i<height;i++){
    temp[i] = malloc(sizeof(char)*width);
    for(int j = 0;j<width;j++){
      temp[i][j] = lines[i][j];
    }
  }
  for(int i = 0;i<height;i++){
    for(int j = 0;j<width;j++){
      full = 0;
      for(int r = -1;r<2;r++){
        for(int c = -1;c<2;c++){
          if((!(r==0 && c==0))&&(i+r)>=0&&(j+c)>=0&&(i+r)<height&&(j+c)<width&&temp[i+r][j+c]=='#'){
            full++;
          }
        }
      }
      if(temp[i][j] == 'L' && full == 0){
        lines[i][j]='#';
        changed = true;
      } else if(temp[i][j]=='#'&&full>=4){
        lines[i][j]='L';
        changed = true;
      }
    }
  }
  return changed;
}

int main(int arg, char** argv){
  char** lines;
  lines = malloc(98*sizeof(char*));
  char line[100];
  int counter =0;
  int width;
  while(fgets (line, 1000000, stdin)!=NULL){
    width = strlen(line)-1;
    lines[counter] = malloc(sizeof(char)*width);
    strcpy(lines[counter], strtok(line, "\n"));
    counter++;
  }
  bool changed = true;
  while(changed){
    changed = flip(lines, counter, width);
  }
  printf("\n");
  int count = 0;
  for(int i = 0;i<counter;i++){
    for(int j = 0;j<width;j++){
      printf("%c", lines[i][j]);
      if(lines[i][j]=='#'){
        count++;
      }
    }
    printf("\n");
  }
  printf("The count is %d, the counter is %d\n", count, counter);
}
