#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  int arr[26]={0, };
  cin>>input;
  for(int i=0; i<input.size(); i++) arr[input[i]-'a']++;
  for(int i=0; i<26; i++) {
    cout<<arr[i];
    if(i!=25) cout<<' ';
  }
  cout<<'\n';
  return 0;
}