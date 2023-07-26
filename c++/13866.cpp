#include <iostream>
using namespace std;

int main() {
  int a, b, ans;
  int arr[4];
  for(int i=0; i<4; i++) cin>>arr[i];
  a=arr[0]+arr[3]; b=arr[1]+arr[2];
  ans = (a>b) ? a-b : b-a;
  cout<<ans<<'\n';
  return 0;
}