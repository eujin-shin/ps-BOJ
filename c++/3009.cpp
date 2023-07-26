#include <iostream>
using namespace std;

int arr[2][3]={0, };

int main() {
  int x, y;
  for(int i=0; i<3; i++) cin>>arr[0][i]>>arr[1][i];
  if(arr[0][0]==arr[0][2]) x=1;
  else if(arr[0][1]==arr[0][2]) x=0;
  else x=2;
  if(arr[1][0]==arr[1][2]) y=1;
  else if(arr[1][1]==arr[1][2]) y=0;
  else y=2;
  cout<<arr[0][x]<<' '<<arr[1][y]<<'\n';
  return 0;
}