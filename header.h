#include <stdio.h>
#include <string.h>

#define MAX 16

void readIPAddress (char ipAddress []);

long int convertIPToLongNumber ( char ipAddress [], int lengthIPAddr, int * numDigits);

char classifyIPAddress (char ipAddress []);

int countDig (int);
void convertToBinary (int octet, int octetBinary [8]);
void combineAllOctets (int octetBinary[8], int pos, int binaryAllOctets [32]);
long int convertBinaryToDecimal (int binaryAllOctets [32]);

