n = int(input())
list_a = list(map(int, input().split()))
list_b = list(map(int, input().split()))
list_a.sort()
list_b.sort(reverse=True)
sum = 0
for i in range(n):
  sum += list_a[i]*list_b[i]
print(sum)