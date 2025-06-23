#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0, totalCost = 0;
    int start = 0, tank = 0;

    for (int i = 0; i < gas.size(); i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];

        // If tank goes negative, can't start from previous stations
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    return (totalGas < totalCost) ? -1 : start;
}
