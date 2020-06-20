import java.util.HashSet;
import java.util.Set;

//Leet Code Problem - https://leetcode.com/problems/longest-duplicate-substring/
public class Solution {
	int prime = 23;

	// Using binary search + rabin karp algorithm
	public String longestDupSubstring(String S) {
		int start = 1;
		int end = S.length();
		String dup = "";
		String ans = "";
		while (start <= end) {
			int mid = start + (end - start) / 2;
			dup = getDuplicate(S, mid);
			if (dup != null) {
				// probably there must be duplicate of more length
				// lets find that
				ans = dup;
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}
		return ans;
	}

	private String getDuplicate(String s, int size) {
		long hash = getHash(s.substring(0, size), size);
		Set<Long> hashSet = new HashSet<>();
		hashSet.add(hash);
		for (int i = 1; i < s.length() - size + 1; i++) {
			hash = (long) ((hash - (s.charAt(i - 1) - 'a' + 1)) / prime
					+ (s.charAt(i + size - 1) - 'a' + 1) * Math.pow(prime, size - 1));
			if (!hashSet.add(hash)) {
				return s.substring(i, i + size);
			}
		}
		return null;
	}

	private long getHash(String substring, int size) {
		long hash = 0;
		int primePow = 1;
		for (int i = 0; i < size; i++) {
			hash += (substring.charAt(i) - 'a' + 1) * primePow;
			primePow *= prime;
		}
		return hash;
	}

	public static void main(String args[]) {
		Solution solution = new Solution();
		System.out.println(solution.longestDupSubstring("banana"));
	}

}
