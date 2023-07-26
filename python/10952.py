a, b = map(int, input().split())
sum = []
while ((a+b)>0):
  sum.append(a+b)
  a, b = map(int, input().split())
for i in range (len(sum)):
  print(sum[i]) 
