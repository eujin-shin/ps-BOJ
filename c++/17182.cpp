#include <iostream>
#include <vector>
#define MAX 10000
using namespace std;

int arr[10][10]={0, }, v[10]={0, };
int n, ans=MAX;

void Backtrack(int k, int sum) {
  bool b=true;
  for(int i=0; i<n; i++) {
    if(v[i]!=0) continue;
    b=false;
    v[i]=1;
    Backtrack(i, sum+arr[k][i]);
    v[i]=0;
  }
  if(b && sum<ans) ans=sum;
  return;
}

int main() {
  int k;
  cin>>n>>k;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) cin>>arr[i][j];
  }
  for(int i=0; i<n; i++) {
    for(int x=0; x<n; x++) {
      for(int y=0; y<n; y++) {
        if(arr[x][y]>arr[x][i]+arr[i][y]) {
          arr[x][y]=arr[x][i]+arr[i][y];
        }
      }
    }
  }
  v[k]=1;
  Backtrack(k, 0);
  cout<<ans<<'\n';
  return 0;
}