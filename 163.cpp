#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct cow
{
	int x1,y1,x2,y2,time;
};
int px[9]={0,2, 2, 1, 1,-1,-1,-2,-2};
int py[9]={0,1,-1, 2,-2, 2,-2, 1,-1};
queue<cow> q;
cow p1,p2;
bool mark[10][10][10][10];
int main()
{
	int i,j,n,b,c,x1,y1,x2,y2;
	char ch;
	cin>>ch;
	p1.x1=ch-'a'+1;
	cin>>ch;
	p1.y1=ch-'0';
	cin>>ch;
	p1.x2=ch-'a'+1;
	cin>>ch;
	p1.y2=ch-'0';
	p1.time=0;
	mark[p1.x1][p1.y1][p1.x2][p1.y2]=true;
	mark[p1.x2][p1.y2][p1.x1][p1.y1]=true;
	q.push(p1);
	int ans=-1;
	while(!q.empty())
	{
		p1=q.front();
		q.pop();
		if(p1.x1==p1.x2 && p1.y1==p1.y2)
		{
			ans=p1.time;
			break;
		}
		for(i=1;i<=8;++i)
			for(j=1;j<=8;++j)
			{
				x1=p1.x1+px[i];
				y1=p1.y1+py[i];
				x2=p1.x2+px[j];
				y2=p1.y2+py[j];
				if(x1>0 && x1<=8 && x2>0 && x2<=8 && y1>0 && y1<=8 && y2>0 && y2<=8 && mark[x1][y1][x2][y2]==false)
				{
					p2.x1=x1;
					p2.y1=y1;
					p2.x2=x2;
					p2.y2=y2;
					p2.time=p1.time+1;
					mark[x1][y1][x2][y2]=true;
					mark[x2][y2][x1][y1]=true;
					q.push(p2);
				}
			}
			
	}
	cout<<ans;
	return 0;
}