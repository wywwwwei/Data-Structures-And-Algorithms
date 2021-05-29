/**
 * 1012 The Best Rank
 * link: https://pintia.cn/problem-sets/994805342720868352/problems/994805502658068480
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    unordered_map<string, int> str2id;
    cin >> N >> M;

    int id_count = 0;
    string id;
    int average, clang, math, english;

    vector<pair<int, int>> all_clang, all_math, all_english, all_average;
    for (int i = 0; i < N; ++i)
    {
        cin >> id >> clang >> math >> english;
        average = (clang + math + english) / 3;
        str2id[id] = id_count;

        all_clang.emplace_back(id_count, clang);
        all_math.emplace_back(id_count, math);
        all_english.emplace_back(id_count, english);
        all_average.emplace_back(id_count, average);
        id_count++;
    }

    // Record and sort the score with id
    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) -> bool
    { return a.second > b.second; };
    sort(all_clang.begin(), all_clang.end(), cmp);
    sort(all_math.begin(), all_math.end(), cmp);
    sort(all_english.begin(), all_english.end(), cmp);
    sort(all_average.begin(), all_average.end(), cmp);

    vector<pair<int, int>> *store[4] = {&all_average, &all_clang, &all_math, &all_english};
    char status[4] = {'A', 'C', 'M', 'E'};
    vector<pair<int, char>> result(N, {INT_MAX, 0});

    // For each subject's score, calculate the rank
    for (int i = 0; i < 4; ++i)
    {
        int last = store[i]->begin()->second;
        store[i]->begin()->second = 1;
        for (int j = 1; j < N; ++j)
        {
            if (store[i]->at(j).second == last)
            {
                store[i]->at(j).second = store[i]->at(j - 1).second;
            }
            else
            {
                last = store[i]->at(j).second;
                store[i]->at(j).second = j + 1;
            }
        }
    }

    // Choose the best rank
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int id = store[j]->at(i).first;
            if (result[id].first > store[j]->at(i).second)
            {
                result[id].first = store[j]->at(i).second;
                result[id].second = status[j];
            }
        }
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> id;
        if (str2id.find(id) != str2id.end())
        {
            int cur = str2id[id];
            cout << result[cur].first << ' ' << result[cur].second << endl;
        }
        else
        {
            cout << "N/A" << endl;
        }
    }
}