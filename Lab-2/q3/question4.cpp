#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

double findMedian(const std::vector<int>& arr) {
    std::vector<int> sortedArr = arr;  // Make a copy to avoid modifying the original array
    std::sort(sortedArr.begin(), sortedArr.end());

    int n = sortedArr.size();
    
    if (n % 2 == 1) {
        // If the number of elements is odd, return the middle element
        return static_cast<double>(sortedArr[n / 2]);
    } else {
        // If the number of elements is even, return the average of the two middle elements
        return static_cast<double>(sortedArr[n / 2 - 1] + sortedArr[n / 2]) / 2.0;
    }
}

int main() {
    std::ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        std::cerr << "Error opening the input file.\n";
        return 1;
    }

    int n;
    input_file >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        input_file >> arr[i];
    }

    input_file.close();

    double median = findMedian(arr);

    std::ofstream output_file("output_median.txt");
    if (!output_file.is_open()) {
        std::cerr << "Error opening the output file.\n";
        return 1;
    }

    output_file << "Median: " << median << std::endl;

    output_file.close();

    return 0;
}
