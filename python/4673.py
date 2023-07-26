ans = []
for i in range(10000):
  ans.append(i+1)
for i in range(10000):
  a = i+1
  sum = a
  while a>0:
    sum += a%10
    a = a//10
  '''print(sum)'''
  if sum>10000:
    continue
  else:
    ans[sum-1] = 0
for i in range(10000):
  if ans[i] == 0:
    continue
  else:
     print(ans[i])