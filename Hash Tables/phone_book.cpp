/* Data Structures Homework

Task.  In this task your goal is to implement a simple phone book manager. It
should be able to process the following types of user’s queries:

∙ add number name. It means that the user adds a person with name name and phone
number number to the phone book. If there exists a user with such number
already, then your manager has to overwrite the corresponding name.

∙ del number. It means that the manager should erase a person with number number
from the phone book. If there is no such person, then it should just ignore the
query.

∙ find number. It means that the user looks for a person with phone number
number. The manager should reply with the appropriate name, or with string “not
found" (without quotes) if there is no such person in the book.

------------------------------------------------------------------------------------
Input Format.  There is a single integer 𝑁 in the first line — the number of
queries. It’s followed by 𝑁 lines, each of them contains one query in the format
described above.

Constraints. 1 ≤ 𝑁 ≤ 105. All phone numbers consist of decimal digits, they
don’t have leading zeros, and each of them has no more than 7 digits. All names
are non-empty strings of latin letters, and each of them has length at most 15.
It’s guaranteed that there is no person with name “not found".

Output Format. Print the result of each find query — the name corresponding to
the phone number or “not found" (without quotes) if there is no person in the
phone book with such phone number. Output one result per line in the same order
as the find queries are given in the input.

*/

#include <iostream>
#include <vector>
#include <string>
#include <map> 

using namespace std;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {

    vector<string> result;
    map<int, string> contacts;

    for (size_t i = 0; i < queries.size(); ++i) {
        if (queries[i].type == "add") {
            if (contacts.find(queries[i].number) != contacts.end()) {
                contacts.find(queries[i].number)->second = queries[i].name;
            }
            else {
                contacts.insert(pair<int, string>(queries[i].number, queries[i].name));
            }
            continue;
        }
        if (queries[i].type == "del") {
            if (contacts.find(queries[i].number) != contacts.end())
                contacts.erase(queries[i].number);
            continue;
        }
        if (queries[i].type == "find") {
            string response = "not found";
            if (contacts.find(queries[i].number) != contacts.end())
                response = contacts.find(queries[i].number)->second;
            result.push_back(response);
            continue;
        }

        cout << "Wrong input!" << "\n";
         
    }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
