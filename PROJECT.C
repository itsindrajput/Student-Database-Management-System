/*     Project On Student Database Management System */
//                    By  Rishabh Singh


#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<dos.h>

union REGS i,o;
void outline();
void screen_1();
void password_input();
void draw_screen();

void initialize_mouse();  // to check mouse support
void show_mouse();        //to show mouse on screen
void get_mouse();         // to get coordinates of user click
void add_window();
void add_student_record();
void search_student_record();
void delete_student_record();
void delete_progress();
void modify_student_record();
void list_student_record();
void student_backup_database();
void progress();
void exit_system();

struct ADDRESS
{
char COUNTRY[30];
char STATE[40];
char DISTRICT[50];
char CITY[30];
char STREET[30];
long int  PIN;
};

struct STUDENT_RECORD
{
int ROLL_NO;
float MARKS;
char MOBILE_NO[12];
char F_NAME[25];
char L_NAME[25];
char COURSE_NAME[15];
char GENDER[10];
char FEES[10];
int DAYS;
int MONTH;
int YEAR;
struct ADDRESS A;
};

void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:/TURBOC3/BGI");
outline();
screen_1();
password_input();

start:
cleardevice();
draw_screen();
initialize_mouse();
//       display function beigns from here
setcolor(3);
setfillstyle(1,6);
rectangle(405,55,215,88);
rectangle(410,50,210,93);
floodfill(392,52,3);
gotoxy(29,5);
printf("1. ADD STUDENT RECORD");

gotoxy(29,8);
setcolor(3);
setfillstyle(1,6);
rectangle(405,135,215,105);
rectangle(410,140,210,100);
floodfill(394,139,3);
printf("2. SEARCH RECORD");

gotoxy(29,11);
setcolor(3);
setfillstyle(1,6);
rectangle(405,180,215,152);
rectangle(410,185,210,146);
floodfill(394,184,3);
printf("3. DELETE RECORD");

gotoxy(29,14);
setcolor(3);
setfillstyle(1,6);
rectangle(405,229,215,199);
rectangle(410,234,210,194);
floodfill(394,233,3);
printf("4. MODIFY RECORD");

gotoxy(29,17);
setcolor(3);
setfillstyle(1,6);
rectangle(405,275,215,248);
rectangle(410,280,210,242);
floodfill(394,279,3);
printf("5. LIST RECORDS");

gotoxy(29,20);
setcolor(3);
setfillstyle(1,6);
rectangle(405,325,215,295);
rectangle(410,330,210,290);
floodfill(394,329,3);
printf("6. BACKUP DATABASE");

gotoxy(29,23);
setcolor(3);
setfillstyle(1,6);
rectangle(405,372,215,345);
rectangle(410,377,210,340);
floodfill(394,376,3);
printf("7. EXIT SYSTEM");

settextstyle(1,0,3);
outtextxy(195,400,"CHOOSE YOUR OPTION");

