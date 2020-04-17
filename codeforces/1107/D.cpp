#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s[maxn];
int n;

int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n; i ++){
		cin >> s[i];
		string str = "";
		for(auto j : s[i]){
			if(j == '0')
				str+="0000";
			if(j == '1')
				str+="0001";
			if(j == '2')
				str+="0010";
			if(j == '3')
				str+="0011";	
			if(j == '4')
				str+="0100";
			if(j == '5')
				str+="0101";	
			if(j == '6')
				str+="0110";
			if(j == '7')
				str+="0111";
			if(j == '8')
				str+="1000";
			if(j == '9')
				str+="1001";
			if(j == 'A')
				str+="1010";
			if(j == 'B')
				str+="1011";
			if(j == 'C')
				str+="1100";
			if(j == 'D')
				str+="1101";
			if(j == 'E')
				str+="1110";
			if(j == 'F')
				str+="1111";
		}
		s[i] = str;
	}
	int ans = 0;
    for(int i = 0 ; i < n ; i ++){
		int cnt =1 , cnt2 = 1;
		for(int j = 0 ; j < n-1 ; j ++){
			if(s[i][j] == s[i][j + 1]){
				cnt++;
			}
			else{
				ans = __gcd(ans , cnt);
				cnt = 1;
			}
			if(s[j][i] == s[j+1][i]){
				cnt2++;
			}
			else{
				ans = __gcd(ans , cnt2);
				cnt2 = 1;
			}
		}
		ans = __gcd(ans , cnt);
		ans = __gcd(ans , cnt2);
	}
	cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
