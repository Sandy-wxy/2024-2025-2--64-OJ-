#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

struct MoonCake
{
    LL eat_time, expire_moment, happy;

    bool operator<(MoonCake other) const
    {
        if (expire_moment != other.expire_moment)
            return expire_moment < other.expire_moment;
        else if (eat_time != other.eat_time)
            return eat_time < other.eat_time;
        else
            return happy < other.happy;
    }
};

LL get_num_required_cakes(LL expire_moment, const vector<MoonCake> &cakes)
{
    struct Cmp
    {
        bool operator()(MoonCake cake, LL expire_moment) const
        {
            return cake.expire_moment < expire_moment;
        }

        bool operator()(LL expire_moment, MoonCake cake) const
        {
            return expire_moment < cake.expire_moment;
        }
    };
    return lower_bound(cakes.begin(), cakes.end(), expire_moment, Cmp()) - cakes.begin();
}

void max_update(LL &target, LL other)
{
    if (other > target)
        target = other;
}

int main()
{
    LL n = 0, max_time = 0, total_eat_time = 0, total_happy = 0, best_happy = 0;
    cin >> n >> max_time;
    vector<MoonCake> cakes(n);
    for (LL i = 0; i < n; ++i)
        cin >> cakes[i].eat_time >> cakes[i].expire_moment >> cakes[i].happy;
    sort(cakes.begin(), cakes.end());
    for (LL i = 0; i < n; ++i)
    {
        if (cakes[i].expire_moment < total_eat_time + cakes[i].eat_time)
            continue;
        total_eat_time += cakes[i].eat_time;
        if (total_eat_time > max_time)
            break;
        total_happy += cakes[i].happy;
        if (get_num_required_cakes(total_eat_time, cakes) <= i + 1)
            max_update(best_happy, total_happy);
    }
    cout << best_happy << '\n';
}
