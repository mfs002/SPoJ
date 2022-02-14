#include <bits/stdc++.h>
using namespace std;

vector<int> index[26];

signed main()
{
	string a; cin >> a; int n = a.length();

	for (int i = 0; i < n; i++) index[a[i] - 'a'].push_back(i);
	for (int i = 0; i < n; i++) index[a[i] - 'a'].push_back(1e9);

	int q; cin >> q;
	while (q--)
	{
		int l, r; cin >> l >> r; char ch; cin >> ch;

		// Corner Case
		if (index[ch - 'a'].size() == 0) cout << 0 << endl;

		else
		{
			int l_b = lower_bound(index[ch - 'a'].begin(), index[ch - 'a'].end(), l) - index[ch - 'a'].begin();
			int u_b = lower_bound(index[ch - 'a'].begin(), index[ch - 'a'].end(), r) - index[ch - 'a'].begin();
			int cnt = u_b - l_b;

			if (u_b < 1e9 and index[ch - 'a'][u_b] == r) cnt++;
			cout << cnt << endl;
		}
	}
}