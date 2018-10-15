#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Match(char c) {
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
    int value = -1;
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next, position));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty() || !opening_brackets_stack.top().Match(next)) {
                value = position + 1;
                break;
            }
            opening_brackets_stack.pop();
        }
    }

    // Printing answer, write your code here
    if (opening_brackets_stack.empty() && value == -1){
        std::cout << "Success" << std::endl;
    }
    else if (value == -1)
        std::cout << opening_brackets_stack.top().position + 1 << std::endl;
    else
        std::cout << value << std::endl;




    return 0;
}