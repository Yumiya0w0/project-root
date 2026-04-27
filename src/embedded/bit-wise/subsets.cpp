#include <vector>
#include <cstdint>

using namespace std;
// int getFistSetbitIndex(uint32_t val)
// {
//     int count = 0;
//     while(! (val & 1))
//     {
//         val >> 1;
//         count ++;
//     }
//     return count;
// }

int getFistSetbitIndex(uint32_t val)
{
    val
}

vector<vector<int>> subsets(vector<int> set)
{
    vector<vector<int>> subsets;
    int nums = 1 << set.size();
    for(int i = 0; i < nums; i++)
    {
        // get every set bit index
        vector<int> tmp;
        uint32_t mask = i;
        while(mask)
        {
            int index = __builtin_ctz(mask);
            // tmp.push_back(set[getFistSetbitIndex(n)]);
            tmp.push_back(set[index]);
            mask &= (mask-1);
        }
        subsets.push_back(tmp);
    }
    return subsets;
}