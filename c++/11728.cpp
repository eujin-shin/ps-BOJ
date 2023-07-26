#include <iostream>
using namespace std;

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[2000000] = {0, };
  int n, m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  for(int i=0; i<m; i++) {
    cin>>arr[i+n];
  }
  qsort(arr, n+m, sizeof(int), Cmp);
  for(int i=0; i<n+m; i++) {
    cout<<arr[i];
    if(i==n+m-1) {
      cout<<'\n';
    } else {
      cout<<' ';
    }
  }
  return 0;
}
