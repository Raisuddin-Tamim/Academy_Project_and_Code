#include <bits/stdc++.h>
using namespace std;

bool Find(const vector<int>& frames, int key) {
    return find(frames.begin(), frames.end(), key) != frames.end();
}

int find_optimal_index(const vector<int>& pages, const vector<int>& frames, int current_index) {
    int index_to_replace = -1;
    int farthest_usage = current_index;

    for (int i = 0; i < frames.size(); i++) {
        int j;
        for (j = current_index; j < pages.size(); j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest_usage) {
                    farthest_usage = j;
                    index_to_replace = i;
                }
                break;
            }
        }
        if (j == pages.size()) {
            return i;
        }
    }

    return (index_to_replace == -1) ? 0 : index_to_replace;
}

void OptimalPageReplacement(const vector<int>& pages, int frame_size) {
    vector<int> frames(frame_size, -1);
    int page_faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        if (!Find(frames, pages[i])) {
            page_faults++;
            auto it = find(frames.begin(), frames.end(), -1);
            if (it != frames.end()) {
                *it = pages[i];
            } else {
                int replace_index = find_optimal_index(pages, frames, i + 1);
                frames[replace_index] = pages[i];
            }
        }
    }

    cout << "Page faults: " << page_faults << endl;
}

int main() {
    cout << "Enter number of pages: ";
    int n; cin >> n;
    vector<int> pages(n);

    cout << "Enter pages: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter frame size: ";
    int frame_size; cin >> frame_size;

    OptimalPageReplacement(pages, frame_size);

    return 0;
}
//2 3 5 4 0 5 3 2 4 0

