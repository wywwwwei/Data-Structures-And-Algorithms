#include<iostream>
#include<string>

using namespace std;
int finalResult[7];

int abs(int a)
{
	return a > 0 ? a : -a;
}

int main()
{ 
	int inputa, inputb;
	while (cin >> inputa >> inputb)
	{
		int count = 0;
		int result = inputa + inputb;
		while (true)
		{
			finalResult[count++] = abs(result % 10);
			result /= 10;
			if (result == 0)break;
		}
		if(inputa+inputb!=0)
			finalResult[count - 1] *= (inputa + inputb) / abs(inputa + inputb);
		while (count)
		{
			cout << finalResult[--count];
			if (count % 3 == 0&&count!=0)cout << ',';
		}
		cout << endl;
	}
	return 0;
}
