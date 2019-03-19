public

class Solution {
public

    ArrayList <ArrayList<Integer>> combinationSum2(int[] num, int target) {
        ArrayList <ArrayList<Integer>> res = new ArrayList <ArrayList<Integer>>();
        Arrays.sort(num);
        combinationSumHelper(candidates, 0, target, new ArrayList<Integer>(), res);
        return res;
    }

public

    void combinationSumHelper(int[] candidates, int start, int target, ArrayList <Integer> path,
                              ArrayList <ArrayList<Integer>> res) {
        if (start < 0 || target < 0)
            return;
        if (target == 0) {
            ArrayList <Integer> result = new ArrayList<Integer>(path);
            res.add(result);
        } else {
            for (int i = start; i < candidates.length && candidates[i] <= target; i++) {
                // skip duplicates
                if (i > start && candidates[i] == candidates[i - 1])
                    continue;
                path.add(candidates[i]);
                combinationSumHelper(candidates, i + 1, target - candidates[i], path, res);
                path.remove(path.size() - 1);
            }
        }
    }
}