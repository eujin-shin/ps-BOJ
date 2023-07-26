#include <iostream>
#include <algorithm>
#include <vector>
#define M 1000000
using namespace std;

int main() {
  int arr[M];
  vector <int> v;
  int n, index;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
    v.push_back(arr[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for(int i=0; i<n; i++) {
    index = lower_bound(v.begin(), v.end(), arr[i])-v.begin();
    cout<<index;
    if(i==n-1) cout<<'\n';
    else cout<<' ';
  }
  return 0;
}