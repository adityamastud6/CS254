#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

void findFirstAndSecondMin(const std::vector<int> &arr, int &firstMin, int &secondMin)
{
    firstMin = std::numeric_limits<int>::max();
    secondMin = std::numeric_limits<int>::max();

    for (const int &num : arr)
    {
        if (num < firstMin)
        {
            secondMin = firstMin;
            firstMin = num;
        }
        else if (num < secondMin && num != firstMin)
        {
            secondMin = num;
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

    int n;
    input_file >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        input_file >> arr[i];
    }

    input_file.close();

    if (n < 2)
    {
        std::cerr << "Array should have at least two elements.\n";
        return 1;
    }

    int firstMin, secondMin;
    findFirstAndSecondMin(arr, firstMin, secondMin);

    std::ofstream output_file("output.txt");
    if (!output_file.is_open())
    {
        std::cerr << "Error opening the output file.\n";
        return 1;
    }

    output_file << "First Min: " << firstMin << std::endl;
    output_file << "Second Min: " << secondMin << std::endl;

    output_file.close();

    return 0;
}
