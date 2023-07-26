#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int input[10]={0, }, test[10]={0, };
int s, b;
vector <int> v;

void Check(int x) {
  int st=0, ba=0;
  for(int i=1; i<10; i++) {
    if(input[i]==0 || test[i]==0) continue;
    if(input[i]==test[i]) st++;
    else if(input[i]!=0 && test[i]!=0) ba++;
  }
  if(st!=s || ba!=b) return;
  v.push_back(x);
  return;
}

int Checker(int x) {
  int st=0, ba=0;
  for(int i=1; i<10; i++) {
    if(input[i]==0 || test[i]==0) continue;
    if(input[i]==test[i]) st++;
    else if(input[i]!=0 && test[i]!=0) ba++;
  }
  if(st!=s || ba!=b) return 0;
  return 1;
}

void Init(int r, int x) {
  if(r==3) {
    Check(x); return;
  }
  for(int i=1; i<10; i++) {
    if(test[i]!=0) continue;
    test[i]=r+1; Init(r+1, x*10+i); test[i]=0;
  }
  return;
}

void MakeTest(int x) {
  int r=3;
  while(x) {
    test[x%10]=r; r--; x/=10;
  }
  return;
}

void Solve() {
  for(int i=0; i<v.size(); i++) {
    memset(test, 0, sizeof(test));
    MakeTest(v[i]);
    if(Checker(v[i])) continue;
    v.erase(v.begin()+i); i--;
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, in, tmp, idx;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>in>>s>>b;
    tmp=in; idx=3;
    memset(input, 0, sizeof(input));
    while(tmp) {
      input[tmp%10]=idx; idx--; tmp/=10;
    }
    if(i==0) Init(0, 0);
    else Solve();
  }
  cout<<v.size()<<'\n';
  return 0;
}