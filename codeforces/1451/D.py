q = int(input())

def f(d , k):
	l = 0
	r = 100011
	if(k == d):
		return("Ashish");
	while(r - l > 1):
		mid = (l + r)//2;
		if((k*mid)*(k*mid) * 2 <= d*d):
			l = mid;
		else:
			r = mid;
	if((k*l)*(k*l) + (k*(l+1))*(k*(l+1)) > d*d):
		return("Utkarsh")
	return("Ashish")

while(q!=0):
	q -= 1;
	(d , k) = tuple(map(int , input().split()))
	print(f(d , k))
