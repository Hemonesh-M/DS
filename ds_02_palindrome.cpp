#include <iostream>
using namespace std;
int main()
{
    string str;
    cout<<"Enter The String:";
    cin >> str;
    int size = str.length();
    int i = 0, j = size - 1;
    bool flag = 0;
    while (i <= j)
    {
        if (str[i] != str[j])
        {
            cout << "String Is Not Palindrome" << endl;
            flag = 1;
            break;
        }
        i++;
        j--;
    }

    if (flag == 0)
    {
        cout << "String Is Palindrome" << endl;
    }

    return 0;
}