show_mouse();
while(!kbhit())
{
draw_screen();
show_mouse();
get_mouse();

if(o.x.bx==1 && o.x.cx<410 && o.x.cx>210 && o.x.dx<93 && o.x.dx>50)
{
setcolor(3);                           //1ST BOX
setfillstyle(1,10);
rectangle(405,55,215,88);
rectangle(410,50,210,93);
floodfill(392,52,3);
delay(100);
gotoxy(59,5);
printf("YOU WANT ADD");
gotoxy(58,6);
printf("STUDENT RECORD");
delay(1700);
cleardevice();
draw_screen();
add_window();
add_student_record();
fflush(stdin);
goto start;
}
if(o.x.bx==1 && o.x.cx<410 && o.x.cx>210 && o.x.dx<140 && o.x.dx>100)
{
setcolor(3);                                //2ND BOX
setfillstyle(1,10);
rectangle(405,135,215,105);

rectangle(410,140,210,100);
floodfill(394,139,3);
delay(100);
gotoxy(10,8);
printf("YOU WANT SEARCH");
gotoxy(10,9);
printf("STUDENT RECORD");
delay(1700);
cleardevice();
draw_screen();
add_window();
search_student_record();
fflush(stdin);
goto start;
}
if(o.x.bx==1 && o.x.cx<410 && o.x.cx>210 && o.x.dx<185 && o.x.dx>146)
{
setcolor(3);
setfillstyle(1,10);
rectangle(405,180,215,152);
rectangle(410,185,210,146);
floodfill(394,184,3);			        //3RD BOX
delay(100);
gotoxy(58,10);

printf("YOU WANT DELETE");
gotoxy(58,11);
printf("STUDENT RECORD");
cleardevice();
draw_screen();
add_window();
delete_student_record();
delay(1700);

fflush(stdin);
goto start;
}
if(o.x.bx==1 && o.x.cx<410 && o.x.cx>210 && o.x.dx<234 && o.x.dx>194)
{
setcolor(3);                                 //4TH BOX
setfillstyle(1,10);
rectangle(405,229,215,199);
rectangle(410,234,210,194);
floodfill(394,233,3);
delay(100);
gotoxy(10,14);
printf("YOU WANT MODIFY");
gotoxy(10,15);
printf("STUDENT RECORD");
cleardevice();
draw_screen();
add_window();
modify_student_record();
delay(1700);
fflush(stdin);
goto start;
}
if(o.x.bx==1 && o.x.cx<410 && o.x.cx>210 && o.x.dx<280 && o.x.dx>242)
{
setcolor(3);                              //5TH BOX
setfillstyle(1,10);
rectangle(405,275,215,248);
rectangle(410,280,210,242);
floodfill(394,279,3);
delay(100);
gotoxy(58,16);
printf("YOU WANT LIST");
gotoxy(58,17);
printf("STUDENT RECORD");
cleardevice();
draw_screen();
add_window();
list_student_record();
delay(1700);
fflush(stdin);
goto start;
}
if(o.x.bx==1 && o.x.cx<410 && o.x.cx>210 && o.x.dx<330 && o.x.dx>290)
{
setcolor(3);                           //6TH BOX
setfillstyle(1,10);
rectangle(405,325,215,295);
rectangle(410,330,210,290);
floodfill(394,329,3);
delay(100);
gotoxy(10,20);
printf("YOU WANT BACKUP");
gotoxy(10,21);
printf("STUDENT RECORD");
cleardevice();
draw_screen();
add_window();
student_backup_database();
delay(1700);
fflush(stdin);
goto start;
}
if(o.x.bx==1 && o.x.cx<410 && o.x.cx>210 && o.x.dx<377 && o.x.dx>340)
{
setcolor(3);
setfillstyle(1,10);                         //7TH BOX
rectangle(405,372,215,345);
rectangle(410,377,210,340);
floodfill(394,376,3);
delay(100);
gotoxy(58,23);
printf("YOU WANT CLOSE");
gotoxy(58,24);
printf("STUDENT RECORD WINDOW");
cleardevice();
draw_screen();
add_window();
exit_system();
delay(1700);
fflush(stdin);
goto start;
}
}
getch();
closegraph();
}

