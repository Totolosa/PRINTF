#include "ft_printf.h"

int main()
{
	int a = -1;
//	unsigned long long b = 18446744073709551615;
	int c = 50;
	char *str1 = "ALLER";
	char *str2 = "le stade";
	char z = '0';
	void *p = &a;

	char *format = "%.*s\n";

	setbuf(stdout, NULL);
	int retmoi = ft_printf(format, 0, 42);
	int retbibli = printf(format, 0, 42);
	printf("retour moi = %d\n", retmoi);
	printf("retour bibli = %d\n", retbibli);
//	printf("Bibli : %.*s\n", 0, 42);
//	printf("Bibli : %0-10.s\n", str1);
	return(0);
}


// A FAIRE
// - check les - si flags 0 (%d, -1)