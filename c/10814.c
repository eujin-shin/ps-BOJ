#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int age;
  char name[102];
} MEMBER;

int Cmp(const void *a, const void *b) {
  MEMBER one = *(MEMBER *)a, two = *(MEMBER *)b;
  if(one.age<two.age) {
    return -1;
  } else if(one.age>two.age) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  MEMBER *array;
  int n;
  scanf("%d", &n);
  array = (MEMBER *)malloc(sizeof(MEMBER)*n);
  for(int i=0; i<n; i++) {
    scanf("%d %s", &array[i].age, array[i].name);
  }
  qsort(array, n, sizeof(MEMBER), Cmp);
  for(int i=0; i<n; i++) {
    printf("%d %s\n", array[i].age, array[i].name);
  }
  return 0;
}