#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

void perm(string sub, size_t b, size_t c, vector<string>& allSubs) {
    if (b == c) {
        allSubs.push_back(sub);
    }
    else {
        // i++ -> x=i;i++;
        // ++i -> x=i+1;  --> daha performanslı
        for (size_t i = b; i <= c; ++i) {
            swap(sub[b], sub[i]);

            perm(sub, b + 1, c, allSubs);

            swap(sub[b], sub[i]);
        }
    }
}

void generateWord(string s, size_t index, string sub, size_t n, vector<string>& allSubs) {
    if (index == n) {
        if (sub.length() > 0) {
            perm(sub, 0, sub.length() - 1, allSubs);
        }
        return;
    }
    else {
        sub.push_back(s[index]);

        generateWord(s, index + 1, sub, n, allSubs);

        sub.pop_back();

        generateWord(s, index + 1, sub, n, allSubs);
    }
}

int main()
{
    string word, sub;
    vector<string> allSubs;

    cout << "Karakterleri giriniz: ";
    cin >> word;

    // zamanlı geri dönüş eklenecek
    generateWord(word, 0, sub, word.length(), allSubs);
    
    srand((unsigned int)time(NULL));

    string randomWord = allSubs.at(rand() % allSubs.size());
    
    cout << randomWord << endl;
}
