#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int isReservedInProgramming(const char buffer[])
{
    const char reservedKeywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                                           "do", "double", "else", "enum", "extern", "float", "for", "goto",
                                           "if", "int", "long", "register", "return", "short", "signed",
                                           "sizeof", "static", "switch", "struct", "typedef", "union",
                                           "unsigned", "void", "volatile", "while"};
    for (int i = 0; i < 32; ++i)
    {
        if (strcmp(reservedKeywords[i], buffer) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void display(string inputCode)
{

    char math_op[] = "+-*/=", logical_op[] = "><", other[] = ",;\(){}[]'':";

    int mark[256] = {0};

    int i, j = 0, kc = 0, ic = 0, lc = 0, mc = 0, nc = 0, oc = 0, aaa = 0;

    vector<string> k;
    vector<char> id;
    vector<char> lo;
    vector<char> ma;
    vector<string> nu;
    vector<char> ot;

    char buffer[15];
    char b[30];

    for (char ch : inputCode)
    {

        for (i = 0; i < sizeof(other) - 1; ++i)
        {
            if (ch == other[i])
            {
                if (mark[ch] != 1)
                {
                    ot.push_back(ch);
                    mark[ch] = 1;
                    ++oc;
                }
            }
        }

        for (i = 0; i < sizeof(math_op) - 1; ++i)
        {
            if (ch == math_op[i])
            {
                if (mark[ch] != 1)
                {
                    ma.push_back(ch);
                    mark[ch] = 1;
                    ++mc;
                }
            }
        }

        for (i = 0; i < sizeof(logical_op) - 1; ++i)
        {
            if (ch == logical_op[i])
            {
                if (mark[ch] != 1)
                {
                    lo.push_back(ch);
                    mark[ch] = 1;
                    ++lc;
                }
            }
        }

        if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '.' || ch == ' ' || ch == '\n' || ch == ';')
        {
            if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '.')
            {
                b[aaa++] = ch;
            }
            if ((ch == ' ' || ch == '\n' || ch == ';') && (aaa != 0))
            {
                b[aaa] = '\0';
                aaa = 0;
                char arr[30];
                strcpy(arr, b);
                nu.push_back(arr);
                ++nc;
            }
        }

        if (isalnum(ch))
        {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && (j != 0))
        {
            buffer[j] = '\0';
            j = 0;
            if (isReservedInProgramming(buffer) == 1)
            {
                k.push_back(buffer);
                ++kc;
            }
            else
            {
                if (buffer[0] >= 'a' && buffer[0] <= 'z')
                {
                    if (mark[buffer[0]] != 1)
                    {
                        id.push_back(buffer[0]);
                        ++ic;
                        mark[buffer[0]] = 1;
                    }
                }
            }
        }
    }

    cout << "Reserved Keywords: ";
    for (const string &keyword : k)
    {
        cout << keyword << ", ";
    }
    cout << "\n";

    cout << "Identifiers: ";
    for (char identifier : id)
    {
        cout << identifier << ", ";
    }
    cout << "\n";

    cout << "Math Operators: ";
    for (char mathOperator : ma)
    {
        cout << mathOperator << ", ";
    }
    cout << "\n";

    cout << "Logical Operators: ";
    for (char logicalOperator : lo)
    {
        cout << logicalOperator << ", ";
    }
    cout << "\n";

    cout << "Numerical Values: ";
    for (const string &numericValue : nu)
    {
        cout << numericValue << ", ";
    }
    cout << "\n";

    cout << "Others: ";
    for (char otherChar : ot)
    {
        cout << otherChar << " ";
    }
    cout << "\n";
}

int main()
{


    string inputCode = "int a, b, c ; float d, e;   a = b = 5;  c = 6;  if ( a > b) {	c = a - b; e = d - 2.0;} else{d = e + 6.0; b = a + c;}";
    display(inputCode);

    return 0;
}
