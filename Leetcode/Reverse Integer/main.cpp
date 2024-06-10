class Solution {
public:
    int reverse(int x) {
        int max { 2147483647 };
        int min { -2147483648 };

        if(x == min) {
            return 0;
        }

        if(x < 10 && x >= 0) {
            return x;
        }

        bool positive { true };

        if(x < 0) {
            x *= -1;
            positive = false;
        }

        int multiplier { 1 };

        int copy { x };
        while(copy / 10 != 0) {
            copy /= 10;
            multiplier *= 10;
        }

        if(multiplier >= 1000000000 && x % 10 > 2) {
            return 0;
        }

        int answer { 0 };
        while(x) {
            if((answer / 2) + ((x % 10 * multiplier) / 2) > (max / 2)) {
                return 0;
            }
            answer += x % 10 * multiplier;
            x /= 10;
            multiplier /= 10;
        }

        if(!positive) {
            return answer * -1;
        }

        return answer;

    }
};

int main() {

    Solution solve {};

    int input { 1563847412 };

    int answer { solve.reverse(input) };
  
}