#include<bits/stdc++.h>
using namespace  std;
// helper(0,0,v,mp,row,col)
void helper(int r,int c,vector<vector<char> > &v,
map<pair<int,int>,map<int,int> > &mp,vector<map<int,int> > row,
vector<map<int,int> > col)
{
	if(r==9)
	{
		for(auto it : v)
		{
			for(auto i:it)
			cout<<i<<' ';
		
			cout<<"\n";
		}
		cout<<"\n";
		return;
		
	}
	if(c==9)
	{
		helper(r+1,0,v,mp,row,col);
		return;
	}
	if(v[r][c]!='.')
	{
		helper(r,c+1,v,mp,row,col);
		return;
	}
	for(int i=1;i<=9;i++)
	{
		int rw=r/3,cl=c/3;
		if(!mp[{rw,cl}][i] && !row[r][i] && !col[c][i])
		{
			mp[{rw,cl}][i]=1;
			row[r][i]=1;
			col[c][i]=1;
			v[r][c]=i+'0';
			helper(r,c+1,v,mp,row,col);
			
		}
	}
	
}
// --------------------------------------------------
void solve_suduko(vector<vector<char>> &v)
{
	map<pair<int,int>,map<int,int>> mp;//to track the sub array of order in squareroot of n
	
	vector<map<int,int>> row(9);
	vector<map<int,int>> col(9);
	
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(v[i][j]!='.')
			{
				mp[{i/3,j/3}][v[i][j]-'0']=1;
				row[i][v[i][j]-'0']=1;
				col[j][v[i][j]-'0']=1;
				
			}
		}
	}
	helper(0,0,v,mp,row,col);
}
//----------------------------------------------------
int32_t main()
{
	//suduko
	vector<vector<char>> suduko={
	{'.','.','9','1','.','.','.','.','.'},
	{'.','.','.','.','2','4','.','.','8'},
	{'.','2','.','9','3','.','.','6','.'},
	{'.','7','.','.','9','.','.','2','.'},	
	{'.','4','.','2','.','1','.','7','.'},
	{'1','.','.','.','4','.','.','.','6'},
	{'.','.','.','3','6','.','.','.','4'},
	{'.','.','6','.','8','5','7','.','.'},
	{'.','8','.','7','.','.','.','.','.'}
		 };
	int n=suduko.size(); // no of rows or columns in suduko
	long long order=n*n;//order of suduko
	solve_suduko(suduko);
		 

}
