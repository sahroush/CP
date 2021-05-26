#include <bits/stdc++.h>

using namespace std;

int n , a[3010];
int64_t ans;
priority_queue < int > pq;

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n, pq.push(-1);
	for(int i = 1 ; i <= n ; pq.push(a[i]) , i ++){
		cin >> a[i] , a[i] -= i , a[i] += n;
		if(a[i] < pq.top()) ans += pq.top() , pq.pop() , pq.push(a[i]) , ans -= a[i];
	}
	cout << ans;
	return(0);
}
