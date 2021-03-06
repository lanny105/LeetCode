//Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//Each number in C may only be used once in the combination.
//
//Note:
//All numbers (including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
//A solution set is: 
//[
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]
//和上一题思路几乎一样，需要修改的地方：对于弟弟子树， 如果nums[depth]的值一样，直接就忽略。 第二点，子树必需从i+1开始递归，因为一个数不能重复使用。
//同理最好画一下深搜树再写。

class Solution {
public:
    bool dfs(vector<int>& candidates, int target, int depth, vector<int>& cur,vector<vector<int>> &res) {  //true表示可以对弟弟子树剪枝
        if(!target) {
            res.push_back(cur);
            return true;
        }
        
        if(target < 0) return true;
        
        for(int i = depth; i < candidates.size(); ++i) {
            if(i>depth&&candidates[i] == candidates[i-1]) continue;
            cur.push_back(candidates[i]);
            if(dfs(candidates, target-candidates[i], i+1, cur, res)) {
                // break;
                cur.pop_back();
                break;
            }
            cur.pop_back();
        }
        return false;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(candidates, target, 0, cur, res);
        
        return res;
    }
    
    注意这题防止重复，（数字有可能有重复，所以即使选取的下标不同也算重复），我们只能选择排序，然后展开时，略过所有那些相同的数。记住剪枝还是依靠candidates[i] > target剪枝。
    void dfs(vector<int> &candidates, int depth, vector<int> &cur, vector<vector<int>> &res, int target) {
        if(target == 0) {
            res.push_back(cur);
            return;
        }
        
        for(int i = depth; i < candidates.size(); ++i) {
            if(candidates[i] > target) break;
            if(i > depth&&candidates[i] == candidates[i-1]) continue;
            cur.push_back(candidates[i]);
            dfs(candidates, i+1, cur, res, target - candidates[i]);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<vector<int>> res;
        dfs(candidates, 0, cur, res, target);
        return res;
    }
};