#include<iostream>
#include<unordered_map>
using namespace std;

/*
Problem: B1. Wonderful Coloring - 1 (Codeforces)

Goal:
- Paint characters using red and green such that:
  1. Each letter is either unpainted or painted once in either red or green.
  2. No two same letters are painted in the same color.
  3. Number of red letters == number of green letters.
  4. The number of painted letters is maximized.

Approach:
- Count how many letters appear once (called 'ones').
- Count how many letters appear at least twice (called 'twos_or_more').
- From 'ones', we can make (ones / 2) red-green pairs.
- From each 'twos_or_more', we can make 1 red-green pair.
- Total red-green pairs = ones / 2 + twos_or_more.
- Each pair contributes one red and one green letter.
*/

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        unordered_map<char, int> f; // Frequency map to count occurrences of each letter

        // Count the frequency of each character in the string
        for(int i = 0 ; i < s.size() ; i++){
            f[s[i]]++;
        }

        int ones = 0;          // Count of characters that appear exactly once
        int twos_or_more = 0;  // Count of characters that appear two or more times

        // Analyze frequency map
        for(auto it : f){
            if(it.second >= 2)
                twos_or_more++;  // Can use two different instances (red & green)
            else
                ones++;          // Can only be used once (either red or green)
        }

        // Maximum number of red-green pairs = twos_or_more + (ones / 2)
        // Each pair contributes one red and one green, so answer is total number of red letters
        cout << (twos_or_more + ones / 2) << '\n';
    }

    return 0;
}
