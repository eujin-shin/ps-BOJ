#include <iostream>
#include <string>
using namespace std;

int n;
string s[8];

void Pre(int r) {
  for(int i=0; i<r; i++) cout<<s[0];
  return;
}

void Recur(int r) {
  Pre(r); cout<<s[2];
  if(r==n) {
    Pre(r); cout<<s[6];
    Pre(r); cout<<s[7];
    return;
  } 
  for(int i=3; i<6; i++) {
    Pre(r); cout<<s[i];
  }
  Recur(r+1);
  Pre(r); cout<<s[7];
  return;
}

int main() {
  cin>>n;
  s[0]="____";
  s[1]="어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
  s[2]="\"재귀함수가 뭔가요?\"\n";
  s[3]="\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
  s[4]="마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
  s[5]="그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
  s[6]="\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
  s[7]="라고 답변하였지.\n";
  cout<<s[1];
  Recur(0);
}