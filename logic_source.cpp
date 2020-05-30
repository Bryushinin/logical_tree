#include "logic_header.h"

char* Read()
{
    freopen("input.txt","r",stdin);
    char* st=(char *)calloc(100,sizeof(char));
    cin.getline(st,100);
    strcat(st,".");
    char* st1=(char *)calloc(100,sizeof(char));

    int i=0,j=0;
    while(st[i]!='.')
    {
        if(st[i]!=' ' && st[i]!='.')
        {st1[j]=st[i];++j;}
        ++i;
    }
    free(st);
    return(st1);
}

tree* Form(char* st);

tree* Atom(char* st)
{
    if((st[0]=='1')||(st[0]=='0'))
    {
        tree* Ans=(tree*)malloc(sizeof(tree));
        Ans->left=NULL;
        Ans->right=NULL;
        if(st[0]=='1')
            Ans->cont='1';
        else
            Ans->cont='0';
        return(Ans);
    }
    if(st[0]=='!')
    {
        tree* inv=(tree*)malloc(sizeof(tree));
        inv->right=NULL;
        inv->cont='!';
        inv->left=Atom(st+1);
        return(inv);
    }

    int i=0,k=1,j=0;
    char* temp=(char*)calloc(100,sizeof(char));
    while(k)
    {
        if(st[i+1])
            {
                if(st[i+1]=='(')
                    ++k;
                if(st[i+1]==')')
                    --k;
            }
        if(k)
        {
            temp[j]=st[i+1];
            ++j;
            ++i;
        }
    }
    return(Form(temp));

}

tree* Term(char* st)
{
    //cout<<"Term: "<<st<<endl;
    char *temp=(char*)calloc(100,sizeof(char));
    tree* Ans=(tree*)malloc(sizeof(tree));
    int i=0,j=0,k=0;
    while(st[i])
    {
        if((st[i]!='*')||(k))
        {
            if(st[i]=='(')
                ++k;
            if(st[i]==')')
                --k;
            temp[j]=st[i];
            ++j;
            ++i;
        }
        else
        {
            Ans->left=Atom(temp);
            free(temp);
            Ans->cont='*';
            ++i;
            Ans->right=Term(st+i);
            return(Ans);
        }
    }
    return(Atom(st));
}

tree* Form(char* st)
{
    //cout<<"Form: "<<st<<endl;
    char *temp=(char*)calloc(100,sizeof(char));
    tree* Ans=(tree*)malloc(sizeof(tree));
    int i=0,j=0,k=0;
    while(st[i])
    {
        if((st[i]!='+')||(k))
        {
            if(st[i]=='(')
                ++k;
            if(st[i]==')')
                --k;
            if(st[i]!=' ')
            {
                temp[j]=st[i];
                ++j;
            }
            ++i;
        }
        else
        {
            Ans->left=Term(temp);
            free(temp);
            Ans->cont='+';
            ++i;
            Ans->right=Form(st+i);
            return(Ans);
        }
    }
    return(Term(st));
}

tree* Convert(char* st)
{
    return(Form(st));
}

void Print(tree *t, int n)
{
  if (t)
  {
    Print(t->left, n + 1);
    cout << setw(n * 3)<< t->cont <<endl;
    Print(t->right, n + 1);
  }
}

int Computing2(tree* A)
{
    if(!(A->left) && !(A->right))
        return(A->cont - '0');
    if(!(A->right))
        return((Computing2(A->left)+1)%2);
    if((A->cont)=='+')
        return(Computing2(A->left) || Computing2(A->right));
    return(Computing2(A->left) && Computing2(A->right));
}

