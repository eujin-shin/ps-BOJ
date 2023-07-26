#include <iostream>
using namespace std;

// 01234567890123456789023456
// abcdefghijklmnopqrstuvwxyz

int vows[6] = {0, }, cons[23] = {0, };
int alpha[28] = {0, };
int output[15] = {0, };

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

void BTrack(int v, int c, int x, int cha, int r, int l) {
  bool flag = true;
  if(r==l) {
    qsort(output, l, sizeof(int), Cmp);
    char ans;
    for(int i=0; i<l; i++) {
      ans = output[i]+'a';
      cout<<ans;
      if(i==l-1) cout<<'\n';
    }
  } else {
    for(int i=x; i<cha; i++) {
      if(alpha[i]==0 || alpha[i]==4 || alpha[i]==8 || alpha[i]==14 || alpha[i]==20) {
        flag = false;
      } else flag = true;
      if(l-v<=2 && !flag) continue;
      if(l-c<=1 && flag) continue;
      output[r] = alpha[i];
      if(flag) c++; else v++;
      BTrack(v, c, i+1, cha, r+1, l);
      if(flag) c--; else v--;
    }
  }
  return;
}

int main() {
  int len, cha, c_count, v_count, v_len = 1, c_len = 2;
  char temp;
  c_count = v_count = 0;
  cin>>len>>cha;
  for(int i=0; i<cha; i++) {
    cin>>temp;
    temp -= 'a';
    alpha[i] = temp;
  }
  qsort(alpha, cha, sizeof(int), Cmp);
  BTrack(0, 0, 0, cha, 0, len);
  return 0;
}