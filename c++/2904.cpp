#include <iostream>
#include <vector>
using namespace std;

int arr[1000001]={0, }, map[101][80000]={0, };
vector <int> prime, v; 

int main() {
  int n, max=0, x, k, ans=1, c=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x; v.push_back(x);
    if(max<x) max=x;
  }
  for(int i=2; i<=max; i++) {
    if(arr[i]==-1) continue;
    prime.push_back(i);
    for(int j=i*2; j<=max; j+=i) arr[j]=-1;
  }
  for(int i=0; i<n; i++) {
    x=v[i]; k=0;
    while(x>1) {
      if(x%prime[k]==0) {
        x/=prime[k]; map[i][k]++;
        if(arr[k]<0) arr[k]=1;
        else arr[k]++;
      } else k++;
    }
  }
  for(int i=0; i<prime.size(); i++) {
    for(int j=0; j<arr[i]/n; j++) ans*=prime[i];
    for(int j=0; j<n; j++) {
      if(map[j][i]<arr[i]/n) c+=arr[i]/n-map[j][i];
    }
  }
  cout<<ans<<' '<<c<<'\n';
  return 0;
}