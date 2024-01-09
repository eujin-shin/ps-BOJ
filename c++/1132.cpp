#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector <pair<long long, int> > v;
  long long arr[10]={0, }, sum=0, k;
  string s;
  int c[10]={0, }, n, l;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>s;
    l=s.length(); k=1;
    for(int j=1; j<=l; j++, k*=10) arr[s[l-j]-'A']+=k;
    c[s[0]-'A']++;
  }
  for(int i=0; i<10; i++) v.push_back(make_pair(arr[i], i));
  sort(v.begin(), v.end());
  k=1;
  for(int i=0; i<10; i++) {
    if(k==1 && c[v[i].second]==0) k=0;
    else sum+=(k+i)*v[i].first;
  }
  cout<<sum<<'\n';
  return 0;
}