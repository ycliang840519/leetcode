bool isAnagram(char* s, char* t) {
    int alphabet[26] = {};
    while (*s && *t) {
        alphabet[*s - 'a']++;
        alphabet[*t - 'a']--;
        s++;
        t++;
    }
    if (*t || *s)
        return false;
    for (int i = 0; i < 26; i++)
        if (alphabet[i])
            return false;
    return true;
}
