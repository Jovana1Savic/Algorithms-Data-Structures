/*
https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space/0

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Example:

If the array is 

1 2 3 4 5 6 7 8 9

Then the rotated array becomes: 

7 4 1 8 5 2 9 6 3

Input:

The first line contains an integer 'T' denoting the total number of test cases.
In each test cases, the first line contains an integer 'N' denoting the size of
the 2D square matrix.

And in the second line, the elements of the matrix A[][], each separated by a
space in row major form.


Output:

For each test case, print the elements of the rotated array row wise, each
element separated by a space. Print the output of each test case in a new line.


Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 10
1 ≤ A [ i ][ j ] ≤ 100
*/

#include <iostream>
using namespace std;


const int N_MAX = 10;
int mat[N_MAX][N_MAX];

void swap(int* a, int *b){
    int tmp = *a;
    (*a) = (*b);
    (*b) = tmp;
}

// Transpose matrix
void transpose(int N){

    for (int i = 0; i < N; i++){
        for (int j = 0; j < i; j++){
            swap(&mat[i][j], &mat[j][i]);
        }
    }
}

// Mirror matrix along verical line. 
void mirror(int N){

    int lim = (N - 1) / 2 - (N % 2);

    for (int i = 0; i < N; i++){
        for (int j = 0; j <= lim; j++){
            swap(&mat[i][j], &mat[i][N - 1 - j]);
        }
    }
}

void readMat(int N){
    for (int i = 0; i < N; i++){
	        for (int j = 0; j < N; j++){
	            cin >> mat[i][j];
	        }
	    }
}

void printMat(int N){
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << mat[i][j] << " ";
        }
    }
}

/*
Rotating a matrix is equivallent to transposing it and then mirroring it along
vertical line. 

Time complexity : O(n^2)
Space complexity : O(1)
*/
int main() {
	int N, T;
	cin >> T;
	while (T--){
	    cin >> N;
	    readMat(N);
	    transpose(N);
	    mirror(N);
	    printMat(N);
	    cout << endl;
	}
	return 0;
}