
def f(n):
	if n<=1:
		return 1;
	else:
		return n*f(n-1);

t= raw_input()
t = int(t)
for i in range(t):
	n = raw_input()
	n = long(n)
	print f(n)