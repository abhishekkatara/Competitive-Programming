import java.util.*;
class Main
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int L = scan.nextInt();
		int R = scan.nextInt();
		int count = 0;
		int len = R-L+1;
		int[] array = new int[N];
		int[] lengths = new int[len];
	 
		for(int o=0;o<len ;o++)
			lengths[o]=o+L;
		
	 
		for(int i=0;i<N;i++)
		{
			array[i] = scan.nextInt();
		}
		for(int i =0;i<len;i++)
		{
			for(int j=0;j<N-1;j++)
			{
				for(int k=j+1;k<N;k++)
				{
					int a=array[j] + array[k];
					int b=array[j] + lengths[i];
					int c=array[k] + lengths[i];
					if(a>=lengths[i]&&b>=array[k]&&c>=array[j]&&j!=k)
						count++;
	 
				}
			}
		}
		System.out.println(count%13);
	}
}