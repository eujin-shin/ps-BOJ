#include <iostream>
using namespace std;

int weight[1000]={0, }, pos[1000]={0, };

int main() {
  int n, w, l, sum=0, s=0, e=0, cnt=0;
  cin>>n>>l>>w;
  for(int i=0; i<n; i++) cin>>weight[i];
  while(1) {
    if(e==n && sum==0) break;
    for(int i=s; i<e; i++) {
      pos[i]+=1;
      if(pos[i]>l) {
        sum-=weight[i]; s++;
      }
    }
    if(e<n && sum+weight[e]<=w) {
      sum+=weight[e]; pos[e]=1; e++;
    }
    cnt++;
  }
  cout<<cnt<<'\n';
  return 0;
}