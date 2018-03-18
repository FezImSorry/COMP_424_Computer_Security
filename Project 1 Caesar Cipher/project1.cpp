#include <iostream>

using namespace std;

int main(){

    int shift;
    string input;
    string encryptionResult = "";
    string decryptionResult = "";

    cout<<"Enter number to shift by in encryption process: ";
    cin>>shift;

    cout<<"\nEnter string to be encrypted: ";
    cin>>input;

    for(int i = 0; i < input.length(); i++){

        if(isupper(input[i]))
            encryptionResult += (input[i] + shift - 65)%26 + 65;
        else if (input[i] == ' ')
            encryptionResult += ' ';
        else
            encryptionResult += (input[i] + shift - 97)%26 + 97;
    }

    cout<<"\nEncryption Result: "<<encryptionResult<<"\n";

    for(int i = 0; i < input.length(); i++){

        if(isupper(input[i]))
            decryptionResult += (encryptionResult[i] + (26 - shift) - 65)%26 + 65;
        else if (input[i] == ' ')
            decryptionResult += ' ';
        else
            decryptionResult += (encryptionResult[i] + (26 - shift) - 97)%26 + 97;
    }

    cout<<"\nDecryption Result: "<<decryptionResult<<"\n";

    return 0;
}
