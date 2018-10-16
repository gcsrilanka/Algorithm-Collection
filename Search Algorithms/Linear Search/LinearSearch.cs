//Linear Search Algorithm 
public static int LinearSearch(int[] data, int item)
{
 int N=data.Length;
 for (int i=0; i < N; i++)
	if (data[i] == item)
	   return i;
 return -1;
}

//Example 
static void Main(string[] args)
{
Console.WriteLine("Please Enter Some Integer values separate them by using ,");
string EnteredIntegers = Console.ReadLine();
int position = 0;
bool isFound = false;
string[] strIntegers = EnteredIntegers.Split(',');

if (strIntegers.Length <= 0)
{
	Console.WriteLine("Invalid InPut");
	return;
}

Console.WriteLine("Please Enter the Number You Want To Search");

int searchNum = Convert.ToInt32(Console.ReadLine());


	for (int i = 0; i < strIntegers.Length; i++)
	{
		if (Convert.ToInt32(strIntegers[i]).Equals(searchNum))
		{
			position = i;
			isFound = true;
		}
	}

if (isFound)
{
	Console.WriteLine("Your Search Value :" + searchNum.ToString() + " Is at position :" + position.ToString());
}
else
{
	Console.WriteLine("No Items Match Your Selection");
}

Console.ReadLine();
}