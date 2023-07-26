#include <iostream>
#define M 500000
using namespace std;

int arr[M]={0, };
int high[M]={0, };

int find(int n, int index) {
  int i, j, x=arr[n];
  for(i=index-1; i>-1; i--) {
    if(high[i]>x) break;
  }
  for(j=high[i]; j<n-1; j++) {
    if(arr[j+1]<=x) break;
  }
  return j+1;
}

int main() {
  ios_base::sync_with_stdio(false);
  int ans[M]={0, };
  int n, max, index=1;
  bool up;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  max=arr[0];
  for(int i=1; i<n; i++) {
    if(arr[i-1]>arr[i]) {
      if(up) {
        high[index]=i-1; index++;
        up=false;
      }
      ans[i]=i;
    } else {
      up=true;
      if(arr[i]>max) {
        max=arr[i]; continue;
      }
      ans[i]=find(i, index);
    }
  }
  for(int i=0; i<n; i++) {
    cout<<ans[i];
    if(i==n-1) cout<<'\n';
    else cout<<' ';
  }
  return 0;
}