void outline()
{
setcolor(8);
setfillstyle(1,9);
rectangle(10,10,630,470);        //1st outline of the screen
rectangle(11,11,629,469);
rectangle(12,12,628,468);        //1st outline of the screen
rectangle(13,13,627,467);
rectangle(14,14,626,466);        //1st outline of the screen
rectangle(15,15,625,465);
rectangle(16,16,624,464);        //1st outline of the screen
rectangle(17,17,623,463);
floodfill(100,100,8);
setcolor(8);
setfillstyle(1,3);
floodfill(18,18,8);
setcolor(0);
rectangle(52,52,593,300);        //2nd outline
setcolor(4);
rectangle(53,53,592,298);        //2nd outline
setcolor(7);
rectangle(54,54,591,297);        //2nd outline
setcolor(4);
rectangle(55,55,590,296);        //2nd outline
setcolor(7);
rectangle(56,56,589,295);        //2nd outline
setcolor(7);
setfillstyle(1,17);
floodfill(58,58,7);
}
void screen_1()
{
void logo_sec();
void school_desig();
setcolor(0);
setfillstyle(1,15);
rectangle(245,249,365,273);   //1st rectangle
rectangle(244,250,366,272);   // First rectangle
rectangle(243,251,367,271);   // First rectangle
floodfill(247,253,0);
setfillstyle(1,3);
rectangle(392,251,433,269);   // Second rectangle
rectangle(391,252,434,268);   // Second rectangle
rectangle(390,253,435,267);   // Second rectangle
floodfill(394,255,0);
setcolor(4);
settextstyle(1,0,1);
outtextxy(396,247,"-->");
setcolor(12);
setfillstyle(1,10);       //Here The Logo Section Beigns
rectangle(187,152,411,223);   // Third rectangle
rectangle(186,153,412,222);   // Third rectangle
rectangle(185,154,413,221);   // Third rectangle
rectangle(184,155,414,220);   // Third rectangle
floodfill(191,156,12);
logo_sec();  	    // logo section call
setcolor(12);
setfillstyle(1,14);
rectangle(69,80,574,130);      //Fourth rectangle
rectangle(68,81,575,129);      //4th rectangle
rectangle(67,82,576,128);      //Fourth rectangle
rectangle(66,83,577,127);      //4th rectangle
rectangle(65,84,578,128);      //4threctangle
floodfill(75,85,12);
school_desig();        // inside logo school function call here
setcolor(0);
settextstyle(1,0,3);
outtextxy(82,91,"STUDENT DATABASE MANAGEMENT SYSTEM");
}
void logo_sec()
{
setcolor(4);
ellipse(220,174,0,360,9,13);      //1st student face
ellipse(220,174,0,360,10,14);      //1st student face
setfillstyle(1,7);
floodfill(221,175,4);
setcolor(6);
setfillstyle(1,WHITE);
ellipse(217,171,0,360,4,2);       //1st student 1st eye
floodfill(216,170,6);
ellipse(225,170,0,360,3,2);       //1st student 2nd eye
floodfill(224,169,6);
line(223,174,223,179);            //1st student nose
line(222,174,222,179);            //1st student nose
setlinestyle(0,0,2);
line(222,188,224,202);   	  //1ST student Body
line(223,188,225,202);         	  //1ST student Body
line(224,202,214,215);   	  //1ST student 1st leg
line(225,202,215,215);    	  //1ST student 1st leg
line(222,188,208,202);            //1st student 1st hand
line(222,189,208,203);            //1st student 1st hand
line(222,189,237,196);            //1st student 2nd hand
line(222,190,237,197);             //1st student 2nd hand
line(224,194,237,212);            //1st student 2nd leg
line(224,195,237,213);            //1st student 2nd leg

setcolor(16);
ellipse(253,174,0,360,9,13);      //2nd student face
ellipse(253,174,0,360,10,14);      //2nd student face
setfillstyle(1,7);
floodfill(254,175,16);
setcolor(6);
setfillstyle(1,WHITE);
ellipse(250,171,0,360,4,2);       //2nd student 1st eye
floodfill(251,170,6);
ellipse(258,170,0,360,3,2);       //2nd student 2nd eye
floodfill(259,171,6);
line(256,174,256,179);            //2nd student nose
line(255,174,255,179);            //2nd student nose
line(255,188,257,202);  	  //2nd student Body
line(256,188,258,202);    	  //2nd student Body
line(255,188,241,202);            //2nd student 1st hand
line(255,189,241,203);            //2nd student 1st hand
line(255,189,270,196);            //2nd student 2nd hand
line(255,190,270,197);             //2nd student 2nd hand
line(257,202,247,215);   	  //2nd student 1st leg
line(258,202,248,215);     	  //2nd student 1st leg
line(257,197,270,212);            //2nd student 2nd leg
line(258,197,271,212);  	  //2nd student 2nd leg

setcolor(5);
ellipse(286,174,0,360,9,13);      //3rd student face
ellipse(286,174,0,360,10,14);      //3rd student face
setfillstyle(1,7);
floodfill(288,175,5);
setcolor(6);
setfillstyle(1,WHITE);
ellipse(283,171,0,360,4,2);       //3rd student 1st eye
floodfill(283,171,6);
ellipse(291,170,0,360,3,2);       //3rd student 2nd eye
floodfill(291,170,6);
line(289,174,289,179);            //3rd student nose
line(288,174,288,179);            //3rd student nose
line(288,188,290,202);  	  //3rd student Body
line(289,188,291,202);    	  //3rd student Body
line(288,188,274,202);            //3rd student 1st hand
line(288,189,274,203);            //3rd student 1st hand
line(288,189,305,196);            //3rd student 2nd hand
line(288,190,305,197);             //3rd student 2nd hand
line(290,202,280,215);    	  //3rd student 1st leg
line(291,202,281,215);    	  //3rd student 1st leg
line(290,197,303,212);            //3rd student 2nd leg
line(291,197,304,212);            //3rd student 2nd leg
}
void school_desig()
{
int array[]={364,203,407,215,404,185,385,157, 364,175,364,203};
int array1[]={363,204,406,216,403,186,384,158,363,176,363,204};
int array2[]={362,205,405,217,402,187,383,159,362,177,362,205};
int array3[]={361,206,404,218,401,188,382,160,361,178,361,206};
setcolor(0);
settextstyle(8,0,3);
outtextxy(572,50,"X");
setcolor(9);
setfillstyle(1,4);
drawpoly(6,array);
floodfill(365,201,9);
setcolor(9);
drawpoly(6,array1);
drawpoly(6,array2);
drawpoly(6,array3);
setcolor(0);
line(361,205,311,204);     // road or track
line(361,206,311,205);
line(405,217,290,215);
line(405,218,290,216);
line(365,181,395,181);     // border of text school
line(365,193,401,193);
settextstyle(2,0,4);
outtextxy(365,181,"School");
setcolor(11);
outtextxy(199,231,"HELLO, ENTER YOUR PASSWORD TO CONTINUE");
setcolor(4);
settextstyle(2,0,5);
outtextxy(38,440,"WELCOME TO STUDENT'S DBMS");
outtextxy(365,440,"LOGIN TO OPERATE WITH DATABASE");
}

