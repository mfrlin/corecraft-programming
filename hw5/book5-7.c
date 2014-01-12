#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char *p);
void writelines(char *lineptr[], int nlines);
void qsort(char *v[], int left, int right);

int main(void) {
	int nlines;
	char p[MAXLINES * MAXLEN];
	if ((nlines = readlines(lineptr, MAXLINES, p)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

int getline(char *m, int);

int readlines(char *lineptr[], int maxlines, char *p) {
	int len, nlines;
	char line[MAXLEN];

	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0) {
		if (nlines >= maxlines) {
			return -1;
		} else {
			line[len-1] = '\0';
			strcpy(&p[nlines * MAXLEN], line);
			lineptr[nlines++] = &p[nlines * MAXLEN];
		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines) {
	int i;
	for (i = 0; i < nlines; i++) {
		printf("%s\n", lineptr[i]);
	}
}

int getline(char *m, int maxlen) {
	int c, i;
	
	for (i = 0; i < maxlen-1 && (c = getchar()) != EOF && c != '\n'; i++)
		m[i] = c;
	if (c == '\n') {
		m[i] = c;
		++i;
	}
	m[i] = '\0';
	return i;
}

void swap(char *v[], int i, int j);

void qsort(char *v[], int left, int right) {
	int i, last;
	
	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
		swap(v, left, last);
		qsort(v, left, last-1);
		qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
