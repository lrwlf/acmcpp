import java.math.*;
import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        BigInteger s = new BigInteger("0");
        BigInteger singel = new BigInteger("0");
        int x, n = 0;
        x = scan.nextInt();
        while(true)
        {
        	n++;        
            singel = singel.multiply(BigInteger.TEN);
            singel = singel.add(BigInteger.ONE);
            if(singel.remainder(BigInteger.valueOf(x)).equals(BigInteger.ZERO))
            {
            	break;
            }
        }
        System.out.print(singel.divide(BigInteger.valueOf(x))+" "+n);

    }
}