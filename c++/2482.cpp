#include <iostream>
#define MOD 1000000003
using namespace std;

int map[1001][1001][2]={0, };

int empty(int n, int k) {
  if(n<k*2) return 0;
  if(n==k*2) return 0;
  if(k==1) return n-2;
  if(map[n][k][1]==1) {
    
  }
}

int fill(int n, int k) {
  if(n<k*2) return 0;
  if(n==k*2) return 2;
  if(k==1) return 2;
  if(map[n][k][0]==0) {
    map[n][k][0]=empty(n-1, k)%MOD;
  }
  return map[n][k][0];
}

int Select(int n, int k) {
  return (fill(n, k)+empty(n, k))%MOD; 
}

int main() {
  int n, k;
  cin>>n>>k;
  cout<<Select(n, k)<<'\n';
  return 0;
}