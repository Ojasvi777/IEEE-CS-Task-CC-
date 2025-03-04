//Data structure implementation
#include <iostream>
#include <vector>
using namespace std;
class Merger {
private:
    vector<pair<int, int>> intervals;
public:
    void addInterval(int start, int end) {
        vector<pair<int, int>> merged;
        bool inserted = false;

        for (const auto& interval : intervals) {
            if (end < interval.first) {
                if (!inserted) {
                    merged.push_back({start, end});
                    inserted = true;
                }
                merged.push_back(interval);
            } else if (start > interval.second) {
                merged.push_back(interval);
            } else {
                start = min(start, interval.first);
                end = max(end, interval.second);
            }
        }
        if (!inserted) {
            merged.push_back({start, end});
        }
        intervals = merged;
    }
    vector<pair<int, int>> getIntervals() {
        return intervals;
    }
    void printI() {
        cout << "[ ";
        for (const auto& interval : intervals) {
            cout << "[" << interval.first << ", " << interval.second << "] ";
        }
        cout << "]" << endl;
    }
};
int main() {
    Merger merger;
    merger.addInterval(1, 5);
    merger.addInterval(6, 8);
    merger.addInterval(4, 7);
    cout << "Merged Intervals: ";
    merger.printI();
    return 0;
}
