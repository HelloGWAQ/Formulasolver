#include<stdio.h>
#include<string.h>

int lcoefx=0,lcons=0,rcoefx=0,rcons=0,mnls;
float sol;
char lformula[40];
char rformula[40];

int linducer()
{
    int xsgn=0,indunum=0,porm=1,coefx=0,cons=0,ones=0,i;
    for(i=0;i<=strlen(lformula);i++)
    {
        if(lformula[i]=='x')
        {
            if(indunum==0)
            {
                indunum=1;
            }
            xsgn=1;
        }
        else if(lformula[i]=='+'||lformula[i]=='-'||lformula[i]=='\0')
        {
            if(xsgn==1)
            {
                coefx=coefx+porm*indunum;
                xsgn=0;
            }
            else if(xsgn==0)
            {
                cons=cons+porm*indunum;
            }
            indunum=0;
            if(lformula[i]=='+')
            {
                porm=1;
            }
            else if(lformula[i]=='-')
            {
                porm=-1;
            }
        }
        else
        {
            ones=(int)lformula[i]-48;
            indunum=10*indunum+ones;
        }
    }
    lcoefx=coefx;
    lcons=cons;
    return 0;
}

int rinducer()
{
    int xsgn=0,indunum=0,porm=1,coefx=0,cons=0,ones=0,i;
    for(i=0;i<=strlen(rformula);i++)
    {
        if(rformula[i]=='x')
        {
            if(indunum==0)
            {
                indunum=1;
            }
            xsgn=1;
        }
        else if(rformula[i]=='+'||rformula[i]=='-'||rformula[i]=='\0')
        {
            if(xsgn==1)
            {
                coefx=coefx+porm*indunum;
                xsgn=0;
            }
            else if(xsgn==0)
            {
                cons=cons+porm*indunum;
            }
            indunum=0;
            if(rformula[i]=='+')
            {
                porm=1;
            }
            else if(rformula[i]=='-')
            {
                porm=-1;
            }
        }
        else
        {
            ones=(int)rformula[i]-48;
            indunum=10*indunum+ones;
        }
    }
    rcoefx=coefx;
    rcons=cons;
    return 0;
}

int main()
{
    while(1){
    printf("Please input your formula(E.g. 2x+6=8x-7)\n");
    scanf("%40[^=]=%40s",lformula,rformula);
    mnls=linducer();
    mnls=rinducer();
    sol=(float)(rcons-lcons)/(lcoefx-rcoefx);
    printf("x=%f\n",sol);
    getchar();
    getchar();
    }
    return 0;
}