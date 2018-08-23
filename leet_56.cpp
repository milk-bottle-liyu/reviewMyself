static const auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    static bool comp(const Interval & a, const Interval &b)
    {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> rc;
        if (intervals.size() == 0)
            return rc;
        sort(intervals.begin(), intervals.end(), comp);

        int curStart = intervals[0].start, curEnd = intervals[0].end;
        for (unsigned i = 0; i < intervals.size(); i++)
        {
            if (curEnd >= intervals[i].start)
            {
                if (curEnd < intervals[i].end)
                    curEnd = intervals[i].end;
            }
            else
            {
                rc.push_back(Interval(curStart, curEnd));
                curStart = intervals[i].start;
                curEnd = intervals[i].end;
            }
        }
        rc.push_back(Interval(curStart, curEnd));

        return rc;
    }
};
