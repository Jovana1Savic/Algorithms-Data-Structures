/*Given a matrix M of size N where M[i][j] denotes the cost of moving from city
/*i to city j. Your task is to complete a tour from the city 0 (0 based index)
/*to all other cities such that you visit each city atmost once and then at the
/*end come back to city 0 in min cost.

Input: The first line of input contains an integer T denoting the no of test
cases. Then T test cases follow. Each test case contains an integer N denoting
the size of the matrix then in the next line are N*N space separated values of
the matrix M.
 
Output: For each test case print the required result denoting the min cost of
the tour in a new line.

Constraints:
1<=T<=15
1<=N<=12
1<=M[][]<=10000
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N_MAX = 12;
int graph[N_MAX][N_MAX];

int travellingSalesman(int start, int N) {

    vector<int> v;
    for (int i = 0; i < N; i++) {
        if (i != start)
            v.push_back(i);
    }

    int minPath = INT_MAX;
    do {

        int curWeight = 0;
        int k = start;

        for (int i = 0; i < v.size(); i++) {
            curWeight += graph[k][v[i]];
            k = v[i];
        }

        curWeight += graph[k][start];

        if (curWeight < minPath)
            minPath = curWeight;
        
    } while (next_permutation(v.begin(), v.end()));

    return minPath;
}
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> graph[i][j];
        }

        cout << travellingSalesman(0, n) << endl;
    }
    return 0;
}