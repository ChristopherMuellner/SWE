#include <iostream>


using namespace std;


int sum(const int* pNumbers, unsigned int numbersSize);
int minimum(const int* pNumbers, unsigned int numbersSize);
int maximum(const int* pNumbers, unsigned int numbersSize);
int median(int* pNumbers, unsigned int numbersSize);
float average(const int* pNumbers, unsigned int numbersSize);
void printMemoryView(const int* pNumbers, unsigned int numbersSize);
bool isPrimeNumber(int);


int main()
{
    int numbers[] =
            {
                    44573, 24856, 6663,  63799, 58352, 32987, 385,   49006, 16234, 1864,
                    70452, 39270, 51521, 59321, 86473, 57078, 14682, 21066, 36264, 41885,
                    49988, 42082, 19369, 96273, 43921, 723,   67045, 51027, 85441, 6066,
                    77023, 33335, 70686, 90768, 78386, 10778, 87307, 71577, 43527, 7730,
                    89103, 91605, 54612, 48948, 21435, 39717, 46139, 97527, 92596, 84710,
                    2490,  30172, 22199, 26717, 80938, 30109, 4212,  73593, 96297, 45318,
                    86037, 47184, 97055, 9866,  20684, 46183, 40171, 73454, 78345, 25569,
                    85891, 1505,  58211, 6755,  1072,  39853, 91810, 86441, 53402, 21288,
                    34847, 50878, 90456, 62736, 15583, 90197, 93377, 99493, 24725, 75949,
                    56198, 28856, 81799, 40044, 75558, 12424, 22157, 85085, 97611, 77915,
                    48320 };

    int arrayLength = sizeof(numbers) / sizeof(int);

    cout << "sum: " << sum(numbers, arrayLength) /* TODO: add function call here and remove 0 */ << endl;
    cout << "average: " << average(numbers, arrayLength) /* TODO: add function call here and remove 0 */ << endl;
    cout << "minimum: " << minimum(numbers, arrayLength) /*TODO: add function call here and remove 0 */ << endl;
    cout << "maximum: " << maximum(numbers, arrayLength) /* TODO: add function call here and remove 0 */ << endl;
    cout << "median: " << median(numbers, arrayLength) /* TODO: add function call here and remove 0 */ << endl;

    cout << endl;
    printMemoryView(numbers, arrayLength);

    int counter = 0;

    for (int i = 0; i < arrayLength;i++)
    {
        if (isPrimeNumber(*(numbers + i)))
        {
            counter++;
        }
    }

    cout << endl;
    cout << "Primzahlen: " << counter << endl;

    return 0;
}


int sum(const int* pNumbers, unsigned int numbersSize)
{
    int sum = 0;
    for (int i = 0; i < numbersSize; i++)
    {
        sum += *(pNumbers + i);
    }

    return sum;
}


float average(const int* pNumbers, unsigned int numbersSize)
{
    int sum = 0;
    for (int i = 0; i < numbersSize; i++)
    {
        sum += *(pNumbers + i);
    }
    return static_cast<float>(sum) / static_cast<float>(numbersSize); // Vl nicht nötig return (float)sum / numbersSize;
}


int minimum(const int* pNumbers, unsigned int numbersSize)
{
    int min = *(pNumbers);

    for (int i = 0; i < numbersSize; i++)
    {
        if (*(pNumbers + i) < min)
        {
            min = *(pNumbers + i);
        }
    }
    return min;
}


int maximum(const int* pNumbers, unsigned int numbersSize)
{
    int max = *(pNumbers);

    for (int i = 0; i < numbersSize; i++)
    {
        if (*(pNumbers + i) > max)
        {
            max = *(pNumbers + i);
        }
    }
    return max;
}


int median(int* pNumbers, unsigned int numbersSize)
{
    for (int i = 0; i < numbersSize; i++)
    {
        for (int j = 0; j < numbersSize - i - 1; j++)
        {
            if (*(pNumbers + j) > *(pNumbers + j + 1))
            {
                int tmp = *(pNumbers + j);
                *(pNumbers + j) = *(pNumbers + j + 1);
                *(pNumbers + j + 1) = tmp;
            }
        }
    }
    return *(pNumbers + (numbersSize / 2));
}


void printMemoryView(const int* pNumbers, unsigned int numbersSize)
{
    cout << "Adress" << "\t" << "\tValue" << endl;
    for (int i = 0; i < numbersSize; i++)
    {
        cout << (pNumbers + i) << "\t" << *(pNumbers + i) << endl;
    }
}


bool isPrimeNumber(int x)
{
    if (x <= 1)
    {
        return false;
    }

    for (int i = 2; i < x; i++)
    {
        if ((x % i) == 0)
        {
            return false;
        }
    }
    return true;
}