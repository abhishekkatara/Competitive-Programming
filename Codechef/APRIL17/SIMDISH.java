import java.util.*;
public class Main
{
	public static void main(String[] args)
	{
		Scanner scan=new Scanner(System.in);
		int T=scan.nextInt();
		// String[] result = new String[T+1];
		for (int i=0;i<T ;i++ )
		{
			String[] dish1 = new String[4];
			String[] dish2 = new String[4];
 
			for (int j=0;j<4 ;j++ )
			{
				dish1[j]=scan.next();
			}
			for (int j=0;j<4 ;j++ )
			{
				dish2[j]=scan.next();
			}
			int count=0;
			for (int j=0;j<4 ;j++ )
			{
				if(count>=2)
					break;
				for (int k=0;k<4 ;k++ )
				{
					if(dish1[j].equals(dish2[k]))
					{
						count++;
						break;
					}

				}
			}

			if(count>=2)
			{
				System.out.println("similar");
			}
			else
			{
				System.out.println("dissimilar");
			}
		}
	}
}

