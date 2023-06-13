/*
Dynamic Programming - Cutting a Rod

Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
For example, if the length of the rod is 8 and the values of different pieces are given as the following, 
then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

*/

#include <iostream>
#include <vector>

using namespace std;

int CutRod(int* cost, int rodLength)
{
	vector<vector<int> > dp(rodLength+1, vector<int>(rodLength+1, 0));

	for(int i=1; i<=rodLength; i++)  //cost
	{
		for(int j=1; j<=rodLength; j++) //rodLength
		{
			if(j<i)
			{
				dp[j][i] = dp[j][i-1];
			}
			else{
				dp[j][i] = max(dp[j][i-1], dp[j-i][i] + cost[i-1]);
			}
		}
	}
	
	return dp[rodLength][rodLength];
}

int main()
{
	int rodLength = 8;
	int cost[] = { 1, 5, 8, 9, 10, 17, 17, 20 };

	cout<<CutRod(cost, rodLength)<<endl;

	return 0;

}