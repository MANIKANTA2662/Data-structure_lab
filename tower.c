#include <stdio.h>

// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, char from, char to, char aux)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", from, to);
		return;
	}
	towerOfHanoi(n-1, from, aux, to);
	printf("\n Move disk %d from rod %c to rod %c", n, from, to);
	towerOfHanoi(n-1, aux, to, from);
}

int main()
{
	int n = 4; // Number of disks
	towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
	return 0;
}
