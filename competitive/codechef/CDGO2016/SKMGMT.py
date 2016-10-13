t = raw_input()
t= int(t)

while t:
	t=t-1
	time=[]
	j=[]
	nm = raw_input()
	n = int(nm.split(' ')[0])
	m = int(nm.split(' ')[1])
	# print "nm done"
	temp = n

	while temp:
		tj = raw_input()
		ti = int(tj.split(' ')[0])
		ji = int(tj.split(' ')[1])
		time.append(ti)
		j.append(ji)
		temp=temp-1

	# print n,m

	ts = raw_input()
	ts = ts.split(' ')
	ts = [int(tsi) for tsi in ts]
	max_time = max(ts)

	vals = []
	vals.append([0 for k in range(max_time+1)])
	for k in range(1,n+1):
		vals.append([])
		# print k
		for z in range(0,max_time+1):
			if z==0:
				vals[k].append(0)
			else:
				if time[k-1] < z:
					vals[k].append(max(vals[k-1][z] , j[k-1]+vals[k-1][z-time[k-1]] ))
				elif time[k-1]==z:
					vals[k].append(max(vals[k-1][z] , j[k-1]))
				else:
					vals[k].append(vals[k-1][z])
				# print vals[k]

	for k in ts:
		print vals[n][k],