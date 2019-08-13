/*
	Calculator++ project by - 
	
	 	    Jawad Ul Kabir - 201705062
	 Mahfuzur Rahman Rifat - 201705063
	  Ataf Fazledin Ahamed - 201705066
	
*/	

#define _CRT_SECURE_NO_WARNINGS
#include"iGraphics.h"
#include"calculator.h"


void iDraw() {

    iClear();
    iSetColor(scrRed, scrGreen, scrBlue);
     //     button BG
    DrawAllButton();

    iSetColor(255,255,255);
    iRectangle(      X  ,   Y + 45 + 8*(dY+space), 340, 150);
    iSetColor(scrRed, scrGreen, scrBlue);
    iFilledRectangle(X+1,   Y + 47 + 8*(dY+space), 337, 147);

    //    Title
    if(mode==1)
    {
         iSetColor(230, 230, 230);

         iLine(X+2, Y+175+8*(dY+space), 348,Y+175+8*(dY+space));
         iRectangle(X+2,   Y+2 + 45 + 8*(dY+space), 340-4, 150-4);

        if(theme_clicked%2==0 && modeClicked==0 && calcMode==1)
            iText(21, 480, str, GLUT_BITMAP_HELVETICA_18);

        if(theme_clicked%2==1)
        {
           iText(21, 480, "1.Charcoal (Default)", GLUT_BITMAP_HELVETICA_18);
           iText(21, 457, "2.Sapphire", GLUT_BITMAP_HELVETICA_18);
           iText(21, 434, "3.Ruby", GLUT_BITMAP_HELVETICA_18);
           iText(21, 411, "4.Emerald", GLUT_BITMAP_HELVETICA_18);

           if((strcmp(str,"1")==0) || (strcmp(str,"2")==0) || (strcmp(str,"3")==0) || (strcmp(str,"4")==0))
                       iText(330, 390, str, GLUT_BITMAP_HELVETICA_18);
           else
                resetEverything();
        }

        if(modeClicked==1)
        {
           calcMode=0;
           iText(21, 480, "1.Calculate (Default)", GLUT_BITMAP_HELVETICA_18);
           iText(21, 457, "2.a1x+b1y=c1, a2x+b2y=c2", GLUT_BITMAP_HELVETICA_18);
           iText(21, 434, "3.ax^2+bx+c=0", GLUT_BITMAP_HELVETICA_18);

           if((strcmp(str,"1")==0) || (strcmp(str,"2")==0) || (strcmp(str,"3")==0))
                       iText(330, 390, str, GLUT_BITMAP_HELVETICA_18);
           else
                resetEverything();
        }

        if(dsmode%2==1){
            iText(255,510,"D");
            if(calcMode==1)
                iText(340-(10*strlen(answer)), 390,answer, GLUT_BITMAP_HELVETICA_18);

            else if(calcMode==2)
                    calcuMode2(1);

            else if(calcMode==3)
                    calcuMode3(2);
        }
        else{
            iText(255,510,"S");
            if(calcMode==1)
            {
                if(lob>9999||hor>9999)
                    iText(340-(10*strlen(answer)), 390,answer, GLUT_BITMAP_HELVETICA_18);
                else
                    iText(340-(10*strlen(answer_S)), 390,answer_S, GLUT_BITMAP_HELVETICA_18);
            }
            else if(calcMode==2)
                calcuMode2(2);
            else if(calcMode==3)
                calcuMode3(2);
        }

        if(drmode%2==0)               // even---radian
            iText(200, 510, "RAD");
        else
            iText(200, 510, "DEG");
    }

    iSetColor(230, 260, 230);
    iShowBMP(88, 320, "title.bmp");

}

void iMouseMove(int mx, int my) {

}

