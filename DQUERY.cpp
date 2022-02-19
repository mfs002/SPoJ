#include <bits/stdc++.h>
#define lc (x << 1)
#define rc (x << 1) | 1
using namespace std;

const int N = 3e4;
int a[N + 1], n, q;
int ST[4 * N];

struct node
{
    int l;
    int r;
    int ind;
};

bool comp(node n1, node n2)
{
    if (n1.r < n2.r) return true;
    return false;
}

void build(int x = 1, int l = 1, int r = n + 1)
{
    // Base Case
    if (l == r - 1)
    {
        ST[x] = 0;
        return;
    }

    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(lc + 1, mid, r);

    // Combine ST[lc] and ST[rc]]
    ST[x] = ST[lc] + ST[rc];
}

int query(int L, int R, int x = 1, int l = 1, int r = n + 1)
{
    // Base Case
    if (l >= R or r <= L) return 0;
    if (l >= L and r <= R) return ST[x];

    int mid = (l + r) / 2;
    int l_c = query(L, R, lc, l, mid);
    int r_c = query(L, R, lc + 1, mid, r);

    // Combine
    int ans = l_c + r_c;
    return ans;
}

void update(int pos, int val, int x = 1, int l = 1, int r = n + 1)
{
    if (pos < l or pos >= r) return;
    if (l == r - 1)
    {
        ST[x] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(pos, val, lc, l, mid);
    update(pos, val, lc + 1, mid, r);

    // Combine
    ST[x] = ST[lc] + ST[rc];
}

signed main()
{
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];

    cin>>q; vector<node> store; 
    vector<int> last_occurence(1000001, -1);

    int cnt = 0; int no_of_query = q;
    while(no_of_query--)
    {
        int l, r; cin>>l>>r;
        store.push_back({l, r, cnt});
        cnt++;
    }

    sort(store.begin(), store.end(), comp);
    vector<int> ans(q);
    build();

    // Current index of store[]
    int curr_ind = 0;
    for (int i=1; i<=n; i++)
    {
        if (last_occurence[a[i]] == -1)
        {
            update(i, 1);
            last_occurence[a[i]] = i;
        }

        else
        {
            update(last_occurence[a[i]], 0);
            update(i, 1);
            last_occurence[a[i]] = i;
        }

        // Check whether any query ends at i
        while (curr_ind < q and store[curr_ind].r <= i)
        {
            ans[store[curr_ind].ind] = query(store[curr_ind].l, (store[curr_ind].r)+1);
            curr_ind++;
        }
    }

    for (int i=0; i<q; i++) cout << ans[i] << '\n';
}