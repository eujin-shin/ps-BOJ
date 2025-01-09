#include <iostream>
#define SIZE 1000000
using namespace std;

int arr[SIZE] = {0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, x;
  cin>>n;
  int start = 0, second = 1, end = n - 1;
  int positions[4] = {0, 0, 1, n - 1};
  for(int i = n; i > 0; i--) {
    cin>>x;
    arr[positions[x]] = i;

    if(x == 1) {
      positions[1] = positions[2];
      positions[2]++;
    } else if(x == 2) {
      positions[2]++;
    } else if(x == 3) {
      positions[3]--;
    }
  }

  for(int i = 0; i < n; i++) {
    if(i > 0) {
      cout<<' ';
    }
    cout<<arr[i];
  }
  cout<<'\n';
  return 0;
}