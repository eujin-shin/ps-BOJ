#include <iostream>
#include <string>
using namespace std;

string lcs[7] = {0, };

int main() {
  string str1, str2;
  cout<<".\n";
  cin>>str1>>str2;
  int len1 = str1.length(), len2 = str2.length();
  char c1, c2;
  for(int i=0; i<len1; i++) {
    c1 = str1[i];
    for(int j=0; j<len2; j++) {
      c2 = str2[j];
      if(c1==c2) {
        for(int h=j; h<len2; h++) {
          lcs[h] = lcs[h] + c1;
        }
        str2[j] = '.';
        break;
      }
    }
  }
  cout<<lcs[len2].length()<<'\n';
  if(lcs[len2].length()!=0) {
    cout<<lcs[len2]<<'\n';
  }
  return 0;
}