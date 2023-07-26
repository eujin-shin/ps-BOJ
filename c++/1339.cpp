#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[26]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  string input;
  int n, x, sum=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input; x=1;
    for(int j=input.size()-1; j>=0; j--) {
      arr[input[j]-'A']+=x; x*=10;
    }
  }
  sort(arr, arr+26); x=9;
  for(int i=0; i<10; i++) {
    sum+=arr[25-i]*x; x--;
  }
  cout<<sum<<'\n';
  return 0;
}