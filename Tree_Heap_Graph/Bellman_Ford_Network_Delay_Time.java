/**


There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

 

Example 1:



Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
 

Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.

**/

//Problem Link - https://leetcode.com/problems/network-delay-time/
class Solution {
	public static int networkDelayTime(int[][] times, int N, int K) {
		// initialize distance array
		double[] dis = new double[N];
		Arrays.fill(dis, Double.POSITIVE_INFINITY);
		dis[K - 1] = 0;

		// loop for n-1 times over the edges
		// Note if we loop for the nth times and still the min weight is reduced, it
		// implies that graph contains negative edges
		for (int i = 1; i <= N - 1; i++) {
			for (int[] time : times) {
				int src = time[0] - 1;
				int dst = time[1] - 1;
				int cost = time[2];
				// check if this distance reduces the distance in dis Array
				dis[dst] = Math.min(dis[dst], dis[src] + cost);
			}
		}

        //logic specific to problem statement
		double maxDis = Double.NEGATIVE_INFINITY;
		for (int i = 0; i < N; i++) {
			if (dis[i] == Double.POSITIVE_INFINITY)
				return -1;
			maxDis = Math.max(maxDis, dis[i]);
		}
		return (int) maxDis;
	}

}
