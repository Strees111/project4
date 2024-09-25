#include <iostream>

inline unsigned long long convertToDecimal(const char inputNumber[], unsigned long long base) {
    unsigned long long decimalValue = 0;
    for (int i = 0; inputNumber[i] != '\0'; ++i) {
        int digitValue = 0;
        if (inputNumber[i] >= '0' && inputNumber[i] <= '9') {
            digitValue = inputNumber[i] - '0';
        } else if (inputNumber[i] >= 'A' && inputNumber[i] <= 'Z') {
            digitValue = inputNumber[i] - 'A' + 10;
        } else if (inputNumber[i] >= 'a' && inputNumber[i] <= 'z') {
            digitValue = inputNumber[i] - 'a' + 10;
        }

        if (digitValue >= base) {
            throw "wrong integer";
        }

        decimalValue = static_cast<unsigned long long>(digitValue + decimalValue * base);
    }
    return decimalValue;
}

inline void convertFromDecimal(char outputNumber[], unsigned long long decimalValue, unsigned long long base) {
    char tempResult[64];
    unsigned long long index = 0;
    const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (decimalValue > 0) {
        tempResult[index++] = digits[decimalValue % base];
        decimalValue /= base;
    }

    for (int i = 0; i < index; ++i) {
        outputNumber[i] = tempResult[index - 1 - i];
    }
    outputNumber[index] = '\0';
}

inline void convertBase(char inputNumber[], char outputNumber[], unsigned long long fromBase, unsigned long long toBase) {
    unsigned long long decimalValue = convertToDecimal(inputNumber, fromBase);
    convertFromDecimal(outputNumber, decimalValue, toBase);
}

int main() {
    unsigned long long fromBase = 0, toBase = 0;
    char inputNumber[64]{};
    char outputNumber[64]{};

    std::cin >> inputNumber;
    std::cin >> fromBase >> toBase;

    try {
        convertBase(inputNumber, outputNumber, fromBase, toBase);
    } catch (const char *errorMessage) {
        std::cout << errorMessage << std::endl;
        return 0;
    }

    std::cout << outputNumber << std::endl;
    return 0;
}
