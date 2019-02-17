import java.util.*;
class Main
{
	public static void main(String[] args)
	{
		Scanner scan=new Scanner(System.in);
		int T =scan.nextInt();
		for (int n=0;n<T ;n++ ) {
			int N=scan.nextInt();
			int K=scan.nextInt();
			int[] temp=new int[K+1];
			int count=0;
			int some=0;
			for(int i=0;i<N;i++)
			{
				if(count >= K)
				{
					some=1;
				}
				int X=scan.nextInt();
				for (int j=0;j<X ;j++ )
				{
					int Y=scan.nextInt();
					if(temp[Y]!=1)
					{
						temp[Y]=1;
						count++;
					}
				}
			}
			if(some==1)
			{
				System.out.println("some");
			}
			else if(count>=k)
			{
				System.out.println("all");
			}
			else
			{
				System.out.println("sad");
			}
		}
	}
}
