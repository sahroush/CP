#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 111;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , m , len[maxn] , a[maxn][maxn] ;
int mxval[maxn][maxn] , prt[maxn];
int dp[maxn][10010];

int main(){
    migmig
    cin >> n >> m;
    for (int i = 0 ; i < n ; i ++){
        cin >> len[i];
        for (int j = 0 ; j < len[i] ;  j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0 ; i < n ; i++){
        fill(prt , prt + maxn , 0);
        for (int j = 0 ; j <= len[i] ; j++){
            if (j){
                prt[j] = a[i][j-1] + prt[j-1];
            }
            else{
                prt[j] = 0;
            }
        }
        fill(mxval[i] , mxval[i] + maxn , 0 );
        for(int j = 1 ; j  <= len[i] ; j ++){
            for (int k = 0 ; k <= j ; k++){
                mxval[i][j] = max(mxval[i][j] ,prt[k]+prt[len[i] ]- prt[len[i] - (j - k) ] );
            }
        }
    }
    for (int i = 0; i <= 100 ; i ++) {

        dp[i][0] = 0;
    }
    if (n == 1){
        dokme(mxval[0][m]);
    }
    for (int i = 0 ; i < n ; i++){
        if (i){

            dp[i][1] = max(dp[i-1][1] , mxval[i][1]);
        }
        else{
            dp[i][1] = mxval[i][1];
        }
    }
    for (int i = 0 ; i < n ; i ++){ // ta i biaim
        for (int j = 2 ; j <= m ; j ++){ // m
            dp[i][j] = 0;
            for (int k = 0 ; k <= len[i] ; k++){
                if (j - k >= 0 and i){
                    dp[i][j] = max(dp[i][j] , dp[i-1][j-k] + mxval[i][k]);
                }
                else if (i == 0){
                    dp[i][j] = mxval[0][min(j , len[i])];
                }
            }
        }
    }

    cout << dp[n-1][m];



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
