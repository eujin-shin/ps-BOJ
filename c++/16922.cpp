#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int arr[4]={1, 5, 10, 50};

void Btrack(int n, int r, int x, int sum) {
  if(n==r) {
    v.push_back(sum);
    return;
  }
  for(int i=x; i<4; i++) {
    Btrack(n, r+1, i, sum+arr[i]);
  }
  return;
}

int main() {
  int n;
  cin>>n;
  Btrack(n, 0, 0, 0);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  cout<<v.size()<<'\n';
  return 0;
}