void iMouse(int button, int state, int mx, int my) {

     int xxx, yyy; 	// for the indices of 2D array calcButton. And also be sure
                  	//not to use i and j in this regard because i is already a
                  	//global variable used for the string

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)

    {    //printf("%d %d\n",mx,my);

     if(mx >= 290 && mx <= 350 && my >= 330 && my <= 360 && mode == 0)
        {
            mode = 1; //the box is activated when mode is 1
        }

        clickMouse(mx,my);

/* this part handles the case when the mouse is used to take input into
  the computer. calcButton array is assumed to be exactly as the buttons
  positions are. So, whenever an element of the array is found to be 1, the
  button in that particular position is printed
*/

//first row
          if(calcButton[0][0]==1){
                ///code for theme change
                calcMode=0;
                modeClicked=0;
                resetEverything();
                for(idx=0;idx<strlen(str2);idx++) str2[idx]=0;
///---------------
                theme_clicked++;
                if(theme_clicked%2==0)
                    {
                        resetEverything();
                        theme_clicked=0;
                        calcMode=tempo;
                    }
                 TempColChange[0][0]=1;
          }
           if(calcButton[0][4]==1){
               //ON buttON
                    equalCount=0;
                    equalCount2=0;
                    strcpy(query,"Enter a1: ");
                    strcpy(query2,"Enter a: ");
                    resetEverything();
                    theme_clicked=0;
                    calcMode=tempo;
                    modeClicked=0;

              TempColChange[0][4]=1;
           }

//second row
          if(calcButton[1][0]==1){
                strcat(str,"sqrt(");
                len+=5;  TempColChange[1][0]=1;
          }
          if(calcButton[1][1]==1){
                strcat(str,"^-1");
                len+=3;  TempColChange[1][1]=1;
          }
          if(calcButton[1][2]==1){
                strcat(str,"^2");
                len+=2;  TempColChange[1][2]=1;
          }
          if(calcButton[1][3]==1){
                str[len]='^';
                len++;   TempColChange[1][3]=1;
          }
          if(calcButton[1][4]==1){
                    ///code for MODE
            equalCount=0;
            equalCount2=0;
            strcpy(query,"Enter a1: ");
            strcpy(query2,"Enter a: ");
            theme_clicked=0;
           resetEverything();

           for(idx=0;idx<strlen(str2);idx++) str2[idx]=0;

              if(modeClicked==0)
                    {
                        tempo=calcMode;
                        modeClicked=1;
                    }
              else
                    {
                        modeClicked=0;
                        calcMode=tempo;
                    }

              TempColChange[1][4]=1;
          }
//third row
          if(calcButton[2][0]==1){
                strcat(str,"log(");
                len+=4;  TempColChange[2][0]=1;
          }
          if(calcButton[2][1]==1){

                strcat(str,"ln(");
                len+=3;  TempColChange[2][1]=1;
          }
          if(calcButton[2][2]==1){
                strcat(str,"sin^-1(");
                len+=7;  TempColChange[2][2]=1;
          }
          if(calcButton[2][3]==1){
                strcat(str,"cos^-1(");
                len+=7;  TempColChange[2][3]=1;
            }
          if(calcButton[2][4]==1){
                strcat(str,"tan^-1(");
                len+=7;  TempColChange[2][4]=1;
            }
//      fourth row
          if(calcButton[3][0]==1){
                str[len]='e';
                len++;   TempColChange[3][0]=1;
                }
          if(calcButton[3][1]==1){
                str[len]='p';
                str[len+1]='i';
                len+=2;  TempColChange[3][1]=1;
                }
          if(calcButton[3][2]==1){
                strcat(str,"sin(");
                len+=4;  TempColChange[3][2]=1;
          }
          if(calcButton[3][3]==1){
                strcat(str,"cos(");
                len+=4;  TempColChange[3][3]=1;
          }
          if(calcButton[3][4]==1){
                strcat(str,"tan(");
                len+=4;  TempColChange[3][4]=1;
          }
//fifth row
          if(calcButton[4][0]==1){
                str[len]='!';
                len++;   TempColChange[4][0]=1;
          }
          if(calcButton[4][1]==1){
                str[len]='(';
                len++;   TempColChange[4][1]=1;
          }
          if(calcButton[4][2]==1){
                str[len]=')';
                len++;   TempColChange[4][2]=1;
          }
          if(calcButton[4][3]==1){
                dsmode++;   TempColChange[4][3]=1;
          }

          if(calcButton[4][4]==1 ){
                drmode++;   TempColChange[4][4]=1;
          }

                if(drmode%2==0 && mode==1) {    // even---radian
                        ang = 1;
                   }
                else{
                        ang = PI/180;
                }


//sixth row
          if(calcButton[5][0]==1){
                str[len]='7';
                len++;   TempColChange[5][0]=1;
          }
          if(calcButton[5][1]==1){
                str[len]='8';
                len++;   TempColChange[5][1]=1;
          }
          if(calcButton[5][2]==1){
              str[len]='9';
              len++;   TempColChange[5][2]=1;
          }
          if(calcButton[5][3]==1){
              //DEL Button
              str[strlen(str)-1]=0;
              len--;   TempColChange[5][3]=1;
          }
          if(calcButton[5][4]==1){
              //AC Button
                equalCount=0;
                equalCount2=0;
                strcpy(query,"Enter a1: ");
                strcpy(query2,"Enter a: ");
                resetEverything();
                      theme_clicked=0;
                      calcMode=tempo;
                      modeClicked=0;
                  TempColChange[5][4]=1;
          }
//seventh row
          if(calcButton[6][0]==1){
              str[len]='4';
              len++;   TempColChange[6][0]=1;
          }
          if(calcButton[6][1]==1){
              str[len]='5';
              len++;   TempColChange[6][1]=1;
          }
          if(calcButton[6][2]==1){
                str[len]='6';
                len++;   TempColChange[6][2]=1;
          }
          if(calcButton[6][3]==1){
                str[len]='*';
                len++;   TempColChange[6][3]=1;
          }
          if(calcButton[6][4]==1){
                str[len]='/';
                len++;   TempColChange[6][4]=1;
          }
//eighth row
          if(calcButton[7][0]==1){
                str[len]='1';
                len++;   TempColChange[7][0]=1;
          }
          if(calcButton[7][1]==1){
                str[len]='2';
                len++;   TempColChange[7][1]=1;
          }
          if(calcButton[7][2]==1){
                str[len]='3';
                len++;   TempColChange[7][2]=1;
          }

          if(calcButton[7][3]==1){
                str[len]='+';
                len++;   TempColChange[7][3]=1;
          }
          if(calcButton[7][4]==1){
                str[len]='-';
                len++;   TempColChange[7][4]=1;
             }
//ninth row
          if(calcButton[8][0]==1){
                str[len]='0';
                len++;   TempColChange[8][0]=1;
             }
          if(calcButton[8][1]==1){
                str[len]='.';
                len++;   TempColChange[8][1]=1;
          }
          if(calcButton[8][2]==1){
                strcat(str,"*10^");
                len+=4;  TempColChange[8][2]=1;
                }

          if(calcButton[8][3]==1){
                //Ans Button
                strcat(str,"Ans");
                len+=3;  TempColChange[8][3]=1;
                }
          if(calcButton[8][4]==1){
                //= Button
                equalCount++;
                equalCount2++;
                if(calcMode==2)
                    resetEverything();
                if(calcMode==3)
                    resetEverything();
                strcpy(str2, str);
                ///printf("%s\n", str2);
///------------------------------

                if(theme_clicked==0 && modeClicked==0 && calcMode==1) printFile(str2);
                if(theme_clicked==1) resetEverything();
                if(modeClicked==1)
                {
                    if(strcmp(str,"1")==0) {calcMode=1;tempo=1;}
                    else if(strcmp(str,"2")==0) {calcMode=2;tempo=2;equalCount=0;}
                    else if(strcmp(str,"3")==0) {calcMode=3;tempo=3;equalCount2=0;}
                    else {calcMode=tempo;equalCount=0;equalCount2=0;}
                    resetEverything();
                    modeClicked=0;
                }

                TempColChange[8][4]=1;
                }

    }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_UP){

        //printf("%d %d\n",mx,my);

     if(mx >= 290 && mx <= 350 && my >= 320 && my <= 350 && mode == 0)
        {
            mode = 1; //the box is activated when mode is 1
        }

        clickMouse(mx,my);


                  for(xxx=0;xxx<9;xxx++)
                    {
                         for(yyy=0;yyy<5;yyy++)
                              {
                                   TempColChange[xxx][yyy]=0;
                              }
                 ///after releasing the mouse button, all the elements are made zero
                    }



                    for(xxx=0;xxx<9;xxx++)
                    {
                         for(yyy=0;yyy<5;yyy++)
                              {
                                   calcButton[xxx][yyy]=0;
                              }
                 ///after one mouse click, all the elements are made zero
                    }
            }
}

