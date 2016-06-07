
class permutations
{
	String [] p;//A variable to store all permutations

	private void permute(char [] s , int start , int end)
	{
		if(start == end)
			System.out.println(s);
		else
		{
			int i;
			for(i=start;i<end;i++)
			{
				char t = s[start];
				s[start] = s[i];
				s[i]= t;
				
				permute(s,start+1,end);
				
				t = s[start];
				s[start] = s[i];
				s[i] = t;
			}
		}
	}

	public static void main(String[] args)
	{
		String a = "abc";
		permutations pr = new permutations();
		pr.permute(a.toCharArray() , 0,3);
	}
	
}