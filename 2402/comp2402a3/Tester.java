package comp2402a3;

import java.util.Random;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class Tester {

  // Handy for testing correctness now that we know A2Table works
  public static <T> boolean tableEquals(Table<T> t1, Table<T> t2) {
    if (t1.rows() != t2.rows()) return false;
    if (t1.cols() != t2.cols()) return false;
    for (int i = 0; i < t1.rows(); i++) {
      for (int j = 0; j < t2.cols(); j++) {
        T x1 = t1.get(i, j);
        T x2 = t2.get(i, j);
        if (x1 != null && x2 == null) return false;
        if (x1 == null && x2 != null) return false;
        if (x1 != null && !x1.equals(x2)) return false;
      }
    }
    return true;
  }


  public static boolean testPart1(Table<Integer> t) {
    // put your testing code here
    for (int i=0; i<20; i++) t.addRow(i);
    for (int i=0; i<15; i++) t.addCol(i);
    if (t.rows() != 20) return false;
    if (t.cols() != 15) return false;

    t.set(4, 6, 33);

    if (t.get(4,6) != 33) return false;

    t.removeRow(3);
    t.removeCol(5);

    if (t.rows() != 19) return false;
    if (t.cols() != 14) return false;

    t.removeRow(3);
    t.removeCol(5);

    if (t.get(3, 5) != null || t.get(4,6) != null) return false;

    return true;
  }

  public static void testTable(Table<Integer> tab) {
    long start = System.nanoTime();
    boolean result = Tester.testPart1(tab);
    long stop = System.nanoTime();
    double elapsed = (stop-start)/1e9;
    System.out.println("testPart1 returns " + result + " in " + elapsed + "s"
                       + " when testing a " + tab.getClass().getName());
  }


  public static boolean testPart2(List<Integer> ell) {
    // put your testing code here
    ell.add(4,7);
    ell.add(7,2);
    if (ell.get(7) != 2) return false;
    if (ell.set(4,9) != 7) return false;
    if (ell.get(3) != null) return false;
    ell.remove(3);
    if (ell.get(3) != 9) return false;

    else return true;
  }

  public static void testDefaultList(List<Integer> ell) {
    long start = System.nanoTime();
    boolean result = Tester.testPart2(ell);
    long stop = System.nanoTime();
    double elapsed = (stop-start)/1e9;
    System.out.println("testPart1 returns " + result + " in " + elapsed + "s"
                       + " when testing a " + ell.getClass().getName());
  }

}
