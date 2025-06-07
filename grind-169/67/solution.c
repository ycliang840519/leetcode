// index calculation needs to be dealt with carefully

char* addBinary(char* a, char* b) {
    int alen = strlen(a);
    int blen = strlen(b);
    int clen = alen > blen ? alen : blen;
    int carry = 0;
    char *c = (char*)calloc(clen + 1, sizeof(char)); // +1 for '\0' 
    c[clen] = '\0';

    for (int i = 0; i < clen; i++) {
        int aindex = alen - 1 - i;
        int bindex = blen - 1 - i;
        int cindex = clen - 1 - i;
        
        int add1 = aindex < 0 ? 0 : (a[aindex] - '0');
        int add2 = bindex < 0 ? 0 : (b[bindex] - '0');
        
        int sum = add1 + add2 + carry;
        if (sum > 1) {
            carry = 1;
            c[cindex] = (sum & 1) + '0';
        } else {
            carry = 0;
            c[cindex] = sum + '0';
        }
    }

    if (carry == 1) {
        c = (char*)realloc(c, (clen + 2) * sizeof(char));
        for (int i = clen + 1; i > 0; i--) {
            c[i] = c[i-1];
        }
        c[0] = '1';
    }

    return c;
}

// index calculation is killing me QQ
char* addBinary(char* a, char* b) {
    int alen = strlen(a);
    int blen = strlen(b);
    int clen = alen > blen ? alen : blen;
    int carry = 0;
    char *c = (char*)calloc(clen + 2, sizeof(char)); // extra 2 char: one for possible carry, one for '\0' 
    c[clen + 1] = '\0';

    for (int i = 0; i < clen; i++) {
        int aindex = alen - 1 - i;
        int bindex = blen - 1 - i;
        int cindex = (clen + 1) - 1 - i;
        
        int add1 = aindex < 0 ? 0 : (a[aindex] - '0');
        int add2 = bindex < 0 ? 0 : (b[bindex] - '0');
        
        int sum = add1 + add2 + carry;
        if (sum > 1) {
            carry = 1;
            c[cindex] = (sum & 1) + '0';
        } else {
            carry = 0;
            c[cindex] = sum + '0';
        }
    }

    if (carry == 1) 
        c[0] = '1';
    else
        c = c + 1;

    return c;
}
