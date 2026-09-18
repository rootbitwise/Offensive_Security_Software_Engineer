#include <stdio.h>




// Tomar un dato y capturar cada bit para formar un binario de 8 bits imprimible por pantalla

void print_bits(unsigned char byte)
{
	for(int i =7; i >= 0; i--)
	{
		printf("%d", (byte >> i) &1 ); // Mover byte a la posicion de i y capturar el bit
		
		if (i == 4)
		{
			printf(" ");
		}
	}
}


int main(void) 
{

	unsigned char valores[] = {181, 0xFF, 199, 202, 0x00};

	int n = sizeof(valores) / sizeof(valores[0]);
	printf("UN TOTAL DE %d-BYTE\n", n); // Imprimir los byte que tiene el buffer


	for (int i = 0; i < n; i++)
	{
		unsigned char v = valores[i];

		printf("DECIMAL = %3u, HEXADECIMAL = 0x%X, BINARIO = ", v, v);
		print_bits(valores[i]); // Imprimir valores bit por bit hasta formal el binario
		
		printf("\n");
	}

return 0;
}


