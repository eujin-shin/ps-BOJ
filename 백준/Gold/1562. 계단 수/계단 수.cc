#include <iostream>
#define MOD 1000000000
#define MASK 1024
#define NUMBER 10
using namespace std;

int prevCounts[11][2000] = {0, }, curCounts[11][2000] = {0, };

void reset();
void setCurCount(int x);
void addCurCount(int x, int k);

int main() {
  int n;
  cin>>n;

  for(int x = 1, index = 2; x < NUMBER; x++, index <<= 1) {
    prevCounts[x][index] = 1;
  }

  for(int i = 2; i <= n; i++) {
    for(int x = 0; x < NUMBER; x++) {
      setCurCount(x);
    }
    reset();
  }

  int sum = 0;
  for(int x = 0; x < NUMBER; x++) {
    sum = (sum + prevCounts[x][MASK - 1]) % MOD;
  }
  cout<<sum<<'\n';
  return 0;
}

void reset() {
  for(int x = 0; x < NUMBER; x++) {
    for(int index = 1; index < MASK; index++) {
      prevCounts[x][index] = curCounts[x][index];
      curCounts[x][index] = 0;
    }
  }
  return;
}

void setCurCount(int x) {
  if(x - 1 >= 0) {
    addCurCount(x, x - 1);
  }
  if(x + 1 < NUMBER) {
    addCurCount(x, x + 1);
  }
  return;
}

void addCurCount(int x, int k) {
  int target;
  for(int index = 1; index < MASK; index++) {
    target = index | (1 << x);
    curCounts[x][target] = (curCounts[x][target] + prevCounts[k][index]) % MOD;
  }
  return;
}