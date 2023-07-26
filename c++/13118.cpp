#include <iostream>
using namespace std;

int main() {
  int arr[4]={0, };
  int x, y, r, k=0;
  for(int i=0; i<4; i++) cin>>arr[i];
  cin>>x>>y>>r;
  for(int i=0; i<4; i++) if(arr[i]==x) k=i+1;
  cout<<k<<'\n';
  return 0;
}