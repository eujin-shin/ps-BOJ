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
      // 각 최저가를 구함
    if(one_price < low_one_price) low_one_price = one_price;
      // 각 최저가를 구함
  }

  printf("%d %d\n", low_set_price, low_one_price);

  
  if(low_one_price * 6 > low_set_price){ // 뭐가 더 싼지 구함
    total_price += low_set_price*(N/6);
    N %= 6;
  }

  printf("%d\n", N);

// 남은 개수
// 낱개로 구매하는 것 vs 세트로 구매하는것 비교
  if(low_set_price < N * low_one_price) 
    printf("%d",total_price + low_set_price);

  else printf("%d",total_price + N*low_one_price);



}