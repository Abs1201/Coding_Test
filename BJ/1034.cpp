#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(void){

    int n, m, k;
	cin >> n >> m;

	vector<string> v;
	map<string, int> table;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}

	cin >> k;
	for (auto& i : v)
	{
		int zero = 0;
		for (auto& j : i)
			if (j == '0')
				zero++;

		if (zero > k || (zero % 2 != k % 2))
			continue;

		if (table.find(i) == table.end())
			table.insert({ i, 1 });
		else
			table[i]++;
	}

	int ans = 0;
	for (auto& j : table)
		ans = max(ans, j.second);
	cout << ans;
	return 0;
}