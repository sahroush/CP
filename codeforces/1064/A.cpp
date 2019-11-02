#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int t , a , b, c  , d, k , mn= 1000;;

int main(){
    migmig;
    cin >> a >> b >> c;
    if (a+b > c and a + c > b and c+b > a){
        dokme(0);
    }
    else{
        int p = a;

        while (!(p+b > c and p + c > b and c+b > p)){
            p++;
            if (p > 1000){
                break;
            }
        }
        mn= min(mn , p - a);
        p  = b;
        while (!(a+p > c and a + c > p and c+p > a)){
            p++;
            if (p > 1000){
                break;
            }
        }
        mn= min(mn , p - b);
        p  = c;
        while (!(a+b > p and a + p > b and p+b > a)){
            p++;
            if (p > 1000){
                break;
            }
        }
        mn= min(mn ,p - c);
    }
    dokme(abs(mn));



    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
