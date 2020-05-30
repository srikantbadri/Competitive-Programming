class Solution {
    public class UnionFind {
	int[] parent;
	int[] size;
	int count = 0;

	public UnionFind(int n) {
		count = n;
		parent = new int[n];
		size = new int[n];
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

    //return number of disjoint subsets
    int count(){
        return count;
    }    
        
	// find representative of the disjoint group
	int find(int x) {
		while (x != parent[x])
			x = parent[x];
		return x;
	}

	// same - checks whether a and b belongs to same set or not
	boolean same(int a, int b) {
		return find(a) == find(b);
	}

	// always join representative of smaller element to rep. of larger element
	// to maintain a balanced tree - O(logN)
	// unite - joins the sets a & b
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b)
			return;
		if (size[a] < size[b]) {
			size[b] += size[a];
			parent[a] = b;
		} else {
			size[a] += size[b];
			parent[b] = a;
		}
        count-- ;
	}

}
    
    public int findCircleNum(int[][] M) {
        UnionFind uf = new UnionFind(M.length);
        for(int i=0;i<M.length-1;i++){
            for(int j=i+1;j<M.length;j++){
                if(M[i][j]==1)uf.unite(i,j);
            }
        }
        return uf.count();
    }
}