#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n;
ld sum,tar;

struct tap{
	ll a , t;
}t[maxn];

bool cmp(tap x , tap y){
	return(x.t < y.t);
}

bool chk(ld x){
	ld mn=0 , mx=0 , sum = 0;
	for(int i = 0 ; i < n ; i ++)
		if(sum+t[i].a <= x)
			sum+=t[i].a , mn+=t[i].a*t[i].t;
		else {
			mn+=(x - sum)*t[i].t;break;}
	sum=0;
	for(int i = n-1 ; i >= 0 ; i --)
		if(sum+t[i].a <= x)
			sum+=t[i].a , mx+=t[i].a*t[i].t;
		else {
			mx+=(x - sum)*t[i].t;break;}
	return(mn<=tar*x and mx >= tar*x);
}

int main(){
    migmig
    cin >> n >> tar;
    cout << fixed << setprecision(9);
    for(int i = 0 ; i < n ; i ++)
		cin >> t[i].a;
	for(int i = 0 ;i < n ; i ++ )
		cin >> t[i].t;
	for(int i = 0 ; i < n ; i ++)
		sum+=t[i].a;
	sort(t , t+n , cmp);
	ld l = 0 , r = sum;
	for(int i = 0 ; i < 100 ; i ++){
		ld mid = (l + r)/2.0;
		if(chk(mid))
			l = mid;
		else
			r = mid;
	}
	dokme(l);
    return(0);
}