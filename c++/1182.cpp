#include <iostream>
using namespace std;

int num[21] = {0, };
int result[21] = {0, };

void BackTrack(int k, int i, int n, int x, int r) {
  if(r==x) {
    if(k==num[0]) {
      result[r] = result[r]+1;
    }
  } else {
    for(int index=i; index<=n; index++) {
      k+=num[index];
      BackTrack(k, index+1, n, x, r+1);
      k-=num[index];
    }
  }
}

int main() {
  int n, count=0;
  cin>>n>>num[0];
  for(int i=1; i<=n; i++) {
    cin>>num[i];
    if(num[i]==num[0]) {
      count++;
    }
  }
  for(int i=2; i<=n; i++) {
    BackTrack(0, 1, n, i, 0);
    count+=result[i];
  }
  cout<<count<<endl;
}