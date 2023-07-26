#include <iostream>
#include <string>
using namespace std;

typedef struct NODE {
  int x;
  NODE *n;
} node;

typedef struct QUEUE {
  node *front, *rear;
  int count;
} queue;

queue *MakeQueue() {
  queue *head;
  head->count=0; 
  head->front=NULL; head->rear=NULL;
  return head;
}

node *MakeNode(int x) {
  node *newnode;
  newnode->x=x; newnode->n=NULL;
  return newnode;
}

void Print(queue *head, int k) {
  if(head->count==0) {
    cout<<"-1\n";
  } else if(k==0) {
    cout<<head->front->x<<'\n';
  } else if(k==1) {
    cout<<head->rear->x<<'\n';
  }
  return;
}

void Push(queue *head) {
  node *newnode;
  int x;
  cin>>x;
  newnode = MakeNode(x);
  newnode->n=head->front; head->front=newnode;
  head->count++;
  if(head->count==1) {
    head->rear=newnode;
  }
  return;
}

void Pop(queue *head) {
  if(head->count==0) {
    cout<<"-1\n"; return;
  }
  node *tmp;
  Print(head, 0);
  tmp=head->front;
  head->front=tmp->n;
  delete tmp;
  head->count--;
  return;
}

int Empty(queue *head) {
  if(head->count==0) return 0;
  return 1;
}

void DelQueue(queue *head) {
  node *del=head->front, *next;
  for(int i=0; i<head->count; i++) {
    next=del->n;
    delete del;
    del=next;
  }
  delete head;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  queue *head = MakeQueue();
  string input;
  int n, k;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input;
    if(input.compare("push")==0) Push(head);
    else if(input.compare("pop")==0) Pop(head);
    else if(input.compare("size")==0) cout<<head->count<<'\n';
    else if(input.compare("empty")==0) cout<<Empty(head)<<'\n';
    else if(input.compare("front")==0) Print(head, 0);
    else if(input.compare("back")==0) Print(head, 1);
  }
  // DelQueue(head);
  return 0;
}