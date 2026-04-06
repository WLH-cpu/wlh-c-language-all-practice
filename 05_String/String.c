#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 255

typedef struct
{
    char ch[MAXLEN+1];
    int length;
}SString;

int Index_BF(SString S,SString T,int pos)
{
    int i=pos,j=1;
    while(i<=S.length&&j<=T.length)
    {
        if(S.ch[i]==T.ch[j]){i++;j++;}
        else
        {
            i=i-j+2;
            j=1;
        }
    }
    if(j>T.length) return i-T.length;
    else return 0;
}

void get_next(SString T,int* next)
{
    int i=1,j=0;
    next[1]=0;
    while(i<T.length)
    {
        if(j==0||T.ch[i]==T.ch[j])
        {
            next[++i]=++j;
        }
        else 
        {
            j=next[j];
        }
    }
}

void get_nextval(SString T,int* nextval)
{
    int i=1,j=0;
    nextval[1]=0;
    while(i<T.length)
    {
        if(j==0||T.ch[i]==T.ch[j])
        {
            i++,j++;
            if(T.ch[i]!=T.ch[j])
            nextval[i]=j;
            else
            nextval[i]=nextval[j];
        }
        else
        {
            j=nextval[j];
        }
    }
}

int Index_KMP(SString S,SString T,int pos)
{
    int i=pos,j=1;
    int next[MAXLEN+1];
    get_next(T,next);
    while(i<=S.length&&j<=T.length)
    {
        if(j==0||S.ch[i]==T.ch[j]) {i++,j++;}
        else
        {
            j=next[j];
        }
    }
    if(j>T.length) return i-T.length;
    else return 0;
}

void StrAssign(SString* S,char* str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        S->ch[i+1]=str[i];
    }
    S->length=i;
}

int main( )
{
    SString S,T;
    StrAssign(&S,"ababcabcacbab");
    StrAssign(&T,"abcac");
    printf("BF:%d\n",Index_BF(S,T,1));
    printf("KMP:%d\n",Index_KMP(S,T,1));
    StrAssign(&T,"xyz");
    printf("BF:%d\n",Index_BF(S,T,1));
    printf("KMP:%d\n",Index_KMP(S,T,1));

    return 0;
}