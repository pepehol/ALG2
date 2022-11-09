// du3.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

void printArray(int* A, const int numElements)
{
    for (int i = 0; i < numElements; i++)
        std::cout << A[i] << " ";
    std::cout << "\n";
}

void ComparisonCountingSort(const int* inArr, const unsigned int numElements, int* outArr)
{
    int* C = new int[numElements];

    for (int i = 0; i < numElements; i++)
    {
        C[i] = 0;
    }
    
    for (int i = 0; i < numElements - 1; i++)
    {
        for (int j = i + 1; j < numElements; j++)
        {
            if (inArr[i] < inArr[j])
            {
                C[j] = C[j] + 1;
            }
            else
            {
                C[i] = C[i] + 1;
            }
        }
    }

    for (int i = 0; i < numElements; i++)
    {
        outArr[C[i]] = inArr[i];
    }

    delete[] C;
}

void DistributionCountingSort(const int* inArr, const unsigned int numElements,  const unsigned l, const unsigned u, int* outArr)
{
    unsigned int numElementsD = u - l + 1;

    int* D = new int[numElementsD];

    for (unsigned int j = 0; j < numElementsD; j++)
    {
        D[j] = 0;
    }

    for (unsigned int i = 0; i < numElements; i++)
    {
        D[inArr[i] - l] = D[inArr[i] - l] + 1;
    }

    for (unsigned int j = 1; j < numElementsD; j++)
    {
        D[j] = D[j - 1] + D[j];
    }

    for (int i = numElements - 1; i >= 0; i--) 
    {
        int j = inArr[i] - l;
        outArr[D[j] - 1] = inArr[i];
        D[j] = D[j] - 1;
    }

    delete[] D;
}


int main()
{
    const unsigned int N = 7;
    int A[N] = { 1, 4, 2, 4, 1, 3, 1 };
    int B[N];

    ComparisonCountingSort(A, N, B);

    printArray(B, N);

    const unsigned int M = 6;
    int C[M] = { 13, 11, 12, 13, 12, 12 };
    int D[M];

    DistributionCountingSort(C, N - 1, 11, 13, D);

    printArray(D, M);

    return EXIT_SUCCESS;
}
