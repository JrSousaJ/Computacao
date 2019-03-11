#include<bits/stdc++.h>

using namespace std;
int main()
{
	unsigned long long n,i,k;
	while(cin >> n)
	{
		char s2[n+1]
		for(int i=0;i<n;i++){
			char s[8];
			scanf(" %s",s);
			int v1=0;
			int c=1;
			for(int j=strlen(s);j>=0;j--)
			{
				c*=2;
				if(s[j]=='1')v1+=c;
			}
			int q=v1/4;
			if(q==64)q/=2;
			printf("%c",q);
		}
		printf("\n");
	}
	return 0;
}
