#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>

void printText(std::vector<char>& raw, std::vector<char>& encrypted);
void replaceSingleChar(std::vector<char>& input, char current, char target);

int main(){
    std::cout << "Hello world, cryptoApp!\n";

    std::string inputText = "Stoi na stacji lokomotywa";
    
    std::map<char, char> privateKey{
        {'a', 'b'},
        {'o', 'k'},
        {'f', 'q'}
    };
    
    std::vector<char> rawText(inputText.begin(), inputText.end());
    std::vector<char> encryptedText(inputText.begin(), inputText.end()); 

    printText(rawText, encryptedText);
    replaceSingleChar(encryptedText, 'a', privateKey['a']);
    printText(rawText, encryptedText);
      
    replaceSingleChar(encryptedText, 'o', privateKey['o']);
    printText(rawText, encryptedText);
     
    replaceSingleChar(encryptedText, 'f', privateKey['f']);
    printText(rawText, encryptedText);
 
    return 0;
}

void printText(std::vector<char>& raw, std::vector<char>& encrypted){
    std::cout << "In:  ";
    std::copy(raw.begin(), raw.end(), std::ostream_iterator<char>(std::cout, ""));
    std::cout << "\n";    
    std::cout << "Out: ";
    std::copy(encrypted.begin(), encrypted.end(), std::ostream_iterator<char>(std::cout, ""));
    std::cout << "\n";    
}

void replaceSingleChar(std::vector<char>& input, char current, char target){
    std::replace(input.begin(), input.end(), current, target);

}
