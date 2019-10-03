#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 3e3+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);


int n , a[maxn], b[maxn] , c[maxn];
ll dp[maxn][4]; //0:a  , 1: c , 2: 0b , 3:b0



int main(){
    migmig
    cin >> n;
    for (int i= 0 ; i < n ; i ++){
        cin >> a[i];
    }
    for (int i = 0 ; i < n ; i++){
        cin >> b[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> c[i];
    }
    dp[0][0] = a[0];
    dp[0][1] = -1;
    dp[0][2] = b[0];
    dp[0][3] = -1;
    for (int i = 1 ; i < n ; i ++){
        dp[i][0] = max(dp[i-1][2] , dp[i-1][3])+a[i];
        dp[i][1] = max(dp[i-1][0] , dp[i-1][1]) + b[i];
        dp[i][2] = max(dp[i-1][2] , dp[i-1][3]) + b[i];
        dp[i][3] = max(dp[i-1][0] , dp[i-1][1]) + c[i];
    }
    cout << max(dp[n-1][0] , dp[n-1][1]);

    
}