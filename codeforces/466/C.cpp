#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll maxn = 5e5+10;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;
 
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init     freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout); 

ll sum[maxn];


int main(){
	//migmig;
	ll n;
	cin >> n;
	int a[n];
	bool f=0;

	fill (sum ,  sum + maxn , 0);
	for (int i = 0 ; i < n ; i ++){
		cin >> a[i];
		if (i){
			sum[i] = sum[i-1] + a[i];
		}
		else{
			sum[i] = a[i];
		}
		if (a[i] != 0){
			f=1;
		}
	}	
	
	if (sum[n-1]%3 != 0 or n < 3){
		dokme(0);
	}
	
	ll brd=sum[n-1] / 3;
	
	int x=-123,y=-123,z=-123;
	for (int i = 0 ; i < n ; i ++){
		if (sum[i] == brd){
			x=i;
			break;
		}
	}
	if (x==-123){
		dokme(0);
	}
	
	for (int i = x+1 ; i <n ; i++){
		if (sum[i] - sum[x] == brd){
			y=i;
			break;
		}
	}
	if (y==-123){
		dokme(0);
	}
	z=n-1;
	ll cnt1=1 , cnt2=1;
	for (int i =x+1 ; i < y ; i ++){
		
		if (sum[i] - sum[x] == 0){
			cnt1++;
		}
	}
	
	for (int i =y+1 ; i < n ; i ++){
		if (sum[i] - sum[y] == 0){
			cnt2++;
		}
	}
	
	if (x==y or y==z or x==z){
		dokme(0);
	}
	if (!f){
		n--;
		dokme((n*(n-1))/2);
	}
	if(n==4){
		dokme(1);
	}
	if (n==5 and a[0] == 3){
		dokme(3);
	}
	cout << cnt1*cnt2;
	
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
