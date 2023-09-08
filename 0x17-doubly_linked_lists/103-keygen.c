#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * main - This function generates a key depending on a username
 * for crackme5
 * @argc: This counts the number of arguments passed
 * @argv: This is the arguments passed to main
 *
 * Return:  This function returns 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	unsigned int z, a;
	size_t len, add;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char p[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	len = strlen(argv[1]);
	p[0] = l[(len ^ 59) & 63];
	for (z = 0, add = z; z < len; z++)
		add += argv[1][z];
	p[1] = l[(add ^ 79) & 63];
	for (z = 0, a = 1; z < len; z++)
		a *= argv[1][z];
	p[2] = l[(a ^ 85) & 63];
	for (a = argv[1][0], z = 0; z < len; z++)
		if ((char)a <= argv[1][z])
			a = argv[1][z];
	srand(a ^ 14);
	p[3] = l[rand() & 63];
	for (a = 0, z = 0; z < len; z++)
		a += argv[1][z] * argv[1][z];
	p[4] = l[(a ^ 239) & 63];
	for (a = 0, z = 0; (char)z < argv[1][0]; z++)
		a = rand();
	p[5] = l[(a ^ 229) & 63];
	printf("%s\n", p);
	return (0);
}
