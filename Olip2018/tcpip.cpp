#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	vector<string>s;
	while(cin >> n)
	{
		getchar();
		while(1)
		{
			string s1,s2;
			cin >> s1;
			if(s1[0]=='0')break;
			cin >> s2;
			s.push_back(s2);
		}
		sort(s.begin(),s.end());
		for(int i=0;i<s.size();i++)cout << "Package " << s[i] << endl;

		s.clear();
		printf("\n", );
	}
	return 0;
}
