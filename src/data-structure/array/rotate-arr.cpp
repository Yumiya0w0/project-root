
void rightShift(int* array, size_t size)
{
    if(size <= 1) return;
    int rightMostEle = array[size-1];
    for(int i = 0; i < size-1; i++)
    {
        array[size-1-i] = array[size-2-i];
    }
    array[0] = rightMostEle; 
}

void rightShift_N(int* array, size_t size, int n)
{
    for(int i = 0; i < n; i++) rightShift(array, size);
}

void printArray(int* array, size_t size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;
}

void swap(int& a, int& b)
{
    if(&a == &b) return;
    a = a^b;
    b = b^a;
    a = a^b;
}
void reverse(int* array, int pos, int len)
{
    for(int i = 0; i < len/2; i++)
    {
        swap(array[i], array[pos+len-1-i]);
    }
}
void rotate(int* array, size_t size, int n)
{
    n = n% size;
    n = (n+size)%size;
    reverse(array, 0, size - n);
    reverse(array, size-n, n);
    reverse(array, 0, size);
}

int main()
{
    int n = 3;
    size_t size = 5;
    int* array = new int[size]{1, 2, 3, 4, 5};
    printArray(array, size);
    rightShift_N(array, size, n);
    printArray(array, size);
    delete[] array;
}