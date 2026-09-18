#include<stdio.h>
#include<stdint.h>

int main(void)
{

	uint32_t entero = 0x12345678;

	unsigned char msbyte = (entero >> 24) & 0xFF;
	unsigned char lsbyte = entero & 0xFF;
	unsigned char byte2 = (entero >> 8) & 0xFF;
	unsigned char byte1 = (entero >> 16) & 0xFF;

	printf("El valor entero es 0X%08X\n", entero);
	printf("MSByte  : 0X%02X\n", msbyte);
	printf("Byte 01 : 0X%02X\n", byte1);
	printf("Byte 02 : 0X%02X\n", byte2);
	printf("LSByte  : 0X%02X\n", lsbyte);

return 0;
}

