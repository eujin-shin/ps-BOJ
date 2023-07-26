#include <iostream>
#include <string>
using namespace std;

// 'abcde' f'g'h'i'j
// kl'm'no pq'r'st
// uvwxy z
int main() {
  string input;
  int tmp, flag;
  cin>>input;
  for(int i=0; i<input.size(); i++) {
    tmp=input[i]-'A'; flag=1;
    if(tmp>=0 && tmp<5) flag=-1;
    else if(tmp==6 || tmp==8 || tmp==12 || tmp==17) flag=-1;
    if(flag>0) cout<<input[i];
  }
  cout<<'\n';
  return 0;
}