void iKeyboard(unsigned char key){

   //this next part is copied from the text input demo code and supposed to serve the
   //purpose of handling the case when the numbers are taken from keyboard directly

    if(mode == 1)
        {
        if(key == '\r'||key == '=') ///ENTER & = KEY
            {
                equalCount++;
                equalCount2++;
                if(calcMode==2)
                    resetEverything();
                if(calcMode==3)
                    resetEverything();
                strcpy(str2, str);
                printf("%s\n", str2);
///------------------------------
                if(theme_clicked==0 && modeClicked==0) printFile(str2);
                if(theme_clicked==1) resetEverything();
                if(modeClicked==1)
                {
                    if(strcmp(str,"1")==0) calcMode=1;
                    if(strcmp(str,"2")==0) {calcMode=2;equalCount=0;}
                    if(strcmp(str,"3")==0) {calcMode=3;equalCount2=0;}
                    resetEverything();
                    modeClicked=0;
                }

            }
        else if(key==8)     ///BACKSPACE KEY
            {
            str[strlen(str)-1]=0;
            len--;
            }

        else
            {
            str[len] = key;
            len++;
            }
        }
     }

void iSpecialKeyboard(unsigned char key) {

    if (key == GLUT_KEY_END) {
        exit(0);
    }

}

int main(){

    iInitialize(dxBox, dyBox, "Calculator++");
    return 0;
}
