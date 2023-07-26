#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x, cnt;
  cin>>x;
  while(x!=-1) {
    int arr[100]={0, };
    cnt=0;
    while(x!=0) {
      cnt+=arr[x];
      if(x*2<100) arr[x*2]++;
      if(x%2==0) arr[x/2]++;
      cin>>x;
    }
    cout<<cnt<<'\n';
    cin>>x;
  }
  return 0;
}