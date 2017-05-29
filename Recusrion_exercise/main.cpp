#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& input);
int digitSum(int input);
int waysToClimb(int numStairs);

int main() {
    //test palindrome
    string user;
    cout << "~~~~~ HELLO! ~~~~~\n\nPlease enter a string to see if it is a Palindrome:";
    cin >> user;
    if  (isPalindrome(user)==1){
        cout << user << " is a Panlindrome!\n\n\n";
    }else{
        cout << user << " is not a Panlindrome!\n\n\n";
    }
    
    //test digit Sum
    int number, sum;
    cout << "Enter a number to see all of its digits added together:";
    cin >> number;
    if (number == 0){
        cout << "The sum of 0 is 0!\n\n";
    }else{
        sum = digitSum(number);
        cout <<"\nThe sum of all the digits is: " << sum <<endl;
    }
    
    //test number of ways to climb a staircase
    int stairs, combos;
    cout <<"\n\nEnter a number of stairs for the full combination of possible ways down the stairs by taknig either 1 or 2 steps.If the staircase has three steps, for example, there are three ways to climb it (three small strides, or a large stride followed by a small stride, or a small stride followed by a large stride).\n\nEnter number:";
    cin >> stairs;
    combos = waysToClimb(stairs);
    
    cout << "There are " << combos << " ways to climb " << stairs << " stairs\n\n";
    
    
    
    return 0;
}

bool isPalindrome(const string& input){
    string word = input;
    int size = word.length();
    //base case
    if (size ==1){
        // cout << word << " is a Panlindrome!\n";
        return true;
    }
    else if (size == 2){
        //load the first two characters and compare them. If they are the same, then it will return true
        char a = word[0];
        char b = word [1];
        if (a == b){
            // cout << word << " is a Panlindrome!\n";
            return true;
        }else{
            // cout << word << " is not a Panlindrome!\n";
            return false;
        }
    }else{
        // if the letters dont match, return 0
        if(input[0] != input[size-1]){
            return false;
            
        }
        return isPalindrome(word.substr(1,size-2));
    }
}

int digitSum(int input){
    int number = input, sum=0, r;
    //base case
    if(number/10 == 0){
        return number;
    }else{
        //get the remainder
        r=number%10;
        
        //recursivly add the remainders together
        sum+= r+digitSum(number/10);
        
        //return all the remainders added
        return sum;
    }
    
    return sum;
}



int waysToClimb(int numStairs){
    int combos = numStairs;
    
    //base case
    if(combos<=1){
        return 1;
    }
    //possible ways down, take a step or two steps.
    return waysToClimb(combos-1)+ waysToClimb(combos-2);
}

