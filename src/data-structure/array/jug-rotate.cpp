int getGCD(int a, int b)
{
    if(a%b == 0) return max(a, b);
    if(a > b)
    {
        return getGCD(b, a%b);
    }
    return getGCD(a, b%a);
}

int getGCD(int a , int b)
{
    return (b==0) ? a :  getGCD(b, a%b);
}

void jugRotate(int* array, size_t size, int k)
{
    if(size == 0) return;
    k = (k % size + size) % size;
    int d = getGCD(size, k);
    for(int i = 0; i < d; i++)
    {
        int curr = i;
        int temp = array[i];
        while(true)
        {
            int prev = (curr - k + size) % size;
            if(prev == i){ break;}
            array[curr] = array[prev];
            curr = prev;
        }
        array[curr] = temp;
    }
}