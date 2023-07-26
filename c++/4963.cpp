#include <iostream>
using namespace std;

int graph[52][52] = {0, };

void DFS(int i, int j, int w, int h) {
  graph[i][j] = 0;
  if(i>0 && j>0) {
    if(graph[i-1][j-1]) {
      DFS(i-1, j-1, w, h);
    }
  } 
  if(i>0) {
    if(graph[i-1][j]) {
      DFS(i-1, j, w, h);
    }
    if(graph[i-1][j+1]) {
      DFS(i-1, j+1, w, h);
    }
  } 
  if(j>0) {
    if(graph[i][j-1]) {
      DFS(i, j-1, w, h);
    }
    if(graph[i+1][j-1]) {
      DFS(i+1, j-1, w, h);
    }
  }
  if(graph[i+1][j]) {
    DFS(i+1, j, w, h);
  }
  if(graph[i][j+1]) {
    DFS(i, j+1, w, h);
  }
  if(graph[i+1][j+1]) {
    DFS(i+1, j+1, w, h);
  }
  return;
}

int main() {
  int count, w, h;
  while(1) {
    count = 0;
    cin>>w>>h;
    if(w+h==0) {
      break;
    }
    for(int i=0; i<h; i++) {
      for(int j=0; j<w; j++) {
        cin>>graph[i][j];
      }
    }
    for(int i=0; i<h; i++) {
      for(int j=0; j<w; j++) {
        if(graph[i][j]) {
          count++;
          DFS(i, j, w, h);
        }
      }
    }
    cout<<count<<endl;
  }
  return 0;
}