class KMP 
{
	private void kmp(String s , String pattern)
	{
		int p_len = pattern.length() , s_len = s.length();
		int [] lpas = new int[p_len];//Longest proper prefix that is also suffix

		int i;
		for(i=0;i<p_len;i++)
		{
			int k=0,val=0;
			while(k<i)
			{
				if(pattern.charAt(k)==pattern.charAt(i-k))
					val++;
				else break;
				k++;
			}

			lpas[i] = val;
		}

		int match=0,j=0;

		for(i=0;i<s_len;)
		{
			if(s.charAt(i)==pattern.charAt(j))
			{
				j++;
				match++;
				i++;
			}
			else
			{
				if(match!=0)
				{
					i+=(match - lpas[match - 1])-match;
				}
				else i++;
				j=0;
				match=0;
			}
			if(match==p_len)
			{
				System.out.println("Match found at "+Integer.toString(i-p_len)+" !");
				j=0;
				match=0;
			}
		}
	}

	public static void main(String[] args) 
	{
		String st = new String("aababca");
		KMP obj = new KMP();
		obj.kmp("asdaaababcawetgefaagaababcaasd",st);
	}
}