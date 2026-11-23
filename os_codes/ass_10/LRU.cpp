// LRU (Least Recently used )

#include <iostream>
#include <vector>
using namespace std;
int main()
{

    // number of frames available in memory
    int capacity = 3;

    // page reference string
    vector<int> pages = {1, 2, 3, 1, 4, 2, 5};

    // total number of page references
    int n = pages.size();

    // stores pages currently present in memory
    vector<int> frames;

    // stores the last used position of each page
    vector<int> lastUsed;

    // counts total pagefaults
    int page_Faults = 0;

    // process each page
    for (int i = 0; i < n; i++)
    {
        int page = pages[i];

        // check if page is already present
        bool found = false;
        int pos = -1;

        for (int j = 0; j < frames.size(); j++)
        {
            if (frames[j] == page)
            {
                found = true;
                pos = j;
                break;
            }
        }
        // Page hit
        if (found)
            lastUsed[pos] = i;
        else
        {
            // Page Fault occurs
            page_Faults++;

            // if frames are full find the recently used page
            if (frames.size() == capacity)
            {
                int lru = 0;

                // find index of least recently used
                for (int j = 1; j < lastUsed.size(); j++)
                {
                    if (lastUsed[j] < lastUsed[lru])
                        lru = j;
                }
                // replace the LRU page
                frames[lru] = page;

                // update its last used position
                lastUsed[lru] = i;
            }
            else
            {
                // empty frame available
                frames.push_back(page);
                lastUsed.push_back(i);
            }
        }
        // display current frames

        cout << "Page " << page << " : ";
        for (int j = 0; j < frames.size(); j++)
        {
            cout << frames[j] << " ";
        }
        if (found)
            cout << "HIT " << endl;
        else
            cout << "Page fault " << endl;
    }

    cout << endl;
    // display total number of page faults
    cout << "Total page Faults = " << page_Faults << endl;
}