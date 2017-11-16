package comp2402a3;

import java.util.List;
import java.util.ArrayList;
import java.util.Random;
import java.util.Collections;

/**
 *  This is just a copy of A2Table, your job is to make it faster
 */
public class FasterTable<T> implements Table<T> {
	List<List<T>> tab;
	ArrayList<Integer> index;

	int nrows, ncols;

	public FasterTable(Class<T> t) {
		nrows = 0;
		ncols = 0;
		tab = new ArrayList<List<T>>();
		index = new ArrayList<Integer>();
	}

	public int rows() {
		return nrows;
	}

	public int cols() {
		return ncols;
	}

	public T get(int i, int j) {
		if (i < 0 || i > rows() - 1 || j < 0 || j > cols()-1)
			throw new IndexOutOfBoundsException();
		return tab.get(i).get(index.get(j));
	}

	public T set(int i, int j, T x) {
		if (i < 0 || i > rows() - 1 || j < 0 || j > cols()-1)
			throw new IndexOutOfBoundsException();
		return tab.get(i).set(index.get(j), x);
	}

	public void addRow(int i) {
		if (i < 0 || i > rows()) throw new IndexOutOfBoundsException();
		nrows++;
		List<T> row = new ArrayList<T>();
		for (int j = 0; j < cols(); j++) row.add(null);
		tab.add(i, row);
	}

	public void removeRow(int i) {
		if (i < 0 || i > rows() - 1) throw new IndexOutOfBoundsException();
		nrows--;
		tab.remove(i);
	}

	public void addCol(int j) {
        // this method is too slow!
		if (j < 0 || j > cols()) throw new IndexOutOfBoundsException();
		ncols++;
        // this loop takes O( rows*(cols()-j) ) time
		for (int i = 0; i < rows(); i++)
			tab.get(i).add(null);
			index.add(j,cols()-1);
	}

	public void removeCol(int j) {
        // this method is too slow!
		if (j < 0 || j > cols() - 1) throw new IndexOutOfBoundsException();
		ncols--;
        // this loop takes O( rows*(cols()-j) ) time
		for (int i = 0; i < rows(); i++)
			tab.get(i).set(j,null);
			index.remove(j);
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < rows(); i++) {
			for (int j = 0; j < cols(); j++) {
				sb.append(String.valueOf(get(i, j)));
				sb.append(" ");
			}
			sb.append("\n");
		}
		return sb.toString();
	}

	public static void main(String[] args) {
		Tester.testTable(new FasterTable<Integer>(Integer.class));
	}
}
