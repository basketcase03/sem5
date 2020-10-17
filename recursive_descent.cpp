#include<stdio.h>
#include <ctype.h> 

static char c[100];
int j=0,error=0;

//{ E-> TE', E' ->+TE' | 0, T-> FT' , T'->*FT'|0 , F-> (E) | id }

void E();
void T();
void Eprime();
void Tprime();
void F();

int main()
{
    printf("Enter input, eg-> a+a$\n");
    scanf("%s",c);
    
    E();
    
    if(c[j]=='$' && error==0)
        printf("Valid string\n");
    else
        printf("Invalid string\n");
    return 0;
}

void E()
{
     T();
     Eprime();
}
void Eprime()
{
     if(c[j]=='+')
     {
     	j++;
     	T();
     	Eprime();
     }
}
void T()
{
     F();
     Tprime();
}
void Tprime()
{
     if(c[j]=='*')
     {
        j++;
        F();
        Tprime();
    }
}
void F()
{
    if(isalnum(c[j]))
		j++;
    else if(c[j]=='(')
    {
        j++;
        E();
        if(c[j]==')')
          j++;

        else 
			error=1;
    }
    else 
		error=1;
}
