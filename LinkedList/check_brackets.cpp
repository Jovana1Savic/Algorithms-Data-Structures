#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position) :
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    bool error = false;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(Bracket(next, position));
        }

        if (next == ')' || next == ']' || next == '}') {
            if (opening_brackets_stack.empty()) {
                std::cout << position + 1 << std::endl;
                error = true;
                break;
            }
            Bracket m = opening_brackets_stack.top();
            opening_brackets_stack.pop();
            if (!m.Matchc(next)) {
                std::cout << position + 1 << std::endl;
                error = true;
                break;
            }
        }
    }

    if (!error) {
        if (opening_brackets_stack.empty()) {
            std::cout << "Success" << std::endl;
        }
        else {
            Bracket b = opening_brackets_stack.top();
            while (!opening_brackets_stack.empty()) {
                b = opening_brackets_stack.top();
                opening_brackets_stack.pop();
            }

            std::cout << b.position + 1 << std::endl;
        }
    }
    

    return 0;
}
