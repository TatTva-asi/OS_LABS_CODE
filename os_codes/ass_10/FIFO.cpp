#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
void display(queue<int> q)
{
    while (!q.empty())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
    }
}
int main()
{
    // no of frames available in memory
    int capacity = 3;

    // page reference string
    int pages[] = {1, 2, 3, 4, 1, 2, 5};

    // total number of pages
    int n = 7;

    // queue stores the pages currently in memory
    queue<int> q;

    // counts total no of page faults

    int page_Faults = 0;

    // process each page one by one
    for (int i = 0; i < n; i++)
    {
        int page = pages[i];

        // check if page is already there in memory
        bool flag = false;

        queue<int> temp = q;
        while (!temp.empty())
        {
            if (temp.front() == page)
            {
                flag = true;
                break;
            }
            temp.pop();
        }

        // if page was not found , page fault occurs
        if (flag == false)
        {
            page_Faults++;

            // if memory is full, remove the oldest page
            if (q.size() == capacity)
            {
                q.pop();
            }

            // push page into the queue

            q.push(page);
        }

        // display page in memory
        cout << "Page " << page << " : ";
        display(q);

        // if page hit
        if (flag == true)
            cout << " (Hit) ";
        else
            cout << " (Page Fault) ";
    }
    cout << endl;

    // display total page faults
    cout << "\n total page fault = " << page_Faults << endl;
    return 0;
}