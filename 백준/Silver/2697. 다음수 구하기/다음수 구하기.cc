#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int t;
  string s;
  cin>>t;

  int arr[80] = {0, }, x, y, len;
  while(t--) {
    cin>>s;

    x = 0;
    y = -1;
    len = s.length();
    for(int i = 0; i < len; i++) {
      arr[i] = s[i] - '0';
    }

    int temp;
    for(int i = 0; i < len; i++) {
      temp = -1;
      for(int j = i + 1; j < len; j++) {
        temp = arr[i] < arr[j] && (temp < 0 || arr[temp] > arr[j]) ? j : temp;
      }
      if(temp > i) {
        x = i;
        y = temp;
      }
    }
    if(y < 0) {
      cout<<"BIGGEST\n";
      continue;
    }
    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
    sort(arr + x + 1, arr + len);
    for(int i = 0; i < len; i++) {
      cout<<arr[i];
    }
    cout<<'\n';
  }
  return 0;
}