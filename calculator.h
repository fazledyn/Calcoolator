#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//  constants
#define PI 2*(acos(0))
#define e exp(1)
//  screen resolution
#define dxBox 360
#define dyBox 535
#define space 10
#define dX 60
#define dY 30

//-------------------------------------

int ii,jj;
int length;
int dsmode=1;
int calcMode=1,modeClicked=0;
int tempo=calcMode;
int error=0;
int equalCount=0,equalCount2=0;

double a1, b1, c1, a2, b2, c2, x, y, a, b, c, x1, x2;
double left, right;
double operands[500];

long long lob,hor;

char *buffer;
char query[12] = "Enter a1: ";
char query2[12] = "Enter a: ";
char operators[500];
char mode2strx[30], m2x[30];
char mode2stry[30], m2y[30];
char mode3strx1[30], m3x1[30];
char mode3strx2[30], m3x2[30];

//-------------------------------------

double shade = 100;
double fontCol;

double  colorRed;
double  colorGreen;
double  colorBlue;

double  sColorR     = 100;
double  sColorG     = 100;
double  sColorB     = 100;

double  scrRed      = 0;
double  scrGreen    = 0;
double  scrBlue     = 0;

double  bColorR     = 60;
double  bColorG     = 60;
double  bColorB     = 60;

//-------------------------------------

int X = 10, Y = 10;
int mode,len,i;
int calcButton[9][5], TempColChange[9][5];
int row, col;
int drmode = 1;
int theme_clicked = 0, num = 1, eraseOptions = 0, idx;

char lastKey = 0;
char str[100], str2[100];
char answer[40];
char answer_S[40];

double ang=(2*(acos(0))/180);
double angle;
double ans;
double temp;

//-------------------------------------


long long GCD(long long a, long long b)
{
    long long gcd,t;

    if(a==0)
        gcd=b;

    else if(b==0)
        gcd=a;

    else
    {
        while(b!=0)
        {
            t=b;
            b=a%b;
            a=t;
        }
        gcd=a;
    }

    return gcd;
}

void DtoS(double number,char s_t_r[])
{
    FILE *d_to_s;
    d_to_s=fopen("Result_S.txt","w");

    int isNegative=1;
    if(number<0)
        {
            number*=-1;
            isNegative=-1;
        }
    long long gcd;
    lob=round(number*10000000000);
    hor=10000000000;

    while(GCD(lob,hor)!=1)
        {
            gcd=GCD(lob,hor);
            lob/=gcd;
            hor/=gcd;
        }
    if(hor==1)
            fprintf(d_to_s,"%I64d",lob*isNegative);
    else
            fprintf(d_to_s,"%I64d/%I64d",lob*isNegative,hor);

    fclose(d_to_s);

    d_to_s=fopen("Result_S.txt","r");
    fscanf(d_to_s,"%s",s_t_r);
    fclose(d_to_s);

    return;
}

