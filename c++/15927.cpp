#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  cin>>input;
  int p=-1, f=-1, l=input.size();
  if(l%2==1) l++;
  for(int i=0; i<l/2; i++) {
    if(input[i]!=input[input.size()-i-1]) p=1;
    if(i>0 && input[i]!=input[i-1]) f=1;
  }
  if(p>0) cout<<input.size()<<'\n';
  else if(f>0) cout<<input.size()-1<<'\n';
  else cout<<"-1\n";
  return 0;
}