n = int(input())
results = []
for i in range (n):
  a, b = input().split()
  a = int(a)
  b = int(b)
  results.append(a+b)
for i in range (n):
  print(results[i])