#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  int len=0;
  cin>>input;
  for(int i=0; i<input.size(); i++) {
    if(i==0 || input[i]!=input[i-1]) len+=10;
    else len+=5;
  }
  cout<<len<<'\n';
  return 0;
}