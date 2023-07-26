#include <iostream>
#include <string>
using namespace std;

string n[1000], s[1000];

int Compare(string a, string b) {
  if(a.length()!=b.length()) return 0;
  for(int i=0; i<a.length(); i++) {
    if(a[i]!=b[i]) return 0;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  int m, k, cnt;
  string ans, t;
  cin>>m>>t;
  for(int i=0; i<m; i++) {
    cin>>n[i]>>s[i];
    if(Compare(n[i], t)) k=i;
  }
  cnt=0;
  for(int i=0; i<k; i++) {
    if(Compare(s[i], s[k])) cnt++;
  }
  cout<<cnt<<'\n';
  return 0;
}