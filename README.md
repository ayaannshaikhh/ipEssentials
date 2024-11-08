# IP Essentials

This project provides functions to perform various tasks with an IP address in C. The main functionalities include reading an IP address, converting it to a decimal format, and classifying it by IP class.

## Features

1. **Reading an IP Address**  
   Prompts the user to input each octet of the IP address, ensuring valid ranges:
   - Octet 1: 0-127
   - Octet 2, 3, 4: 0-255

2. **Converting IP Address to Decimal**  
   Converts the IP address to a long integer representation. This involves:
   - Breaking down the IP into octets.
   - Converting each octet into binary.
   - Combining the binary values and converting them to a single decimal number.

3. **Classifying IP Address by Class**  
   Determines the IP class (A, B, C, D, or E) based on the second octet of the IP address.

## Usage

### Compilation

To compile the program, use the following commands:

```bash
gcc -std=c99 -Wall functions.c main.c -o ipEssentials
./ipEssentials
```

### Example Usage

1. **Reading an IP Address**  
   When prompted, enter each octet within the specified range.

   ```plaintext
   Octet#1 - Enter a number - must be between 0 and 127: 192
   Octet#2 - Enter a number - must be between 0 and 255: 168
   Octet#3 - Enter a number - must be between 0 and 255: 1
   Octet#4 - Enter a number - must be between 0 and 255: 10
   ```

   Output:
   ```plaintext
   IP Addr: 192.168.1.10
   ```

2. **Converting IP to Decimal**  
   After reading the IP, the program will convert it to a decimal number and display the number of digits.

   ```plaintext
   ipDecimal = 3232235770
   Number of digits = 10
   ```

3. **Classifying the IP Address**  
   The program will determine and display the IP class. Note that it uses the second octet to classify rather than the first.

   ```plaintext
   Class for 192.168.1.10 = C
   ```

## Functions Overview

- **readIPAddress**: Reads and validates the IP address from user input.
- **convertIPToLongNumber**: Converts the IP address to a long integer.
- **classifyIPAddress**: Classifies the IP address by class based on the second octet.
- **Helper Functions**:
  - `countDig`: Counts the number of digits in a number.
  - `convertToBinary`: Converts an octet to binary.
  - `combineAllOctets`: Combines binary values of each octet.
  - `convertBinaryToDecimal`: Converts binary to a decimal integer.

## License
This project is developed as part of an academic assignment and is intended for educational purposes.