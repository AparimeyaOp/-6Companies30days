/*BULLS & COWS 299*/
/*
You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

 

Example 1:

Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"
Example 2:

Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1123"        "1123"
  |      or     |
"0111"        "0111"
Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.
 

Constraints:

1 <= secret.length, guess.length <= 1000
secret.length == guess.length
secret and guess consist of digits only.
*/

class Solution {
public:
    /* same as approach 2 just simplified version*/

    string getHint(string secret, string guess) {
        //intialization
        int bulls = 0,cows = 0;
        vector<int> vec(10,0);

        //calcuating frequencies & bulls in one loop
        for(int i = 0;i<secret.size();i++){
            // if bulls no need to add anything to frequency, just increment it
            if(secret[i] == guess[i]){
                bulls++;
            }
            //frequencies must be calculated here
            else{
                vec[secret[i]-'0'] ++;
            }
        }

        //calcuating cows
        for(int i = 0;i<guess.size();i++){
            if(guess[i] != secret[i] && vec[guess[i]-'0']>0){
                cows++;
                vec[guess[i]-'0']--;
            }
        }

        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};


/*
        2) SECOND APPROACH(OPTIMAL) WITH ARRAY
        TIME COMPLEXITY -> O(N);
        SPACE COMPLEXITY -> O(1); since vector size is fixed
        LOGIC->
        1)TAKE A VECTOR TO STORE FREQUECIES
        2)ONCE FREQUENCIES HAVE BEEN STORE GO FOR BULLS
            ->COMPARE SAME INDEXES IF EQUAL
                A) BULLS ++
                B) DECREMENT FREQUENCIES
                C) MAKE GUESS[i] = 'x', so that we don't count things again
        3)CALCULATE COWS
            ->SIMPLY CHECK FREQUENCIES
            ->IF>0
                A)COWS ++
                B)DECREMENT COUNT

        vector<int> vec(10,0);
        for(int i=0;i<secret.size();i++){
            vec[secret[i]-'0'] ++;
        }
        
        int bulls = 0,cows = 0;
        for(int i = 0;i<guess.size();i++){
            if(guess[i] == secret[i]){
                bulls ++;
                vec[guess[i]-'0']--;
                guess[i] = 'x';
            }
        }

        for(int i = 0;i<guess.size();i++){
            if(guess[i] != 'x'){
                if(vec[guess[i]-'0']>0){
                    cows ++;
                    vec[guess[i]-'0'] --;
                }
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
        
    }

 /*
        1)My brute force approach + hint
        TIME COMPLEXITY-> O(N^2)
        SPACE COMPLEXITY-> O(1)
        int bulls = 0,cows = 0;
        for(int i = 0;i<guess.size();i++){
            if(guess[i] == secret[i]){
                bulls++;
                guess[i] = 'x';
                secret[i] = 'x';
            } 
        }

        for(int i = 0;i<guess.size();i++){
            for(int j = 0;j<secret.size();j++){
                if(guess[i] != 'x' && secret[j] != 'x' && guess[i] == secret[j] ){
                    cout<<guess[i]<<" "<<secret[j]<<endl;
                    cows ++;
                    secret[j] = 'x';
                    break;
                }
            }
        }
        string op = "";
        op += to_string(bulls)+"A"+to_string(cows)+"B";
        return op;
*/

