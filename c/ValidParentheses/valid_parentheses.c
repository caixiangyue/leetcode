/**
 * Author: Xiangyue Cai
 * Date: 2019-07-02
 */

bool isValid(char *s){
    int len = strlen(s);
    if(len == 0)
        return true;

    char ch[len];
    int counter = 0;
    for (int i = 0 ; i < len; ++i)
    {
        switch(s[i])
        {
            case '(':
            case '[':
            case '{': ch[counter++] = s[i]; break;
            case ')':if (counter == 0 || '(' != ch[--counter]) return false;break;
            case ']':if (counter == 0 || '[' != ch[--counter]) return false;break;
            case '}':if (counter == 0 || '{' != ch[--counter]) return false;break;
            default:return false;
        }
    }
    if(counter == 0)
        return true;
    return false;
}