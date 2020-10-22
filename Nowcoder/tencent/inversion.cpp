/**
 * [编程题]逆序对
 * https://www.nowcoder.com/questionTerminal/8fe007e54fc04b5e82089aaa71ba3553
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 20
#define MAX_INPUT (1 << 20)

int input[MAX_INPUT];
int tmp[MAX_INPUT];
long long result[MAX_N + 1];
long long reverse_result[MAX_N + 1];


// Calculate the number of inversion pairs between 2^i and 2^i (0 <= i <= n)
// and record the number of inversions after they are flipped at the same time.
// There are 2^(2i-2) combinations between 2^i and 2^i (0 <= i <= n).
// if there are t inversions and k pairs of the same number such as (a,a)
// after they are flipped, there are 2^(2i-2) - t - k inversions.
void merge(int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;

    merge(l, mid);
    merge(mid + 1, r);

    long long inv_count = 0;
    int i = l, j = mid + 1;
    int pos = l;

    long long same = 0;
    int continuous_l = input[l];
    int continuous_t = 0;
    while (i <= mid && j <= r)
    {
        if (input[i] < input[j])
        {
            tmp[pos++] = input[i++];
            inv_count += (j - mid - 1);
        }
        else if (input[i] == input[j])
        {
            continuous_l = input[i];
            continuous_t = 0;
            do
            {
                continuous_t++;
                tmp[pos++] = input[i++];
                inv_count += (j - mid - 1);
            } while (i <= mid && input[i] == input[j]);
        }
        else
        {
            if (input[j] == continuous_l)
                same += continuous_t;
            tmp[pos++] = input[j++];
        }
    }
    while (i <= mid)
    {
        tmp[pos++] = input[i++];
        inv_count += (j - mid - 1);
    }
    while (j <= r)
    {
        if (input[j] == continuous_l)
            same += continuous_t;
        tmp[pos++] = input[j++];
    }

    memmove(input + l, tmp + l, sizeof(int) * (r - l + 1));

    int idx = __builtin_ctz(r - l + 1);
    result[idx] += inv_count;
    reverse_result[idx] += ((1LL << (2 * idx - 2)) - inv_count - same);
}

int main()
{
    int array_size;
    cin >> array_size;

    int actual_size = 1 << array_size;
    for (int i = 0; i < actual_size; i++)
        cin >> input[i];

    merge(0, actual_size - 1);

    int question_num;
    cin >> question_num;

    int cur_m;
    for (int i = 0; i < question_num; i++)
    {
        cin >> cur_m;
        long long sum = 0;
        
        // Simulation of reverse
        for (int i = cur_m; i > 0; i--)
            swap(result[i], reverse_result[i]);
        
        for (int i = 1; i <= array_size; i++)
            sum += result[i];
        cout << sum << endl;
    }
}