#include <stdio.h>



/* 
  * En un header IPv4 en si byte fuese 0x45 que quedaria en alto y en bajo??
  * la variable alto quedaria 4 y en la variable bajo quedaria con el valor 5
*/




void print_bits(unsigned char b)
{
	for (int i = 7; i >= 0; i--)
	{
		printf("%d", (b >> i)&1); 
		if ( i == 4)
		{
			printf(" ");
		}
	}
}


int main(void)
{
	unsigned char byte = 0xAF;

	// Capturar los nibble altos
	
	unsigned char alto = (byte >> 4) & 0x0F;

	// Capturar los nibble bajos
	
	unsigned char bajo = 0x0F & byte;

	printf("Byte 0x%02X = ",byte); print_bits(byte); printf("\n");
	printf("Alto 0x%02X = ",alto); print_bits(alto); printf("\n");
	printf("Bajo 0x%02X = ",bajo); print_bits(bajo); printf("\n");

	
	
return 0;
}
