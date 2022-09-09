

#include <iostream>
#include <string>

using namespace std;

bool isValidCreditCard(string cc_number)
{
    // this function will return true or false according to the validity 
    // of credit card number
    // Instruction 1
    // first check if the length of the parameter is 16 or not. If not, return false
    if (cc_number.length() < 16)
    {
        return false;
    }

    // Instruction 2
    // Now that you get 16 characters string, declare an array of integers with size 16 digits
    // and get each of the characters from the string into the corresponding element of the
    // array Follow the logic and hints I gave there  in the problem statement for this
    // conversion you will need to subtract the ASCII of '0' to get each digit properly into
    // the array as integer. You will do this in a loop.
    int arr[16];
    string::iterator it = cc_number.begin();
    int i = 0;
    while (it != cc_number.end() && i < 16)
    {
        if (*it == ' ')
        {
            it++;
        }
        else
        {
            arr[i] = (int)(*it - 48);
            i++;
            it++;
        }
    }
    // Instruction 3:  Now here you need to do the processing as described in the step 1,2,3
    // in the problem statement. You will need a loop and inside of loop you will do this.

    for (i = 0; i < 16; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = arr[i] * 2;
        }
    }
    for (i = 0; i < 16; i++)
    {
        if (arr[i] >= 10)
        {
            int num = arr[i];
            int first = num / 10;
            int last = num % 10;

            arr[i] = first + last;
        }
    }
    // Instruction 4: Find the sum of each of the elements in the array, you will do this in a
    // loop.
    int sum = 0;
    for (i = 0; i < 16; i++)
    {
        sum += arr[i];
    }

    // Instruction 5:
    // if the sum is divisible by 10, then return true otherwise return false.
    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}