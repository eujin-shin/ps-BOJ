#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> v;

bool Compare(string a, string b) {
  if(a.size()!=b.size()) return false;
  for(int i=0; i<a.size(); i++) {
    if(a[i]!=b[i]) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  string tmp;
  int n, cnt=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
  }
  for(int i=0; i<n; i++) {
    cin>>tmp;
    if(Compare(tmp, v[cnt])) cnt++;
  }
  cout<<n-cnt<<'\n';
  return 0;
}

