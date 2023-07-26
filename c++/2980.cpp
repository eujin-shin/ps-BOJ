#include <iostream>
#include <vector>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  int n, l, dis, r, g, pos=0, sec=0;
  cin>>n>>l;
  for(int i=0; i<n; i++) {
    cin>>dis>>r>>g;
    sec+=dis-pos; pos=dis;
    if(sec%(r+g)>=r) continue;
    sec+=r-sec%(r+g);
  } 
  sec+=l-pos;
  cout<<sec<<'\n';
  return 0;
}