void password_input()
{
char org_password[]={"rishabh"};
char password[10],ch,ex;
int i,j,k,X=251,Y=248;
for(i=0;i<10;i++)
{
for(k=1;k<=1;k++)
{
ch=getch();
sound(999*k);
delay(30);
nosound();
}
password[i]=ch;
if(ch==13)               //Ascii value for enter key = 13
{
password[i]='\0';
delay(150);
for(i=0;i<10;i++)
{
sound(99*i);
setcolor(8);
setfillstyle(1,12);
rectangle(392,251,433,269);    // Second rectangle
rectangle(391,252,434,268);   // Second rectangle
rectangle(390,253,435,267);   // Second rectangle
delay(20);
floodfill(395,256,8);
setcolor(4);
settextstyle(1,0,1);
outtextxy(396,247,"-->");
delay(100);
setcolor(0);
setfillstyle(1,3);
rectangle(392,251,433,269);    // Second rectangle
rectangle(391,252,434,268);   // Second rectangle
rectangle(390,253,435,267);   // Second rectangle
floodfill(394,255,0);
setcolor(4);
settextstyle(1,0,1);
outtextxy(396,247,"-->");
nosound();
}
delay(1000);
}
if(ch==8)       //Ascii value for backspace key  = 8
{
i--;
i--;
X=X-11;
fflush(stdin);
if(X<251)
{
X=251;
}
for(j=1;j<=1;j++)
{
sound(999*j);
setcolor(15);
outtextxy(X,Y,"*");
delay(30);
nosound();
}
X=X-11;
}
if(ch==27)     //when user press esc key ascii code for esc = 27
{
cleardevice();
setcolor(8);
rectangle(160,165,451,315);     //Outline
rectangle(159,166,452,314);
rectangle(158,167,453,313);
rectangle(157,168,454,312);
rectangle(156,169,455,311);
setfillstyle(11,12);
floodfill(0,0,8);
for(i=1;i<=10;i++)
{
sound(399*i);
setcolor(7);
gotoxy(30,14);
printf(" Do You Want To Exit:");
delay(100+i);
nosound();
}
gotoxy(31,17);
printf(" Press 1 For Exit");
ex=getch();
if(ex==49)
exit();
}
setcolor(0);
outtextxy(X,Y,"*");
X=X+11;
}
if(strcmp(org_password,password)==0)
{
cleardevice();
delay(900);
setcolor(15);
setfillstyle(9,12);
rectangle(100,130,520,340);
rectangle(99,129,521,341);
rectangle(98,128,522,342);
rectangle(130,155,490,315);
floodfill(110,135,15);
setcolor(4);
setfillstyle(1,1);
ellipse(307,235,0,360,120,50);
ellipse(307,235,0,360,121,51);
ellipse(307,235,0,360,119,49);
floodfill(308,236,4);
for(i=1;i<=10;i++)
{
sound(599*i);
setcolor(10);
settextstyle(8,0,2);
outtextxy(221,218,"LOGIN GRANTED");
setfillstyle(9,13);
floodfill(0,0,WHITE);
delay(99+i);
nosound();
}
delay(1000);
}
else
{
cleardevice();
delay(1200);
setcolor(15);
setfillstyle(1,6);
rectangle(100,130,520,340);
rectangle(99,129,521,341);
rectangle(98,128,522,342);
rectangle(130,155,490,315);
floodfill(110,135,15);
setcolor(4);
setfillstyle(1,7);
ellipse(307,235,0,360,120,50);
ellipse(307,235,0,360,121,51);
ellipse(307,235,0,360,119,49);
floodfill(308,236,4);
for(i=1;i<=10;i++)
{
sound(799*i);
setcolor(4);
settextstyle(8,0,3);
outtextxy(220,218,"LOGIN DENIED");
setfillstyle(11,2);
floodfill(0,0,WHITE);
delay(40+i);
nosound();
}
delay(1500);
exit();
}
}

