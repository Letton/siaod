#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

struct Word {
    size_t firstCharIndex;
    size_t size;
    char* str;
};

struct PalindromeNumberInStr {
    size_t firstCharIndex;
    size_t number;
    size_t strSize;
    size_t wordIndex;
};

bool isPalindrome(const Word word) {
    for (int i = 0; i < word.size / 2; i++) {
        if (word.str[i] != word.str[word.size - i -  1]) {
            return false;
        }
    }
    return true;
}

void copyCharArray(char *dest, char *src) {
    size_t len = strlen(src);
    for (size_t i = 0; i < len; i++) {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

void splitIntoWords(char* str, Word* words, size_t &wordsCount)  {
    size_t i = 0, j = 0;
    while (str[i] != '\0') {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))) {
            str[i] = '\0';
            if (j != 0) {
                words[wordsCount].str = &str[i - j];
                words[wordsCount].size = j;
                words[wordsCount].firstCharIndex  = i - j;
                wordsCount += 1;
            }
            j = 0;
        } else {
            ++j;
        }
        ++i;
    }
    if (j != 0) {
        words[wordsCount].str = &str[i - j];
        words[wordsCount].size = j;
        words[wordsCount].firstCharIndex  = i - j;
        wordsCount += 1;
    }
}

PalindromeNumberInStr findMaxPalindrome(Word *words, size_t wordsCount) {
    size_t palindromeNumber = 0;
    PalindromeNumberInStr maxPalindromeNumberInStr {
        0,
        0,
        0
    };
    for (size_t i = 0; i < wordsCount; ++i) {
        if (isPalindrome(words[i])) {
            ++palindromeNumber;
            if (words[i].size > maxPalindromeNumberInStr.strSize) {
                maxPalindromeNumberInStr.firstCharIndex = words[i].firstCharIndex;
                maxPalindromeNumberInStr.number = palindromeNumber;
                maxPalindromeNumberInStr.strSize = strlen(words[i].str);
                maxPalindromeNumberInStr.wordIndex = i;
            }
        }
    }
    return maxPalindromeNumberInStr;
}

void replaceStr(char* str, PalindromeNumberInStr palindrome, Word* words) {
    Word wordToReplace = words[palindrome.wordIndex];
    char tempStr [1024];
    size_t tempSize = 0;
    size_t tempNumber = palindrome.number;
    while (tempNumber != 0) {
        tempStr[tempSize] = (tempNumber % 10) + '0';
        tempNumber /= 10;
        tempSize++;
    }
    tempStr[tempSize] = '\0';
    if (tempSize <= wordToReplace.size) {
        for (size_t i = 0; i <  tempSize; ++i) {
            str[wordToReplace.firstCharIndex + i] = tempStr[i];
        }
        for (size_t i = 0; i <  wordToReplace.size - tempSize; ++i) {
            for (size_t j = wordToReplace.firstCharIndex + tempSize; j < strlen(str); ++j) {
                str[j] = str[j + 1];
            }
        }
    } else {
        for (size_t i = 0; i < tempSize - wordToReplace.size; ++i) {
            for (size_t j = strlen(str); j > wordToReplace.firstCharIndex + wordToReplace.size + i + 1; ++j) {
                str[j + 1] = str[j];
            }
        }
    }
}

int main() {
    int n;
    cout << "1 - Given a sentence consisting of words separated by commas or spaces. Find the longest palindrome word.\n"
            "    Replace a word in a sentence with a number given its number among the sentence's palindromes.\n"
            "    (static array)\n"
            "2 - Given a sentence consisting of words separated by commas or spaces. Find the longest palindrome word.\n"
            "    Replace a word in a sentence with a number given its number among the sentence's palindromes.\n"
            "    (std::string)\n";
    cout << "Select task:\n";
    cin >> n;
    if (n == 1) {
        size_t wordsCount = 0;
        char str[1024], tempStr[1024];
        Word words[1024];
        cout << "Input sentence (max sentence size = 1024)\n";
        cin.ignore();
        cin.getline(str, 1024);
        copyCharArray(tempStr, str);
        splitIntoWords(tempStr, words, wordsCount);
        replaceStr(str, findMaxPalindrome(words, wordsCount), words);
        cout << str;
    } else if (n == 2) {

    } else {
        cout << "Incorrect input\n";
        return -1;
    }
    return 0;
}