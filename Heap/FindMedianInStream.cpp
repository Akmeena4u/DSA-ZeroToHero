
class Solution {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    // Function to insert heap.
    void insertHeap(int &x) {
        if (maxHeap.empty() || x < maxHeap.top())
            maxHeap.push(x);
        else
            minHeap.push(x);

        balanceHeaps();
    }

    // Function to balance heaps.
    void balanceHeaps() {
        int maxSize = maxHeap.size();
        int minSize = minHeap.size();

        if (abs(maxSize - minSize) <= 1)
            return;

        if (maxSize > minSize) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Function to return Median.
    double getMedian() {
        int maxSize = maxHeap.size();
        int minSize = minHeap.size();

        if (maxSize == minSize) {
            if (maxSize == 0)
                return 0;
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        return maxSize > minSize ? maxHeap.top() : minHeap.top();
    }
};
