#include <stdio.h>

int PrintSet(int num_set[]) {
  int check = 1;
  for(int i=0; i<5; i++) {
    printf("%d ", num_set[i]);
    if(num_set[i]!=i+1) {
      check = 0;
    }
  }
  printf("\n");
  return check;
}

int main() {
  int num_set[5] = {0, };
  for(int i=0; i<5; i++) {
    scanf("%d", &num_set[i]);
  }
  int check, temp, index = 0;
  do {
    if(num_set[index]>num_set[index+1]) {
      temp = num_set[index];
      num_set[index] = num_set[index+1];
      num_set[index+1] = temp;
      check = PrintSet(num_set); 
    }
    index++;
    if(index>3) {
      index-=4;
    }
  } while(!check);
  return 0;
}