#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

void printText(std::vector<char>& raw, std::vector<char>& encrypted);
void replaceSingleChar(std::vector<char>& input, char current, char target);

int main(){
    std::cout << "Hello world, cryptoApp!\n";

    std::string inputText = "Stoi na stacji lokomotywa";
    std::vector<char> rawText(inputText.begin(), inputText.end());
    std::vector<char> encryptedText(inputText.begin(), inputText.end()); 

    printText(rawText, encryptedText);
    replaceSingleChar(encryptedText, 'a', 'b');
    printText(rawText, encryptedText);
      
    replaceSingleChar(encryptedText, 'o', 'k');
    printText(rawText, encryptedText);
     
    replaceSingleChar(encryptedText, 'f', 'q');
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
