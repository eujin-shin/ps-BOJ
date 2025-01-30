#include <iostream>
#include <queue>
#define MAX 200000
using namespace std;

int visited[MAX] = {0, };
queue <int> sameLevels, nextLevels;

void findSameLevel(int level, int x, int k);
void checkLevel(int level, int x);

int main() {
  int n, k;
  cin>>n>>k;

  int x, level = 1;
  visited[n] = level;
  nextLevels.push(n);
  while(visited[k] == 0) {
    while(!nextLevels.empty()) {
      x = nextLevels.front();
      findSameLevel(level, x, k);
      nextLevels.pop();
    }

    if(visited[k] != 0) {
      break;
    }

    level++;
    while(!sameLevels.empty()) {
      x = sameLevels.front();
      checkLevel(level, x + 1);
      checkLevel(level, x - 1);
      sameLevels.pop();
    }
  }

  cout<<visited[k] - 1<<'\n';
  return 0;
}

void checkLevel(int level, int x) {
  if(x < MAX && x >= 0 && visited[x] == 0) {
    visited[x] = level;
    nextLevels.push(x);
  }
  return;
}

void findSameLevel(int level, int x, int k) {
  visited[x] = level;
  sameLevels.push(x);
  while(x != 0 && x < k) {
    x *= 2;
    visited[x] = level;
    sameLevels.push(x);
  }
  return;
}