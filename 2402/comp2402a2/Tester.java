package comp2402a2;
import java.util.List;


/**
 */
public class Tester {
	public static boolean testPart1(List<Integer> ell) {
		//List<Integer> tr = new ArrayDeque<Integer>(Integer.class);
		int K = 10000;
		Stopwatch s = new Stopwatch();

		//add to back
		s.start();
		for (int i = 0; i < K; i++) {
			ell.add(ell.size(),i);
		}
		s.stop();
		if (s.elapsedSeconds() > 2 || ell.get(ell.size()-1) != 9999) return false;

		//get
		s.start();
		int number = ell.get(50);
		s.stop();
		if(s.elapsedSeconds() > 2 || number != 50) return false;

		//add to front
		s.start();
		for (int i = 0; i < K; i++) {
			ell.add(0, i);
		}
		s.stop();
		if (s.elapsedSeconds() > 2 || ell.get(0) != 9999) return false;

		//add to middle
		s.start();
		for (int i = 0; i < K; i++) {
			ell.add(ell.size()/2, i);
		}
		s.stop();
		if (s.elapsedSeconds() > 2 || ell.size() != 3*K) return false;

		//remove from back
		s.start();
		for (int i = 0; i < K; i++) {
			ell.remove(ell.size()-1);
		}
		s.stop();
		if (s.elapsedSeconds() > 2 || ell.size() != 2*K) return false;

		//remove from front
		s.start();
		for (int i = 0; i < K; i++) {
			ell.remove(0);
		}
		s.stop();
		if (s.elapsedSeconds() > 2 || ell.size() != K) return false;

		//size
		s.start();
		int capacity = ell.size();
		s.stop();
		if(s.elapsedSeconds() > 2 || capacity != K) return false;

		//set
		s.start();
		ell.set(66,33);
		s.stop();
		if (s.elapsedSeconds() > 2 || ell.get(66) != 33) return false;

		//remove from middle
		s.start();
		for (int i = 0; i < K; i++) {
			ell.remove(ell.size()/2);
		}
		s.stop();
		if (s.elapsedSeconds() > 2 || ell.size() != 0) return false;

		s.start();
		ell.add(0,33);
		int x = ell.remove(0);
		s.stop();
		if(s.elapsedSeconds() > 2 || x != 33) return false;


		//correctness testing
		for(int i=0;i<50;i++){
			ell.add(i,i);
		}
		ell.add(4,44);
		ell.add(25,52);
		ell.add(44,4);
		if (ell.get(4)!= 44 || ell.get(25)!=52 || ell.get(44)!=4) return false;

		return true;
	}

	public static boolean testPart2(List<Integer> ell) {
		int K = 10000;
		Stopwatch s = new Stopwatch();
		s.start();
		for (int i = 0; i < K; i++) {
			ell.add(ell.size(),i);
		}
		s.stop();
		if (s.elapsedSeconds() > 2 || ell.get(ell.size()-1) != 9999) return false;

		s.start();
		for (int i = 0; i < K; i++) {
			ell.add(0, i);
		}
		s.stop();
		if (s.elapsedSeconds() > 2 || ell.get(0) != 9999) return false;

		s.start();
		for (int i = 0; i < K; i++) {
			ell.remove(0);
		}
		s.stop();
		if (s.elapsedSeconds() > 2 || ell.size() != K) return false;

		s.start();
		ell.set(66,33);
		s.stop();
		if (s.elapsedSeconds() > 2 || ell.get(66) != 33) return false;

		s.start();
		for (int i = 0; i < K; i++) {
			ell.remove(ell.size()-1);
		}
		s.stop();
		if (s.elapsedSeconds() > 2 || ell.size() != 0) return false;

		return true;
	}

	public static boolean testPart3(AbstractTable<Integer> ell) {
		int nrows = 90, ncols = 60;
		Stopwatch s = new Stopwatch();
		for (int i = 0; i < nrows; i++) {
			ell.addRow(ell.rows());
		}
		if (s.elapsedSeconds() > 2 || ell.rows()!=nrows) return false;

		s.start();
		for (int i = 0; i < ncols; i++) {
			ell.addCol(ell.cols());
		}
		s.stop();
		if (s.elapsedSeconds() > 2 || ell.cols()!=ncols) return false;

		s.start();
		ell.addCol(2);
		s.stop();
		if(s.elapsedSeconds() > 2 || ell.cols()!=ncols+1) return false;
		s.start();
		ell.addRow(3);
		s.stop();
		if(s.elapsedSeconds() > 2 || ell.rows()!=nrows+1) return false;

		s.start();
		ell.removeCol(2);
		s.stop();
		if(s.elapsedSeconds() > 2 || ell.cols()!=ncols) return false;
		s.start();
		ell.removeRow(3);
		s.stop();
		if(s.elapsedSeconds() > 2 || ell.rows()!=nrows) return false;

		s.start();
		ell.set(3,5,99);
		s.stop();
		if(s.elapsedSeconds() > 2 || ell.get(3,5)!=99) return false;

		return true;
	}

}
