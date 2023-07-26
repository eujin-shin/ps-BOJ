#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

vector <string> v;

int main() {
  ios_base::sync_with_stdio(false);
  string input;
  int arr[26];
  int n, m, max, c, tmp, d=0;
  char ans;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>input; v.push_back(input);
  }
  for(int i=0; i<m; i++) {
    c=0;
    memset(arr, 0, sizeof(arr));
    for(int j=0; j<n; j++) {
      tmp=v[j][i]-'A';
      arr[tmp]++;
      if(arr[tmp]>c || (arr[tmp]==c && tmp<max)) {
        max=tmp; c=arr[tmp];
      }
    }
    d+=n-arr[max];
    ans=max+'A'; cout<<ans;
  }
  cout<<'\n'<<d<<'\n';
  return 0;
}