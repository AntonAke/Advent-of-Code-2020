#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

long long int comb(int* ints, int start, int end, long long int* combs, bool* filled){
  if(filled[start] ||start>end){
    return combs[start];
  } else {
    combs[start] = ints[start]*(comb(ints, start+1,end,combs,filled) + comb(ints, start+2,end,combs,filled) + comb(ints, start+3,end,combs,filled));
    filled[start]=true;
    return combs[start];
  }
}

int main(int arg, char** argv){
  int* ints ;
  ints = malloc(sizeof(int)*200);
  long long int* combs;
  combs = malloc(sizeof(long long int)*200);
  int new;
  bool filled[200];
  for(int i = 0;i<200; i++){
    ints[i] = 0;
    combs[i]=0;
    filled[i]=false;
  }
  int last = 0;
  char line[100];
  while(fgets (line, 100, stdin)!=NULL){
    new = 0;
    for(int i = 0;i<strlen(line)-1; i++){
      new += (line[i]-'0')*pow(10, strlen(line)-2-i);
    }
    ints[new]++;
    if(new)>last{
      last = new;
    }
  }
  ints[0] = 1;
  ints[last+3]=1;
  combs[last+3] = 1;
  filled[last+3]=true;
  printf("The number of possibilities is %lld", comb(ints, 0, last,combs,filled));

  /*
  int countone = 0;
  int countthree = 1;
  for(int i = 1;i<200;i++){
    if(ints[i]>0 && ints[i-1]>0){
      countone++;
    } if(ints[i]>0&&i>2&&ints[i-3]>0&&ints[i-2]==0&&ints[i-1]==0){
      countthree++;
    }
  }
  printf("%d\n",countone*countthree);*/
}
