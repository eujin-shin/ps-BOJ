#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector <int> v, len, back;
stack <int> s;

int Bound(int k) {
  int l=0, r=len.size()-1, mid, ans;
  while(l<=r) {
    mid=(l+r)/2;
    if(v[len[mid]]<k) {
      l=mid+1;
    } else {
      r=mid-1;
      ans=mid;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, tmp, idx;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
    if(len.empty()) {
      len.push_back(i);
      tmp=-1;
    } else {
      idx=len[0];
      if(v[i]<=v[idx]) {
        len[0]=i;
        tmp=-1;
      } else {
        idx=len[len.size()-1];
        if(v[i]>v[idx]) {
          len.push_back(i);
          tmp=idx;
        } else {
          idx=Bound(v[i]);
          len[idx]=i;
          tmp=len[idx-1];
        }
      }
    }
    back.push_back(tmp);
  }
  cout<<len.size()<<'\n';
  if(len.size()>0) {
    idx=len[len.size()-1];
    s.push(v[idx]);
    while(back[idx]!=-1) {
      idx=back[idx];
      s.push(v[idx]);
    }
    while(1) {
      cout<<s.top();
      s.pop();
      if(!s.empty()) cout<<" ";
      else break;
    }
    cout<<'\n';
  }
  return 0;
}