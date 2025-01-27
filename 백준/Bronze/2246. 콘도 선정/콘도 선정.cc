#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int> > v;

int main() {
  int n, d, c;
  cin>>n;
  for(int i = 0; i < n; i++) {
    cin>>d>>c;
    v.push_back(make_pair(d, c));
  }
  sort(v.begin(), v.end());
  int min = 10001, count = 0;
  for(int i = 0; i < n; i++) {
    if(v[i].second < min) {
      count++;
      min = v[i].second;
    }
  }
  cout<<count<<'\n';
  return 0;
}