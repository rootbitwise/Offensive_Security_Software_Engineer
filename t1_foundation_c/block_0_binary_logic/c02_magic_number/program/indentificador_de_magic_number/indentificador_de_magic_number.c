#include<stdio.h>


int main(void)
{

 	/* 
	 * Analizar los bytes de una fima magic number para verificar que el Magic Number coincide con 
	 * la extension que dice llevar o determinar el tipo de archivo que realmente es.
	*/

	unsigned char bytes[] = {0x7F, 0x45, 0x4C, 0x46};

	if (bytes[0] == 0x7F && bytes[1] == 0x45 && bytes[2] == 0x4C && bytes[3] == 0x46)
	{
		printf("ELF Binario de Linux\n");
	}
	else if (bytes[0] == 0x4D && bytes[1] == 0x5A )
	{
		printf("PE/DOS Ejecutable de Windows\n");
	}
	else if (bytes[0] == 0x89 && bytes[1] == 0x50 && bytes[2] == 0x4E && bytes[3] == 0x47)
	{
		printf("PNG\n");
	}
	else if (bytes[0] == 0x50 && bytes[1] == 0x4B)
	{
		printf("ZIP o jar/apk/docx\n");
	}
	else 
	{
		printf("Es un archivo desconocido");
	}

return 0; 
}

