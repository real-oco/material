#include <bits/stdc++.h>
using namespace std;

// Max-Heap using zero-based indexing
class Heap {
private:
    vector<int> nums;

    void heapifyDown(int idx) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int largest = idx;

        if (left < nums.size() && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < nums.size() && nums[right] > nums[largest]) {
            largest = right;
        }

        if (largest != idx) {
            swap(nums[idx], nums[largest]);
            heapifyDown(largest); // recursive call on swapped index
        }
    }

public:
    Heap() {}

    void insert(int num) {
        nums.push_back(num);
        int idx = nums.size() - 1;
        int parent = (idx - 1) / 2;

        while (idx > 0 && nums[parent] < nums[idx]) {
            swap(nums[parent], nums[idx]);
            idx = parent;
            parent = (idx - 1) / 2;
        }
    }

    void print() {
        for (auto it : nums) cout << it << " ";
        cout << endl;
    }

    void extractMax() {
        if (nums.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }

        cout << "Max Element: " << nums[0] << endl;
        nums[0] = nums.back();
        nums.pop_back();
        heapifyDown(0);
    }
};

int main() {
    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(40);
    h.insert(30);

    cout << "Current Heap: ";
    h.print();

    h.extractMax();
    cout << "Heap after extractMax(): ";
    h.print();

    h.extractMax();
    cout << "Heap after another extractMax(): ";
    h.print();

    return 0;
}
