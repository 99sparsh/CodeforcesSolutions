import java.util.*;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            int n = sc.nextInt();
            String st = sc.next();
            String st2 = sc.next();
            int a[] = new int[n];
            int b[] = new int[n];
            int i;
            for (i = 0; i < n; i++) {
                a[i] = st.charAt(i) - '0';
                b[i] = st2.charAt(i) - '0';
            }
            StringBuilder ans = new StringBuilder();
            int count = 0;
            int x = n - 1, temp, j;
            for (x = n - 1; x >= 1; x--) {
                if (a[0] == b[x]) {
                    count++;
                    ans.append(1).append(' ');
                    a[0] = a[0] ^ 1;
                    count++;
                    ans.append(x + 1).append(' ');
                    int lim = x / 2;
                    if (x % 2 == 0)
                        lim = (x - 1) / 2;
                    for (j = 0; j <= lim; j++) {
                        a[j] = a[j] ^ 1;
                        a[x - j] = a[x - j] ^ 1;
                        temp = a[j];
                        a[j] = a[x - j];
                        a[x - j] = temp;
                    }
                    if (x % 2 == 0)
                        a[x / 2] = a[x / 2] ^ 1;
                } else {
                    count++;
                    ans.append(x + 1).append(' ');
                    int lim = x / 2;
                    if (x % 2 == 0)
                        lim = (x - 1) / 2;
                    for (j = 0; j <= lim; j++) {
                        a[j] = a[j] ^ 1;
                        a[x - j] = a[x - j] ^ 1;
                        temp = a[j];
                        a[j] = a[x - j];
                        a[x - j] = temp;
                    }
                    if (x % 2 == 0)
                        a[x / 2] = a[x / 2] ^ 1;
                }
            }
            if (a[0] != b[0]) {
                count++;
                a[0] = a[0] ^ 1;
                ans.append(1).append(' ');
            }
            ans.deleteCharAt(ans.length() - 1);
            sb.append(count).append(' ').append(ans).append('\n');
        }
        System.out.println(sb);
    }
}