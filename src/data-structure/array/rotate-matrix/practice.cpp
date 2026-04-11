#include <array>
#include <iostream>
using namespace std;

const size_t MAX_SIZE = 256;
using Matrix = array<array<int, MAX_SIZE>, MAX_SIZE>;
static inline void printArray(array<int, MAX_SIZE> arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

static inline void printMatrix(Matrix matrix, size_t size)
{
    cout << "================" << endl;
    for (size_t i = 0; i < size; i++)
        printArray(matrix[i], size);
}

void symmetrix(Matrix& matrix, size_t size)
{
    for (size_t i = 0; i < size; i++)
        for (size_t j = i; j < size; j++)
            swap(matrix[i][j], matrix[j][i]);
}
void vertMirror(Matrix& matrix, size_t size)
{
    for (size_t j = 0; j < size; j++)
    {
        int start = 0, end = size - 1;
        while(start < end)
        {
            swap(matrix[start++][j], matrix[end--][j]);
        }
    }
}
void cwRotate(Matrix& matrix, size_t size)
{
    vertMirror(matrix, size);
    symmetrix(matrix, size);
}
void ccwRotate(Matrix& matrix, size_t size)
{
    symmetrix(matrix, size);
    vertMirror(matrix, size);
}

int main()
{
    array<array<int, MAX_SIZE>, MAX_SIZE> matrix
        {{ {{1,2,3,4,5}},
            {{1,2,3,4,5}},
            {{1,2,3,4,5}},
            {{1,2,3,4,5}},
            {{1,2,3,4,5}}, }};
    printMatrix(matrix, 5);
    cwRotate(matrix, 5);
    printMatrix(matrix, 5);
    cwRotate(matrix, 5);
    printMatrix(matrix, 5);
}