#include <iostream>
using namespace std;

int arr[8]={0, };
int ret[8]={0, };

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

void DFS(int n, int r, int m) {
  if(m==r) {
    for(int i=0; i<r; i++) {
      cout<<ret[i];
      if(i==r-1) cout<<'\n';
      else cout<<' ';
    }
  } else {
    int temp;
    for(int i=0; i<n; i++) {
      if(arr[i]<0 || i>0 && arr[i]==arr[i-1]) continue;
      ret[r]=arr[i]; temp=arr[i]; arr[i]=-1;
      DFS(n, r+1, m);
      arr[i]=temp;
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  qsort(arr, n, sizeof(int), Cmp);
  DFS(n, 0, m);
  return 0;
}