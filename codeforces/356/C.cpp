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

int n;
int cnt[5];

int main(){
    migmig
    cin >> n;
    int sum = 0;
    for(int i = 0 ; i < n ; i ++){
		int x;cin >> x;sum+=x;cnt[x]++;}
    if(sum == 5 or sum < 3)dokme(-1);
    int ans = 0;
    if(cnt[1] > cnt[2]){
		ans+=cnt[2];
		cnt[3]+=cnt[2];
		cnt[1]-=cnt[2];
		ans+=cnt[1]/3*2;
		cnt[3]+=cnt[1]/3;
		cnt[1]%=3;
		if(cnt[1])
			ans+=2;
		if(cnt[1] == 1 and cnt[3])
			ans--;
	}
    else{
		ans+=cnt[1];
		cnt[3]+=cnt[1];
		cnt[2]-=cnt[1];
		ans+=cnt[2]/3*2;
		cnt[2]%=3;
		if(cnt[2])
			ans+=2;
		if(cnt[2]==1 and cnt[4])
			ans--;
	}
    cout << ans;
    return(0);
}