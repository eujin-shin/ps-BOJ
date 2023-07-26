#include <iostream>
#include <queue>
using namespace std;

int arr[100001]={0, };

int DFS(int start, int x, int r) {
  if(arr[x]==start) {
    return r;
  } else if(arr[x]<0) {
    arr[0]=x;
    return -r;
  } else if (arr[x]==0 || arr[x]<start) {
    return 0;
  } else {
    int temp=arr[x], res;
    arr[x]=-1;
    res=DFS(start, temp, r+1);
    arr[x]=0;
    if(res<0 && x==arr[0]) {
      arr[0]=0;
      res=(-res)-r;
    }
    return res;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, count;
  cin>>t;
  while(t--) {
    cin>>n; count=n;
    for(int i=1; i<=n; i++) {
      cin>>arr[i];
      if(i==arr[i]) {
        arr[i]=0; count--;
      }
    }
    for(int i=1; i<=n; i++) {
      if(arr[i]<i) continue;
      count-=DFS(i, i, 1);
    }
    cout<<count<<'\n';
  }
  return 0;
}