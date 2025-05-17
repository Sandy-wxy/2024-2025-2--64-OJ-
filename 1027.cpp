#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int a[26];

// 函数检查给定的k是否能杀掉所有的坏人
bool fun(int m, int k)
{
    int sum = 2 * m;
    int i = 0; // 报数位置
    for (int j = 0; j < m; j++)
    {
        i = (i + k - 1) % sum;
        if (i < m)
            return false;
        --sum;
        if (i == sum)
            i = 0;
    }
    return true;
}

int find(int m)
{
    int k = m + 1;
    while (true)
    {
        if (fun(m, k))
            return k;
        ++k;
    }
}
int main()
{
    int n;
    while (cin >> n)
    {
        cout << find(n) << endl;
    }

    return 0;
}