#include <stdio.h>
#include <string.h>
#include "header.h"

int main() {
    int numDigits;
    long int ipDecimal;
    char ipAddress[MAX];
    char classificationIP;
    
    // Runs the readIPAddress function and performs task 1
    readIPAddress(ipAddress);
    printf("IP Addr: %s\n\nTask 1 ends\n", ipAddress);

    // Runs the convertIPToLongNumber function and performs task 2
    ipDecimal = convertIPToLongNumber(ipAddress, 4, &numDigits);
    printf("\nTesting Task 2 in main");
    printf("\n\nipDecimal = %ld\n", ipDecimal); // Prints the long number
    printf("Number of digits = %d\n", numDigits); // Prints the number of digits in the long number
    printf("Task 2 ends\n");

    // Runs the classifyIPAddress function and performs task 3
    classificationIP = classifyIPAddress(ipAddress);
    printf("\nTesting Task 3 in main\n\n");
    printf("Class for %s = %c\n", ipAddress, classificationIP); // Prints the class
    printf("Task 3 ends\n\n");

    return 0;
}
