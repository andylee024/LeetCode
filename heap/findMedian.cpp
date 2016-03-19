// Leet Code 295 - Find Median from Data Stream

// Solution Idea:
// Here the idea is to maintain two priority queues (heaps), one containing all the smaller items and the other containing
// the bigger items. This allows quick access for finding the median because you just need to query the top item of the queue// Note, smaller items is maxPQ and bigger items is minPQ. 

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

class MedianFinder {

public:

    std::priority_queue<int> q1; // lower half items -  max priority queue
    std::priority_queue<int, std::vector<int>, std::greater<int> > q2; // upper half items - min priority queue
    
    
    // Adds a number into the data structure.
    void addNum(int num) {

        // edge case - size 0 queues
        if (q1.size() == 0){
            q1.push(num);
            return;
        }

        if (q2.size() == 0){
            if (num < q1.top()){
                q2.push(q1.top());
                q1.pop();
                q1.push(num);
            }
            else
                q2.push(num);
            
            return;
        }
             

        // regular case 
        if (q1.size() == q2.size()){
            
    		if (num >= q1.top() && num <= q2.top())
                q1.push(num);
            
            else if (num < q1.top())
                q1.push(num);
            
            else if (num > q2.top()){
                q1.push(q2.top());
                q2.pop();
                q2.push(num);
            }
        }

        else{ 
            if (num <= q1.top()){
                q2.push(q1.top());
                q1.pop();
                q1.push(num);
            }
            else           
                q2.push(num);
        }       
    }
        

    // Returns the median of current data stream
    double findMedian() {
        if (q1.size() == q2.size())
            return (q1.top() + q2.top())/2.0;
        
        return q1.top();
    }
};

