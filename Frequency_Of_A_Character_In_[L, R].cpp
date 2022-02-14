#include <bits/stdc++.h>
using namespace std;

signed main()
{
    string a; cin >> a; int n = a.length();

    // preprocess
    vector<vector<int>> pref_cnt(n + 1, vector<int> (26, 0));
    for (int i = 0; i < 26; i++)
    {
        int freq = 0;
        for (int j = 0; j < n; j++)
        {
            pref_cnt[j + 1][i] = pref_cnt[j][i];
            if ((a[j] - 'a') == i)
            {
                freq++;
                pref_cnt[j + 1][i] = freq;
            }
        }
    }

    int q; cin >> q;
    while (q--)
    {
        int l, r; cin >> l >> r; char ch; cin >> ch;

        int cnt_r = pref_cnt[r + 1][ch - 'a'], cnt_l = pref_cnt[l][ch - 'a'];
        int ans = cnt_r - cnt_l;

        cout << ans << endl;
    }
}