#include <iostream>
#include <vector>
#include <fstream>

int medianOfThree(std::vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] < arr[low]) {
        std::swap(arr[low], arr[mid]);
    }
    if (arr[high] < arr[low]) {
        std::swap(arr[low], arr[high]);
    }
    if (arr[mid] > arr[high]) {
        std::swap(arr[mid], arr[high]);
    }

    return mid;
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivotIndex = medianOfThree(arr, low, high);
    int pivotValue = arr[pivotIndex];

    std::swap(arr[pivotIndex], arr[high]);

    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivotValue) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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

    quickSort(arr, 0, n - 1);

    // Output the sorted array to output.txt
    std::ofstream output_file("output.txt");
    if (!output_file.is_open()) {
        std::cerr << "Error opening the output file.\n";
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        output_file << arr[i] << " ";
    }

    output_file.close();

    return 0;
}
