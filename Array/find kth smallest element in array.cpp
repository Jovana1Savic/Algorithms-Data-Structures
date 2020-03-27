/*

https://practice.geeksforgeeks.org/problems/kth-smallest-element/0

Given an array arr[] and a number K where K is smaller than size of array, the
task is to find the Kth smallest element in the given array. It is given that
all array elements are distinct. Expected Time Complexity: O(n)

Input: The first line of input contains an integer T, denoting the number of
testcases. Then T test cases follow. Each test case consists of three lines.
First line of each testcase contains an integer N denoting size of the array.
Second line contains N space separated integer denoting elements of the array.
Third line of the test case contains an integer K.

Output: Corresponding to each test case, print the kth smallest element in a new
line.
*/

#include <iostream>
using namespace std;

int main() {
	
	int T;
	cin >> T;
	while (T) {

		int N, K;
		cin >> N;

		int count[100001];
		for (int i = 0; i < 100001; i++)
			count[i] = 0;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			count[data] = 1;
		}
		cin >> K;

		int k = 0, i = 0;
		while (k < K)
			if (count[i++] == 1)
				k++;

		cout << i - 1 << endl;
		T--;
	}
	return 0;
}