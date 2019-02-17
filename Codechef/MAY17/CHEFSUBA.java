import java.util.*;
public class chefsuba
{
	public static void main(string[] args)
	{
		scanner scan = new scanner(system.in);
		long n = scan.nextlong();
		long k = scan.nextlong();
		long p = scan.nextlong();
		if(k>n)
			k=n;
		long [] arr = new long[(int)n];
		for(int i=0;i<n;i++)
		{
			arr[i]=scan.nextint();
		}
		string s = scan.next();
		for(int j=0;j<p;j++)
		{
			if(s.charat(j)=='?')
			{
				long result = returnwindowmax(arr,k,n);
				system.out.println(result);
			}
			else
			{
				arr=shift(arr,1,n);
	/*for(int k=0;k<n;k++)
	{
	system.out.print(arr[k]);
	}
	system.out.println();*/
}
}
}
public static long[] shift(long[] data, long k, long n) {
	if (data==null||k<0)
	{
		throw new illegalargumentexception("array is empty or window size is less than zero");
	}
	k = k%n;
	long new_data[] = new long[(int)n];
	for(int i=0;i<n;i++)
	{
		new_data[((int)k+i)%(int)n] = data[i];
	}
	return new_data;
}

public static long returnwindowmax(long data[], long k, long n) {
	long max = integer.min_value ;
	for (int i = 0; i<n-k+1;i++) {
		long m=0;
		for (int j=0;j<k;j++)
		{
			m+=data[i+j];
		}
		max= math.max(m,max);
	}
	return max;
}

}