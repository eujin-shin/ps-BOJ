#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int arr[MAX]={0, };
vector <int> v;

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, cnt;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x;
    v.push_back(x); arr[x]++;
  }
  for(int i=0; i<n; i++) {
    x=v[i]; cnt=-1;
    for(int j=1; j*j<=x; j++) {
      if(x%j!=0) continue;
      cnt+=arr[j];
      if(j!=x/j) cnt+=arr[x/j];
    }
    cout<<cnt<<'\n';
  }
  return 0;
}