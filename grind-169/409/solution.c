int longestPalindrome(char* s) {
    int alpha[52] = {}, max = 0, odd = 0;
    for (; *s; s++) {
        if (*s >= 'a')
            alpha[*s - 'a']++;
        else
            alpha[*s - 'A' + 26]++;
    }
    for (int i = 0; i < 52; i++) {
        if (alpha[i] & 1) {
            max += (alpha[i] - 1);
            odd = 1;
        } else {
            max += alpha[i];
        }
    }
    return max + odd;
}
