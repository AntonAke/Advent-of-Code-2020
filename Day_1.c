#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv){
    int* nums;
    nums = calloc(10000, sizeof(int));
    int num;
    int count = 0;
    while(!feof(stdin)){
      scanf("%d\n", &num);
      nums[count] = num;
      count++;
    }
    count--;
    for(int i = 0; i<count;i++){
      for(int j = 0; j<count;j++){
        for(int k = 0;k<count;k++){
          if(nums[i] + nums[j] + nums[k] == 2020){
            printf("The answer is %d\n", nums[i]*nums[j]*nums[k]);
          }
        }
      }
    }
}
