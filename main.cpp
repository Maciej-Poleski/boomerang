#ifndef DEBUG
#define NDEBUG
#else
#define _GLIBCXX_CONCEPT_CHECKS
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cassert>
#include <unordered_map>
#include <map>
#include <set>
#include <unistd.h>
#include <fcntl.h>
#include <functional>

using namespace std;

struct Point
{
    int x, y;
};

static bool operator==(Point a, Point b)
{
    return (a.x == b.x) && (a.y == b.y);
}

static long dist2(Point a, Point b)
{
    assert(abs(a.x) <= 10000);
    assert(abs(a.y) <= 10000);
    assert(abs(b.x) <= 10000);
    assert(abs(b.y) <= 10000);
    long result = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return result;
}

static long combinations(int n)
{
    assert(n >= 0);
    return n * (n - 1) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int current = 1; current <= t; ++current) {
        int n;
        cin >> n;
        vector<Point> input(n);
        for (auto &p : input) {
            cin >> p.x >> p.y;
        }
        long result = 0;
        for (int i = 0; i < n; ++i) {
            vector<long> distances;
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                distances.push_back(dist2(input[i], input[j]));
            }
            sort(distances.begin(), distances.end());
            for (int i = 0; i < n - 1;) {
                int j = i;
                while ((j < n - 1) && (distances[j] == distances[i])) {
                    j += 1;
                }
                result += combinations(j - i);
                i = j;
            }
        }
        cout << "Case #" << current << ": " << result << '\n';
    }
}