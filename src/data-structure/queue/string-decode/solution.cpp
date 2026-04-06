#include <string>
#include <stack>
#include <cctype>
#include <iostream>

std::string decodedString(std::string encoded)
{
    std::stack<int> counts;
    std::stack<std::string> resultStack;
    std::string current;
    int k = 0;

    for (char c : encoded)
    {
        if (std::isdigit(static_cast<unsigned char>(c)))
        {
            k = k * 10 + (c - '0');
        }
        else if (c == '[')
        {
            counts.push(k);
            resultStack.push(current);
            k = 0;
            current.clear();
        }
        else if (c == ']')
        {
            int repeat = counts.top();
            counts.pop();
            std::string decoded = resultStack.top();
            resultStack.pop();
            for (int i = 0; i < repeat; ++i)
                decoded += current;
            current = std::move(decoded);
        }
        else
        {
            current.push_back(c);
        }
    }

    return current;
}

int main()
{
    std::string input = "3[a2[c]]";
    std::cout << decodedString(input) << std::endl;
}