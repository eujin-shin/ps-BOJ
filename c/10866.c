#include <stdio.h>
#include <string.h>

int deque[20002] = {0, };
int max, min, n;

int empty() {
  int ans;
  if(max-min==1) {
    ans = 1;
  } else {
    ans = 0;
  }
  return ans;
}

void push_front(int n) {
  deque[min] = n;
  min--;
}

void push_back(int n) {
  deque[max] = n;
  max++;
}

void pop_front() {
  if(empty()==1) {
    printf("-1\n");
  } else {
    min++;
    printf("%d\n", deque[min]);
  }
} 

void pop_back() {
  if(empty()==1) {
    printf("-1\n");
  } else {
    max--;
    printf("%d\n", deque[max]);
  }
}

void size() {
  printf("%d\n", max-min-1);
}

void front() {
  if(empty()==1) {
    printf("-1\n");
  } else {
    printf("%d\n", deque[min+1]);
  }
}

void back() {
  if(empty()==1) {
    printf("-1\n");
  } else {
    printf("%d\n", deque[max-1]);
  }
}
 
int main() {
  max = 10000;
  min = 9999;
  int count;
  char order[12];
  scanf("%d", &count);
  for(int i=0; i<count; i++) {
    scanf("%s", order);
    if(!strcmp(order, "push_front")) {
      scanf("%d", &n);
      push_front(n);
    } else if(!strcmp(order, "push_back")) {
      scanf("%d", &n);
      push_back(n);
    } else if(!strcmp(order, "pop_front")) {
      pop_front();
    } else if(!strcmp(order, "pop_back")) {
      pop_back();
    } else if(!strcmp(order, "size")) {
      size();
    } else if(!strcmp(order, "empty")) {
      printf("%d\n", empty());
    } else if(!strcmp(order, "front")) {
      front();
    } else if(!strcmp(order, "back")) {
      back();
    }
  }
  return 0;
}