#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int Gcd(int a, int b) {
  if(b%a==0) return a;
  return ((b-a>a) ? (Gcd(a, b-a)) : (Gcd(b-a, a)));
}

int main() {
  int n, s, tmp;
  cin>>n>>s;
  for(int i=0; i<n; i++) {
    cin>>tmp;
    if(tmp>s) v.push_back(tmp-s);
    else if(tmp<s) v.push_back(s-tmp);
  }
  sort(v.begin(), v.end());
  for(int i=1; i<v.size(); i++) {
    v[i]=Gcd(v[i-1], v[i]);
  }
  cout<<v[v.size()-1]<<'\n';
  return 0;
}