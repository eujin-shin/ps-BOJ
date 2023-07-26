#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b;
  int arr[2][26]={0, }, cnt=0;
  cin>>a>>b;
  for(int i=0; i<a.size(); i++) arr[0][a[i]-'a']++;
  for(int i=0; i<b.size(); i++) arr[1][b[i]-'a']++;
  for(int i=0; i<26; i++) {
    cnt += ((arr[0][i]>arr[1][i]) ? (arr[0][i]-arr[1][i]) : (arr[1][i] - arr[0][i]));
  }
  cout<<cnt<<'\n';
  return 0;
}