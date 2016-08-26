public class fib
{

	private static int calFib(int number)
	{
		if( number ==0 || number ==1)
			return 1;
		else
			return calFib(number-1) + calFib(number-2);
	}

	public static void main(String[] args)
	{
		if(args.length !=1)
		{
			System.out.println("usage: fib range");
			System.exit(-1);
		}

		System.out.println(calFib(Integer.parseInt(args[0])));

	}
}