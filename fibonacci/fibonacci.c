#include <stdio.h>

unsigned long long fibonacci(int);

int main(int argc, char **argv) {
	int n;
	scanf("%d", &n);
	printf("%llu\n", fibonacci(n));
	return 0;
}

unsigned long long fibonacci(int n) {
	unsigned long long f[] = {0, 1}, fn;
	int i = n;
	if (n > 1)
		for (;--n;) {
			fn = f[0] + f[1];
			f[0] = f[1];
			f[1] = fn;
		}
	else 
		return f[n];
	return fn;
}
