// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int value;
        do value = 1 * (rand7() - 1) + 
                   7 * (rand7() - 1) + 
                   49 * (rand7() - 1) +
                   343 * (rand7() - 1);
        while (value == 2400);
        return (value / 240) + 1;
    }
};