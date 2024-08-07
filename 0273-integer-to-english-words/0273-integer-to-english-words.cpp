class Solution {
public:
    string numberToWords(int num) { 
        string words;
        const int G = 1000000000;
        const int M = 1000000;
        const int K = 1000;
        if (num / G){
            words = threeDigit(num / G) + " " + hundredBillion[3];
        }
        if (num % G / M){
            if(!words.empty()){
                words += " ";
            }
            words += threeDigit(num % G / M) + " " + hundredBillion[2];
        }
        if (num % M / K){
            if(!words.empty()){
                words += " ";
            }
            words += threeDigit(num % M / K) + " " + hundredBillion[1];
        }
        if (num % K) {
            if(!words.empty()){
                words += " ";
            }
            words += threeDigit(num % K);
        }
        if (words.empty()){
            words = "Zero";
        }
        return words;
    };

private:
    const vector<string> hundredBillion = {"Hundred", "Thousand", "Million", "Billion"};

    const vector<string> thirtyNinety = {
        "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    const vector<string> zeroTwenty = {
        "Zero",     "One",      "Two",      "Three",   "Four",    "Five",
        "Six",      "Seven",    "Eight",    "Nine",    "Ten",     "Eleven",
        "Twelve",   "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
        "Eighteen", "Nineteen", "Twenty"};
    
    string zeroToNinetyNine(int num){
        if (num <= 20){
            return zeroTwenty[num];
        }
        else {
            string word = thirtyNinety[num/10];
            if (num % 10){
                word += " " + zeroTwenty[num%10];
            }
            return  word;
        }
    }

    string threeDigit(int num){
        string word;
        const int H = 100;

        if (num / H){
            word += zeroTwenty[num / H] + " " + hundredBillion[0];
        }
        if (num % H){
            if (!word.empty()){
                word += " ";
            }
            word += zeroToNinetyNine(num % H);
        }
        cout << word << '\n';
        return word;
    }
};