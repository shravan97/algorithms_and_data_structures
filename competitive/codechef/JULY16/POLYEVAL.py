a = raw_input()
a = long(a)
coeff_list = raw_input()
coeff_list = coeff_list.split(' ')
coeff_list = [long(k) for k in coeff_list]
q = raw_input()
q = long(q)

while q>0:
	x = raw_input()
	x = long(x)
	totsum=0
	count=0

	for k in coeff_list:
		totsum+= ((k%786433)*pow(x,count,786433))
		count+=1
	print totsum
	q=q-1