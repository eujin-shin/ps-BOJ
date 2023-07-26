n = int(input())
num_set = list(map(int, input().split()))
num_set.sort()
sum = 0
for i in range(n):
  sum += num_set[i]*(n-i)
print(sum)