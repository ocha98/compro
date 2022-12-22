import java.util.*;
import java.math.BigDecimal;

class Main {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        while(scan.hasNext()){
            BigDecimal r = new BigDecimal(scan.next());
            int n = scan.nextInt();
            String ans = r.pow(n).toPlainString();
            System.out.println(ans.replaceAll("^0|0*$|\\.0*$", ""));
        }
    }
}
