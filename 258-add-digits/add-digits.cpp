class Solution {
public:
    int sumOfDigits( int num){
        if(num == 0) return 0;
        return (num % 10) + sumOfDigits(num/10);
    }
    int addDigits(int num) {
        if(num < 10){
            return num;
        }
        return addDigits(sumOfDigits(num));
    }
};