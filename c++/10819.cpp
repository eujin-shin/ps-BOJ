#include <iostream>
using namespace std;

int arr[9] = {0, };
int visit[9]={0, };

void DFS(int r, int x, int n, int sum, int *max) {
  if(n==r) {
    if(*max<sum) *max=sum;
  } else {
    int dif=0;
    for(int i=0; i<n; i++) {
      if(!visit[i]) {
        if(r>0) {
          dif=arr[x]-arr[i];
          if(dif<0) dif=-dif;
        }
        visit[i]=1;
        DFS(r+1, i, n, sum+dif, max);
        visit[i]=0;
      }
    }
  }
  return;
}

int main() {
  int n, max=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  DFS(0, 0, n, 0, &max);
  cout<<max<<'\n';
  return 0;
}