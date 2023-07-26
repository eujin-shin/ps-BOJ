#include <iostream>
#include <vector>
#define MAX 1000000000
using namespace std;

typedef struct trie {
  bool end;
  struct trie* link[10];
} TRIE;

void initTrie(TRIE *cur) {
  cur->end=false;
  for(int i=0; i<10; i++) {
    cur->link[i]=NULL;
  }
}

bool InsertTrie(TRIE *head, long long data) {
  bool ret=false;
  TRIE *cur=head;
  int x;
  long long c=MAX;
  while(c>data) {
    c/=10;
  }
  while(c) {
    x=data/c; data%=c; c/=10;
    if(cur->link[x]==NULL) {
      cur->link[x]=(TRIE *)malloc(sizeof(trie));
      initTrie(cur->link[x]);
      if(cur->end) {
        ret=true;
      }
    } else if(c==0) {
      ret=true;
    }
    cur=cur->link[x];
  }
  cur->end=true;
  return ret;
}

void DelTrie(TRIE *cur) {
  for(int i=0; i<10; i++) {
    if(cur->link[i]!=NULL) {
      DelTrie(cur->link[i]);
    }
  }
  free(cur);
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  long long data;
  bool flag, res;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    flag=false;
    TRIE *head=(TRIE *)malloc(sizeof(TRIE));
    initTrie(head);
    while(n--) {
      scanf("%lld", &data);
      if(flag) continue;
      res=InsertTrie(head, data);
      if(res) flag=true;
    }
    if(flag) printf("NO\n");
    else printf("YES\n");
    DelTrie(head);
  }
  return 0;
}