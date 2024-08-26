class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // If starting fuel is already greater or equal to target, no need to 
        // refuel
        if (startFuel >= target) return 0;

        // Create a max heap to store the fuel capacities of stations
        priority_queue<int> max_heap;
        int i = 0, n = stations.size();
        int stops = 0;
        int max_distance = startFuel;

        // Loop until the car reaches the target or is out of fuel
        while (max_distance < target) {
            // Add fuel to the heap for stations within the current range
            while (i < n && stations[i][0] <= max_distance) {
                max_heap.push(stations[i][1]);
                i++;
            }

            // If there are no more stations in range and we can't reach the target, return -1
            if (max_heap.empty()) return -1;

            // Refuel with the largest amount available and increment stops
            max_distance += max_heap.top();
            max_heap.pop();
            stops++;
        }

        // Return the number of stops taken
        return stops;
    }
};