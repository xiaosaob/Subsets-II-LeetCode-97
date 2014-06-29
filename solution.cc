// Given a collection of integers that might contain duplicates, S, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If S = [1,2,2], a solution is:

// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> sol;
        sort(S.begin(), S.end());
        helper(S, 0, sol, res);
        return res;
    }
    
    void helper(vector<int> &S, int startIdx, vector<int> &sol, vector<vector<int> > &res) {
        if(startIdx == S.size()) {
            res.push_back(sol);
            return;
        }
        
        int i = startIdx;
        while(i < S.size() && S[i] == S[startIdx]) ++i;
        helper(S, i, sol, res);
        
        sol.push_back(S[startIdx]);
        helper(S, startIdx+1, sol, res);
        sol.pop_back();
    }
};
