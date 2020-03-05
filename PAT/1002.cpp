#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

bool cmp(pair<int,double> left,pair<int,double> right)
{
	return left.first > right.first;
}

int main()
{ 
	int testa, testb;
	vector<pair<int, double>> store, result;
	while (cin >> testa)
	{
		for (int i = 0; i < testa; i++)
		{
			int exponent;
			double coefficient;
			cin >> exponent >> coefficient;
			store.push_back(make_pair(exponent, coefficient));
		}
		cin >> testb;
		for (int i = 0; i < testb; i++)
		{
			int exponent;
			double coefficient;
			cin >> exponent >> coefficient;
			store.push_back(make_pair(exponent, coefficient));
		}

		sort(store.begin(), store.end(), cmp);

		for (vector<pair<int, double>>::iterator iter = store.begin(); iter != store.end(); iter++)
		{
			vector<pair<int, double>>::iterator temp = iter + 1;
			if (temp!=store.end()&&iter->first == temp->first)
			{
				if (iter->second + temp->second != 0)
				{
					result.push_back(make_pair(iter->first, iter->second + temp->second));
				}
				iter++;
			}
			else
			{
				result.push_back(make_pair(iter->first, iter->second ));
			}
		}

		cout << result.size();
		for (vector<pair<int, double>>::iterator iter = result.begin(); iter != result.end(); iter++)
		{
			cout << ' ' << iter->first << ' ' << fixed << setprecision(1) << iter->second;
		}

		store.clear();
		result.clear();
	}
	return 0;
}
