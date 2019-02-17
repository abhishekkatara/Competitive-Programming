import java.util.*;
import java.lang.Math;
class Main
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int M = scan.nextInt();
		int[] A = new int[N];
		for(int i=0;i<N;i++)
			{ int test = scan.nextInt();
	//if(test<1&&test>3)
				
	//{
				A[i] = test;
	//}
				
				
				
			}
	 
			if(N>=1 && N<=1000 && M>=1 && M<=10)
			{
				for(int j=0;j<M;j++)
				{
					int L = scan.nextInt();
					int R = scan.nextInt();
					int k = scan.nextInt();
					int q=(int) Math.floor((R-L+1)/2);
	 
	 
					int count = 1, tempCount=0;
					int popular = A[L];
					int temp = 0;
					for (int i = L; i < R-1; i++)
					{
						temp = A[i];
						tempCount = 0;
						int l= L+1;
						if (temp == A[l])
							tempCount++;
						
						if (tempCount > count)
						{
							popular = temp;
							count = tempCount;
						}
					}
	if(q < k && k <= (R-L+1) )//&& tempCount >= k)
	{
		System.out.println(popular);
	}
	else if(q >= k || k > (R-L+1) && popular < k)
	{
		System.out.println(-1);
	}
}
}
}
}