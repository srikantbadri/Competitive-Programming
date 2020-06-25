/*

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


*/

//https://leetcode.com/problems/network-delay-time/

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class NetworkDelayTime {

	public static void main(String[] args) {
		System.out.println(
				new NetworkDelayTime().networkDelayTime(new int[][] { { 2, 1, 1 }, { 2, 3, 1 }, { 3, 4, 1 } }, 4, 2));
	}

	class Pair {
		int node;
		int dis;

		public Pair(int node, int dis) {
			super();
			this.node = node;
			this.dis = dis;
		}

		public int getNode() {
			return node;
		}

		public void setNode(int node) {
			this.node = node;
		}

		public int getDistance() {
			return dis;
		}

		public void setDis(int dis) {
			this.dis = dis;
		}

	}

	public int networkDelayTime(int[][] times, int N, int K) {
		List<List<Pair>> graph = new ArrayList<>();
		int[] dis = new int[N];

		// initialize distance array
		for (int i = 0; i < N; i++) {
			graph.add(new ArrayList<>());
			dis[i] = Integer.MAX_VALUE;
		}
		// distance from source node to source node is 0
		dis[K - 1] = 0;

		// create graph
		for (int[] time : times) {
			int src = time[0];
			int dst = time[1];
			int cost = time[2];
			graph.get(src - 1).add(new Pair(dst, cost));
		}

		// priority queue to keep track of nodes and the distances, kept in the
		// increasing order
		PriorityQueue<Pair> pQueue = new PriorityQueue<>((a, b) -> a.getDistance() - b.getDistance());
		pQueue.add(new Pair(K, 0));

		while (!pQueue.isEmpty()) {
			Pair selectedPair = pQueue.poll();

			int selectedNode = selectedPair.getNode();
			int selectedNodeDistance = selectedPair.getDistance();

			List<Pair> selectedList = graph.get(selectedNode - 1);
			for (Pair neighbor : selectedList) {
				int neighborNode = neighbor.getNode();
				int neighborDistance = neighbor.getDistance();
				if (dis[neighborNode - 1] > selectedNodeDistance + neighborDistance) {
					dis[neighborNode - 1] = selectedNodeDistance + neighborDistance;
					pQueue.offer(new Pair(neighborNode, dis[neighborNode - 1]));
				}
			}
		}

		int maxDis = 0;
		for (int i = 0; i < N; i++) {
			if (dis[i] == Integer.MAX_VALUE)
				return -1;
			maxDis = Math.max(maxDis, dis[i]);
		}
		return maxDis;
	}

}
