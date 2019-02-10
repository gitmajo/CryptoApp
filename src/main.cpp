#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>

void printText(std::vector<char>& raw, std::vector<char>& encrypted);
void replaceSingleChar(std::vector<char>& input, char current, char target);
void printSecretMap(const std::map<char, char>& secretMap);

int main(){
    std::cout << "Hello world, cryptoApp!\n";

    std::string inputText = "Stoi na stacji lokomotywa";
    
    std::map<char, char> secretMap{
        {'a', 'b'},
        {'o', 'k'},
        {'f', 'q'}
    };
    
    std::vector<char> rawText(inputText.begin(), inputText.end());
    std::vector<char> encryptedText(inputText.begin(), inputText.end()); 

    printText(rawText, encryptedText);
    replaceSingleChar(encryptedText, 'a', secretMap['a']);
    printText(rawText, encryptedText);
      
    replaceSingleChar(encryptedText, 'o', secretMap['o']);
    printText(rawText, encryptedText);
     
    replaceSingleChar(encryptedText, 'f', secretMap['f']);
    printText(rawText, encryptedText);
 
    printSecretMap(secretMap);

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


void printSecretMap(const std::map<char, char>& secretMap){
    std::for_each(secretMap.begin(), secretMap.end(), [](const auto& p) 
                 { std::cout << p.first << ":" << p.second << "\n"; });
}
