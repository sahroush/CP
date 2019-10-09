#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , q , a[maxn];
ll r;
bool f[maxn];
int  dq[maxn];


int main(){
    migmig
    cin >> q;
    std::set<int>::iterator it;
    for (int ff = 0 ; ff < q ; ff ++){
        cin >> n >> r;
        //fill(f , f+maxn , 0);
        fill(dq , dq+n+10 , 0);
        int pos = 0;
        for (int i = 0 ; i < n ; i ++){
            cin >> a[i];
            if (f[a[i]] == 0){
                dq[pos] = a[i];
                pos++;
            }
            f[a[i]] = 1;
        }

        sort(dq , dq+pos);
        //reverse(dq , dq+pos);
        pos--;

        ll cnt = 0 ;
        int ans = 0;
        if (pos == 0){
            cout << 1 << endl;
        }
        else{
            while(1){
                //cout << dq[pos];
                if (dq[pos] - (cnt*r) > 0 and pos>0){
                    pos--;
                    cnt++;
                    ans++;

                }
                else if(dq[pos] - (cnt*r) > 0 and pos == 0){
                    cout << cnt+1 << endl;
                    break;
                }

                else{
                    cout << ans << endl;
                    break;
                }

            }
        }
        for (int i = 0 ; i<n ; i++){
        	f[dq[i]] = 0;
        }


        //cout << ans << endl;

    }



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
