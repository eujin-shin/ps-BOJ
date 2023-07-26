#include <iostream>
#include <queue>
using namespace std;

int map[51][51]={0, };

int BFS(int x, int y, int visit[][51]) {
  queue <int> q;

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, l, r;
  cin>>n>>l>>r;
  for(int y=0; y<n; y++) {
    for(int x=0; x<n; x++) {
      cin>>map[x][y];
    }
  }
  int day=0, avr;
  while(1) {
    day++;
    int visit[51][51]={0, };
    for(int y=0; y<n; y++) {
      for(int x=0; x<n; x++) {
        if(visit[x][y]) continue;

      }
    }
  }
}