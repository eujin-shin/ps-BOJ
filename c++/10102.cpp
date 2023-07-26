#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int n, a=0, b=0;
  cin>>n>>s;
  for(int i=0; i<n; i++) {
    if(s[i]=='A') a++;
    else if(s[i]=='B') b++;
  }
  if(a>b) cout<<"A\n";
  else if(b>a) cout<<"B\n";
  else cout<<"Tie\n";
  return 0;
}