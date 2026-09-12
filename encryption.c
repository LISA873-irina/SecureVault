#include <stdio.h>
#include <string.h>
#include "encryption.h"

#define ENCRYPTION_KEY 0x5A

void encryptText(const char input[], char output[], int outputSize)
{
    int i;
    int required = (int)strlen(input) * 2 + 1;

    if (outputSize < required)
    {
        output[0] = '\0';
        return;
    }

    for (i = 0; input[i] != '\0'; i++)
    {
        unsigned char value = (unsigned char)input[i] ^ ENCRYPTION_KEY;
        sprintf(&output[i * 2], "%02X", value);
    }

    output[i * 2] = '\0';
}

void decryptText(const char input[], char output[], int outputSize)
{
    int i;
    int length = (int)strlen(input);

    if (length % 2 != 0 || outputSize < length / 2 + 1)
    {
        output[0] = '\0';
        return;
    }

    for (i = 0; i < length / 2; i++)
    {
        unsigned int value = 0;
        sscanf(&input[i * 2], "%2X", &value);
        output[i] = (char)((unsigned char)value ^ ENCRYPTION_KEY);
    }

    output[i] = '\0';
}
