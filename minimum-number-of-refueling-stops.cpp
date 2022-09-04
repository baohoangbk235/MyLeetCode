// A car travels from a starting position to a destination which is target miles east of the starting position.

// There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates that the ith gas station is positioni miles east of the starting position and has fueli liters of gas.

// The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

// Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.

// Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the destination with 0 fuel left, it is still considered to have arrived.

#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int N = stations.size();
        vector<long> dp(N + 1, 0);
        dp[0] = startFuel;
        for (int i = 0; i < N; ++i)
        {
            for (int t = i; t >= 0; --t)
            {
                if (dp[t] >= stations[i][0])
                    dp[t + 1] = max(dp[t + 1], (long)stations[i][1] + dp[t]);
            }
        }

        for (int i = 0; i <= N; ++i)
        {
            if (dp[i] >= target)
                return i;
        }
        return -1;
    }
};