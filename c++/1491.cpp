#include <iostream>
using namespace std;

int main() {
  int arr[4]={0, }, pair[4]={2, 3, 0, 1};
  int cur=0, next=1, x, y;
  cin>>arr[1]>>arr[2];
  arr[2]--; arr[1]--;
  while(1) {
    if(arr[cur]==arr[pair[cur]]) {
      if(cur%2==0) {
        y=arr[cur]; x=arr[next];
      } else {
        x=arr[cur]; y=arr[next];
      }
      break;
    }
    if(cur==1 || cur==2) arr[cur]--;
    else arr[cur]++;
    cur++; next++;
    if(next==4) next=0;
    if(cur==4) cur=0;
  }
  cout<<x<<' '<<y<<'\n';
  return 0;
}