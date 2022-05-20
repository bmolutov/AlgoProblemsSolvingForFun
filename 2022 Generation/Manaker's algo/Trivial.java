// not completed yet

public class Trivial {
    public static void main(String[] args) {
    
    } 
    public static int trivialManaker(String s) {
        int n = s.length();

        int[] d1 = new int[n];
        int[] d2 = new int[n];

        int mx = 0;

        for(int i = 0; i < n; i++) {
            d1[i] = 1;
            while(i-d1[i] >= 0 && i+d1[i] < n && s.charAt(i-d1[i]) == s.charAt(i+d1[i])) {
                ++d1[i];
                mx = Math.max(mx, d1[i]);
            }
            d2[i] = 0;
            while(i-d2[i]-1 >= 0 && i+d2[i] < n && s.charAt(i-d2[i]-1) == s.charAt(i+d2[i])) {
                ++d2[i];
                mx = Math.max(mx, d2[i]);
            }
        }
        if(n % 2 == 0) {
            return mx * 2;
        } else {
            return mx * 2 - 1;
        }
    }
}
