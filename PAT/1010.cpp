/**
 * 1010 Radix
 * link: https://pintia.cn/problem-sets/994805342720868352/problems/994805507225665536
 */

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int convert(char c)
{
    if (isdigit(c))
        return c - '0';
    else
        return 10 + c - 'a';
}

ll convert(string &s, ll radix)
{
    ll sum = 0;
    ll base = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        sum += convert(s[i]) * base;
        base *= radix;
    }
    return sum;
}

ll find_radix(string &n, ll input)
{
    char it = *max_element(n.begin(), n.end());
    ll low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;

    ll high = max(input, low);
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll t = convert(n, mid);
        if (t < 0 || t > input)
            high = mid - 1;
        else if (t == input)
            return mid;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    string n1, n2;
    int tag;
    ll radix, result;

    cin >> n1 >> n2 >> tag >> radix;
    result = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result != -1)
        cout << result << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}