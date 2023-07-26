#include <iostream>
using namespace std;

int e[3001]={0, };
int arr[30000]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, d, k, c, max=0, cur=0;
  cin>>n>>d>>k>>c;
  e[c]=1;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
    if(cur>=k) {
      if(arr[i-d+1]!=c) e[arr[i-d+1]]-=1;
      cur-=1;
    } 
    if(e[arr[i]]==0) cur+=1;
    e[arr[i]]+=1;
    if(max<cur) max=cur;
  }
  cout<<max+1<<'\n';
  return 0;
}