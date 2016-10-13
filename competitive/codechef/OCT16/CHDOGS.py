t = raw_input()
t = int(t)

while t:
	t=t-1
	sn = raw_input()
	s = int(sn.split(' ')[0])
	n = int(sn.split(' ')[1])
	print float(99.00000000*float(s)/float(n))