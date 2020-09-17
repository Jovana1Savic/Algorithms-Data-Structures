#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// For Hacker Rank use preallocated array in order to reduce run time
const int max_size = 100000;
int p1[max_size];
int p2[max_size];
int res[max_size * 2]

void readArray(int a[], int n){
	for(int i = 0; i < n; i++){
		int data;
		cin >> data;
		a[i] = data;
	}
}

void multiplyPolynomials(int p1[], int p2[], int low, int high, int res[]){

	if (low > high) return;

	if (low == high){
		res[low] = p1[low] * p2[low];
		return;
	}

	if (low + 1 == high){
		int a1b1 = p1[high] * p2[high];
		int a0b0 = p1[low] * p2[low];
		int mid = (p1[low] + p1[high]) * (p2[low] + p2[high]) - a1b1 - a0b0;

		res[low] += a0b0;
		res[low + 1] += mid;
		res[low + 2] += a1b1;

		return;
	}

	int n = (high - low) >> 1;
	multiplyPolynomials(p1, p2, low, n, res);
	multiplyPolynomials(p1, p2, n + 1, high, res);

	int* res_tmp = new int[n + 1];
	for (int i = low; i <= n; i++){
		res_tmp[i - low] = -res[i];
	}
	for (int i = n + 1; i <= high; i++){
		res_tmp[i - n - 1] -= res[i];
	}

	p_tmp_size = n + ((high - low) % 2) + 1;
	int* p1_tmp = new int[p_tmp_size];
	int* p2_tmp = new int[p_tmp_size];
	for (int i = 0; i < n; i++){
		p1_tmp[i] = p1[low + i] + p1[n + i + 1];
		p2_tmp[i] = p2[low + i] + p2[n + i + 1];
	}

	p1_tmp = p1[low + n];
	p2_tmp = p2[low + n];

	if (high == 2 * n + 1){
		p1_tmp[i] += p1[high];
		p2_tmp[i] += p2[high];
	}

	multiplyPolynomials(p1_tmp, p2_tmp, 0, low + n, res_tmp);

	

}

void solve(int p1[], int p2[], int n, int m, int res[]){
	
	// Pad with zeros.
	int size = max(n, m);
	for (int i = n; i < size; i++)
		p1[i] = 0;
	for (int i = m; i < size; i++)
		p2[i] = 0;

	for (int i = 0; i < n + m; i++)
		res[i] = 0;

	multiplyPolynomials(p1, p2, 0, size - 1, res);

	

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t, n, m;
    cin >> t;
    while (t--){
    	cin >> n >> m;
    	readArray(p1, n);
    	readArray(p2, m);
    }
    return 0;
}