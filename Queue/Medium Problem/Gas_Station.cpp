#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public :
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int tg = 0,tc = 0,cs = 0, s = 0;
        for(int i = 0; i < gas.size(); i++){
            tg += gas[i];
            tc += cost[i];
            cs += (gas[i] - cost[i]);
            if(cs < 0){
                s = i + 1;
                cs = 0; 
            }
        }
        if(tg < tc){
            return -1;
        }
        return s;
    }
};

int main(){
    Solution sol;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    int result = sol.canCompleteCircuit(gas, cost);
    cout << result << endl;
    return 0;
}