void draw_screen()
{
setcolor(7);
setfillstyle(9,12);
line(0,40,640,40);
line(0,41,640,41);
line(0,42,640,42);
floodfill(0,0,7);
line(0,440,640,440);
line(0,439,640,439);
line(0,438,640,438);
floodfill(0,460,7);
}
void initialize_mouse()
{
i.x.ax=0;
int86(0x33,&i,&o);
}
void show_mouse()
{
i.x.ax=1;
int86(0x33,&i,&o);
}
void get_mouse()
{
i.x.ax=3;
int86(0x33,&i,&o);
}

void add_window()
{
setcolor(11);
settextstyle(8,0,2);
outtextxy(0,44,"||** ENTER STUDENT RECORD TO STORE IN DATABASE **||");
setcolor(15);
setfillstyle(1,6);
rectangle(80,75,560,415);
rectangle(79,76,561,414);
setcolor(15);
rectangle(100,95,540,395);
rectangle(99,96,539,394);
floodfill(155,85,15);
}

void add_student_record()
{
char INPUT;
struct STUDENT_RECORD S;
FILE *fp;
fp=fopen("C:\\TURBOC3\\STUDENT1_DATABADSE.DAT","a");
if(fp==NULL)
{
cleardevice();
draw_screen();
add_window();
gotoxy(30,16);
printf("FILE OPENING ERROR:");
delay(2000);
exit();
}
fseek(fp,0,SEEK_END);
INPUT='Y';
while(INPUT=='y' || INPUT=='Y')
{
cleardevice();
draw_screen();
add_window();
fflush(stdin);
gotoxy(16,8);
printf("ENTER ROLL NUMBER OF STUDENT : ");
scanf("%d",&S.ROLL_NO);
fflush(stdin);
gotoxy(16,9);
printf("ENTER FIRST NAME OF STUDENT : ");
scanf("%s",S.F_NAME);
gotoxy(16,10);
printf("ENTER LAST NAME OF STUDENT : ");
scanf("%s",S.L_NAME);
gotoxy(16,11);
printf("ENTER STUDENT GENDER : ");
scanf("%s",S.GENDER);
gotoxy(16,12);
printf("ENTER COURSE NAME : ");
scanf("%s",S.COURSE_NAME);
gotoxy(16,13);
printf("ADMISSION DATE DD/MM/YY FORMAT : ");
gotoxy(49,13);
scanf("%d",&S.DAYS);
gotoxy(51,13);
printf("/");
gotoxy(53,13);
scanf("%d",&S.MONTH);
gotoxy(55,13);
printf("/");
gotoxy(57,13);
scanf("%d",&S.YEAR);
gotoxy(16,14);
printf("FEES STATUS [PAID OR DUE] :: ");
scanf("%s",S.FEES);
gotoxy(16,15);
printf("MARKS OF STUDENT :: ");
scanf("%f",&S.MARKS);
gotoxy(16,16);
printf("ENTER MOBILE NO. OF STUDENT :: ");
scanf("%s",S.MOBILE_NO);
gotoxy(21,18);
printf("!!|| *****  ADDRESS  ***** ||!!");
gotoxy(16,20);
printf("ENTER COUNTRY OF STUDENT :: ");
scanf("%s",S.A.COUNTRY);
gotoxy(16,21);
printf("ENTER DISTRICT :: ");
scanf("%s",S.A.DISTRICT);
gotoxy(16,22);
printf("ENTER CITY :: ") ;
scanf("%s",S.A.CITY);
gotoxy(16,23);
printf("ENTER STREET :: ");
scanf("%s",S.A.STREET);
gotoxy(16,24);
printf("ENTER PIN CODE :: ") ;
scanf("%ld",&S.A.PIN);

fwrite(&S,sizeof(S),1,fp);
cleardevice();
draw_screen();
gotoxy(20,14);
setcolor(3);
setfillstyle(1,8);
rectangle(530,260,130,170);
rectangle(520,250,140,180);
floodfill(521,251,3);
printf("DO YOU WANT TO ADD ANOTHER RECORD..?  (Y/N)");
fflush(stdin);
INPUT = getch();
}
fclose(fp);
}


