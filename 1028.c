//C is the fastest
//The template of C++ result in overtime

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define scanf_s scanf

struct StuNode {
	char id[7], name[9];
	int g;
};

typedef struct StuNode Stu;

Stu l[100000];	

int sort1(const void *s1, const void *s2) {
	return strcmp(((Stu *)s1)->id, ((Stu *)s2)->id);
}

int sort2(const void *s1, const void *s2) {
	if (strcmp(((Stu *)s1)->name, ((Stu *)s2)->name) != 0)
		return strcmp(((Stu *)s1)->name, ((Stu *)s2)->name);
	else
		return sort1(s1, s2);
}

int sort3(const void *s1, const void *s2) {
	if (((Stu *)s1)->g != ((Stu *)s2)->g)
		return ((Stu *)s1)->g - ((Stu *)s2)->g;
	else
		return sort1(s1, s2);
}

int main() {
	int c;
	unsigned int n, i;
	scanf("%d", &n);
	scanf("%d", &c);
	for (i = 0; i < n; i++) {
		scanf("%s", l[i].id);
		scanf("%s", l[i].name);
		scanf("%d", &l[i].g);
	}
	size_t s = sizeof(Stu);
	if (c == 1)
		qsort(l, n, s, sort1);
	else if (c == 2)
		qsort(l, n, s, sort2);
	else
		qsort(l, n, s, sort3);
	for (i = 0; i < n; i++) {
		printf("%s %s %d\n", l[i].id, l[i].name, l[i].g);
	}
	return 0;
}
