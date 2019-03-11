#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n;scanf("%d",&n);
	while(n--)
	{
		string s;cin >> s;
		for(int i=s.size();i>=0;i--)
		{
			if(s[i]>=97 && s[i]<=122)printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}