void search_student_record()
{
int RLNO;
struct STUDENT_RECORD S;
FILE *fp;
cleardevice();
draw_screen();
setcolor(15);
setfillstyle(1,10);
rectangle(490,210,140,130);
rectangle(480,200,150,140);
floodfill(451,205,15);
gotoxy(22,11);
printf("ENTER ROLL NUMBER TO SEARCH :: ");
scanf("%d",&RLNO);
fp=fopen("C:\\TURBOC3\\STUDENT1_DATABADSE.DAT","rb+");
if(fp==NULL)
{
cleardevice();
draw_screen();
add_window();
gotoxy(30,16);
printf("FILE OPENING ERROR:");
delay(2000);
exit();
}
while(fread(&S,sizeof(S),1,fp)==1)
{
if(strcmp(&S.ROLL_NO,&RLNO)==0)
{
cleardevice();
draw_screen();
add_window();
gotoxy(17,8);
printf("NAME OF STUDENT :  %s %s",S.F_NAME,S.L_NAME);
gotoxy(17,9);
printf("STUDENT GENDER :  %s",S.GENDER);
gotoxy(17,10);
printf("STUDENT COURSE NAME :  %s",S.COURSE_NAME);
gotoxy(17,11);
printf("ADMISSION DATE :  %d/%d/%d",S.DAYS,S.MONTH,S.YEAR);
gotoxy(17,12);
printf("FEES STATUS [PAID OR DUE] ::  %s",S.FEES);
gotoxy(17,13);
printf("MARKS OF STUDENT ::  %.2f",S.MARKS);
gotoxy(17,14);
printf("ENTER MOBILE NO. OF STUDENT ::  %s",S.MOBILE_NO);
gotoxy(24,16);
printf("!!! **** ADDRESS **** !!!");
gotoxy(17,18);
printf("ENTER COUNTRY OF STUDENT ::  %s",S.A.COUNTRY);
gotoxy(17,19);
printf("ENTER DISTRICT ::  %s",S.A.DISTRICT);
gotoxy(17,20);
printf("ENTER CITY ::  %s",S.A.CITY);
gotoxy(17,21);
printf("ENTER STREET ::  %s",S.A.STREET);
gotoxy(17,22);
printf("PIN CODE ::  %ld",S.A.PIN);
delay(5000);
break;
}
else
{
cleardevice();
draw_screen();
setcolor(3);
setfillstyle(1,12);
rectangle(485,249,150,180);
rectangle(475,240,160,189);
floodfill(451,241,3);
gotoxy(24,14);
printf("ROLL NUMBER NOT FOUND IN DATABASE");
delay(4000);
fflush(stdin);
break;
}
}
}



