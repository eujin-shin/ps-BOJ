a, b = input().split()
sum = 0
sumN = 0
if len(a)>len(b):
  n = a
  m = b
else:
  n = b
  m = a
for i in range(len(n)):
  sumN = sumN + int(n[i])
for i in range(len(m)):
  sum = sum + int(m[i])*sumN
print(sum)