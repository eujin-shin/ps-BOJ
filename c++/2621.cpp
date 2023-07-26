#include <iostream>
#include <vector>
using namespace std;

vector <int> num[10];
vector <int> color[4];
vector <pair<int, int> > v;

int main() {
  char c;
  int x, n;
  bool con = false;
  for(int i=0; i<5; i++) {
    cin>>c>>n;
    if(c=='R') x=0;
    else if(c=='B') x=1;
    else if(c=='Y') x=2;
    else if(c=='G') x=3;
    num[n].push_back(x);
    color[x].push_back(x);
  }
  for(int i=1; i<10; i++) {
    if(num[i].empty()) continue;
    v.push_back(make_pair(num[i].size(), i));
  }
  sort(v.begin(), v.end());
  if(v.size()==5 && v[0].second+4==v[4].second) con=true;
  
}