n = int(input())
li = list(map(int, input().split()))
max = max(li)
for i in range(n):
  li[i] = li[i]/max*100
sum = 0
for i in range(n):
  sum += li[i]
print(sum/n)