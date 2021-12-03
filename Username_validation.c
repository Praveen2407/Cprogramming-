#include <stdio.h>
#include <string.h>

//using namespace std;


int validate(char * username)
{
    //int special = 0, l = username.length();
    int special = 0, l= strlen(username);
    //check length is 0 or more than 30
    if (l == 0 || l > 30)
        return 0;

    for (int i = 0; i < l; i++)
    {
        char first = username[0];
        char last = username[l-1];
        char s = username[i];
        if (s == ' ' || !(isalpha(first)))
            return 0;
        if( last == '_')
            return 0;
        //characters other than alphabets and numbers
        if (isalnum(s))
            continue;
        else
        {
            //periods and underscore allowed but only one
            if (s == '_' )
            {
                special++;
                if (special > 1)
                    return 0;
            }
            else
                return 0;
        }
    }
    return 1;
}
 int main()
{
    printf("%d\n", validate("Mike_Standish")); // Valid username
    printf("%d", validate("Mike Standish")); // Invalid username
    return 0;
}
