link: https://leetcode.com/problems/relative-ranks/

class Solution {
public:
    static const int length = 100000;

    struct Heap {
        int values[length];
        int size;
        Heap () {
            size = 0;
        }
        int leftChildIndex (int ii) {
            return (2 * ii + 1);
        }
        int rightChildIndex (int ii) {
            return (2 * ii + 2);
        }
        int getMax () {
            return values[0];
        }
        void siftUp (int i) { // for one of the previous problems used &i
            int parent = (i - 1) / 2;
            while (i > 0 && values[i] > values[parent]) {
                swap (values[i], values[parent]);
                i = parent;
                parent = (i - 1) / 2;
            }
        }
        // for building the heap by siftUp
        // this builds by default builds correct heap
        void add (int x) {
            int i = size++;
            values[i] = x;
            siftUp (i);
            // optional
            // cout << i + 1 << '\n';
        }
        // for building the heap by siftDown
        void addBySiftDown (int x) {
            int i = size++;
            values[i] = x;
    //        int ii = (i - 1) / 2;
    //        siftDown (ii);
        }
        void buildHeapBySiftDown () {
            for (int i = size / 2; i >= 0; i--) {
                siftDown (i);
            }
        }
        void siftDown (int ii) { // for one of the previous problems used &ii
            while (2 * ii + 1 < size) {
                int leftChild = leftChildIndex(ii);
                int rightChild = rightChildIndex(ii);
                int candidate = leftChild;
                if (rightChild < size) {
                    if (values[rightChild] > values[leftChild]) {
                        candidate = rightChild;
                    }
                }
                if (values[ii] < values[candidate]) {
                    swap (values[ii], values[candidate]);
                    ii = candidate;
                } else {
                    // if the parent is incomparable
                    break;
                }
            }
        }
        void deleteRoot () {
            if (size > 0) {
                values[0] = values[--size];
                int ii = 0;
                siftDown (ii);
            }
        }
        void print () {
            for (int i = 0; i < size; i++) {
                cout << values[i] << ' ';
            } cout << '\n';
        }
        void increasePriority (int ii, int x) {
            int answer = ii;
            values[ii] += x;
            siftUp (ii);
            answer = ii;
            // printing the final index
            cout << ++answer << '\n';
        }
        void decreasePriority (int ii, int x) {
            int answer = ii;
            values[ii] -= x;
            siftDown (ii);
            answer = ii;
            // printing the final index
            cout << ++answer << '\n';
        }
        void extractMax () {
            int maximum = values[0];
            values[0] = values[--size];
            int ii = 0;
            if (size != 0) {
                siftDown (ii);
            }
            else {
                ii = -1;
            }
            // printing the index of the sifted element and maximum
            cout << ++ii << ' ' << maximum << '\n';
        }
        void deleteCustom (int index) {
            index--;
            cout << values[index] << '\n';
            int tempA = values[index], tempB = values[size - 1];
            swap (values[index], values[size - 1]);
            size--;
            if (tempA < tempB) {
                siftUp (index);
            } else {
                siftDown (index);
            }
        }
    };
    vector<string> findRelativeRanks(vector<int>& score) {
        Heap h;
        int cnt = 1;
        vector <string> ans;
        int n = (int) score.size ();
        for (int i = 0; i < n; i++) {
            h.add (score[i]);
        }
        vector <int> sorted;
        for (int i = 0; i < n; i++) {
            sorted.push_back (h.getMax ());
            h.deleteRoot ();
        }
        for (int i = 0; i < n; i++) {
            int place;
            for (int j = 0; j < n; j++) {
                if (score[i] == sorted[j]) {
                    place = j + 1;
                    break;
                }
            }
            if (place == 1) {
                ans.push_back ("Gold Medal");
            } else if (place == 2) {
                ans.push_back ("Silver Medal");
            } else if (place == 3) {
                ans.push_back ("Bronze Medal");
            } else {
                ans.push_back (to_string (place));        
            }
        }
        return ans;
    }
};