#include <iostream>
#define M 1000000
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int arr[M]={0, };
  long long cnt;
  int n, b, c;
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i];
  cin>>b>>c;
  cnt=n;
  for(int i=0; i<n; i++) {
    if(arr[i]<=b) continue;
    cnt+=(arr[i]-b)/c;
    if((arr[i]-b)%c!=0) cnt++;
  }
  cout<<cnt<<'\n';
  return 0;
}