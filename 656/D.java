import java.util.*;
import java.io.*;

public class D {
    public static long recur(char s[], int l, int r, char c, int switcher) {
        if (l == r) {
            if (s[l] != c)
                return 1;
            else
                return 0;
        }
        if (switcher == 1) {
            int count = 0, mid = (r + l) / 2;
            for (int i = mid + 1; i <= r; i++) {
                if (s[i] != c)
                    count++;
            }
            return count
                    + Math.min(recur(s, l, mid, (char) ((int) c + 1), 0), recur(s, l, mid, (char) ((int) c + 1), 1));
        } else {
            int count = 0, mid = (r + l) / 2;
            for (int i = l; i <= mid; i++) {
                if (s[i] != c)
                    count++;
            }
            return count + Math.min(recur(s, mid + 1, r, (char) ((int) c + 1), 0),
                    recur(s, mid + 1, r, (char) ((int) c + 1), 1));
        }

    }

    public static void main(String args[]) {
        FastReader sc = new FastReader();
        StringBuilder finalans = new StringBuilder();
        int t, i, n;
        t = sc.nextInt();
        while (t-- > 0) {
            n = sc.nextInt();
            char s[] = sc.next().toCharArray();
            long ans = Math.min(recur(s, 0, n - 1, 'a', 0), recur(s, 0, n - 1, 'a', 1));
            finalans.append(ans).append('\n');
        }
        finalans.deleteCharAt(finalans.length() - 1);
        out.println(finalans);
    }

    static PrintWriter out;

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out, true);
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
