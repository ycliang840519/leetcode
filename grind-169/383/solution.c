bool canConstruct(char* ransomNote, char* magazine) {
    int alphabet[26] = {};
    for (char *c = magazine; *c != '\0'; c++) {
        alphabet[*c - 'a']++;
    }
    for (char *c = ransomNote; *c != '\0'; c++) {
        if (--alphabet[*c - 'a'] < 0)
            return false;
    }
    return true;
}
