// 09. Palindrome Number

bool isPalindrome(int x) {
    // any negative number is not a palindrome bc of the signal
    if (x < 0)
        return false;

    // catching each digit 1 by 1 from the last to the first and turning it into a single number
    unsigned int aux = x, y = 0;
    while (aux >= 1) {
        y += aux % 10;
        
        if (aux >= 10)
            y *= 10;

        aux /= 10;
    }

    // comparing the normal and the inverted one
    if (x == y)
        return true;
    
    return false;
}
