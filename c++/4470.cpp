#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  string s;
  cin>>n; 
  getline(cin, s, '\n');
  for(int i=1; i<=n; i++) {
    getline(cin, s, '\n');
    cout<<i<<". "<<s<<'\n';
  }
  return 0;
}