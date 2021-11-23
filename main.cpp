#include <iostream>
#include "tree.h"
using namespace std;
char mas[12] = {'0','1','2','3','4','5','6','7','8','9'};
char ss[4] = {'+','/','*','-'};
tree* form(char *s,int& i);
tree *term(char *s,int& i);
tree *atom(char *s,int& i);
tree *t1;

double pod(double a,double b,char c)
{
    switch(c)
    {
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        return a / b;
        break;

    }
}
int inch(char k)
{
    for(int j = 0; j < 4; j++)
    {
        if(k == ss[j]) return 1;

    }
    return 0;
}
int in(char k)
{
    for(int j = 0; j < 10; j++)
    {
        if(k == mas[j]) return 1;
    }
    return 0;

}

tree* form(char *s,int& i)
{
    while(i < strlen(s))
    {
        if(s[i] == ')')
        {
            i++;
            return t1;
        }
        else
        {
            t1 = term(s,i);
            if(s[i] == '+' || s[i] == '-')
            {
                tree *p = new tree;
                p->id = s[i];
                p->left = t1;
                i++;
                t1 = term(s,i);
                p->right = t1;
                t1 = p;
            }
        }

    }
    return t1;
}
tree *term(char *s,int& i)
{
    t1 = atom(s,i);
    while(s[i] == '*' || s[i] == '/')
    {
        tree *p = new tree;
        p->id = s[i];
        p->left = t1;
        i++;
        t1 = atom(s,i);
        p->right = t1;
        t1 = p;
    }
    return t1;
}
tree *atom(char *s,int& i)
{
    if(in(s[i]))
    {

        t1 = new tree;
        t1->id = s[i];
        t1->left = NULL;
        t1->right = NULL;
        i++;
    }
    else if(s[i] == '(')
    {
        i++;
        t1 = form(s,i);
    }
    return t1;
}
int islist(tree *root)
{
    if(root->right == NULL && root->left == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
double result(tree *root)
{
    char a[2];
    char b[2];
    double a1,b1,c1;
    if(islist(root->right) && islist(root->left))
    {
        a[0] = root->left->id;
        a[1] = '\0';
        a1 = atoi(a);
        b[0] = root->right->id;
        b[1] = '\0';
        b1  = atoi(b);
        return pod(a1,b1,root->id);
    }
    else if(islist(root->right) && !(islist(root->left)))
    {
        b[0] = root->right->id;
        b[1] = '\0';
        b1  = atoi(b);
        return pod(result(root->left),b1,root->id);
    }
    else if(!(islist(root->right)) && islist(root->left))
    {
        a[0] = root->left->id;
        a[1] = '\0';
        a1 = atoi(a);
        return pod(a1,result(root->right),root->id);
    }
    else
    {
        return pod(result(root->left),result(root->right),root->id);
    }
}
int main()
{
    char s[100];
    cin >> s;
    int i = 0;
    tree *q = form(s,i);
    show(q,0);
    double r = 0;
    r = result(q);
    cout << "r = " << r << endl;
    return 0;
}
