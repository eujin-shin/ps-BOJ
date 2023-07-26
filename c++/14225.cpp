#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int n, arr[20]={0, };

void Sum(int r, int s) {
  if(r==n) {
    v.push_back(s); 
    return;
  }
  for(int i=0; i<2; i++) {
    Sum(r+1, s+arr[r]*i);
  }
  return;
}

int main() {
  int k=1;
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i];
  Sum(0, 0);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  while(v.size()>=k && v[k]==k) k++;
  cout<<k<<'\n';
  return 0;
}