#include <ctime>
#include <cstdio>
#include <cmath>

class Solution {
public:
    int daysBetweenDates(string d1, string d2) {
        auto f = [](string s) {
            tm t = {};
            sscanf(s.c_str(), "%d-%d-%d", &t.tm_year, &t.tm_mon, &t.tm_mday);
            t.tm_year -= 1900; t.tm_mon -= 1;
            return mktime(&t) / 86400;
        };
        return abs(f(d1) - f(d2));
    }
};

