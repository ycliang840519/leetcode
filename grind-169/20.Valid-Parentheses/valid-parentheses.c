bool isValid(char* s) {
    /* setup stack */
    int stack_end = -1;
    char stack[10001] = {};
    
    /* process the string */
    for (; *s; s++) {
        if (')' == *s) {
            if (stack_end < 0 || stack[stack_end--] != '(')
                break;
        } else if (']' == *s) {
            if (stack_end < 0 || stack[stack_end--] != '[')
                break;
        } else if ('}' == *s) {
            if (stack_end < 0 || stack[stack_end--] != '{')
                break;
        } else {
            stack[++stack_end] = *s;
        }
    }

    if (*s || stack_end != -1)
        return false;
    return true;
}