void delete_student_record()
{
int RLNO;
FILE *fp,*fp1;
struct STUDENT_RECORD S;

cleardevice();
draw_screen();
setcolor(14);
setfillstyle(1,8);
rectangle(460,240,140,160);
rectangle(450,230,150,170);
floodfill(451,205,14);
gotoxy(26,13);
printf("ENTER ROLL NUMBER : ");
scanf("%d",&RLNO);
delete_progress();
fp = fopen("C:\\TURBOC3\\STUDENT1.DAT","rb+");
fp1 = fopen("C:\\TURBOC3\\TEMP.DAT","wb+");
rewind(fp);
while(fread(&S,sizeof(S),1,fp) == 1)
{
if(strcmp(&S.ROLL_NO,&RLNO)!=0)
{
fwrite(&S,sizeof(S),1,fp1);
}
}
fclose(fp);
fclose(fp1);
remove("C:\\TURBOC3\\STUDENT1.DAT");
rename("C:\\TURBOC3\\TEMP.DAT","C:\\TURBOC3\\STUDENT1.DAT");
}


void modify_student_record()
{
struct STUDENT_RECORD S;
FILE *fp;
long int size = sizeof(S);
char NAME[15];
cleardevice();
draw_screen();
setcolor(2);
settextstyle(8,0,2);
outtextxy(29,44,"||**!!  ENTER STUDENT NAME TO MODIFY DATA  !!**||");

setcolor(14);
setfillstyle(9,13);
rectangle(80,75,560,415);
rectangle(79,76,561,414);
setcolor(14);
rectangle(100,95,540,395);
rectangle(99,96,539,394);
floodfill(155,85,14);

setcolor(3);
setfillstyle(1,12);
rectangle(480,249,150,180);
rectangle(470,240,158,189);
floodfill(451,241,3);
gotoxy(24,14);
printf("ENTER FIRST NAME :: ");
scanf("%s",NAME);
cleardevice();
draw_screen();
add_window();

fp=fopen("C:\\TURBOC3\\STUDENT1_DATABADSE.DAT","rb+");
if(fp==NULL)
{
cleardevice();
draw_screen();
add_window();
gotoxy(30,16);
printf("FILE OPENING ERROR:");
delay(2000);
exit();
}
rewind(fp);
while(fread(&S,sizeof(S),1,fp)==1)
{
if(strcmp(S.F_NAME,NAME)==0)
{
gotoxy(14,8);
printf("ROLL NUMBER OF STUDENT : ");
scanf("%d",&S.ROLL_NO);
fflush(stdin);
gotoxy(14,9);
printf("FIRST NAME OF STUDENT : ");
scanf("%s",S.F_NAME);
gotoxy(14,10);
printf("LAST NAME OF STUDENT : ");
scanf("%s",S.L_NAME);
gotoxy(14,11);
printf("STUDENT GENDER : ");
scanf("%s",S.GENDER);
gotoxy(14,12);
printf("COURSE NAME : ");
scanf("%s",S.COURSE_NAME);
gotoxy(14,13);
printf("ADMISSION DATE DD/MM/YY FORMAT : ");
gotoxy(49,13);
scanf("%d",&S.DAYS);
gotoxy(51,13);
printf("/");
gotoxy(53,13);
scanf("%d",&S.MONTH);
gotoxy(55,13);
printf("/");
gotoxy(57,13);
scanf("%d",&S.YEAR);
gotoxy(14,14);
printf("FEES STATUS [PAID OR DUE] :: ");
scanf("%s",S.FEES);
gotoxy(14,15);
printf("MARKS OF STUDENT :: ");
scanf("%f",&S.MARKS);
gotoxy(14,16);
printf("MOBILE NO. OF STUDENT :: ");
scanf("%s",S.MOBILE_NO);
gotoxy(21,18);
printf("!!|| *****  ADDRESS  ***** ||!!");
gotoxy(14,20);
printf("COUNTRY OF STUDENT :: ");
scanf("%s",S.A.COUNTRY);
gotoxy(14,21);
printf("STUDENT DISTRICT :: ");
scanf("%s",S.A.DISTRICT);
gotoxy(14,22);
printf("STUDENT CITY :: ") ;
scanf("%s",S.A.CITY);
gotoxy(14,23);
printf("STREET :: ");
scanf("%s",S.A.STREET);
gotoxy(14,24);
printf("PIN CODE :: ") ;
scanf("%ld",&S.A.PIN);

fseek(fp,-size,SEEK_CUR);
fwrite(&S,size,1,fp);
}
else
{
setcolor(3);
setfillstyle(1,12);
rectangle(490,249,155,180);
rectangle(480,240,165,189);
floodfill(451,241,3);
gotoxy(24,14);
printf("NO RECORD OF THIS NAME IN DATABASE");
delay(4000);
fflush(stdin);
break;
}
}
fclose(fp);
}


