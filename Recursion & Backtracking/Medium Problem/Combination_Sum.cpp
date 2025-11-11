#include<iostream>
#include<vector>
using namespace std;

void findCombinations(int index, int target, vector<int>& candidates, vector<int>& currentCombination, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(currentCombination);
        return;
    }
    if (target < 0 || index >= candidates.size()) {
        return;
    }

    // Include the current candidate
    currentCombination.push_back(candidates[index]);
    findCombinations(index, target - candidates[index], candidates, currentCombination, result);
    currentCombination.pop_back();

    // Exclude the current candidate and move to the next
    findCombinations(index + 1, target, candidates, currentCombination, result);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> currentCombination;
    findCombinations(0, target, candidates, currentCombination, result);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> combinations = combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << ":\n";
    for (const auto& combination : combinations) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}