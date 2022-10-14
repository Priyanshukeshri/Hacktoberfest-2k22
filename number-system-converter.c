#include <stdio.h>
#include <math.h>
#include <string.h>

//! Functions
int decimalToBinary(int deciNum);
int binaryToDecimal(long long biNum);
int decimalToOctal(int deciNum);
int binaryToHexadecimal(long int binNum);
int octalToDecimal(long int octValue);
int hexadecimalToDecimal();

int main()
{
    int opt1, opt2;
    char options[][30] = {"Decimal", "Binary", "Octal", "Hexadecimal"};

    printf("\n\n\nWelcome to Expert Converter\n\n");
    printf("What you want to convert : \n \t(1) %s\n \t(2) %s\n \t(3) %s\n \t(4) %s :", options[0], options[1], options[2], options[3]);
    scanf("%d", &opt1);

    printf("What you want to convert to : \n \t(1) %s\n \t(2) %s\n \t(3) %s\n \t(4) %s :", options[0], options[1], options[2], options[3]);
    scanf("%d", &opt2);

    if (opt1 == opt2)
    {
        printf("%s to %s the value will be same", options[opt1 - 1], options[opt2 - 1]);
    }
    else
    {
        //? DECIMAL TO BINARY
        if (opt1 == 1 && opt2 == 2)
        {
            int number, result;
            printf("Enter your Decimal Number : ");
            scanf("%d", &number);
            printf("The binary value of %d is : ", number);
            decimalToBinary(number);
        }
        //? DECIMAL TO OCTAL
        else if (opt1 == 1 && opt2 == 3)
        {
            int deciNum;
            printf("Enter your decimal value : ");
            scanf("%d", &deciNum);
            printf("Your octal value is : ");
            decimalToOctal(deciNum);
        }
        //? DECIMAL TO HEXADECIMAL
        else if (opt1 == 1 && opt2 == 4)
        {
            int deciNum;
            printf("Enter your deicmal value : ");
            scanf("%d", &deciNum);
            printf("Your hexadecimal value is : %lX", deciNum);
        }
        //? BINARY TO DECIMAL
        else if (opt1 == 2 && opt2 == 1)
        {
            long long num;
            printf("Enter the binary number : ");
            scanf("%lld", &num);
            int deciNumber = binaryToDecimal(num);
            printf("Your decimal value is : %d", deciNumber);
        }
        //? BINARY TO OCTAL
        else if (opt1 == 2 && opt2 == 3)
        {
            long long binaryNum;
            printf("Enter your binary number : ");
            scanf("%lld", &binaryNum);
            int decimalValue = binaryToDecimal(binaryNum);
            printf("The octal value is : ");
            decimalToOctal(decimalValue);
        }
        //? BINARY TO HEXADECIMAL
        else if (opt1 == 2 && opt2 == 4)
        {
            long int binaryval;
            printf("Enter the binary number: ");
            scanf("%ld", &binaryval);
            binaryToHexadecimal(binaryval);
        }
        //? OCTAL TO DECIMAL
        else if (opt1 == 3 && opt2 == 1)
        {
            unsigned int octalValue;
            printf("Enter the octal value : ");
            scanf("%o", octalValue);
            printf("Your decimal value is %d", octalValue);
        }
        //? OCTAL TO BINARY
        else if (opt1 == 3 && opt2 == 2)
        {
            long int octal, decimalValue;
            int i = 0;

            printf("Enter any octal number: ");
            scanf("%ld", &octal);
            decimalValue = octalToDecimal(octal);
            printf("The binary value is : ");
            decimalToBinary(decimalValue);
        }
        //? OCTAL TO HEXADECIMAL;
        else if (opt1 == 3 && opt2 == 4)
        {
            long int octal, decimalValue;
            int i = 0;

            printf("Enter any octal number: ");
            scanf("%ld", &octal);
            decimalValue = octalToDecimal(octal);
            printf("Your hexadecimal value is %lx", decimalValue);
        }

        //? HEXADECIMAL TO DECIMAL;
        else if (opt1 == 4 && opt2 == 1)
        {
            long long int decimalVal = hexadecimalToDecimal();
            printf("Your decimal value is : %lld", decimalVal);
        }
        //? HEXADECIMAL TO BINARY
        else if (opt1 == 4 && opt2 == 2)
        {
            long long int decimalVal = hexadecimalToDecimal();
            decimalToBinary(decimalVal);
        }
        else if (opt1 == 4 && opt2 == 3)
        {
            long long int decimalVal = hexadecimalToDecimal();
            decimalToOctal(decimalVal);
        }
        else
        {
            printf("Option dosen't matched. Please try again later...");
        }
    }
    printf("\n\nThank you.\n\n");
    return 0;
};

//! CONVERT DECIMAL TO BINARY
int decimalToBinary(int deciNum)
{
    int num = deciNum, i = 0, binary[100] = {};
    while (num != 0)
    {
        binary[i] += num % 2;
        num /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
    return 0;
}

//! CONVERT DECIMAL TO OCTAL
int decimalToOctal(int deciNum)
{
    int octaValue[100] = {}, i = 0;
    while (deciNum != 0)
    {
        int remainder = deciNum % 8;
        octaValue[i] = remainder;
        deciNum /= 8;
        ++i;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", octaValue[j]);
    }
}

//! CONVERT BINARY TO DECIMAL
int binaryToDecimal(long long biNum)
{
    int deciNum = 0, i = 0;
    while (biNum != 0)
    {
        int rem = biNum % 10;
        deciNum += rem * pow(2, i);
        i++;
        biNum /= 10;
    }
    return deciNum;
}

//! BINARY TO HEXADECIMAL
int binaryToHexadecimal(long int binValue)
{
    long int hexadecimalval = 0, i = 1, remainder;
    while (binValue != 0)
    {
        remainder = binValue % 10;
        hexadecimalval += remainder * i;
        i *= 2;
        binValue /= 10;
    }
    printf("Equivalent hexadecimal value: %lx", hexadecimalval);
    return 0;
}

//! OCTAL TO DECIMAL
int octalToDecimal(long int octValue)
{
    long int decimal = 0;
    int i = 0;
    while (octValue != 0)
    {
        decimal = decimal + (octValue % 10) * pow(8, i++);
        octValue /= 10;
    }
    return decimal;
}

//! HEXADECIMAL TO DECIMAL4
int hexadecimalToDecimal()
{
    char hex[1000];
    long long int decimal = 0, base = 1;
    int i = 0, length;
    printf("Enter hexadecimal number: ");
    scanf("%s", &hex);
    length = strlen(hex);
    for (i = length--; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    return decimal;
}
