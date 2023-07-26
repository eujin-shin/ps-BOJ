#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int arr[1003][1003] = {0, };
  int n, temp, max, ans=1;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>temp;
    arr[0][i] = arr[i][0] = temp;
  }
  for(int i=1; i<=n; i++) {
    max = 1;
    for(int j=1; j<i; j++) {
      if(max<arr[j][i]) {
        max = arr[j][i];
      }
    }
    max++;
    for(int j=i+1; j<=n; j++) {
      if(arr[0][j]>arr[i][0]) {
        arr[i][j] = max;
        if(max>ans) {
          ans = max;
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}