#include <iostream>
#include <string>
using namespace std;

int main() {
  int arr[11]={0, };
  string in;
  int n, m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>in;
    for(int j=1; j<=m; j++) cout<<in[m-j];
    cout<<'\n';
  }
  return 0;
}