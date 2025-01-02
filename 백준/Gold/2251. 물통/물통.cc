#include <iostream>
using namespace std;

int visited[201][201][201] = {0, }, answer[201] = {0, };
int bottles[3] = {0, };

int getAmount(int targetSize, int cur, int target) {
  int amount = cur;
  if(targetSize - target < cur) {
    amount = targetSize - target;
  }
  return amount;
}

void change(int x, int y, int z) {
  if(visited[x][y][z] == 1) {
    return;
  }
  if(x == 0) {
    answer[z] = 1;
  }
  visited[x][y][z] = 1;

  int currents[3] = {x, y, z}, amount;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(i == j) {
        continue;
      }  
      amount = getAmount(bottles[j], currents[i], currents[j]);
      currents[i] -= amount;
      currents[j] += amount;

      change(currents[0], currents[1], currents[2]);

      currents[i] += amount;
      currents[j] -= amount; 
    }
  }
  return;
}

int main() {
  for(int i = 0; i < 3; i++) {
    cin>>bottles[i];
  }
  change(0, 0, bottles[2]);
  bool isFirst = true;
  for(int i = 0; i <= bottles[2]; i++) {
    if(answer[i] != 0) {
      if(isFirst) {
        isFirst = false;
      } else {
        cout<<" ";
      }
      cout<<i;
    }
  }
  cout<<'\n';
  return 0;
}