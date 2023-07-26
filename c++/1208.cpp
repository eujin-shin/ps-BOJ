#include <iostream>
#include <map>
using namespace std;

map <int, int> m; 
int arr[41]={0, };
int n, s;
long long cnt=0;

void LeftSum(int k, int sum) {
  if(k==n/2) {
    m[sum]+=1; return;
  }
  LeftSum(k+1, sum+arr[k]);
  LeftSum(k+1, sum);
  return;
}

void RightSum(int k, int sum) {
  if(k==n) {
    cnt+=m[s-sum]; return;
  }
  RightSum(k+1, sum+arr[k]);
  RightSum(k+1, sum);
  return;
}

int main() {
  cin>>n>>s;
  for(int i=0; i<n; i++) cin>>arr[i];
  LeftSum(0, 0);
  RightSum(n/2, 0);
  if(s==0) cout<<cnt-1<<'\n';
  else cout<<cnt<<'\n';
  return 0;
}