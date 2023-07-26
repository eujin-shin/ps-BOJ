#include <iostream>
using namespace std;

int Cmp(const void *a, const void *b) {
  return *(int *)b-*(int *)a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int grade[50] = {0, };
  int k, n, min, max, gap;
  cin>>k;
  for(int i=1; i<=k; i++) {
    cin>>n;
    for(int j=0; j<n; j++) {
      cin>>grade[j];
    }
    qsort(grade, n, sizeof(int), Cmp);
    min = grade[n-1]; max = grade[0];
    gap = grade[0] - grade[1];
    for(int j=2; j<n; j++) {
      if(grade[j-1]-grade[j]>gap) {
        gap = grade[j-1]-grade[j];
      }
    }
    cout<<"Class "<<i<<'\n';
    cout<<"Max "<<max<<", Min "<<min<<", Largest gap "<<gap<<'\n';
  }
  return 0;
}