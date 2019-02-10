#include <iostream>
#include <string>
#include <algorithm> 
#include <iterator>
#include <vector>
#include <map>
#include <numeric> //iota
#include <random>

void printText(const std::vector<char>& raw, const std::vector<char>& encrypted);
void replaceSingleChar(std::vector<char>& input, char current, char target);
void printMap(const std::map<char, char>& secretMap);
std::vector<char> encrypt(const std::vector<char>& plain, const std::map<char,char>& secretMap);
std::vector<char> decrypt(const std::vector<char>& encrypted, const std::map<char,char>& secretMap);
std::map<char, char> generateSecretMap();
std::map<char, char> reverseMap(const std::map<char,char>& original);

int main(){
    std::cout << "Hello world, cryptoApp!\n";

    const std::string inputText = "Stoi na stacji lokomotywa";
    const std::vector<char> rawText(inputText.begin(), inputText.end());

    auto privateMap = generateSecretMap();

    std::vector<char> encrypted = encrypt(rawText, privateMap);
    printText(rawText, encrypted);
 
    std::vector<char> decrypted = decrypt(encrypted, privateMap);
    printText(encrypted, decrypted); 


    return 0;
}

void printText(const std::vector<char>& raw, const std::vector<char>& encrypted){
    std::cout << "In:  ";
    std::copy(raw.begin(), raw.end(), std::ostream_iterator<char>(std::cout, ""));
    std::cout << "\n";    
    std::cout << "Out: ";
    std::copy(encrypted.begin(), encrypted.end(), std::ostream_iterator<char>(std::cout, ""));
    std::cout << "\n";    
}


void printMap(const std::map<char,char>& secretMap){
    std::for_each(secretMap.begin(), secretMap.end(), [](const auto& p){
                std::cout << p.first << ":" << p.second << "\n"; 
            });
}

std::vector<char> encrypt(const std::vector<char>& plain, const std::map<char,char>& sMap){
    auto encrypted = plain;
    char target;
    std::replace_if(encrypted.begin(), encrypted.end(), 
                    [&](char source){ return target = sMap.at(source);}, target);
    return encrypted;
}

std::vector<char> decrypt(const std::vector<char>& encrypted, const std::map<char,char>& sMap){
    auto decrypted = encrypted;
    char target;
    auto reversedMap = reverseMap(sMap);
    std::replace_if(decrypted.begin(), decrypted.end(), 
                    [&](char source){ return target = reversedMap.at(source);}, target);
    return decrypted;
}

std::map<char, char> generateSecretMap(){
    std::vector<int> keys(95);
    std::iota(keys.begin(), keys.end(), 32); //start from Space character 
    std::vector<int> values = keys;
    
    std::shuffle(values.begin(), values.end(), std::mt19937{std::random_device{}()});
    
    std::map<char, char> tempMap;    
    for(unsigned i=0; i<keys.size(); ++i)
        tempMap[keys[i]] = values[i];
    
    return tempMap;
}

std::map<char, char> reverseMap(const std::map<char,char>& original){
    std::map<char, char> reversed;
    for(auto& p : original)
        reversed[(p.second)] = (p.first);
    return reversed;
}
