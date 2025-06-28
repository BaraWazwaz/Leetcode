class Solution {
public:
    string intToRoman(int num) {
        string s;
        while (num >= 1000) {
            s.push_back('M');
            num -= 1000;
        }
        if (num >= 900) {
            s.push_back('C');
            s.push_back('M');
            num -= 900;
        }
        if (num >= 500) {
            s.push_back('D');
            num -= 500;
        }
        if (num >= 400) {
            s.push_back('C');
            s.push_back('D');
            num -= 400;
        }
        while (num >= 100) {
            s.push_back('C');
            num -= 100;
        }
        if (num >= 90) {
            s.push_back('X');
            s.push_back('C');
            num -= 90;
        }
        if (num >= 50) {
            s.push_back('L');
            num -= 50;
        }
        if (num >= 40) {
            s.push_back('X');
            s.push_back('L');
            num -= 40;
        }
        while (num >= 10) {
            s.push_back('X');
            num -= 10;
        }
        if (num >= 9) {
            s.push_back('I');
            s.push_back('X');
            num -= 9;
        }
        if (num >= 5) {
            s.push_back('V');
            num -= 5;
        }
        if (num >= 4) {
            s.push_back('I');
            s.push_back('V');
            num -= 4;
        }
        while (num >= 1) {
            s.push_back('I');
            num -= 1;
        }
        return s;
    }
};