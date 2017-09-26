package comp2402a1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.Map;
import java.util.HashMap;
import java.util.TreeMap;

public class Part8 {

	/**
	 * Your code goes here - see Part0 for an example
	 * @param r the reader to read from
	 * @param w the writer to write to
	 * @throws IOException
	 */

	public static void doIt(BufferedReader r, PrintWriter w) throws IOException {
		// Your code goes here - see Part0 for an example
		Map<String,Integer> map= new TreeMap<String, Integer>(
		Collections.sort(map, new Comparator<Integer>(){
			public int compare(String s1, String s2){
				if(!map.get(s2)==map.get(s1)){
					return !map.get(s2)-map.get(s1);
				}
				else{
					return s1.compareTo(s2);
				}
			}
		});
		);

		for (String line = r.readLine(); line != null; line = r.readLine()) {
				Integer freq = map.get(line);
				if(freq == null){
					map.put(line,1);
				}
				else{
					map.put(line, freq+1);
				}
		}

		for (String line : map.keySet()){
				w.println(line);
		}
	}

	/**
	 * The driver.  Open a BufferedReader and a PrintWriter, either from System.in
	 * and System.out or from filenames specified on the command line, then call doIt.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BufferedReader r;
			PrintWriter w;
			if (args.length == 0) {
				r = new BufferedReader(new InputStreamReader(System.in));
				w = new PrintWriter(System.out);
			} else if (args.length == 1) {
				r = new BufferedReader(new FileReader(args[0]));
				w = new PrintWriter(System.out);
			} else {
				r = new BufferedReader(new FileReader(args[0]));
				w = new PrintWriter(new FileWriter(args[1]));
			}
			long start = System.nanoTime();
			doIt(r, w);
			w.flush();
			long stop = System.nanoTime();
			System.out.println("Execution time: " + 10e-9 * (stop-start));
		} catch (IOException e) {
			System.err.println(e);
			System.exit(-1);
		}
	}
}
