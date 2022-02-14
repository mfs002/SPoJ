#include <bits/stdc++.h>
using namespace std;

signed main()
{
	string a; cin >> a; int n = a.length();

	// preprocess
	vector<vector<int>> pref_par(n + 1, vector<int> (26, -1));
	for (int i = 0; i < 26; i++)
	{
		int freq = 0;
		for (int j = 0; j < n; j++)
		{
			pref_par[j + 1][i] = pref_par[j][i];
			if ((a[j] - 'a') == i)
			{
				freq++;
				pref_par[j + 1][i] = (freq & 1);
			}
		}
	}

	int q; cin >> q;
	while (q--)
	{
		int l, r; cin >> l >> r; char ch; cin >> ch;

		int par_r = pref_par[r + 1][ch - 'a'], par_l = pref_par[l][ch - 'a'];
		int ans = 0;

		if (par_l == -1 and par_r != -1) ans = par_r;
		else if (par_l == -1 and par_r == -1) ans = -1;
		else ans = par_l ^ par_r;

		cout << ans << endl;
	}
}