#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int index;
  cin>>s;
  for(int i = 0; i < s.length(); i++) {
    index = s[i] - 'D';
    cout<<(char)(index < 0 ? index + 'Z' + 1 : index + 'A');
  }
  cout<<'\n';
  return 0;
}