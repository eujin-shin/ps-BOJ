#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int ind[501], arr[501];

void Swap(int *a, int *b) {
  int tmp=*a; *a=*b; *b=tmp;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int t, n, k, m, a, b;
  cin>>t;
  while(t--) {
    cin>>n;
    int map[501][501]={0, };
    memset(ind, 0, sizeof(ind));
    memset(arr, 0, sizeof(arr));
    for(int i=1; i<=n; i++) {
      cin>>k; ind[k]=i-1; arr[i]=k;
      for(int j=1; j<i; j++) {
        map[arr[j]][k]=1;
      }
    }
    cin>>m;
    for(int i=0; i<m; i++) {
      cin>>a>>b;
      if(ind[a]>ind[b]) Swap(&a, &b);
      map[a][b]=0; map[b][a]=1;
      ind[b]--; ind[a]++;
    }
    
  }
}