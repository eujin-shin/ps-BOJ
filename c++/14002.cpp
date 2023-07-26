#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <int> v;
int arr[1000]={0, };
int s[1000]={0, }, p[1000]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  memset(p, -1, sizeof(p));
  int n, max=0, l, next;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i]; s[i]=1;
    for(int j=0; j<i; j++) {
      if(arr[j]>=arr[i]) continue;
      if(s[j]+1>s[i]) {
        s[i]=s[j]+1; p[i]=j;
      }
    }
    if(s[i]>max) {
      max=s[i]; l=i;
    }
  }
  v.push_back(arr[l]); next=p[l];
  while(next!=-1) {
    v.push_back(arr[next]); next=p[next];
  }
  cout<<v.size()<<'\n';
  for(int i=1; i<=v.size(); i++) {
    cout<<v[v.size()-i];
    if(i!=v.size()) cout<<' ';
  }
  cout<<'\n';
  return 0;
}