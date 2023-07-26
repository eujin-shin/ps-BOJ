#include <iostream>
#include <string>
using namespace std;

int arr[52]={0, };

int main() {
  int n, c=0, s=1;
  string input;
  cin>>n>>input;
  for(int i=0; i<input.size(); i++) {
    if(input[i]=='S') {
      if(arr[i]!=0) arr[i+1]=1;
      c++;
    } else {
      if(i>0 && s<0) {
        arr[i+1]=1; c++;
      } else if(arr[i]==0) c++;
      s=-s;
    }
  }
  cout<<c<<'\n';
  return 0;
}