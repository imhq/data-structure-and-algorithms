/*
Dynamic Programming - Longest Increasing Subsequence 

Given an array arr[] of size N, the task is to find the length of the Longest Increasing Subsequence (LIS) 
i.e., the longest possible subsequence in which the elements of the subsequence are sorted in increasing order.
Examples:

Input: arr[] = {3, 10, 2, 1, 20}
Output: 3
Explanation: The longest increasing subsequence is 3, 10, 20

Input: arr[] = {3, 2}
Output:1
Explanation: The longest increasing subsequences are {3} and {2}
*/

#include <iostream>
#include <vector>
using namespace std;

int LongestIncreasingSubsequence(int* arr, int n)
{

	int longestSubsequenceLen = 0;
	vector<int> dp(n, 0);

	for(int i=n-1; i>=0; i--)
	{
		int maxHere = 0;
		for(int j=i+1; j<n; j++)
		{
			if(arr[i]<arr[j])
			{
				maxHere = max(maxHere, dp[j]);
			}
		}
		dp[i] = maxHere + 1;

		longestSubsequenceLen = max(longestSubsequenceLen, dp[i]);
	}

	return longestSubsequenceLen;
}

int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int size = sizeof(arr)/sizeof(arr[0]);

	cout<<LongestIncreasingSubsequence(arr, size)<<endl;

	return 0;
}