import java.util.*;

public class D {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int i, n;
        int t = sc.nextInt();
        while (t-- > 0) {
            char s[] = sc.next().toCharArray();
            int sum = sc.nextInt();
            int a[] = new int[s.length];
            n = s.length;
            int psum = 0;
            for (i = 0; i < n; i++) {
                a[i] = s[i] - '0';
                psum += a[i];
            }
            if (psum <= sum) {
                System.out.println(0);
                continue;
            }
            long ans = 0;
            int flag = 0;
            int carry;
            for (i = n - 1; i >= 0; i--) {
                if (a[i] == 0)
                    continue;
                long diff = 10 - a[i];
                ans += (long) Math.pow(10, n - 1 - i) * diff;
                psum = psum - a[i] + 1;
                if (i != 0)
                    a[i - 1] += 1;
                else
                    carry = 1;
                if (psum <= sum) {
                    flag = 1;
                    break;
                }
            }
            System.out.println(ans);
        }
    }
}