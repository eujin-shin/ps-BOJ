#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[100001] = {0, };
  int n, k, x, sum = 0, max = 0;
  cin>>n>>k;
  for(int i=1; i<=n; i++) {
    cin>>x;
    arr[i] = arr[i-1]+x;
    if(i>k && arr[i]-arr[i-k]>max || i==k) {
      max = arr[i]-arr[i-k];
    }
  }
  cout<<max<<'\n';
  return 0;
}