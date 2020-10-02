#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <climits>

#define testing 

using namespace std;
/* Head ends here */

class Heap {
private:

    vector<long long> heap;
    bool maxHeap;

    int getParent(int i) { return (i - 1) / 2; }
    int getLeftChild(int i) { return 2 * i + 1; }
    int getRightChild(int i) { return 2 * i + 2; }

    bool compare(long long a, long long b) {
        if (maxHeap) return a < b;
        return a > b;
    }

    void shiftUp(int i) {
        while (i > 0 && compare(heap[getParent(i)], heap[i])) {
            swap(heap[getParent(i)], heap[i]);
            i = getParent(i);
        }
    }

    void shiftDown(int i) {

        int maxIndex = i;
        int l = getLeftChild(i);
        int r = getRightChild(i);

        if (l < heap.size() && compare(heap[maxIndex], heap[l]))
            maxIndex = l;
        if (r < heap.size() && compare(heap[maxIndex], heap[r]))
            maxIndex = r;

        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            shiftDown(maxIndex);
        }
    }


public:

    Heap(bool maxHeap = true) :maxHeap(maxHeap) {}

    const size_t getSize() { return heap.size(); }

    void insert(long long k) {
        heap.push_back(k);
        shiftUp(heap.size() - 1);
    }

    long long extractMax() {
        int ret = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        shiftDown(0);
        return ret;
    }

    const long long getMax() { return heap[0]; }

    void remove(int i) {
        if (maxHeap)
            heap[i] = LLONG_MAX;
        else
            heap[i] = LLONG_MIN;
        shiftUp(i);
        extractMax();
    }

    void changeKey(int i, long long k) {
        int old = heap[i];
        heap[i] = k;
        if (compare(k, old)) shiftUp(i);
        else shiftDown(i);
    }

    int findKey(long long k) {
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == k)
                return i;
        }
        return -1;
    }
};

string median(Heap& minHeap, Heap& maxHeap) {

    if (minHeap.getSize() == 0 && maxHeap.getSize() == 0) {
        return "Wrong!";
    }

    if (minHeap.getSize() == maxHeap.getSize()) {
        return to_string((maxHeap.getMax() + minHeap.getMax()) / 2.00);
    }

    if (minHeap.getSize() > maxHeap.getSize()) {
        return to_string(minHeap.getMax());
    }

    return to_string(maxHeap.getMax());
}

void addElem(Heap& maxHeap, Heap& minHeap, long long key) {

    if (maxHeap.getSize() == 0 && minHeap.getSize() == 0) {
        minHeap.insert(key);
        return;
    }

    if (maxHeap.getSize() == 0 || minHeap.getSize() == 0) {
        long long a;
        if (maxHeap.getSize() == 0) a = minHeap.extractMax();
        else a = maxHeap.extractMax();

        if (a > key) {
            maxHeap.insert(key);
            minHeap.insert(a);
        }
        else {
            maxHeap.insert(a);
            minHeap.insert(key);
        }
        return;
    }

    vector<long long> elements(3);
    elements[0] = minHeap.extractMax();
    elements[1] = maxHeap.extractMax();
    elements[2] = key;
    sort(elements.begin(), elements.end());

    maxHeap.insert(elements[0]);
    minHeap.insert(elements[2]);

    if (maxHeap.getSize() >= minHeap.getSize()) {
        minHeap.insert(elements[1]);
    }
    else {
        maxHeap.insert(elements[1]);
    }

}

void removeElem(Heap& maxHeap, Heap& minHeap, long long key) {

    if (maxHeap.getSize() == 0 && minHeap.getSize() == 0) return;
    if (maxHeap.getSize() == 0 && minHeap.getMax() != key) return;
    if (minHeap.getSize() == 0 && maxHeap.getMax() != key) return;
    if (key > maxHeap.getMax() && key < minHeap.getMax()) return;

    if (key <= maxHeap.getMax()) {
        int ind = maxHeap.findKey(key);
        if (ind == -1) return;
        maxHeap.remove(ind);
    }
    else {
        int ind = minHeap.findKey(key);
        if (ind == -1) return;
        minHeap.remove(ind);
    }

    if (maxHeap.getSize() > minHeap.getSize() + 1) {
        long long elem = maxHeap.extractMax();
        minHeap.insert(elem);
        return;
    }

    if (minHeap.getSize() > maxHeap.getSize() + 1) {
        long long elem = minHeap.extractMax();
        maxHeap.insert(elem);
        return;
    }
}

#ifdef testing
string median(const vector<long long>& arr) {
    if (arr.size() == 0) return "Wrong!";
    if (arr.size() % 2) {
        return to_string(arr[arr.size() / 2]);
    }
    return to_string((arr[(arr.size() - 1) / 2] + arr[arr.size() / 2]) / 2.00);
}

void addElem(vector<long long>& arr, long long key) {
    arr.push_back(key);
    sort(arr.begin(), arr.end());
}

void removeElem(vector<long long>& arr, long long key) {
    auto it = find(arr.begin(), arr.end(), key);
    if (it == arr.end()) return;
    arr.erase(it);
}
#endif

void median(vector<char> s, vector<int> X) {

    Heap maxHeap(true);
    Heap minHeap(false);

#ifdef testing
    vector<long long> arr;
#endif

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            addElem(maxHeap, minHeap, X[i]);   
#ifdef testing
            addElem(arr, X[i]);
#endif
        }
        else {
            removeElem(maxHeap, minHeap, X[i]);
#ifdef testing
            removeElem(arr, X[i]);
#endif
        }
        string res = median(minHeap, maxHeap);
#ifdef testing
        string res_brute = median(arr);
        if (res.compare(res_brute) != 0) {
            cout << "Wrong answer!!!" << "\n";
            cout << "Actual answer is: " << res_brute << "\n";
            cout << "Your answer is: ";
        }
#endif
        cout << res << "\n";
    }
}

int main(void) {

    //Helpers for input and output

    int N;
    cin >> N;

    vector<char> s;
    vector<int> X;
    char temp;
    int tempint;
    for (int i = 0; i < N; i++) {
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
    }

    median(s, X);
    return 0;
}
