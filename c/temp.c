#include <stdio.h>

int main(){
  int N,M;
  int set_price,one_price;
  int total_price = 0;
  int low_set_price = 1000, low_one_price = 1000;

  scanf("%d %d",&N,&M);

  for(int i = 0;i<M;i++){
    scanf("%d %d",&set_price,&one_price);
    if(set_price < low_set_price) low_set_price = set_price;
      // �� �������� ����
    if(one_price < low_one_price) low_one_price = one_price;
      // �� �������� ����
  }

  printf("%d %d\n", low_set_price, low_one_price);

  
  if(low_one_price * 6 > low_set_price){ // ���� �� ���� ����
    total_price += low_set_price*(N/6);
    N %= 6;
  }

  printf("%d\n", N);

// ���� ����
// ������ �����ϴ� �� vs ��Ʈ�� �����ϴ°� ��
  if(low_set_price < N * low_one_price) 
    printf("%d",total_price + low_set_price);

  else printf("%d",total_price + N*low_one_price);



}