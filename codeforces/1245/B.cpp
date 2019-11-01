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


int t , n , a  ,b , c;


int main (){
    migmig
    cin >> t;
    while(t--){
        cin >> n;
        cin >> a >> b >> c;
        int goal = (n+1)/2;
        int cnt =0 ;
        string s;
        cin >> s;
        char ans[1000];
        fill (ans , ans+200 , 'F');
        for (int i =0 ; i < n ; i ++){
            if (s[i] == 'R' and b > 0){
                ans[i]='P';
                cnt++;
                b--;
            }
            if (s[i] == 'P' and c > 0){
                ans[i]='S';
                cnt++;
                c--;
            }
            if (s[i] == 'S' and a > 0){
                ans[i]='R';
                cnt++;
                a--;
            }
        }
        if (cnt  < goal){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for (int i = 0 ; i < n; i ++){
                if (ans[i] == 'F'){
                    if (a > 0){
                        ans[i] = 'R';
                        a--;
                    }
                    else if (b){
                        b--;
                        ans[i] = 'P';
                    }
                    else{
                        c--;
                        ans[i] = 'S';
                    }
                }
            }
            for (int i = 0 ; i < n;  i++){
                cout << ans[i];
            }
            cout << endl;
        }
    }

    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
