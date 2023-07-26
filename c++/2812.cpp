#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define pnt pair<int, int>
using namespace std;

struct compare {
  bool operator() (pnt &a, pnt &b) {
    if(a.first!=b.first) return a.first<b.first;
    return a.second>b.second;
  }
};

priority_queue <pnt, vector<pnt>, compare> pq;
string input;
vector <int> v;

int main() {
  int n, k, count=0, erase=-1;
  cin>>n>>k;
  cin>>input;
  for(int i=0; i<n; i++) {
    cout<<erase<<'\n';
    if(pq.size()>k) {
      while(pq.top().second<erase) pq.pop();
      v.push_back(pq.top().first); 
      erase=pq.top().second;
      pq.pop();
    }
    pq.push(make_pair(input[i]-'0', i));
  }
  /*
  for(int i=erase+1; i<n; i++) {
    v.push_back(input[i]-'0');
  }
  */
  for(int i=0; i<v.size(); i++) {
    cout<<v[i];
  }
  cout<<'\n';
  return 0;
}