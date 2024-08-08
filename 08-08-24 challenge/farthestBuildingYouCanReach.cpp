priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap for the smallest climbs

        for(int i = 0; i < heights.size() - 1; i++) {
            int climb = heights[i+1] - heights[i];

            if(climb > 0) {
                minHeap.push(climb);

                if(minHeap.size() > ladders) {
                    bricks -= minHeap.top();
                    minHeap.pop();
                }

                if(bricks < 0) {
                    return i;
                }
            }
        }

        return heights.size() - 1;