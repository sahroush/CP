//*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn  = 5e5+10;

#define pb push_back
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

namespace suffix_array {
template <class T>
void induce(int n, const T s[], bool isL[], int sa[], int l_head[], int B) {
    int buf[B + 2];
    copy_n(l_head, B + 2, buf);

    for (int i = 0; i < n; ++i) {
        if (sa[i] > 0 && isL[sa[i] - 1]) {
            int pos = (int)s[sa[i] - 1];
            sa[buf[pos]++] = sa[i] - 1;
        }
    }

    copy_n(l_head, B + 2, buf);

    for (int i = n - 1; i >= 0; --i) {
        if (sa[i] > 0 && !isL[sa[i] - 1]) {
            int pos = (int)s[sa[i] - 1];
            sa[--buf[pos + 1]] = sa[i] - 1;
        }
    }
}

// sentinel must be added to the end of s in advance

template <class T>
void SA_IS(int n, const T s[], int sa[], int B = 200) {
    bool isL[n];

    isL[n - 1] = false;

    for (int i = n - 2; i >= 0; --i) {
        isL[i] = (s[i] > s[i + 1] || (s[i] == s[i + 1] && isL[i + 1]));
    }

    int l_head[B + 2] = {0};

    for (int i = 0; i < n; ++i) ++l_head[(int)s[i]];

    int sum = 0;

    for (int i = 0; i <= B + 1; ++i) {
        l_head[i] += sum;
        swap(sum, l_head[i]);
    }

    vector<int> lms;
    int lms_id[n];

    fill_n(lms_id, n, -1);

    int buf[B + 2];
    copy_n(l_head, B + 2, buf);

    int now = 0;

    fill_n(sa, n, -1);

    for (int i = 1; i < n; ++i) {
        if (isL[i - 1] && !isL[i]) {
            lms_id[i] = now++;
            lms.push_back(i);
            sa[--buf[(int)s[i] + 1]] = i;
        }
    }

    vector<int> lms2 = lms;
    induce(n, s, isL, sa, l_head, B);

    now = 0;

    for (int i = 0; i < n; ++i) {
        if (lms_id[sa[i]] != -1) {
            lms[now++] = sa[i];
        }
    }

    int s_lms[now], sa_lms[now + 1];

    now = 0;
    s_lms[lms_id[lms[0]]] = 0;

    for (int i = 1; i < lms.size(); ++i) {
        int u = lms[i - 1], v = lms[i];

        bool diff = false;

        for (int j = 0; j < n; ++j) {
            if (s[u + j] != s[v + j] || isL[u + j] != isL[v + j]) {
                diff = true;
                break;
            }

            if (j > 0 && (lms_id[u + j] != -1 || lms_id[v + j] != -1)) break;
        }

        if (diff) now++;
        s_lms[lms_id[lms[i]]] = now;
    }

    if (now + 1 != lms.size()) {
        SA_IS(lms.size(), s_lms, sa_lms, now);
    } else {
        for (int i = 0; i < lms.size(); ++i) {
            sa_lms[s_lms[i]] = i;
        }
    }

    for (int i = 0; i < lms.size(); ++i) {
        lms[i] = lms2[sa_lms[i]];
    }

    copy_n(l_head, B + 2, buf);

    fill_n(sa, n, -1);

    for (int i = (int)lms.size() - 1; i >= 0; --i) {
        int p = s[lms[i]];
        sa[--buf[p + 1]] = lms[i];
    }

    induce(n, s, isL, sa, l_head, B);
}

template <class T>
void LCP(int n, const T s[], const int sa[], int lcp[]) {
    int rsa[n + 1];
    for (int i = 0; i <= n; i++) {
        rsa[sa[i]] = i;
    }

    int h = 0;
    for (int i = 0; i < n; i++) {
        int j = sa[rsa[i] - 1];

        if (h > 0) h--;
        for (; j + h < n && i + h < n; h++) {
            if (s[j + h] != s[i + h]) break;
        }
        lcp[rsa[i] - 1] = h;
    }
}
};  // namespace suffix_array
char s[maxn];
int n;
int a[maxn];
vector < int > pos[2*maxn];
int stk[maxn];
int R[maxn];

int sa[maxn] , lcp[maxn];

int32_t main(){
    migmig;
    cin >> n;
    cin >> s;
    suffix_array::SA_IS(n + 1, s, sa);
    suffix_array::LCP(n, s, sa, lcp);
	a[n+1] = -1e9;
	for(int i = 1 ; i <= n ; i ++)
		a[i] = ((i)? a[i - 1] : 0) + ((s[i-1] == '(')? 1 : -1);
	for(int i = 0 ; i <= n ; i ++)pos[a[i] + maxn].pb(i);
	int st = 0;
	stk[++st] = n+1;
	for(int i = n ; i >= 0 ; i --){
		while(st and a[i] <= a[stk[st]])st--;
		if(st)R[i] = stk[st] - 1;
		stk[++st]=i;
	}
	ll ans = 0;
	for(int i = 0 ; i < n ; i ++){
		if(s[sa[i]] == ')')break;
		int l = sa[i] + lcp[i] + 1;
		int r = R[sa[i]];
		if(l > r)continue;
		auto &v = pos[a[sa[i]] + maxn]; 
		ans+=(upper_bound(v.begin() , v.end() , r) - 
		 lower_bound(v.begin() , v.end() , l ) );
	}
	cout << ans;
    return(0);
}
