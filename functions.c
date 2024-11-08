#include <stdio.h>
#include <string.h>
#include "header.h"

// Task 1
void readIPAddress (char ipAddress []) {
int octet1, octet2, octet3, octet4;
do {
    printf("Octet#1 - Enter a number - must be between 0 and 127: ");
    scanf("%d", &octet1);
} while (octet1 < 0 || octet1 > 127);

do {
    printf("Octet#2 - Enter a number - must be between 0 and 255: ");
    scanf("%d", &octet2);
} while (octet2 < 0 || octet2 > 255);

do {
    printf("Octet#3 - Enter a number - must be between 0 and 255: ");
    scanf("%d", &octet3);
} while (octet3 < 0 || octet3 > 255);

do {
    printf("Octet#4 - Enter a number - must be between 0 and 255: ");
    scanf("%d", &octet4);
} while (octet4 < 0 || octet4 > 255);

/*
Stores the octet values in char ipAddress[] using sprintf()
Dots added in sprintf() to account for . in IP address format i.e. 192.168.2.1
*/
sprintf(ipAddress, "%d.%d.%d.%d", octet1, octet2, octet3, octet4);
}

// Task 2
long int convertIPToLongNumber (char ipAddress[], int lengthIPAddr, int *numDigits) {
int octet1, octet2, octet3, octet4;
int octetBinary[8];
int binaryAllOctets[32]; // Amount of space required to combine all binary numbers of each octet

/*
Using sscanf() to store octet values when entered initially to easily access
Dots added in sscanf() to account for . in IP address format i.e. 192.168.2.1
*/
sscanf(ipAddress, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

// 0, 8, 16, and 24 represent the starting point of each new binary number
// Indicated as the position "pos"
    convertToBinary(octet1, octetBinary);
    combineAllOctets(octetBinary, 0, binaryAllOctets); // octet1 binary takes positions 0 - 7

    convertToBinary(octet2, octetBinary);
    combineAllOctets(octetBinary, 8, binaryAllOctets); // octet1 binary takes positions 8 - 15

    convertToBinary(octet3, octetBinary);
    combineAllOctets(octetBinary, 16, binaryAllOctets); // octet1 binary takes positions 16 - 23

    convertToBinary(octet4, octetBinary);
    combineAllOctets(octetBinary, 24, binaryAllOctets); // octet1 binary takes positions 24 - 31

    long int ipDecimal = convertBinaryToDecimal(binaryAllOctets);
    *numDigits = countDig(ipDecimal);

    return ipDecimal;
}

/* HELPER FUNCTIONS DEFINITION BELOW */

// Divides by 10 until the value is 0 and counts number of iterations as the number of digits in the octet
int countDig(int num) {
int count = 0;
do {
    count++;
    num = num / 10;
} while (num > 0);

return count;
}

// Starts at 7 and decrements until 0 to go from least to most significant bit (octet has 8 bits)
void convertToBinary(int octet, int octetBinary[8]) {
int i;
for (i = 7; i >= 0; i--) {
    octetBinary[i] = octet % 2;
    octet = octet / 2;
}
}

// Combines all octets into binaryAllOctets by taking the position number and adding it to i to keep moving spaces
void combineAllOctets (int octetBinary[8], int pos, int binaryAllOctets [32]) {
for (int i = 0; i < 8; i++) {
    binaryAllOctets[pos + i] = octetBinary[i];
}
}

// Convers binary to decimal by multiplying binaryNumber by 2 (binary is 2) and adding the number it is at in the binaryAllOctets array
long int convertBinaryToDecimal (int binaryAllOctets [32]) { 
long int binaryNumber = 0;
for (int i = 0; i < 32; i++) {
    binaryNumber = binaryNumber * 2 + binaryAllOctets[i];
}
    return binaryNumber;
}

char classifyIPAddress (char ipAddress []) {
char classificationIP;
int octet1, octet2, octet3, octet4;

/*
Using sscanf() to store octet values when entered initially to easily access
Dots added in sscanf() to account for . in IP address format i.e. 192.168.2.1
*/
sscanf(ipAddress, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

/*
If else statement to go through each range and seeing where the second octet lies
and assigning it a character from A to E and returns the letter
*/
if (octet2 <= 126) {
    classificationIP = 'A';
} else if (octet2 >= 128 && octet2 <= 191) {
    classificationIP = 'B';
} else if (octet2 >= 192 && octet2 <= 223) {
    classificationIP = 'C';
} else if (octet2 >= 224 && octet2 <= 239) {
    classificationIP = 'D';
} else if (octet2 >= 240 && octet2 <= 255) {
    classificationIP = 'E';
}

return classificationIP;

}