/************************shaikhAyaanA2Main.c**************
Student Name: Ayaan Shaikh         Email Id: ashaikh26
Due Date: November 8th, 2024       Course Name: CIS*1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity. 2) I
have completed the Computing with Integrity Tutorial on Moodle; and 3) I have
achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.
********************************************************/

/**********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc -std=c99 -Wall shaikhAyaanA2.c shaikhAyaanA2Main.c
Running: ./a.out
OR
gcc -std=c99 -Wall shaikhAyaanA2.c shaikhAyaanA2Main.c -o assn2
Running the Program: ./assn2
*********************************************************/

/*
Citations
sscanf() was used with help of this website:
https://www.tutorialspoint.com/c_standard_library/c_function_sscanf.htm

sprintf() was used with help of this website:
https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm
*/

#include <stdio.h>
#include <string.h>
#include "givenA2.h"

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