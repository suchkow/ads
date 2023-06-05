// https://informatics.msk.ru/mod/statements/view.php?id=33318#1
// https://pastebin.com/rzG4vCmc
#include<iostream>
#include<ctime>
#include<algorithm>
#include<vector>
#include<tuple>

using point = std::pair<int64_t, int>;

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<point> v;

    for (size_t i = 0; i < n; ++i)
    {
        int64_t L = 0;
        int64_t R = 0;

        std::cin >> L;
        std::cin >> R;

        v.emplace_back(L, 1);
        v.emplace_back(R, -1);
    }

    std::sort(v.begin(), v.end(), [&](const point &left, const point &right) {
        return std::tie(left.first, right.second) < std::tie(right.first, left.second);
    });
    std::vector<int> cnt(v.size());
    cnt[0] = 1;
    int64_t ans = 0;

    for (size_t i = 1; i < v.size(); ++i)
    {
        cnt[i] = cnt[i - 1] + v[i].second;
        if (cnt[i - 1] == 0) continue;
        ans += v[i].first - v[i - 1].first;
    }

    std::cout << ans;
    return 0;
}
