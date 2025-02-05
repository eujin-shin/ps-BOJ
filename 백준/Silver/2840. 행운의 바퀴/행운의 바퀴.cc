#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  
  int arr[100] = {0, }, check[26] = {0, };
  int cur = n - 1, moves;
  char ch;
  bool isBroken = false;
  for(int i = 0; i < k; i++) {
    cin>>moves>>ch;
    cur -= moves;
    cur = cur < 0 ? n - (-cur - 1) % n - 1 : cur;
    isBroken = isBroken || (arr[cur] != 0 && (char)arr[cur] != ch) || (check[ch - 'A'] != 0 && cur + 1 != check[ch - 'A']);
    arr[cur] = ch;
    check[ch - 'A'] = cur + 1;
  }
  
  char print;
  if(isBroken) {
    cout<<"!";
  } else {
    for(int i = 0; i < n; i++) {
      print = arr[(i + cur) % n] == 0 ? '?' : (char)arr[(i + cur) % n];
      cout<<print;
    }
  }
  cout<<'\n';
  return 0;
}