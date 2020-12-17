#include "ft_printf.h"

int main()
{
	int a = 20;
	int b = -50;
	int c = -1;
	char *str1 = "ALLER";
	char *str2 = "le stade";
	char z = '0';
	void *p = &a;

	char *format = "%*d\n";

	setbuf(stdout, NULL);
	int retmoi = ft_printf(format, a, b);
	int retbibli = printf(format, a, b);
	printf("retour moi = %d\n", retmoi);
	printf("retour bibli = %d\n", retbibli);
	printf("Bibli : %-*p\n", 10, p);
//	printf("Bibli : %0-10.s\n", str1);
	return(0);
}


// A FAIRE
// - check les - si flags 0 (%d, -1)