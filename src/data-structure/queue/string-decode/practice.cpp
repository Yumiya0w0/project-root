#include <string>
#include <stack>
using namespace std;

string decode(string encoded)
{
    int k = 0;
    stack<int> kStack;
    stack<string> strStack;
    string current;
    for(char c : encoded)
    {
        if(isdigit(c))
        {
            k = k*10+(c-'0');
        }
        else if(c == '[')
        {
            kStack.push(k);
            k=0;
            strStack.push(current);
            current.clear();
        }
        else if(c == ']') // settle current decoded
        {
            int r = kStack.top();
            kStack.pop();
            string decoded = strStack.top();
            strStack.pop();
            for(int i = 0; i < r; i++)
                decoded += current;
            current = decoded;
        }
        else
        {
            current.push_back(c);
        }
    }
    return current;
}