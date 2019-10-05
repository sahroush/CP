#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 5e4+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int dp[maxn][102] , n , cnt[maxn][27];
char s[maxn];
string ans = "";

int main(){
    migmig
    //cin >> s;
    scanf("%s", s + 1);
    //n = sizeof(s);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++){
			cnt[i][j] = cnt[i - 1][j];
        }
		cnt[i][s[i] - 'a'] = i;
	}
    for (int i = 1; i <= n; i++){
		dp[i][0] = i + 1; //2
        dp[i][1] = i; // ++
    }
    for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= 100; j++) {
			dp[i][j] = dp[i -1][ j ];
			if (dp[i - 1][j - 2]){
				dp[i][j] = max(dp[i][j], cnt[dp[i - 1][j - 2] - 1][s[i] - 'a']);
            }
		}
	}
    int len = 100;
    while (!dp[n][len]) len--;
	int t = n;
	while (len > 1) {
		ans+=s[dp[t][len]];
		t = cnt[t][s[dp[t][len]] - 'a'] - 1;
		len -= 2;
	}
	//cout << ans;
    for (int i = 0 ; i < ans.size() ; i++){
        cout << ans[i];
    }
	if (len) cout << s[dp[t][len]];


	for (int i = ans.size()-1 ; i > -1 ; i--){
        cout << ans[i];
    }



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
