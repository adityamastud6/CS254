#include <iostream>
#include <vector>
#include <fstream>

void merge(std::vector<int> &A, int start, int mid, int end)
{
    int p = start, q = mid + 1;

    while (p <= mid && q <= end)
    {
        if (A[p] <= A[q])
        {
            p++;
        }
        else
        {
            int temp = A[q];

            for (int i = q; i > p; i--)
            {
                A[i] = A[i - 1];
            }

            A[p] = temp;

            p++;
            mid++;
            q++;
        }
    }
}

void inPlaceMergeSort(std::vector<int> &A, int n, int m)
{
    for (int currentSize = 1; currentSize < n; currentSize *= 2)
    {
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currentSize)
        {
            int mid = std::min(leftStart + currentSize - 1, n - 1);
            int rightEnd = std::min(leftStart + 2 * currentSize - 1, n - 1);

            merge(A, leftStart, mid, rightEnd);
        }
    }
}

int main()
{
    std::ifstream input_file("input.txt");
    if (!input_file.is_open())
    {
        std::cerr << "Error opening the input file.\n";
        return 1;
    }

    int n, m;
    input_file >> n >> m;

    std::vector<int> A(n);
    for (int i = 0; i < n; ++i)
    {
        input_file >> A[i];
    }

    input_file.close();

    inPlaceMergeSort(A, n, m);

    // Output the sorted array to output.txt
    std::ofstream output_file("output.txt");
    if (!output_file.is_open())
    {
        std::cerr << "Error opening the output file.\n";
        return 1;
    }

    for (int i = 0; i < n; ++i)
    {
        output_file << A[i] << " ";
    }

    output_file.close();

    return 0;
}
