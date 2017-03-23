t = raw_input()
t = int(t)

def f_down(i):
	return i&(i+1)

while t:
	t=t-1
	# print "case "+str(t)
	l_all = raw_input()
	l_all = l_all.split(' ')
	l3 = int(l_all[0],2)
	l2 = int(l_all[1],2)
	l1 = int(l_all[2],2)
	n = l_all[3]
	n=int(n)
	# l = l1+l2*n+l3
	# deci = int(l,2)
	count =0
	if l1==0 and l2==0 and l3==0:
		print 1
		continue

	flag=0

	if l_all[2]=='1'*len(l_all[2]):
		if l_all[1]=='1'*len(l_all[1]):
			flag=1
			count=1
			l3 = f_down(l3)
		else:
			l1 = (l2)<<len(l_all[2]) + l1
			n=n-1

	while l1>=0 and flag==0:
		l1 = f_down(l1)
		l1 = l1-1
		count=count+1

	count2 = 0

	# l2=l2-1

	l2=l2-1

	while l2>=0 and flag==0:
		l2 = f_down(l2)
		l2 = l2-1
		count2=count2+1

	# print "count2 ",count2

	count2=count2*n

	# count=count+1
	# l3=f_down(l3)-1
	l3 = l3-1
	# print "l3 ",l3

	if l3==0:
		count=count+1

	while l3>0:
		l3 = f_down(l3)
		l3 = l3-1
		count=count+1

	# print count

	print count+count2