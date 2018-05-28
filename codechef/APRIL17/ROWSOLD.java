import java.util.*;
	 
public class Main {
	
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		for (int i=0; i<test; i++) {
			String S = scan.nextLine();
			if (S.isEmpty())
			{
				S = scan.nextLine();
			}
			System.out.println(game(S));
		}
	}
	 
private static long game(String str)
{
	int pos=0;
	for (; pos< str.length(); pos++)
		if (str.charAt(pos)=='1')
			break;
		if (pos>=str.length()-1)
			return 0;
		long count1=0;
		int count0=0;
		long time=0;
		for (; pos< str.length(); pos++)
		{
			if (str.charAt(pos)=='1')
			{
				if (count0>0)
				{
					time += count1*(count0+1);
					count0=0;
				}
				count1++;
			}
			else
				count0++;
		}
		if (count0>0)
		{
			time += count1*(count0+1);
		}
		return time;
	}
}
