t=raw_input()
t=int(t)

file = open('out.txt','w+')
count=1
while t:
	t=t-1
	n = raw_input()
	n=int(n)
	e ={'':1}
	dep={}
	lhs={}
	vals=[]
	while n:
		n=n-1
		s = raw_input()
		vals.append(s)
		ls = s.split('=')
		lh = ls[0]
		# print 'lh is ',lh
		rh=ls[1]
		# print 'rh is ',rh
		rl1 = rh.split('(')
		rl2 = rl1[1].split(')')
		args = rl2[0].split(',')
		# print 'args ', args
		dep[lh]=args
		flag=1
		# if args==['']:
		# 	args=[]

		for k in args:
			if k not in e:
				# print k,' is not in ',e
				e[k]=0
				flag=0
			elif e[k]!=1:
				flag=0
		lhs[lh]=1
		if flag:
			e[lh]=1
		else:
			e[lh]=0

	print dep

	for k in vals:
		ls = k.split('=')
		lh = ls[0]
		rh=ls[1]
		rl1 = rh.split('(')
		rl2 = rl1[1].split(')')
		args = rl2[0].split(',')
		flag=1
		# print ' args again ',args

		for z in args:
			if e[z]!=1 and (z not in lhs):
				if z not in dep:
					flag=0
				elif ((lh not in dep[z])):
					# print ' z is nt in ',e
					flag=0
		if flag:
			# print " here it is"
			e[lh]=1

	fl=1
	for p in e:
		if e[p]!=1:
			# print e
			fl=0
			break
	if fl:
		print "GOOD"
		print e
		file.write('Case #'+str(count)+':'+"GOOD\n")
	else:
		print "BAD"
		file.write('Case #'+str(count)+':'+"BAD\n")
	count=count+1