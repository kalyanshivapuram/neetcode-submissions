/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n==0){
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](const Interval& a,const Interval& b){return a.start < b.start;});
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(const Interval& m : intervals){
            if(!minheap.empty() && minheap.top() <= m.start){
                minheap.pop();
            }
            minheap.push(m.end);
        }
        return minheap.size();

    }
};
