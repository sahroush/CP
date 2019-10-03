#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int  q , k;
double dp[10010][1001] , p;

int main(){
    migmig
    dp[1][1] = 1;

    double ep = 1e-7;
    cin >> k >> q;
    for (int i = 2 ; i < 10000 ; i++ ){
        for (int j = 1 ; j  < k+1 ; j++){

            dp[i][j] = dp[i-1][j]*((double)j/(double)k) + dp[i-1][j-1] *(((double)k-(double)j+1) / (double)k);
        }
    }
    /*
    for (int i = 0 ; i < 100 ; i ++){
        for (int  j = 0 ; j < 100 ; j ++){
            cout << dp[i][j] << '\t';
        }
        cout << endl;
    }
    */
    for (int i = 0 ; i < q ; i++){
        cin >> p;
        p = p-ep;
        p/=(double)2000;
        for (int i = 0 ; i < 10000 ; i ++){
            if(dp[i][k] >= p){
                cout << i << endl;
                break;
            }
        }

    }



}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
