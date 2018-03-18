#include <iostream>

using namespace std;

int roundFunction(int key, string rightSplice){

    int result = 0;

    for(int i = 0; i < rightSplice.length(); i++)
        result += rightSplice[i];

    result / key;

    return result;
}

int main()
{
    int numOfIterations;
    int initialKey = 10;
    int subKey = initialKey;
    string input;
    string leftSplice = "";
    string rightSplice = "";
    string temp;

    cout << "Enter number of rounds to run the Feistel Cipher: ";
    cin >> numOfIterations;

    cout << "\nEnter string to be encrypted: ";
    cin >> input;

    int i = 0;

    for(i; i < input.length()/2; i++)
        leftSplice += input[i];

    for(i; i < input.length(); i++)
        rightSplice += input[i];

    for(int i = 0; i < numOfIterations; i++){

        int functionResult = roundFunction(subKey, rightSplice);

        for(int j = 0; j < leftSplice.length(); j++)
            leftSplice[j] = leftSplice[j] ^ functionResult;

        temp = rightSplice;
        rightSplice = leftSplice;
        leftSplice = temp;

        if(i != numOfIterations - 1)
            subKey++;

        cout << "\nEncryption Round " << i + 1 << " Output:\t" << "Left: " << leftSplice << "\t" << "Right: " << rightSplice << "\n";
    }

    temp = rightSplice;
    rightSplice = leftSplice;
    leftSplice = temp;

    cout << "\nEncryption Final Output: " << leftSplice + rightSplice << "\n";

    for(int i = 0; i < numOfIterations; i++){

        int functionResult = roundFunction(subKey, rightSplice);

        for(int j = 0; j < leftSplice.length(); j++)
            leftSplice[j] = leftSplice[j] ^ functionResult;

        temp = rightSplice;
        rightSplice = leftSplice;
        leftSplice = temp;
        subKey--;

        cout << "\nDecryption Round " << i + 1 << " Output:\t" << "Left: " << leftSplice << "\t" << "Right: " << rightSplice << "\n";
    }

    temp = rightSplice;
    rightSplice = leftSplice;
    leftSplice = temp;

    cout << "\nDecryption Final Output: " << leftSplice + rightSplice << "\n";

    return 0;
}
