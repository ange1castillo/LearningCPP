#include <iostream>

class Solution {
public:
    int myAtoi(std::string& s) {
        long val { 0 }; 
        bool positive { true };
        bool reading { false };

        for(auto& e : s) {

            if(e >= '0' && e <= '9') {
                    reading = true;
            }
            
            if(reading) {
                if(e < '0' || e > '9') {
                    break;
                } 

                val *= 10;

                if(val > INT_MAX && positive) {
                    return INT_MAX;
                } 

                else if(val > INT_MAX && !positive) {
                    return INT_MIN;
                }
                
                val += e - 48;
            }

            else {
                if(e == ' ') {
                    continue;
                }

                else if(e == '-') {
                    positive = false;
                    reading = true;
                    continue;
                }

                else if(e == '+') {
                    reading = true;
                    continue;
                }

                else {
                    break;
                }
            }
        }

        if(val > INT_MAX && positive) {
            return INT_MAX;
        } 

        else if(val > INT_MAX && !positive) {
            return INT_MIN;
        }

        if(!positive) {
            return val *= -1;
        }

        return val;
        
    }
};

int main() {

    Solution solve {};

    std::string input { "2147483648" };

    int answer { solve.myAtoi(input) };
  
}