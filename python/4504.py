n = int(input())
while True:
  x = int(input())
  if not x:
    break
  elif not x%n:
    print("%d is a multiple of %d." % (x, n))
  else:
    print("%d is NOT a multiple of %d." %(x, n))