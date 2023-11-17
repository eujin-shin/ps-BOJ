#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector <pair<string, int> > v[15];

void Search(int p, int r) {
  vector <pair<string, int> > child;
  for(int i=0; i<v[r].size(); i++) {
    if(v[r][i].second==p) {
      child.push_back(make_pair(v[r][i].first, i));
    }
  }
  sort(child.begin(), child.end());
  for(int i=0; i<child.size(); i++) {
    for(int j=0; j<r; j++) cout<<"--";
    cout<<child[i].first<<'\n';
    Search(child[i].second, r+1);
  }
  return;
}

int main() {
  string s;
  int n, m, p, cur;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>m; p=0;
    for(int j=0; j<m; j++) {
      cin>>s;
      for(int h=0; h<=v[j].size(); h++) {
        if(h==v[j].size()) {
          v[j].push_back(make_pair(s, p));
          p=h; break;
        } else {
          if(v[j][h].second==p && v[j][h].first.compare(s)==0) {
            p=h; break;
          }
        }
      }
    }
  }
  Search(0, 0);
  return 0;
}