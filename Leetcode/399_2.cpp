/**
 * 399. 除法求值  Weighted union-find
 * link：https://leetcode-cn.com/problems/evaluate-division/
 */

class Solution
{
    int findParent(vector<int> &parent, vector<double> &weight, int node)
    {
        if (parent[node] != node)
        {
            int cur_parent = findParent(parent, weight, parent[node]);
            weight[node] = weight[node] * weight[parent[node]];
            parent[node] = cur_parent;
        }
        return parent[node];
    }

    void merge(vector<int> &parent, vector<double> &weight, int node_a, int node_b, double value)
    {
        int parent_a = findParent(parent, weight, node_a), parent_b = findParent(parent, weight, node_b);
        parent[parent_a] = parent_b;
        weight[parent_a] = value * weight[node_b] / weight[node_a];
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int n = equations.size();
        unordered_map<string, int> variables;
        int nums_variable = 0;

        for (int i = 0; i < equations.size(); i++)
        {
            if (variables.find(equations[i][0]) == variables.end())
                variables[equations[i][0]] = nums_variable++;
            if (variables.find(equations[i][1]) == variables.end())
                variables[equations[i][1]] = nums_variable++;
        }

        vector<int> parent(nums_variable);
        vector<double> weight(nums_variable, 1.0);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < n; i++)
        {
            int node_a = variables[equations[i][0]], node_b = variables[equations[i][1]];
            merge(parent, weight, node_a, node_b, values[i]);
        }

        int m = queries.size();
        vector<double> result(m, 0);
        for (int i = 0; i < m; i++)
        {
            if (variables.find(queries[i][0]) != variables.end() && variables.find(queries[i][1]) != variables.end())
            {
                int node_a = variables[queries[i][0]], node_b = variables[queries[i][1]];
                int parent_a = findParent(parent, weight, node_a), parent_b = findParent(parent, weight, node_b);
                if (parent_a == parent_b)
                {
                    result[i] = weight[node_a] / weight[node_b];
                    continue;
                }
            }
            result[i] = -1.0;
        }

        return result;
    }
};