import java.util.*;

public class C {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int x, y, n;
		int t, rem, nd, diff, i;
		t = sc.nextInt();
		while (t-- > 0) {
			n = sc.nextInt();
			x = sc.nextInt();
			y = sc.nextInt();
			if (n == 2) {
				System.out.println(x + " " + y);
				continue;
			}
			diff = y - x;
			nd = 0;
			ArrayList<Integer> ans = new ArrayList<>();
			for (i = n - 1; i >= 1; i--) {
				if (diff % i == 0) {
					nd = diff / i;
					break;
				}
			}
			int val = x + nd;
			ans.add(x);
			ans.add(y);
			while (val < y) {
				ans.add(val);
				val += nd;
			}
			rem = n - ans.size();
			val = x - nd;
			while (val >= 1 && rem > 0) {
				ans.add(val);
				rem--;
				val -= nd;
			}
			val = y + nd;
			while (rem > 0) {
				ans.add(val);
				rem--;
				val += nd;
			}
			for (i = 0; i < ans.size(); i++)
				System.out.print(ans.get(i) + " ");
			System.out.println();
		}
	}
}