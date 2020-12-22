#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int main(int arg, char** argv){
  bool answers[26];
  for(int i = 0; i<26; i++){
    answers[i]=true;
  }
  int sum = 0;
  char line[50];
  bool personal[26];
  while(fgets (line, 100, stdin)!=NULL){
    if(line[0]=='\n'){
      for(int i = 0; i<26; i++){
        if(answers[i]){
          sum++;
        } else {
          answers[i]=true;
        }
      }
    } else {
      for(int i = 0; i<26; i++){
        personal[i]=false;
      }
      for(int i=0;i<strlen(line)-1;i++){
        personal[(int)line[i]-(int)'a'] = true;
      }
      for(int i=0;i<26;i++){
        answers[i] = answers[i]&&personal[i];
      }
    }
  }
  printf("The sum is %d", sum);
}