void list_student_record()
{
struct STUDENT_RECORD S;
FILE *fp;
int Y = 6;
cleardevice();
draw_screen();
setcolor(3);
rectangle(614,436,18,45);
rectangle(615,437,17,44);

line(18,65,614,65);
line(17,66,615,66);

line(64,45,64,436);
gotoxy(4,4);
printf("R.NO:");

gotoxy(13,4);
printf("NAME OF STUDENT :");
line(292,45,292,436);

gotoxy(38,4);
printf("ADM DATE :");
line(380,45,380,436);

gotoxy(49,4);
printf("COURSE:");
line(440,45,440,436);

gotoxy(57,4);
printf("FEES :");
line(500,45,500,436);

gotoxy(65,4);
printf(" MOBILE NO :");

fp = fopen("C:\\TURBOC3\\STUDENT1.DAT","rb+");
if(fp==NULL)
{
cleardevice();
draw_screen();
add_window();
gotoxy(30,16);
printf("FILE OPENING ERROR:");
delay(2000);
exit();
}
rewind(fp);

while(fread(&S,sizeof(S),1,fp) == 1)
{
gotoxy(4,Y);
printf("%d",S.ROLL_NO);
gotoxy(10,Y);
printf("%s",S.F_NAME);
gotoxy(19,Y);
printf("%s",S.L_NAME);
gotoxy(38,Y);
printf("%d/%d/%d",S.DAYS,S.MONTH,S.YEAR);
gotoxy(50,Y);
printf("%s",S.COURSE_NAME);
gotoxy(58,Y);
printf("%s",S.FEES);
gotoxy(66,Y);
printf("%s",S.MOBILE_NO);
Y++;
}

delay(10000);
fclose(fp);
}


void student_backup_database()
{
struct STUDENT_RECORD S;
FILE *fp,*backup;
fp = fopen("C:\\TURBOC3\\STUDENT1.DAT","rb+");
if(fp==NULL)
{
cleardevice();
draw_screen();
add_window();
gotoxy(30,16);
printf("FILE OPENING ERROR:");
delay(2000);
exit();
}
backup = fopen("C:\\TURBOC3\\BACKUP.DAT","wb+");
if(fp==NULL)
{
cleardevice();
draw_screen();
add_window();
gotoxy(30,16);
printf("FILE OPENING ERROR:");
delay(2000);
exit();
}
progress();
rewind(fp);
while(fread(&S,sizeof(S),1,fp) == 1)
fwrite(&S,sizeof(S),1,backup);
fclose(backup);
fclose(fp);
}


void progress()
{
int i;
cleardevice();
for(i=170;i<=495;i++)
{
draw_screen();
setfillstyle(1,3);
bar(i,255,150,265);
sound(2*i);
delay(10);
}
nosound();
cleardevice();
draw_screen();
setcolor(10);
gotoxy(12,12);
settextstyle(8,0,3);
outtextxy(135,220,"DATA BACKUP SUCCESSFULLY...|||");
delay(4000);
}

void exit_system()
{
cleardevice();
draw_screen();
setcolor(15);
settextstyle(8,0,1);
outtextxy(140,230,"EXITING THE SYSTEM, PLEASE WAIT...");
delay(2500);
exit(1);
}

void delete_progress()
{
int i;
cleardevice();
draw_screen();
setcolor(6);
rectangle(190,270,420,295);
rectangle(189,271,421,294);
rectangle(188,272,422,293);
for(i=191;i<=419;i++)
{
setfillstyle(1,4);
bar(191,273,i,292);
sound(i++);
delay(15);
}
nosound();
delay(20);
cleardevice();
draw_screen();
setcolor(15);
gotoxy(12,12);
settextstyle(8,0,2);
outtextxy(130,210,"DATA DELETED SUCCESSFULLY...!!!");
delay(2500);
}