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

struct cir{
	ld x ,  y , r;
};

cir a , b;

ld area(cir A, cir B) {

    ld d = (A.x - B.x)*(A.x - B.x) + (A.y - B.y) * (A.y - B.y)  ;
	ld dsq = sqrt(d);
	ld r2 = (A.r - B.r) * (A.r - B.r);
    if(r2 >= d){
		return(PI * min(A.r , B.r) * min(A.r , B.r) );
	}
	r2 = (A.r + B.r) * (A.r + B.r);
    if(d >= r2)
		return(0);
	r2 = (A.r - B.r) * (A.r - B.r);
	ld cos1 = acosl((B.r * B.r - A.r * A.r + d)/(B.r*2*dsq));
	ld cos2 = acosl((A.r * A.r - B.r * B.r + d)/(A.r*2*dsq));
	return((A.r*A.r)*(cos2 - cosl(cos2) * sinl(cos2)) + (B.r*B.r)*(cos1 - cosl(cos1) * sinl(cos1)));
}

int main(){
    migmig
    //fuck geo
    //https://www.xarg.org/2016/07/calculate-the-intersection-area-of-two-circles/
    cin >> a.x >> a.y >> a.r;
    cin >> b.x >> b.y >> b.r;
    cout << fixed << setprecision(10) << area(a , b);
    return(0);
}