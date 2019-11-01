#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e5+100;
const ll ZERO = 0;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);


string s;
ll dp[maxn];

int main (){
    migmig
    cin >> s;
    int n = s.size();
    for (int i = 0 ; i  < n ; i ++){
        if (s[i] == 'w' or s[i] == 'm'){
            dokme(0);
        }
    }
    /*
    ll ans = 1;
    vector <int> vec;
    int cnt =0 ;
    for (int i = 1 ; i < n ; i ++){
        if (s[i] == s[i-1] and (s[i] == 'u' or s[i] == 'n')){
            cnt++;
        }
        else if(cnt > 0){
            vec.push_back(cnt+1);
            cnt = 0;
        }
    }
    if(cnt > 0){
        vec.push_back(cnt+1);
        cnt = 0;
    }
    n = vec.size();
    for (int i =0 ; i  < n ; i ++){
        cout << vec[i] << '\t';
    }
    */
    dp[1] = 1;
    dp[0]=1;
    for (int i = 1 ; i < n; i ++){
        dp[i+1] = dp[i];
        if (s[i] == 'n' and s[i-1] == 'n'){
            dp[i+1]+=dp[i-1];
            dp[i+1]%=mod;
        }
        if (s[i] == 'u' and s[i-1] == 'u'){
            dp[i+1]+=dp[i-1];
            dp[i+1]%=mod;
        }
    }
    cout << dp[n];
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