void typeCast(char s_t_r[])
{
    int lll=strlen(s_t_r)-1;

    if(s_t_r[lll]=='0'){
        s_t_r[lll]=0;
        if(s_t_r[lll-1]=='0'){
            s_t_r[lll-1]=0;
            if(s_t_r[lll-2]=='0'){
                s_t_r[lll-2]=0;
                if(s_t_r[lll-3]=='0'){
                    s_t_r[lll-3]=0;
                    if(s_t_r[lll-4]=='0'){
                        s_t_r[lll-4]=0;
                        if(s_t_r[lll-5]=='0'){
                            s_t_r[lll-5]=0;
                            if(s_t_r[lll-6]=='0'){
                                s_t_r[lll-6]=0;
                                if(s_t_r[lll-7]=='0'){
                                    s_t_r[lll-7]=0;
                                    if(s_t_r[lll-8]=='0'){
                                        s_t_r[lll-8]=0;
                                        if(s_t_r[lll-9]=='0'){
                                            s_t_r[lll-9]=0;
                                            s_t_r[lll-10]=0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}

void mode_2()
{
    error=0;
    if((a1/a2)==(b1/b2))
        error=2;
    x=((b2*c1)-(b1*c2))/((b2*a1)-(b1*a2));
    y=((c2*a1)-(c1*a2))/((b2*a1)-(b1*a2));
    if(!x) x=0;
    if(!y) y=0;
    FILE *f;
    f=fopen("mode2.txt","w");
    fprintf(f,"x=%.10lf\ny=%.10lf",x,y);
    fclose(f);
    f=fopen("mode2.txt","r");
    fscanf(f,"%s",mode2strx);
    fscanf(f,"%s",mode2stry);
    fclose(f);
    if(strcmp(mode2strx,"x=-1.#IND000000")==0)  //When Nothing is Given in a1,b1,c1,a2,b2 & c2
        error=2;
    typeCast(mode2strx);
    typeCast(mode2stry);
    DtoS(x,m2x);
    DtoS(y,m2y);

    return;
}

void mode_3()
{
    error=0;
    if(((b*b)-(4*a*c))<0)
        error=3;
    else if(a==0)
        error=2;
    x1=(-b+sqrt((b*b)-(4*a*c)))/(2*a);
    x2=(-b-sqrt((b*b)-(4*a*c)))/(2*a);
    if(!x1) x1=0;
    if(!x2) x2=0;
    FILE *f;
    f=fopen("mode3.txt","w");
    fprintf(f,"x1=%.10lf\nx2=%.10lf",x1,x2);
    fclose(f);
    f=fopen("mode3.txt","r");
    fscanf(f,"%s",mode3strx1);
    fscanf(f,"%s",mode3strx2);
    fclose(f);
    typeCast(mode3strx1);
    typeCast(mode3strx2);
    DtoS(x1,m3x1);
    DtoS(x2,m3x2);

    return;
}

void calcuMode2(int n)
{
    if(equalCount==0)
        {
            iText(21,480,query,GLUT_BITMAP_HELVETICA_18);
            iText(101,480,str,GLUT_BITMAP_HELVETICA_18);
            a1=strtod(str,&buffer);
        }
    else if(equalCount==1)
        {
            strcpy(query,"Enter b1: ");
            iText(21,480,query,GLUT_BITMAP_HELVETICA_18);
            iText(101,480,str,GLUT_BITMAP_HELVETICA_18);
            b1=strtod(str,&buffer);
        }
    else if(equalCount==2)
        {
            strcpy(query,"Enter c1: ");
            iText(21,480,query,GLUT_BITMAP_HELVETICA_18);
            iText(101,480,str,GLUT_BITMAP_HELVETICA_18);
            c1=strtod(str,&buffer);
        }
    else if(equalCount==3)
        {
            strcpy(query,"Enter a2: ");
            iText(21,480,query,GLUT_BITMAP_HELVETICA_18);
            iText(101,480,str,GLUT_BITMAP_HELVETICA_18);
            a2=strtod(str,&buffer);
        }
    else if(equalCount==4)
        {
            strcpy(query,"Enter b2: ");
            iText(21,480,query,GLUT_BITMAP_HELVETICA_18);
            iText(101,480,str,GLUT_BITMAP_HELVETICA_18);
            b2=strtod(str,&buffer);
        }
    else if(equalCount==5)
        {
            strcpy(query,"Enter c2: ");
            iText(21,480,query,GLUT_BITMAP_HELVETICA_18);
            iText(101,480,str,GLUT_BITMAP_HELVETICA_18);
            c2=strtod(str,&buffer);
        }
    else if(equalCount==6)
        {
            mode_2();
            if(error==2)
                iText(230,390,"Math Error!",GLUT_BITMAP_HELVETICA_18);
            else{
                    if(n==1||lob>9999||hor>9999){
                        iText(340-(10*strlen(mode2strx)),413,mode2strx,GLUT_BITMAP_HELVETICA_18);
                        iText(340-(10*strlen(mode2stry)),390,mode2stry,GLUT_BITMAP_HELVETICA_18);
                    }
                    else{
                        iText(320-(10*strlen(m2x)),413,"x=",GLUT_BITMAP_HELVETICA_18);
                        iText(320-(10*strlen(m2y)),390,"y=",GLUT_BITMAP_HELVETICA_18);
                        iText(340-(10*strlen(m2x)),413,m2x,GLUT_BITMAP_HELVETICA_18);
                        iText(340-(10*strlen(m2y)),390,m2y,GLUT_BITMAP_HELVETICA_18);
                    }
                }

        }
    else
        {
            equalCount=0;
            strcpy(query,"Enter a1: ");
        }
    return;
}

void calcuMode3(int n)
{
    if(equalCount2==0)
        {
            iText(21,480,query2,GLUT_BITMAP_HELVETICA_18);
            iText(91,480,str,GLUT_BITMAP_HELVETICA_18);
            a=strtod(str,&buffer);
        }
    else if(equalCount2==1)
        {
            strcpy(query2,"Enter b: ");
            iText(21,480,query2,GLUT_BITMAP_HELVETICA_18);
            iText(91,480,str,GLUT_BITMAP_HELVETICA_18);
            b=strtod(str,&buffer);
        }
    else if(equalCount2==2)
        {
            strcpy(query2,"Enter c: ");
            iText(21,480,query2,GLUT_BITMAP_HELVETICA_18);
            iText(91,480,str,GLUT_BITMAP_HELVETICA_18);
            c=strtod(str,&buffer);
        }
    else if(equalCount2==3)
        {
            mode_3();
            if(error==2)
                iText(230,390,"Math Error!",GLUT_BITMAP_HELVETICA_18);
            else if(error==3)
                iText(200,390,"Imaginary Roots!",GLUT_BITMAP_HELVETICA_18);
            else{
                    if(n==1||lob>9999||hor>9999){
                        iText(340-(10*strlen(mode3strx1)),413,mode3strx1,GLUT_BITMAP_HELVETICA_18);
                        iText(340-(10*strlen(mode3strx2)),390,mode3strx2,GLUT_BITMAP_HELVETICA_18);
                    }
                    else{
                        iText(310-(10*strlen(m3x1)),413,"x1=",GLUT_BITMAP_HELVETICA_18);
                        iText(310-(10*strlen(m3x2)),390,"x2=",GLUT_BITMAP_HELVETICA_18);
                        iText(340-(10*strlen(m3x1)),413,m3x1,GLUT_BITMAP_HELVETICA_18);
                        iText(340-(10*strlen(m3x2)),390,m3x2,GLUT_BITMAP_HELVETICA_18);
                    }
                }

        }
    else
        {
            equalCount2=0;
            strcpy(query2,"Enter a: ");
        }
    return;
}

int factorial(int n)
{
    int i,fac=1;
        for(i=1;i<=n;i++)
            fac*=i;

    return fac;
}

void find_left_right()  //Finding Left and Right Values for a Specific Operator
{
    left=0,right=0;
    for(jj=ii-1;operators[jj]=='0';jj--)
        if(jj<0)                                         // jj<0  Means Array's Index is Negative
            break;

    for(jj++;operators[jj]=='0';jj++)
        {
            if(operands[jj]!=0)
            {
                left=operands[jj];
                ///printf("\n%lf ",left);
                operands[jj]=0;
            }
        }

    operators[jj]='0';

    for(jj++;operators[jj]=='0'&&jj!=length;jj++)
        {
            if(operands[jj]!=0)
            {
                right=operands[jj];
                ///printf("%lf\n",right);
                operands[jj]=0;
            }
        }

        return;
}


void operation(int init,int limit)
{
    for(ii=init;ii<limit;ii++)              //10's Power
    {
        if(operators[ii]=='E')
            {
                find_left_right();
                operands[jj-1]=left*pow(10,right);
            }
    }

    for(ii=init;ii<limit;ii++)              //Power
    {
        if(operators[ii]=='^')
            {
                find_left_right();
                operands[jj-1]=pow(left,right);
            }
    }

    for(ii=init;ii<limit;ii++)              //Factorial
    {
        if(operators[ii]=='!')
            {
                find_left_right();
                if((int)left!=left||left<0)
                    error=2;
                operands[jj-1]=factorial(left);
            }
    }

    for(ii=init;ii<limit;ii++)              //Division
    {
        if(operators[ii]=='/')
            {
                find_left_right();
                if(right==0)
                    error=2;
                operands[jj-1]=left/right;
            }
    }

    for(ii=init;ii<limit;ii++)              //Multiplication
    {
        if(operators[ii]=='*')
            {
                find_left_right();
                operands[jj-1]=left*right;
            }
    }

    for(ii=init;ii<limit;ii++)
    {
        if(operators[ii]=='+')                  //Addition
            {
                find_left_right();
                operands[jj-1]=left+right;
            }
        else if(operators[ii]=='-')             //Subtraction
            {
                find_left_right();
                operands[jj-1]=left-right;
            }
    }

    return;
}


void braces()
{
    int m,idxopen,idxclose;

    for(m=0;m<length;m++)
        {
        if(operators[m]==')')
            {
            idxclose=m;
            for(m--;;m--)
            {
                if(operators[m]=='('||operators[m]=='S'||operators[m]=='C'||operators[m]=='T'
                        ||operators[m]=='s'||operators[m]=='c'||operators[m]=='t'
                        ||operators[m]=='L'||operators[m]=='l'||operators[m]=='r')
                            // '(' or S/C/T/s/c/t/L/l/r
                            // Will Surely Be Found in a VALID Expression Before ')'
                {
                    idxopen=m;
                    break;
                }
            }
            m=idxclose;
            operation(idxopen+1,idxclose);

            if(operators[idxopen]=='S')                  //sin(
                    {
                        angle=ang*operands[idxclose-1];
                        operands[idxclose-1]=0;
                        operands[idxclose]=sin(angle);
                    }
            else if(operators[idxopen]=='C')            //cos(
                    {
                        angle=ang*operands[idxclose-1];
                        operands[idxclose-1]=0;
                        operands[idxclose]=cos(angle);
                    }
            else if(operators[idxopen]=='T')            //tan(
                    {
                        angle=ang*operands[idxclose-1];
                        temp=fabs(angle);
                        temp/=PI;
                        temp-=(int)temp;
                        if(temp==0.5)
                            error=2;
                        operands[idxclose-1]=0;
                        operands[idxclose]=tan(angle);
                    }
            else if(operators[idxopen]=='s')                    //sin^-1(
                    {
                        if(operands[idxclose-1]<-1||operands[idxclose-1]>1)
                            error=2;
                        operands[idxclose]=(asin(operands[idxclose-1]))/ang;
                        operands[idxclose-1]=0;
                    }
            else if(operators[idxopen]=='c')                    //cos^-1(
                    {
                        if(operands[idxclose-1]<-1||operands[idxclose-1]>1)
                            error=2;
                        operands[idxclose]=(acos(operands[idxclose-1]))/ang;
                        operands[idxclose-1]=0;
                    }
            else if(operators[idxopen]=='t')                    //tan^-1(
                    {
                        operands[idxclose]=(atan(operands[idxclose-1]))/ang;
                        operands[idxclose-1]=0;
                    }
            else if(operators[idxopen]=='L')                    //log(
                    {
                        if(operands[idxclose-1]<=0)
                            error=2;
                        operands[idxclose]=log10(operands[idxclose-1]);
                        operands[idxclose-1]=0;
                    }
            else if(operators[idxopen]=='l')                    //ln(
                    {
                        if(operands[idxclose-1]<=0)
                            error=2;
                        operands[idxclose]=log(operands[idxclose-1]);
                        operands[idxclose-1]=0;
                    }
            else if(operators[idxopen]=='r')                    //sqrt(
                    {
                        if(operands[idxclose-1]<0)
                            error=2;
                        operands[idxclose]=sqrt(operands[idxclose-1]);
                        operands[idxclose-1]=0;
                    }
            else                                                //Do Nothing
                ;


            if(idxopen==0)
                  operators[idxopen]='0';
            else if(operators[idxopen-1]=='0')
                  operators[idxopen]='*';         //Placing * if There is No Operator Before ( & Other Bracketed Operators
            else
                  operators[idxopen]='0';


            if(idxclose==length-1)
                  operators[idxclose]='0';
            else if(operators[idxclose+1]=='0')
                  operators[idxclose]='*';         //Placing * if There is No Operator After )
            else
                  operators[idxclose]='0';
            }
        }
    return ;
}


void calculator()       //Will Be Called in printFile() Function
{
    FILE *expression,*result;

    expression=fopen("Expression.txt","r");

    char strTemp[40];
    char *ptr;

    for(ii=0; ;ii++)                    //Seperating Operands and Operators
    {
        if(feof(expression))                //If EOF is Found, Stop Scanning
            break;

        else
        {
            fscanf(expression,"%s",strTemp);

            if((strTemp[0]>='0'&& strTemp[0]<='9')||(strTemp[0]=='.'))  //Numbers
                {
                operands[ii]=strtod(strTemp,&ptr);
                operators[ii]='0';
                }
            else if( !( strcmp("A",strTemp) ) )         //Ans
                {
                operands[ii]=ans;
                operators[ii]='0';
                }
            else if( !( strcmp("e",strTemp) ) )         //e
                {
                operands[ii]=e;
                operators[ii]='0';
                }
            else if( !( strcmp("pi",strTemp) ) )         //pi
                {
                operands[ii]=PI;
                operators[ii]='0';
                }
            else        //sin(, cos(, tan(, sin^-1(, cos^-1(, tan^-1(, log(, ln(, sqrt(,
                        // !, (, ), E, ^, /, *, +, -
                {
                operands[ii]=0;
                operators[ii]=strTemp[0];
                }
        }
    }

    fclose(expression);

    length=ii;

///--------------New-------------------

    int k,minuscount;
    int prev_optr;

    for(k=0;k<length;k++)           //Handles Cases Like 8--7+--+7=22 etc.(Only for Multiple + & - Signs)
    {
        minuscount=0;
        prev_optr=0;

        if(operators[k]=='-'||operators[k]=='+')
        {
           if(operators[k-1]=='E'||operators[k-1]=='^'||operators[k-1]=='/'||operators[k-1]=='*')
                prev_optr=1;

            while(operators[k]=='-'||operators[k]=='+')
                {
                    if(operators[k]=='-')
                    {
                        minuscount++;
                        operators[k]='0';
                    }
                    else
                        operators[k]='0';

                k++;
                }
                k--;
            if(prev_optr==0)   //Means No "E" / "^" / "/" / "*" was Before the Starting +/ -
            {
                if(minuscount%2==0)
                    operators[k]='+';
                else
                    operators[k]='-';
            }
    ///----------

            else        //Means Any of "E" / "^" / "/" / "*" was Before the Starting +/ -
            {
                if(minuscount%2==0)
                    {
                        operands[k+1]*=1;
                        operators[k]='0';
                    }
                else
                    {
                        operands[k+1]*=-1;
                        operators[k]='0';
                    }
            }

    ///----------
        }
    }
///------------------------------------

    for(k=0;k<length;k++)        //Handles Cases Like 5pi as 5*pi
    {
        //if(operands[k]==(2*(acos(0))) && operators[k-1]=='0')
        if(operands[k]==PI && operators[k-1]=='0')
        {
            operands[k]=PI*operands[k-1];
            operands[k-1]=0;
        }
    }
    for(k=0;k<length;k++)           //Handles Cases Like 5e as 5*e
    {
        if(operands[k]==e && operators[k-1]=='0')
        {
            operands[k]=e*operands[k-1];
            operands[k-1]=0;
        }
    }
//-------New----------
    for(k=0;k<length;k++)           //Handles Cases Like 5Ans as 5*Ans
    {
        if(operands[k]==ans && operators[k]=='0' && operators[k-1]=='0')
        {
            operands[k]=ans*operands[k-1];
            operands[k-1]=0;
        }
    }
//--------------------


    braces();           //Brackets,Trigonometric,Logarithmic Operations
    operation(0,length);

    fclose(expression);
    result=fopen("Result.txt","w");

    //This Will Handle Cases Like  (7), Which Will Print "7" As Output
    for(jj=0;jj<length;jj++)
        {
            if(operands[jj]!=0)
            {
                ans=operands[jj];
                break;
            }
            else
                ans=0;
        }

    fprintf(result,"%.10f",ans);
    fclose(result);
    result=fopen("Result.txt","r");
    fscanf(result,"%s",answer);


    typeCast(answer);


    fclose(result);
    DtoS(ans,answer_S);


    if(strlen(str)==0){     //Won't Show Ans Empty Expression is Entered
        answer[0]=0;
        answer_S[0]=0;
    }

    if(!strcmp(answer,"-0"))
        strcpy(answer,"0");


    if(error==1){
        strcpy(answer,"Syntax Error!");
        strcpy(answer_S,"Syntax Error!");
    }
    else if(error==2){
        strcpy(answer,"Math Error!");
        strcpy(answer_S,"Math Error!");
    }
    error=0;            //Making the Value of error ZERO Again

    return;
}

//--------After GUI Portion---------
///--------------------------------------------------------------------
//--------Before GUI Portion--------

void printFile(char str[]){

    FILE *fptr;
    fptr=fopen("Expression.txt","w");

    int x;

    for(x=0;x<strlen(str);x++)           //Assuming Nothing Fancy Has Been Written Like, "rabid(66+69)" :3
    {
        if(str[x]=='*'&&str[x+1]=='1'&&str[x+2]=='0'&&str[x+3]=='^')   //*10^ = E
        {
            fprintf(fptr,"\nE");
            x+=3;
        }
        else if(str[x]=='l')
        {
            if(str[x+2]=='(')       //ln( = l
            {
                fprintf(fptr,"\nl");
                x+=2;
            }
            else                    //log( = L
            {
                fprintf(fptr,"\nL");
                x+=3;
            }
        }
        else if(str[x]=='A'&&str[x+1]=='n'&&str[x+2]=='s')  //Ans
        {
            fprintf(fptr,"\nA");
            x+=2;
        }
        else if(str[x]=='e')        //e
            fprintf(fptr,"\ne");

        else if(str[x]=='p'&&str[x+1]=='i')  //pi
        {
            fprintf(fptr,"\npi");
            x++;
        }
        else if(str[x]=='s')
        {
            if(str[x+3]=='(')       //sin( = S
            {
                fprintf(fptr,"\nS");
                x+=3;
            }
            else if(str[x+1]=='q')  //sqrt( = r
            {
                fprintf(fptr,"\nr");
                x+=4;
            }
            else                    //sin^-1( = s
            {
                fprintf(fptr,"\ns");
                x+=6;
            }
        }
        else if(str[x]=='c')
        {
            if(str[x+3]=='(')       //cos( = C
            {
                fprintf(fptr,"\nC");
                x+=3;
            }
            else                    //cos^-1( = c
            {
                fprintf(fptr,"\nc");
                x+=6;
            }
        }
        else if(str[x]=='t')
        {
            if(str[x+3]=='(')       //tan( = T
            {
                fprintf(fptr,"\nT");
                x+=3;
            }
            else                    //tan^-1( = t
            {
                fprintf(fptr,"\nt");
                x+=6;
            }
        }
        else if(str[x]=='!'||str[x]=='^'||str[x]=='('||str[x]==')'
                ||str[x]=='/'||str[x]=='*'||str[x]=='+'||str[x]=='-')
            fprintf(fptr,"\n%c",str[x]);      //Operators: !, ^, (, ), /, *, +, -

        else
        {
            fprintf(fptr,"\n");
            while((str[x]>='0'&&str[x]<='9')||str[x]=='.')
                {
                    fprintf(fptr,"%c",str[x]);          //Digits & Doshomik
                    x++;
                }
                x--;
        }
    }
    fclose(fptr);

    calculator();

    return;
}


void clickMouse(int mx, int my)
{
     /*this function is used to find out which portion of the calculator
     console has been clicked by the user. It will later be called inside
     the iMouse function*/

     for(row=1;row<=9;row++)
     {
          if(my >= row*Y+(row-1)*dY && my<=row*Y+row*dY)
               {
                    for(col=1;col<=5;col++)
                         {
                              if(mx >= col*X+(col-1)*dX && mx<=col*X+col*dX && mode==1  )
                              {calcButton[9-row][col-1]=1;  break;}
                         }
               }
     }

     return;
}

void resetEverything()
{
          for(i = 0; i < len; i++)
                str[i] = 0;
                len = 0;
              for(i=0;i<strlen(answer);i++)
                answer[i]=0;
              for(i=0;i<strlen(answer_S);i++)
                answer_S[i]=0;

                return;
}

void blackUp()
{    bColorR = 100;
     bColorG = 100;
     bColorB = 100;
             fontCol = 255;
     sColorR = 60;
     sColorG = 60;
     sColorB = 60;

     return;
}

void blackDown()
{    bColorR = 60;
     bColorG = 60;
     bColorB = 60;
            fontCol = 255;
     sColorR = 100;
     sColorG = 100;
     sColorB = 100;

     return;
}

void blueUp()
{    bColorR = 55;
     bColorG = 104;
     bColorB = 147;
           fontCol = 255;
     sColorR = 38;
     sColorG = 58;
     sColorB = 80;

     return;
}

void blueDown()
{    bColorR = 38;
     bColorG = 58;
     bColorB = 80;
           fontCol = 255;
     sColorR = 55;
     sColorG = 104;
     sColorB = 147;

     return;
}

void RedUp()
{    bColorR = 246;
     bColorG = 83;
     bColorB = 83;
            fontCol = 255;
     sColorR = 161;
     sColorG = 0;
     sColorB = 0;

     return;
}

void RedDown()
{    bColorR = 161;
     bColorG = 0;
     bColorB = 0;
            fontCol = 255;
     sColorR = 246;
     sColorG = 83;
     sColorB = 83;

}

void GreenUp()
{    bColorR = 119;
     bColorG = 204;
     bColorB = 146;
             fontCol = 0;
     sColorR = 65;
     sColorG = 117;
     sColorB = 82;

     return;
}

void GreenDown()
{
     bColorR = 65;
     bColorG = 117;
     bColorB = 82;
             fontCol = 0;
     sColorR = 119;
     sColorG = 204;
     sColorB = 146;

     return;
}

void colCall(int num)
{
     if(num==1) blackUp();  if(num==2) blackDown();
     if(num==3) blueUp();  if(num==4) blueDown();
     if(num==5) RedUp();  if(num==6) RedDown();
     if(num==7) GreenUp();  if(num==8) GreenDown();

     return;
}

void drawButton(double x, double y, char name[]){

    // Button Border Color
    iSetColor(sColorR, sColorG, sColorB);
    iFilledRectangle(x, y, dX, dY);
     // Button Color
    iSetColor(bColorR, bColorG, bColorB);
    iFilledRectangle(x+1, y+1, dX-2, dY-2);
    // Button Text Color
    iSetColor(fontCol, fontCol, fontCol);
    iText(x+9, y+9, name, GLUT_BITMAP_HELVETICA_12);

    return;
}

void DrawAllButton(){

  if(theme_clicked==1){
       if((strcmp(str2,"1"))==0) num=1;
       else if((strcmp(str2,"2"))==0) num=3;
       else if((strcmp(str2,"3"))==0) num=5;
       else if((strcmp(str2,"4"))==0) num=7;
  }

    colCall(num+1);
    //  First Row from bottom
    if(TempColChange[8][0]==1) colCall(num); drawButton(X                , Y, "0"); colCall(num+1);
    if(TempColChange[8][1]==1) colCall(num); drawButton(X + (dX+space)   , Y, "."); colCall(num+1);
    if(TempColChange[8][2]==1) colCall(num); drawButton(X + 2*(dX+space) , Y, "x10"); colCall(num+1);
    if(TempColChange[8][3]==1) colCall(num); drawButton(X + 3*(dX+space) , Y, "Ans"); colCall(num+1);
    if(TempColChange[8][4]==1) colCall(num); drawButton(X + 4*(dX+space) , Y, "="); colCall(num+1);
    //  Second Row
    if(TempColChange[7][0]==1) colCall(num); drawButton(X,                Y + (dY+space), "1"); colCall(num+1);
    if(TempColChange[7][1]==1) colCall(num); drawButton(X + (dX+space),   Y + (dY+space), "2"); colCall(num+1);
    if(TempColChange[7][2]==1) colCall(num); drawButton(X + 2*(dX+space), Y + (dY+space), "3"); colCall(num+1);
    if(TempColChange[7][3]==1) colCall(num); drawButton(X + 3*(dX+space), Y + (dY+space), "+"); colCall(num+1);
    if(TempColChange[7][4]==1) colCall(num); drawButton(X + 4*(dX+space), Y + (dY+space), "-"); colCall(num+1);
    //  Third Row
    if(TempColChange[6][0]==1) colCall(num); drawButton(X,                Y + 2*(dY+space), "4"); colCall(num+1);
    if(TempColChange[6][1]==1) colCall(num); drawButton(X + (dX+space),   Y + 2*(dY+space), "5"); colCall(num+1);
    if(TempColChange[6][2]==1) colCall(num); drawButton(X + 2*(dX+space), Y + 2*(dY+space), "6"); colCall(num+1);
    if(TempColChange[6][3]==1) colCall(num); drawButton(X + 3*(dX+space), Y + 2*(dY+space), "X"); colCall(num+1);
    if(TempColChange[6][4]==1) colCall(num); drawButton(X + 4*(dX+space), Y + 2*(dY+space), "/"); colCall(num+1);
    //  Fourth Row
    if(TempColChange[5][0]==1) colCall(num); drawButton(X,                Y + 3*(dY+space), "7"); colCall(num+1);
    if(TempColChange[5][1]==1) colCall(num); drawButton(X + (dX+space),   Y + 3*(dY+space), "8"); colCall(num+1);
    if(TempColChange[5][2]==1) colCall(num); drawButton(X + 2*(dX+space), Y + 3*(dY+space), "9"); colCall(num+1);
    if(TempColChange[5][3]==1) colCall(num); drawButton(X + 3*(dX+space), Y + 3*(dY+space), "DEL"); colCall(num+1);
    if(TempColChange[5][4]==1) colCall(num); drawButton(X + 4*(dX+space), Y + 3*(dY+space), "AC"); colCall(num+1);



     colCall(num);

    //  Fifth Row
    if(TempColChange[4][0]==1) colCall(num+1); drawButton(X,                Y  + 4*(dY+space), "!"); colCall(num);
    if(TempColChange[4][1]==1) colCall(num+1); drawButton(X + (dX+space),   Y  + 4*(dY+space), "("); colCall(num);
    if(TempColChange[4][2]==1) colCall(num+1); drawButton(X + 2*(dX+space), Y  + 4*(dY+space), ")"); colCall(num);
    if(TempColChange[4][3]==1) colCall(num+1); drawButton(X + 3*(dX+space), Y  + 4*(dY+space), "D <=> S"); colCall(num);
    if(TempColChange[4][4]==1) colCall(num+1); drawButton(X + 4*(dX+space), Y  + 4*(dY+space), "Dg/Rd"); colCall(num);
    // Sixth Row
    if(TempColChange[3][0]==1) colCall(num+1); drawButton(X,                Y  + 5*(dY+space), "e"); colCall(num);
    if(TempColChange[3][1]==1) colCall(num+1); drawButton(X + (dX+space),   Y  + 5*(dY+space), "pi"); colCall(num);
    if(TempColChange[3][2]==1) colCall(num+1); drawButton(X + 2*(dX+space), Y  + 5*(dY+space), "sin"); colCall(num);
    if(TempColChange[3][3]==1) colCall(num+1); drawButton(X + 3*(dX+space), Y  + 5*(dY+space), "cos"); colCall(num);
    if(TempColChange[3][4]==1) colCall(num+1); drawButton(X + 4*(dX+space), Y  + 5*(dY+space), "tan"); colCall(num);
    //  Seventh Row
    if(TempColChange[2][0]==1) colCall(num+1); drawButton(X,                Y  + 6*(dY+space), "log"); colCall(num);
    if(TempColChange[2][1]==1) colCall(num+1); drawButton(X + (dX+space),   Y  + 6*(dY+space), "ln"); colCall(num);
    if(TempColChange[2][2]==1) colCall(num+1); drawButton(X + 2*(dX+space), Y  + 6*(dY+space), "arcSin"); colCall(num);
    if(TempColChange[2][3]==1) colCall(num+1); drawButton(X + 3*(dX+space), Y  + 6*(dY+space), "arcCos"); colCall(num);
    if(TempColChange[2][4]==1) colCall(num+1); drawButton(X + 4*(dX+space), Y  + 6*(dY+space), "arcTan"); colCall(num);

    //  Eighth  Row
    if(TempColChange[1][0]==1) colCall(num+1); drawButton(X,                Y  + 7*(dY+space), "sqrt"); colCall(num);
    if(TempColChange[1][1]==1) colCall(num+1); drawButton(X + (dX+space),   Y  + 7*(dY+space), "x^-1"); colCall(num);
    if(TempColChange[1][2]==1) colCall(num+1); drawButton(X + 2*(dX+space), Y  + 7*(dY+space), "x^2"); colCall(num);
    if(TempColChange[1][3]==1) colCall(num+1); drawButton(X + 3*(dX+space), Y  + 7*(dY+space), "x^n"); colCall(num);
    if(TempColChange[1][4]==1) colCall(num+1); drawButton(X + 4*(dX+space), Y  + 7*(dY+space), "MODE"); colCall(num);

    //Ninth row
    if(TempColChange[0][0]==1) colCall(num+1); drawButton(X,                Y  + 8*(dY+space), "Theme"); colCall(num);
    if(TempColChange[0][4]==1) colCall(num+1); drawButton(X + 4*(dX+space),   Y  + 8*(dY+space), "ON"); colCall(num);

    return;
}
