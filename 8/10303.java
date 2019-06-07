import java.math.BigInteger;
import java.util.Scanner;
import java.util.Arrays;

class Solver {
  BigInteger results[] = new BigInteger[1001];

  void initResults() {
    Arrays.fill(results, BigInteger.valueOf(-1));
    results[0] = BigInteger.valueOf(1);
    results[1] = BigInteger.valueOf(1);
  }

  BigInteger solve(int nodec) {
    if(BigInteger.valueOf(-1).compareTo(results[nodec]) != 0) return results[nodec];

    BigInteger result = new BigInteger("0");
    BigInteger r_result, l_result;
    int r, l;

    for(r = nodec - 1, l = 0;l < nodec;r--, l++) {
      r_result = solve(r);
      l_result = solve(l);
      result = result.add(r_result.multiply(l_result));
    }

    return results[nodec] = result;
  }
}

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Solver solver = new Solver();
    solver.initResults();

    while(sc.hasNextInt()) {
      System.out.println(solver.solve(sc.nextInt()));
    }
  }
}

