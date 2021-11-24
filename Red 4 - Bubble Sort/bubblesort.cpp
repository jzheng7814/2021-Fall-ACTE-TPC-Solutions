#include <bits/stdc++.h>

using namespace std;

struct query
{
    int l, r, jump, pos;
    long long int ans;

    bool operator<(const query& other) const
    {
        int idx_a = l / jump; int idx_b = other.l / jump;

        if (idx_a == idx_b)
        {
            return r < other.r;
        }
        else
        {
            return idx_a < idx_b;
        }
    }
};

class FenwickTree
{
    public:
        int arr[100000] = {};

        int sum(int ind)
        {
            int s = 0;
            for (int i = ind + 1; i > 0; i -= (i & -i))
            {
                s += arr[i];
            }

            return s;
        }

        void add(int ind, int val)
        {
            for (int i = ind + 1; i < 100000; i += (i & -i))
            {
                arr[i] += val;
            }
        }
};

int main()
{
    int N, Q; cin >> N >> Q;
    int n[N];
    query q[Q];

    for (int i = 0; i < N; ++i)
    {
        cin >> n[i];
    }

    int jump = sqrt(N);
    for (int i = 0; i < Q; ++i)
    {
        cin >> q[i].l >> q[i].r;
        q[i].jump = jump;
        q[i].pos = i;
    }

    sort(q, q + Q);

    int cL = 0, cR = -1, ele_cnt = 0;
    long long int inv = 0;
    FenwickTree f;
    for (int i = 0; i < Q; ++i)
    {
        int L = q[i].l, R = q[i].r;
        while (cR < R)
        {
            ++cR;
            inv += ele_cnt++ - f.sum(n[cR]);
            f.add(n[cR], 1);
        }

        while (cR > R)
        {
            f.add(n[cR], -1);
            inv -= (--ele_cnt - f.sum(n[cR--]));
        } 

        while(cL < L)
        {
            f.add(n[cL], -1);
            inv -= f.sum(n[cL++]);
            --ele_cnt;
        } 

        while (cL > L)
        {
            --cL;
            inv += f.sum(n[cL]);
            ++ele_cnt;
            f.add(n[cL], 1);
        } 

        q[i].ans = inv;
    }

    sort(q, q + Q, [](query a, query b)
    {
        return a.pos < b.pos;
    });

    for (int i = 0; i < Q; ++i)
    {
        cout << q[i].ans << endl;
    }
}