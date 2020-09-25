/*
Task. In this task your goal is to implement a hash table with lists chaining.
You are already given the number of buckets 𝑚 and the hash function. It is a
polynomial hash function

h(S) = (sum_{i=0}^{len(S) - 1}S[i]x^i mod p) mod m

where S[i] is the ASCII code of the i-th symbol of S, p = 1 000 000 007 and x =
263. Your program should support the following kinds of queries:

∙ add string — insert string into the table. If there is already such string in
the hash table, then just ignore the query.

∙ del string — remove string from the table. If there is no such string in the
hash table, then just ignore the query.

∙ find string — output “yes" or “no" (without quotes) depending on whether the
table contains string or not.

∙ check i — output the content of the 𝑖-th list in the table. Use spaces to
separate the elements of the list. If i-th list is empty, output a blank line.

When inserting a new string into a hash chain, you must insert it in the
beginning of the chain.

--------------------------------------------------------------------------------------
Input Format. There is a single integer 𝑚 in the first line — the number of
buckets you should have. The next line contains the number of queries 𝑁. It’s
followed by 𝑁 lines, each of them contains one query in the format described
above.

Constraints. 1 ≤ 𝑁 ≤ 105; 𝑁 5 ≤ 𝑚 ≤ 𝑁. All the strings consist of latin letters.
Each of them is non-empty and has length at most 15.

Output Format. Print the result of each of the find and check queries, one
result per line, in the same order as these queries are given in the input.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    
    vector<vector<string>> elements;

    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count) : bucket_count(bucket_count) 
    {
        elements.resize(bucket_count);
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    pair<size_t, size_t> find(string s) {
        size_t ind = hash_func(s);
        for (size_t i = 0; i < elements[ind].size(); i++) {
            if (elements[ind][i] == s)
                return pair<size_t, size_t>(ind, i);
        }
        return pair<size_t, size_t>(ind, -1);
    }
    void processQuery(const Query& query) {

        if (query.type == "check") {
            for (auto it = elements[query.ind].rbegin(); it != elements[query.ind].rend(); ++it)
                cout << (*it) << " ";
            cout << "\n";
            return;
        }

        pair<size_t, size_t> found = find(query.s);

        if (query.type == "find") {
            writeSearchResult(found.second != -1);
            return;
        }

        if (query.type == "add") {
            if (found.second != -1) return;
            elements[found.first].push_back(query.s);
            return;
        }

        if (query.type == "del") {
            if (found.second == -1) return;
            elements[found.first].erase(elements[found.first].begin() + found.second);
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
