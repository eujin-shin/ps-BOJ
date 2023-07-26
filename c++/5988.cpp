#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  string s;
  int n, k;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>s;
    k=(s[s.size()-1]-'0')%2;
    if(k==0) cout<<"even\n";
    else cout<<"odd\n";
  }
  return 0;
}