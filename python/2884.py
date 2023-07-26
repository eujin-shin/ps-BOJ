h, m = input().split()
h=int(h)
m=int(m)
if h==0 and m<45: 
  h=23
  m=15+m
elif m<45:
  h=h-1
  m=15+m
else:
  m=m-45
print(h, m)
