#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <pair<int, int> > v;
string s;
int arr[2501]={0, };

bool check(int x, int y) {
  for(int i=0; x+i<=y-i; i++) {
    if(s[x+i]!=s[y-i]) return false;
  }
  return true;
}

int main() {
  int idx=0, n, a, b;
  cin>>s; n=s.length();
  for(int i=0; i<n; i++) {
    for(int j=n-1; j>i; j--) {
      if(check(i, j)) v.push_back(make_pair(i, j));
    }
  }
  for(int i=0; i<=n; i++) arr[i]=i;
  for(int i=1; i<=n; i++) {
    if(arr[i]==0 || arr[i]>arr[i-1]+1) arr[i]=arr[i-1]+1;
    while(idx<v.size() && v[idx].first<i) {
      a=v[idx].first; b=v[idx].second;
      idx++;
      if(arr[b+1]>arr[a]+1) arr[b+1]=arr[a]+1;
    }
  }
  cout<<arr[n]<<'\n';
  return 0;
}