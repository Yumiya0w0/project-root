#include <string>
#include <iostream>

void swapChar(char& a, char& b)
{
    if(&a == &b) return;
    char tmp = a;
    a = b; b = tmp;
}

void reverseStr(std::string& str, size_t start, size_t end)
{
    if(start >= str.size() || end >= str.size() || start > end) return;
    int length = end-start+1;
    for(int i = 0; i < length/2; i++)
    {
        swapChar(str[start + i], str[end - i]);
    }
}

void reverseSentance(std::string& str)
{
    reverseStr(str, 0, str.size()-1);
    size_t l = 0, r = 0;
    while(l < str.size() && r < str.size())
    {
        while(l < str.size() && str[l] == ' ') l++;
        if(l >= str.size()) return;
        r = l;
        while(r < str.size() && str[r] != ' ') r++;
        reverseStr(str, l, r-1);
        l = r;
    }
}

int main()
{
    std::string str ;
    reverseSentance(str);
    std::cout << str << "\n";

    str = "im a gay";
    reverseSentance(str);
    std::cout << str << "\n";

    str = "im a   gay";
    reverseSentance(str);
    std::cout << str << "\n";

    str = "  im a   gay  ";
    reverseSentance(str);
    std::cout << str << "\n";

    str = "    ";
    reverseSentance(str);
    std::cout << str << "\n";
}