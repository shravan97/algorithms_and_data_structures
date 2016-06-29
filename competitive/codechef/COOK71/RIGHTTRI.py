import math
t = raw_input()
t = int(t)

while t :
	vals=raw_input()
	ls = vals.split(' ')
	h=long(ls[0])
	s=long(ls[1])
	if h*h < 4*s:
		print -1
	else:
		s1 = float(math.sqrt((h*h + math.sqrt(pow(h,4) - 16*s*s))/2.0))
		s2 = float(math.sqrt((h*h - math.sqrt(pow(h,4) - 16*s*s))/2.0))
		print s2 , ' ' , s1 , ' ','%.6f' % round(float(h))
	t=t-1