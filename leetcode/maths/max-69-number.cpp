class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        int num4, num3, num2, num1;
        num4 = temp%10;
        temp = temp/10;
        num3 = temp%10;
        temp = temp/10;
        num2 = temp%10;
        temp = temp/10;
        num1 = temp%10;
        if(num1==6)
            return num+3000;
        if(num2==6)
            return num+300;
        if(num3==6)
            return num+30;
        if(num4==6)
            return num+3;
        return num;
    }
};
