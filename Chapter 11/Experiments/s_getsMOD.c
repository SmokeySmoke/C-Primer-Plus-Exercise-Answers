char * s_gets(char * st, int n)
{
	char * ret_val, ps;
	int j, i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)	// i.e., ret_val != NULL
	{
		while (st[i] != '\n' && st[i] && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else if (st[i] == '\b')
			for (j = i; j <= strlen(&st[i]) + 1; j++)
				st[j] = st[j+1];
		else 	// must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
