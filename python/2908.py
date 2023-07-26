num_list = list(map(int, input().split()))
ans_list = [0, 0]
for i in range(len(num_list)):
  x=num_list[i]
  y=ans_list[i]
  for l in range(1,4):
    n=1000
    for k in range(l):
      n=n//10
    y=y+x%10*n
    x=x//10
  ans_list[i]=y
if ans_list[0]>ans_list[1]:
  print(ans_list[0])
else:
  print(ans_list[1])