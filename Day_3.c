#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv){
  char* row;
  row = calloc(500, sizeof(char));
  int x = 0;
  scanf("%s",row);
  int treelist[5] = {0,0,0,0,0};
  int xlist[5] = {0, 0, 0, 0, 0};
  int y = 0;
  while(!feof(stdin)){
    y++;
    scanf("%s",row);
    for(int i = 0; i<4;i++){
      xlist[i]+=(2*i+1);
      if(row[xlist[i]%strlen(row)]=='#'){
        treelist[i]++;
      }
    }
    if(y%2 == 0){
      xlist[4]++;
      if(row[xlist[4]%strlen(row)]=='#'){
        treelist[4]++;
      }
    }
  }
  long prod = 1;
  for(int i = 0;i<5;i++){
    prod*=treelist[i];
  }
  printf("You encountered %ld trees", prod);
}
