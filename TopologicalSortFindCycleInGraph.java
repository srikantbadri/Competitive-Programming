class Solution {
	public static boolean canFinish(int numCourses, int[][] prerequisites) {
		int[] incomingEdges = new int[numCourses];
		List<Integer>[] adjArr = new ArrayList[numCourses];
		Queue<Integer> queue = new LinkedList<>();
		int num = numCourses;
		for (int i = 0; i < numCourses; i++) {
			adjArr[i] = new ArrayList<>();
		}
		for (int[] pre : prerequisites) {
			adjArr[pre[0]].add(pre[1]);
			incomingEdges[pre[1]]++;
		}
		for (int i = 0; i < numCourses; i++) {
			if (incomingEdges[i] == 0)
				queue.add(i);
		}
		while (!queue.isEmpty()) {
			Integer node = queue.poll();
			num--;
			for (Integer ele : adjArr[node]) {
				incomingEdges[ele]--;
				if (incomingEdges[ele] == 0)
					queue.add(ele);
			}
		}
		return num == 0;
	}
}
