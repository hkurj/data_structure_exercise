#include <stdio.h>

#define LIST_MEM_SIZE 1024

struct list {
	int len;
	char value[LIST_MEM_SIZE];
};

void initList(struct list *va, int len)
{
	int i = 0;

	if(len > LIST_MEM_SIZE) return;

	for(i = 0; i<len; i++) {
		va->value[i] = i;
	}
	va->len = i;
}

void insertList(struct list *va, char num)
{
	int i = 0;

	if(va->len >= LIST_MEM_SIZE) return;

	for(i = va->len; i > 0 && num < va->value[i-1]; i--) {
		va->value[i] = va->value[i-1];
	}
	va->value[i] = num;
	va->len++;
}

void printList(struct list *va)
{
	if(va->len > LIST_MEM_SIZE) return;

	printf("LIST:");
	for(int i = 0; i < va->len; i++) {
		printf(" %d",va->value[i]);
	}
	printf("\n");
}

char inputAscii2Num(void)
{
	char c = getchar();
	if(c >= '0' && c <= '9') {
		return c - '0';
	} else if (c == 'q' || c == 'Q') {
		return -1;
	}

	return -2;
}

int main(void)
{
	struct list va;
	char value;

	initList(&va,10);
	while(1) {
		printf("\nplease input:");
		value = inputAscii2Num();
		if(value == -1) break;
		if(value == -2) continue;
		insertList(&va, value);
		printList(&va);
	}

	return 0;
}
