#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE=(int)('z'-'A'+1);
class Solution{
public:
	string minWindow(string s,string t)
	{
		int m=t.length();
		int freq[MAX_SIZE],freq1[MAX_SIZE];;
		memset(freq,0,MAX_SIZE*sizeof(int));
		memset(freq1,0,MAX_SIZE*sizeof(int));
		for(int i=0;i<m;i++)
			freq[(int)(t[i]-'A')]++;
		int p1=0,p2=0;
		int n=s.length();
		int miLen=INT_MAX;
		int indx=-1;
		while(p2<n)
		{
			if(freq[(int)(s[p2]-'A')])
			{
				freq1[(int)(s[p2]-'A')]++;
				int j=0;
				for(;j<MAX_SIZE;j++)
					if(freq[j]>freq1[j])break;
				if(j==MAX_SIZE)
				{
					int len;
					while(p1<=p2)
					{
						len=p2-p1+1;
						if(miLen>len)
						{
							miLen=len;
							indx=p1;
						}
						if(freq[(int)(s[p1]-'A')])
						{
							freq1[(int)(s[p1]-'A')]--;
							if(freq1[(int)(s[p1]-'A')]<freq[(int)(s[p1]-'A')])
							{
								p1++;
								break;
							}

						}
						p1++;
					}
				}//end of if.
				p2++; 
			}
			else p2++;
		}//end of while-loop(outer).
		if(indx==-1)return ""; 
		return s.substr(indx,miLen);
	}
};


int main(){
	freopen("ip.txt","r",stdin);
	int t;cin>>t;
	Solution obj;
	for(int tc=1;tc<=t;tc++)
	{
		cout<<"Test Case[ "<<tc<<" ]:\t";
		string a,b;cin>>a>>b;
		cout<<obj.minWindow(a,b)<<endl;
		cout<<endl;
	}
	return 0;
}