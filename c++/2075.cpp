#include <iostream>
#define min -1000000001
using namespace std;

int idx[1500]={0, };
int map[1500][1500]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, max=0, index;
  cin>>n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>map[i][j];
    }
  }
  for(int i=0; i<n; i++) {
    max=min;
    for(int j=0; j<n; j++) {
      if(idx[j]>=n) continue;
      if(map[n-1-idx[j]][j]<max) continue;
      max=map[n-1-idx[j]][j]; index=j;
    }
    idx[index]+=1;
  }
  cout<<max<<'\n';
  return 0;
}