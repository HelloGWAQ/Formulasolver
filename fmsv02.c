#include<stdio.h>
#include<string.h>

int lcoefx=0,lcons=0,rcoefx=0,rcons=0,mnls;
float sol;
char lformula[60];
char rformula[60];

int linducer()
{
    int xsgn=0,indunum=0,porm=1,coefx=0,cons=0,ones=0,i;
    int kuohao[11]={1,1,1,1,1,1,1,1,1,1,1};
    int kuo=0;
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
                coefx=coefx+porm*indunum*kuohao[1]*kuohao[2]*kuohao[3]*kuohao[4]*kuohao[5]*kuohao[6]*kuohao[7]*kuohao[8]*kuohao[9]*kuohao[10];
                xsgn=0;
            }
            else if(xsgn==0)
            {
                cons=cons+porm*indunum*kuohao[1]*kuohao[2]*kuohao[3]*kuohao[4]*kuohao[5]*kuohao[6]*kuohao[7]*kuohao[8]*kuohao[9]*kuohao[10];
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
        else if(lformula[i]=='(')
        {
            if(indunum==0)
            {
                indunum=1;
            }
            kuo+=1;
            kuohao[kuo]=indunum*porm;
            indunum=0;
            porm=1;
        }
        else if(lformula[i]==')')
        {
            if(xsgn==1)
            {
                coefx=coefx+porm*indunum*kuohao[1]*kuohao[2]*kuohao[3]*kuohao[4]*kuohao[5]*kuohao[6]*kuohao[7]*kuohao[8]*kuohao[9]*kuohao[10];
                xsgn=0;
            }
            else if(xsgn==0)
            {
                cons=cons+porm*indunum*kuohao[1]*kuohao[2]*kuohao[3]*kuohao[4]*kuohao[5]*kuohao[6]*kuohao[7]*kuohao[8]*kuohao[9]*kuohao[10];
            }
            indunum=0;
            kuohao[kuo]=1;
            kuo-=1;
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
    int kuohao[11]={1,1,1,1,1,1,1,1,1,1,1};
    int kuo=0;
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
                coefx=coefx+porm*indunum*kuohao[1]*kuohao[2]*kuohao[3]*kuohao[4]*kuohao[5]*kuohao[6]*kuohao[7]*kuohao[8]*kuohao[9]*kuohao[10];
                xsgn=0;
            }
            else if(xsgn==0)
            {
                cons=cons+porm*indunum*kuohao[1]*kuohao[2]*kuohao[3]*kuohao[4]*kuohao[5]*kuohao[6]*kuohao[7]*kuohao[8]*kuohao[9]*kuohao[10];
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
        else if(rformula[i]=='(')
        {
            if(indunum==0)
            {
                indunum=1;
            }
            kuo+=1;
            kuohao[kuo]=indunum*porm;
            indunum=0;
            porm=1;
        }
        else if(rformula[i]==')')
        {
            if(xsgn==1)
            {
                coefx=coefx+porm*indunum*kuohao[1]*kuohao[2]*kuohao[3]*kuohao[4]*kuohao[5]*kuohao[6]*kuohao[7]*kuohao[8]*kuohao[9]*kuohao[10];
                xsgn=0;
            }
            else if(xsgn==0)
            {
                cons=cons+porm*indunum*kuohao[1]*kuohao[2]*kuohao[3]*kuohao[4]*kuohao[5]*kuohao[6]*kuohao[7]*kuohao[8]*kuohao[9]*kuohao[10];
            }
            indunum=0;
            kuohao[kuo]=1;
            kuo-=1;
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
    scanf("%60[^=]=%60s",lformula,rformula);
    mnls=linducer();
    mnls=rinducer();
    sol=(float)(rcons-lcons)/(lcoefx-rcoefx);
    printf("x=%f\n",sol);
    getchar();
    getchar();
    }
    return 0;
}