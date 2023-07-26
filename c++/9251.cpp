#include <iostream>
#include <string>
using namespace std;

int lcs[1002][1002] = {0, };

int main() {
  int len1, len2;
  string s1, s2;
  cin>>s1>>s2;
  len1 = s1.length();
  len2 = s2.length();
  for(int i=1; i<=len1; i++) {
    for(int j=1; j<=len2; j++) {
      if(s1[i-1]==s2[j-1]) {
        lcs[i][j] = lcs[i-1][j-1]+1;
      } else {
        if(lcs[i-1][j]>lcs[i][j-1]) {
          lcs[i][j] = lcs[i-1][j];
        } else {
          lcs[i][j] = lcs[i][j-1];
        }
      }
    }
  }
  cout<<lcs[len1][len2]<<endl;
  return 0;
}