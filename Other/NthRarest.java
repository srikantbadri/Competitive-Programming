import java.text.ParseException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map.Entry;
import java.util.Set;

public class Demo{
	public static void main(String args[]) throws ParseException {
		int arr[] = new int[] { 5, 4, 3, 2, 1, 5, 4, 3, 2, 5, 4, 3, 5, 4, 5 };
		System.out.println(findNthRarestElement(arr, 2));
	}

	public static int findNthRarestElement(int arr[], int n) {

		HashMap<Integer, Integer> codenames = new HashMap<Integer, Integer>();

		for (int ele : arr) {
			if (codenames.get(ele) != null)
				codenames.put(ele, codenames.get(ele) + 1);
			else
				codenames.put(ele, 1);
		}

		Comparator<Entry<Integer, Integer>> valueComparator = new Comparator<Entry<Integer, Integer>>() {
			@Override
			public int compare(Entry<Integer, Integer> e1, Entry<Integer, Integer> e2) {
				int v1 = e1.getValue();
				int v2 = e2.getValue();
				return v1 - v2;
			}
		};

		Set<Entry<Integer, Integer>> entries = codenames.entrySet();
		// Sort method needs a List, so let's first convert Set to List in Java
		List<Entry<Integer, Integer>> listOfEntries = new ArrayList<Entry<Integer, Integer>>(entries);

		// sorting HashMap by values using comparator
		Collections.sort(listOfEntries, valueComparator);

		int counter = 0;
		for (Entry<Integer, Integer> entry : listOfEntries) {
			// System.out.println(entry.getKey() + ":" + entry.getValue());
			counter++;
			if (counter == n)
				return entry.getKey();
			// sortedByValue.put(entry.getKey(), entry.getValue());
		}
		return -1;

	}

}
