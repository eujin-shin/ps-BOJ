#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b;
  int n, c=0;
  cin>>a>>n;
  for(int i=0; i<n; i++) {
    cin>>b;
    if(b.compare(a)==0) c++;
  }
  cout<<c<<'\n';
  return 0;
}