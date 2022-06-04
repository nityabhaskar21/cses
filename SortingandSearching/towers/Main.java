package SortingandSearching.towers;
import java.util.*;
import java.util.Map.Entry;
import java.io.*;
 
public class Main {
	public static void main(String[] args) throws IOException {
//		Scanner sc = new Scanner(System.in);
		FastScanner sc = new FastScanner("");
		PrintWriter out = new PrintWriter(System.out);
		
		int n = sc.nextInt();
		TreeMap<Integer, Integer> ms = new TreeMap<Integer, Integer>();
		int ans = 0;
		for(int i = 0; i < n; i++) {
			int current = sc.nextInt();
			if(ms.higherKey(current) == null) {
				if(!ms.containsKey(current)) {
					ms.put(current, 1);
				} else {
					ms.put(current, ms.get(current) + 1);
				}
				ans++;
			} else {
				int key = ms.higherKey(current);
				if(ms.get(key) == 1) {
					ms.remove(key);
				} else {
					ms.put(key, ms.get(key) - 1);
				}
				if(!ms.containsKey(current)) {
					ms.put(current, 1);
				} else {
					ms.put(current, ms.get(current) + 1);
				}
			}
		}
		out.println(ans);
		
		out.close();
	}
	
	public static class Pair<S extends Comparable<S>, T extends Comparable<T>> implements Comparable<Pair<S, T>> {
	    S first;
	    T second;
	    
	    Pair(S f, T s) {
	        first = f;
	        second = s;
	    }
 
	    @Override
	    public int compareTo(Pair<S, T> o) {
	        int t = first.compareTo(o.first);
	        if (t == 0) return second.compareTo(o.second);
	        return t;
	    }
	    
	    @Override
	    public int hashCode() {
	        return (31 + first.hashCode()) * 31 + second.hashCode();
	    }
	    
	    @Override
	    public boolean equals(Object o) {
	        if (!(o instanceof Pair)) return false;
	        if (o == this) return true;
	        Pair p = (Pair) o;
	        return first.equals(p.first) && second.equals(p.second);
	    }
	    
	    @Override
	    public String toString() {
	        return "Pair{" + first + ", " + second + "}";
	    }
	}
	
	static class FastScanner {
		BufferedReader br;
		StringTokenizer st=new StringTokenizer("");
		public FastScanner(String name) throws FileNotFoundException {
			if(name.length() == 0) {
				br=new BufferedReader(new InputStreamReader(System.in));
			} else {
				br=new BufferedReader(new FileReader(name));
			}
		}
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
	
	public static void shuffleArray(int[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
            int tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }
	}
}
