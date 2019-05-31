#include <iostream>
#include <vector>

int paritition(std::vector<int> &data, int low, int high) {
    int pivot = data[low];
    while (low < high) {
        while (low < high && data[high] >= pivot) {
            --high;
        }
        data[low] = data[high];

        while (low < high && data[low] <= pivot) {
            ++low;
        }
        data[high] = data[low];
    }
    data[low] = pivot;
    return low;
} 

void quickSort(std::vector<int> &data, int low, int high) {
    if (low < high) {
        int pivot = paritition(data, low, high);
        quickSort(data, low, pivot - 1);
        quickSort(data, pivot + 1, high);
    }
}


int main() {
    std::vector<int> data {6,4,5,12,1,767,23,11};
    for(std::vector<int>::const_iterator i = data.begin(); i != data.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    std::cout << "after sort" << std::endl;
    quickSort(data, 0, data.size() - 1);
    
    for(std::vector<int>::const_iterator i = data.begin(); i != data.end(); ++i) {
        std::cout << *i << " ";
    }
}
