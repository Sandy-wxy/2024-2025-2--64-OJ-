#include <bits/stdc++.h>
using namespace std;
int t;
int n1, n2, n3;
char H[26] = {0};
string a1, a2, a3;

bool dfs(int i, int j, int k)
{

    if (i >= n1 || j >= n2 || k >= n3)
        return false;
    if (i == n1 - 1 && j == n2 - 1 && k == n3 - 1)
        return true;
    bool r1 = 0, r2 = 0;
    if (a1[i + 1] == a3[k + 1])
    {
        r1 = dfs(i + 1, j, k + 1);
        if (r1)
        {
            //            cout<<i<<" "<<j<<" "<<k<<" "<<r1<<endl;
            return r1;
        }
    }
    if (a2[j + 1] == a3[k + 1])
    {
        r2 = dfs(i, j + 1, k + 1);
        if (r2)
        {
            //            cout<<i<<" "<<j<<" "<<k<<" "<<r2<<endl;
            return r2;
        }
    }
    //    cout<<i<<" "<<j<<" "<<k<<" "<<(r1|r2)<<endl;
    return r1 | r2;
}

void s()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a1 >> a2 >> a3;
        n1 = a1.size(), n2 = a2.size(), n3 = a3.size();
        //  bool flag = 1;
        //     for (int i = 0; i < 26; i++)
        //     {
        //         if (H[i] != 0)
        //         {
        //             flag = 0;
        //             H for (int i = 0; i < n1; i++)
        //         H[a1[i] - 'a']++;
        //     for (int i = 0; i < n2; i++)
        //         H[a2[i] - 'a']++;
        //     for (int i = 0; i < n3; i++)
        //         H[a3[i] - 'a']--;
        //    [i] = 0;
        //         }
        //     }
        //     if (!flag)
        //     {
        //         cout << "NO" << endl;
        //         continue;
        //     }
        int result = dfs(-1, -1, -1);
        if (result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int main()
{
    s();
    return 0;
}