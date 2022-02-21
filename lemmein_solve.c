#include <stdio.h>
#include <string.h>

// https://android.googlesource.com/kernel/lk/+/qcom-dima-8x74-fixes/lib/libc/string/strrev.c
void strrev(unsigned char *str) {
	int i;
	int j;
	unsigned char a;
	unsigned len = strlen((const char *)str);
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
	}
}

void unroll(char *text) {
	strrev(text);
}

void unswoop(char *text) {
	for (int i=0; i<strlen(text); i++) {
		text[i] -= (i % 5);
	}
}

int main() {
	char password[256];
	printf("Enter the encrypted password: ");
	scanf("%256s%*c", password);
	unswoop(password);
	unroll(password);
        puts(password);
}
