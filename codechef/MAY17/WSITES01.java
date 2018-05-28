import java.util.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;
class WebName
{
	private static int R=26;
	private Node root;
	private static class Node
	{
		String name;
		private Node[] next = new Node[R];
	}
	public void put(String key)
	{
		root = put(root, key, 0);
	}
	
	private Node put(Node x, String k, int d)
	{
		if (x==null)
		{
			x= new Node();
		}
		if ( d==k.length())
		{
			x.name=k;
			return x;
		}
		int n = k.charAt(d)-'a';
		x.next[n] = put(x.next[n], k, d+1);
		return x;
	}
	
	public int prefixMatch(String key)
	{
		return prefixMatch(root, key, 0);
	}
	
	public int prefixMatch(Node x, String key, int d)
	{
		if (d==key.length())
			return d;
		if (x.next[key.charAt(d)-'a']==null)
			return d;
		return prefixMatch(x.next[key.charAt(d)-'a'], key, d+1);
	}
}
	 
class Main
{
	
	static Scanner scan = new Scanner(System.in);
	 
	public static void main(String[] args)
	{
		int N = scan.nextInt();
		WebName web=new WebName();
		List<String> blocked_web = new ArrayList<>();
		for (int i=0; i<N; i++)
		{
			String C = scan.next();
			String site = scan.next();
			if (C.charAt(0)=='+')
			{
				web.put(site);
			}
			else if (C.charAt(0)=='-')
			{
				blocked_web.add(site);
			}
		}
		solve(web, blocked_web);
	}
	public static void solve(WebName web, List<String> blocked_web)
	{
		boolean possible=true;
		Set<String> unique=new TreeSet<>();
		for (int i=0; i<blocked_web.size(); i++) {
			int match = web.prefixMatch(blocked_web.get(i));
			if (match==blocked_web.get(i).length())
			{
				possible=false;
				break;
			} else
			{
				unique.add(blocked_web.get(i).substring(0, match+1));
			}
		}
		if (possible)
		{
			System.out.println(unique.size());
			for (String s:unique)
				System.out.println(s);
		}
		else
		{
			System.out.println(-1);
		}
	}
	
	
}