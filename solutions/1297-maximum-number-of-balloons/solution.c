#define Min(a, b) ((a) < (b) ? (a) : (b))
int maxNumberOfBalloons(char* text) {
    int size = strlen(text); 
    int counts[26] = {0}; 
    for(int i = 0; i < size; i++){
        counts[text[i] - 'a']++;
    }
    int b = counts['b' - 'a'];
    int a = counts['a' - 'a'];
    int l = counts['l' - 'a']/2;
    int o = counts['o' - 'a']/2;
    int n = counts['n' - 'a'];

    int result = b;
    result = Min(result, a);
    result = Min(result, l);
    result = Min(result, o);
    result = Min(result, n);

    return result; 
}
