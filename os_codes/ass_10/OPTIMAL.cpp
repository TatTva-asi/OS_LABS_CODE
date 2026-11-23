// optimal 

#include<iostream>
#include<vector>
using namespace std;
int main(){

    // no of frames in memory
    int capacity=3;

    // page reference string
    vector<int> pages = {1, 2, 3, 4, 1, 2, 5};

    // total no of pages
    int n = pages.size();

    // store pages that are currently in memory
    vector<int> frames;

    int pageFaults = 0;

    for (int i = 0; i < n;i++){
        int page = pages[i];

        // check if page is already present ?
        bool found = false;
        for (int j = 0; j < frames.size();j++){

            if (frames[j] == page){
                found = true;
                break;
            }
        }

        // if page not present page fault occurs
        if(found==false){
            pageFaults++;

            // if empty frame is available
            if(frames.size()<capacity){
                frames.push_back(page);
            }

            else{

                // find the page whose next use is farthest
                int replaceIdx = -1;
                int farthest = -1;

                for (int j = 0; j < frames.size();j++){
                    // search for next use of frames[j]
                    int k;
                    for (k = i + 1; k < n;k++){
                        if(pages[k]==frames[j])
                            break;  
                    }
                    // now k points to the use index of jth process
                    // if page is never used again , replace it
                    if(k==n){
                        replaceIdx = j;
                        break;
                    }
                    
                    // find page farthese used in future
                    if(k>farthest){
                        farthest = k;
                        replaceIdx = j;
                    }
                }
                // replace selected page
                frames[replaceIdx] = page;
            }
        }

        // display current frames
        cout << "Page " << page << " : ";
        for (int j = 0; j < frames.size();j++){
            cout << frames[j] << " ";
        }
        cout << endl;
        if(found)
            cout << "HIT" << endl;
        else
            cout << "PAGE FAULT " << endl;
        
    }
    cout << endl;

    // display total page faults
    cout << "Total Page faults= " << pageFaults << endl;
}