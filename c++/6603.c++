#include <iostream>
using namespace std;

int result[6] = {0, };

void Swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void BackTrack(int num[], int r, int n, int k) {
  if(r==6) {
    for(int i=0; i<6; i++) {
      cout<<result[i];
      if(i==5) {
        cout<<endl;
      } else {
        cout<<" ";
      }
    }
  } else {
    for(int i=n; i<k; i++) {
      result[r] = num[i];
      BackTrack(num, r+1, i+1, k);
    }
  }
}

int main() {
  int k;
  int s[13] = {0, };
  cin>>k;
  while(k!=0) {
    for(int i=0; i<k; i++) {
      cin>>s[i];
    }
    BackTrack(s, 0, 0, k);
    cin>>k;
    if(k!=0) {
      cout<<endl;
    }
  }
  return 0;
}