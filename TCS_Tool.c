#include <stdio.h>
#include <math.h>
#include <time.h>

// ce to fa
void temperature_converter() {
    char type;
    float temp, result;

    printf("Enter 'C' to convert Celsius to Fahrenheit, 'F' to convert Fahrenheit to Celsius: ");
    scanf(" %c", &type);

    if (type == 'C' || type == 'c') {
        printf("Enter the Celsius temperature: ");
        scanf("%f", &temp);
        result = temp * 9 / 5 + 32;
        printf("The Fahrenheit temperature is: %.2f\n", result);
    } else if (type == 'F' || type == 'f') {
        printf("Enter the Fahrenheit temperature: ");
        scanf("%f", &temp);
        result = (temp - 32) * 5 / 9;
        printf("The Celsius temperature is: %.2f\n", result);
    } else {
        printf("Invalid type. Please enter 'C' or 'F'.\n");
    }
}

// cal
void calculator() {
    float a, b, result;
    char op;

    printf("Please enter an expression (e.g., 3 + 4): ");
    scanf("%f %c %f", &a, &op, &b);

    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b != 0)
                result = a / b;
            else {
                printf("The divisor cannot be 0.\n");
                return;
            }
            break;
        default:
            printf("Invalid operator. Use +, -, *, or /.\n");
            return;
    }

    printf("The result is: %.2f\n", result);
}

// se s
void convert_seconds() {
    int total_seconds, hours, minutes, seconds;

    printf("Please enter the total seconds: ");
    scanf("%d", &total_seconds);

    hours = total_seconds / 3600;
    minutes = (total_seconds % 3600) / 60;
    seconds = total_seconds % 60;

    printf("%d seconds = %d hours %d minutes %d seconds\n",
           total_seconds, hours, minutes, seconds);
}

// main
int main() {
    char choice;

    while (1) {
        printf("\n=== Function Menu ===\n");
        printf("A - Temperature Converter\n");
        printf("B - Simple Calculator\n");
        printf("C - Seconds to Time\n");
        printf("Q - Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);  

        switch (choice) {
            case 'a':
            case 'A':
                temperature_converter();
                break;
            case 'b':
            case 'B':
                calculator();
                break;
            case 'c':
            case 'C':
                convert_seconds();
                break;
            case 'q':
            case 'Q':
                printf("Quitting program.\n");
                return 0;
            default:
                printf("Invalid input, please try again.\n");
        }
    }

    return 0;
}
