#include <stdio.h>
#include <ctype.h>
#define SIZE 10

int getch(void);
void ungetch(int);
double getfloat(double *);

int main(void)
{
	int n;
	double array[SIZE];
	for (n = 0; n < SIZE &&  getfloat(&array[n]) != EOF; n++)
		;
	for (n; n >= 0; n--) 
	{
		printf("%f\n", array[n]);
	}
	return 0;
}

double getfloat(double *pn) 
{
	int c, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		int temp = c;
		c = getch();
		if (!isdigit(c) || c != '.')
		{
			ungetch(c);
			ungetch(temp);
		}
	}
	int point = 0;
	int divide = 1.0;
	for (*pn = 0; isdigit(c) || c == '.'; c = getch())
	{	
		if (point)
		{	
			if (c == '.') 
			{	
				break;
			}
			divide *= 10;
		}
		if (c == '.') 
		{
			point = 1;
		}
		else
		{
			*pn = 10 * *pn + (c - '0');
		}
	}
	*pn /= divide;
	*pn *= sign;
	if (c != EOF)
	{
		ungetch(c);
	}
	return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE) 
	{
		printf("ungetch: too many characters\n");
	}
	else 
	{
		buf[bufp++] = c;
	}
}
