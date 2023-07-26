#include <iostream>
#include <string>
using namespace std;

int score[2][6]={0, };

void Calc(string s, int k) {
  for(int i=0; i<s.size(); i++) {
    if(s[i]=='L') {
      score[k][0]++; score[k][1]++; score[k][2]++;
    } else if(s[i]=='O') {
      score[k][0]++; score[k][3]++; score[k][4]++;
    } else if(s[i]=='V') {
      score[k][1]++; score[k][3]++; score[k][5]++;
    } else if(s[i]=='E') {
      score[k][2]++; score[k][4]++; score[k][5]++;
    }
  }
  return;
}

int main() {
  string s, t, ans;
  int n, p=-1, tmp;
  cin>>s>>n;
  Calc(s, 0);
  for(int i=0; i<n; i++) {
    cin>>t;
    Calc(t, 1);
    tmp=1;
    for(int j=0; j<6; j++) {
      tmp=tmp*(score[0][j]+score[1][j])%100;
      score[1][j]=0;
    }
    if(tmp>p) {
      p=tmp; ans=t;
    } else if(tmp==p) {
      ans=(t<ans) ? (t) : (ans);
    }
  }
  cout<<ans<<'\n';
  return 0;
}