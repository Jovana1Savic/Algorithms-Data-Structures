/*Now a days almost all scientific calculators have the property of solving a
/*system of simultaneous equations. Code a program to do the same for the
/*following and find the value of X,Y and Z.

 a1X + b1Y + c1Z = d1

 a2X + b2Y + c2Z = d2

 a3X + b3Y + c3Z = d3

Input:

The first line of input takes the number of test cases T. Then T test cases
follow.

Each test case has 3 input lines.

The 3 lines of each test case take 4 space separated integers denoting the
values of a, b, c and d respectively.

Note: Your code should be able to handle double values.

Output:

Print 0 in case the system is inconsistent and 1 in case the system is
consistent and has infinitely many solutions.

In case the system is consistent and has a unique solution, print 3 space
separated integers denoting the floor values of X, Y and Z respectively.

Constraints:

1<=T<=100

-100<=a, b, c, d<=100*/

#include <iostream>
#include <cmath>
using namespace std;

double mat[3][4];
double det[3][3];
double D[4];

double determinant3() {
	double p1 = det[0][0]*det[1][1]*det[2][2];
	double p2 = det[0][1]*det[1][2]*det[2][0];
	double p3 = det[0][2]*det[1][0]*det[2][1];
	
	double p4 = det[0][2]*det[1][1]*det[2][0];
	double p5 = det[0][0]*det[1][2]*det[2][1];
	double p6 = det[0][1]*det[1][0]*det[2][2];
	
	
	return (p1 + p2 + p3) - (p4 + p5 + p6);
}

void readEq() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			cin >> mat[i][j];
}

void createDeterminant(int c) {
	for (int i = 0; i < 3; i++){
	    for (int j = 0; j < 3; j++)
	        det[i][j] = mat[i][j];
	}
	if (c < 3){
	    for (int i = 0; i < 3; i++)
	        det[i][c] = mat[i][3];
	}
}

void solve() {
	for (int i = 0; i < 4; i++) {
		createDeterminant(i);
		D[i] = determinant3();
	}
}

bool allZeros() {
	for (int i = 0; i < 4; i++)
		if (D[i] != 0) return false;
	return true;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		readEq();
		solve();

		if (allZeros()) {
			cout << 1 << endl;
			continue;
		}

		if (D[3] == 0) {
			cout << 0 << endl;
			continue;
		}

		for (int i = 0; i < 3; i++) {
			cout << floor(D[i] / D[3]) << " ";
		}
		cout << endl;

	}
	return 0;
}