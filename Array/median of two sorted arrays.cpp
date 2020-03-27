#include <iostream>
#include <algorithm>
#include <stdlib.h>     
#include <time.h>  

using namespace std;

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

/*Left side consists of A[0], ... , A[i - 1] and B[0], ... , B[j - 1] Right side
consists of A[i], ... , A[N - 1] and B[j], ... , B[M] Left and right side need
to have the same number of elements (in case M + N is even), or left needs to
have one more element (if N + M is odd). If max(left_side) <= min(right_side)
then the median can be found.

Threfore, the size of left part is (N + M + 1)/2.  We take i elements from A as
left part and j elements from j for left part. Therefore, i + j = (N + M + 1) /
2.

Assume that N is smaller or equal (N <= M). We use binary search for i starting
from i_min = 0 and i_max = N.  In order to perserve the same lengths we set j =
(N + M + 1) / 2.

If max(left_part) > min(right_part) we need to move. Since A and B are already
sorted, this can happen in two cases: 1. A[i - 1] > B[j] 2. B[j - 1] > A[i]

The solutions for these cases are following:
1. We need to move i to the right (in binary search terms, that is set
i_min = i + 1).
2. We need to move i to the left (i_max = i - 1)

If the above is not the case we are done.

Edge cases: 1. i = 0 2. j = 0 3. i = N 4. j = M

1. If i = 0, it means that the left part consists only of elements from array B.
Therfore, it's as if we have array [B A] for which we need to find median. And
this is simple, it should be the middle element, that is, element at position (M
+ N + 1) / 2 - 1, which is j - 1, or in case  of even sized array, average of
elements at j - 1 and j.  Note that since N <= M, j <= (2M + 1) / 2, j <= M.

2. If j = 0 it means that the left part consists only of elements from array A.
So, it's basically median of array [A B]. Note that for this to happen, the
arrays need to have the same size.

3. If i = N, then it's basically the second case, [A B] array, but median is to
the right in the array B, exactly where j - 1 is.

4. If j = M, i = (N - M + 1) / 2, and since N <= M, at best i =  0, so it's
effectively the first case.

Time complexity: O(log(min(N, M)))
Space complexity: O(1)

 */
double findMedianSortedArrays(int A[], int N, int B[], int M) {

    // First array needs to be smaller. 
    if (N > M) return findMedianSortedArrays(B, M, A, N);

    int i_max = N, i_min = 0;
    int i, j;
    int median = 0;

    while (i_min <= i_max) {

        i = (i_min + i_max) / 2;
        j = (M + N + 1) / 2 - i;

        // Move i to the right.
        if (j > 0 && i < N && B[j - 1] > A[i]) {
            i_min = i + 1;
            continue;
        }

        // Move i to the left.
        if (i > 0 && j < M && A[i - 1] > B[j]) {
            i_max = i - 1;
            continue;
        }

        if (i == 0) {
            median = B[j - 1];
            break;
        }
        if (j == 0) {
            median = A[i - 1];
            break;
        }

        median = max(A[i - 1], B[j - 1]);
        break;

    }

    if ((N + M) % 2)
        return (double)median;

    if (i == N)
        return (median + B[j]) / 2.00;

    if (j == M)
        return (median + A[i]) / 2.00;

    return (median + min(A[i], B[j])) / 2.00;
}



/*
--------------------------------------------------------------------------------
*/

const int N_MAX = 100000;
const int M_MAX = 100000;

int arr1[N_MAX];
int arr2[M_MAX];

int AB[N_MAX + M_MAX];

int arr1_size;
int arr2_size;

void createArrays() {

    srand(time(NULL));

    arr1_size = (((rand()) + 1) * ((rand() % 5) + 1)) % N_MAX;
    arr2_size = (((rand()) + 1) * ((rand() % 5) + 1)) % M_MAX;

    for (int i = 0; i < arr1_size; i++) {
        arr1[i] = (rand()) + 1;
        AB[i] = arr1[i];
    }

    for (int i = 0; i < arr2_size; i++) {
        arr2[i] = (rand()) + 1;
        AB[i + arr1_size] = arr2[i];
    }

    sort(arr1, arr1 + arr1_size);
    sort(arr2, arr2 + arr2_size);

}

void readArrays() {
    cout << "Enter N and M" << endl;
    cin >> arr1_size >> arr2_size;

    for (int i = 0; i < arr1_size; i++) {
        int data;
        cin >> data;
        arr1[i] = data;
        AB[i] = data;
    }

    for (int i = 0; i < arr2_size; i++) {
        int data;
        cin >> data;
        arr2[i] = data;
        AB[i + arr1_size] = data;
    }

    sort(arr1, arr1 + arr1_size);
    sort(arr2, arr2 + arr2_size);
}

void testFunction(int i) {

    int len = arr1_size + arr2_size;
    sort(AB, AB + len);

    double med;

    if (len % 2 == 0)
        med = (AB[len / 2] + AB[len / 2 - 1]) / 2.00;
    else
        med = (double)AB[len / 2];

    double func_median = findMedianSortedArrays(arr1, arr1_size, arr2, arr2_size);


    if (func_median == med){
        cout << "Test " << i << " passed" << endl;
        cout << "Median is " << func_median << endl;
    }   
    else {

        if (func_median == -1.0)
            cout << "Function exception, edge case not handled" << endl;

        cout << "Test " << i << "failed" << endl;
        cout << "Expected output is " << med << endl;
        cout << "Function output is " << func_median << endl;
        cout << "Length A is " << arr1_size << endl;
        cout << "Length B is " << arr2_size << endl;

        cout << "Enter 1 to see arrays " << endl;
        int input;
        cin >> input;
        if (input == 1) {

            cout << "Array A:" << endl;
            for (int i = 0; i < arr1_size; i++)
                cout << arr1[i] << " ";
            cout << endl;

            cout << "Array B: " << endl;
            for (int i = 0; i < arr2_size; i++)
                cout << arr2[i] << " ";
            cout << endl;
        }
    }
}


int main() {
    int TestCases = 10;
    while (TestCases--) {
        //createArrays();
        readArrays();
        testFunction(TestCases);
    }
    return 0;
}