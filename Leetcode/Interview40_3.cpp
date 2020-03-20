/**
 * 面试题40. 最小的k个数 快速选择
 * link：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
 */

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        srand(time(NULL));

        kElement(arr, 0, arr.size() - 1, k);

        vector<int> result(k, 0);
        for (int i = 0; i < k; i++)
            result[i] = arr[i];
        return result;
    }

    int partion(vector<int> &arr, int low, int high)
    {
        int pivot = arr[high];

        int max_elements = low;
        for (int i = low; i < high; i++)
        {
            if (arr[i] <= pivot)
                swap(arr[i], arr[max_elements++]);
        }

        swap(arr[max_elements], arr[high]);
        return max_elements;
    }

    int random_pivot_partion(vector<int> &arr, int low, int high)
    {
        int rand_num = (rand() % (high - low + 1)) + low;
        swap(arr[rand_num], arr[high]);
        return partion(arr, low, high);
    }

    void kElement(vector<int> &arr, int low, int high, int k)
    {
        if (low >= high)
            return;

        int pivot_index = random_pivot_partion(arr, low, high);

        if (pivot_index == k - 1)
            return;
        else if (pivot_index > k - 1)
            kElement(arr, low, pivot_index - 1, k);
        else
            kElement(arr, pivot_index + 1, high, k);
    }
};