#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v;

int Gcd(int a, int b) {
  int tmp;
  if(a==b) return a;
  if(a<b) {
    tmp=a; a=b; b=tmp;
  }
  if(a%b==0) return b;
  return Gcd(b, a-b);
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, tmp;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  x=v[1]-v[0];
  for(int i=2; i<v.size(); i++) {
    x=Gcd(x, v[i]-v[i-1]);
    if(x==1) break;
  }
  cout<<(v[v.size()-1]-v[0])/x+1-v.size()<<'\n';
  return 0;
}