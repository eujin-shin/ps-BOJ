#include <iostream>
#include <vector>
#include <algorithm>
#define N 200001
#define H 500001
using namespace std;

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

int main() {
  ios_base::sync_with_stdio(false);
  int up[H]={0, }, down[H]={0, };
  vector <int> ans;
  int n, h, x, sum=0, count, min;
  cin>>n>>h;
  for(int i=0; i<n; i++) {
    cin>>x;
    if(i%2==0) down[x]=down[x]+1;
    else up[x]=up[x]+1;
  }
  for(int i=h; i>1; i--) {
    down[i-1]+=down[i];
  }
  for(int i=h; i>1; i--) {
    up[i-1]+=up[i];
  }
  for(int i=1; i<=h; i++) {
    ans.push_back(down[i]+up[h-i+1]);
  }
  sort(ans.begin(), ans.end());
  min=ans[0];
  for(count=1; count<h; count++) {
    if(ans[count]>min) break;
  }
  cout<<min<<' '<<count<<'\n';
  return 0;
}