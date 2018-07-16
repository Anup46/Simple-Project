/*  Project Name        : Academic Search Engine
    Programming Language: C
    Developed By        : Anup Kumar
    Id                  : CE-16046
    Department          : CSE,MBSTU.    */

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int addinfo_home();
int a_student();
int a_teacher();
int a_course();
int e_student();
int e_course();
int e_teacher();
int s_student();
int s_teacher();
int s_course();
int s_routine();
int u_student();
int u_teacher();
int u_course();
int u_routine(char * fn);
int f_edit();
int search();
int File_edit();
int routine(char *fn);
int course_info(char *fn);
int rep_del(char *r);
int find_year(char * x);

int addinfo_home()
{
    system("cls");
    printf("\n_1. Add Student Information (press 1)\n");
    printf("\n__2. Add Course Information (press 2)\n");
    printf("\n___3. Add Teacher Information (press 3)\n");
    printf("\n____4. Back to Home page (press b)\n\n");

    char x;
    en:
        x = getch();
        if(x=='1') a_student();
        else if(x=='2') a_course();
        else if(x=='3') a_teacher();
        else if(x=='b') search();
        else goto en;
}

int a_student()
{
    system("cls");
   int i,n;
   char sid[100],sy[100],sn[100],dis[100],phone[100],r[100];
   as:
      printf("\n\n_How many student information you want to add:");
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      {
       printf("\n__(%d.)Enter Student name(ex:Anup_Kumar):",i);
       scanf("%s",&sn);
       printf("\n___(%d.)Enter Student ID(ex:CE-16046):",i);
       scanf("%s",&sid);
       printf("\n____(%d.)Enter Student Study Year(ex:2-1):",i);
       scanf("%s",&sy);
       printf("\n____(%d.)Enter Student Result(ex:3.44):",i);
       scanf("%s",&r);
       printf("\n____(%d.)Enter Student Home District(ex:Kushtia):",i);
       scanf("%s",&dis);
       printf("\n____(%d.)Enter Student Phone Number(ex:01*********):",i);
       scanf("%s",&phone);
       FILE * fp;
       fp= fopen("Student.txt","a");
       fprintf(fp,"%s %s %s %s %s %s\n",&sid,&sy,&r,&dis,&phone,&sn);
       fclose(fp);
       }
       system("cls");
       printf("         \n         1. Add Again(press 1):\n");
       printf("         \n         2. Add in Another formate(press 2):\n");
       printf("         \n         3. Edit Student Information(press 3):\n");
       printf("         \n         4. Go to Search page(press 4):\n\n");
       char z;
       ll:
            z = getch();
            if(z=='1') goto as;
            else if(z=='2') addinfo_home();
            else if(z=='3') e_student();
            else if(z=='4') search_home();
            else goto ll;
}

int a_course()
{
    system("cls");
   int i,n;
   char cc[100],ct[100],ctn[100],cy[100],cs[250],cre[100];
   ac:
      printf("\n\n_How many course information you want to add:");
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      {
       printf("\n__(%d.)Enter Course Code(ex:CSE-2211):",i);
       scanf("%s",&cc);
       printf("\n___(%d.)Enter Course Title(ex:):",i);
       scanf("%s",&ct);
       printf("\n____(%d.)Enter Course Year(ex:2-2):",i);
       scanf("%s",&cy);
       printf("\n____(%d.)Enter Course Credit(ex:3.0):",i);
       scanf("%s",&cre);
       printf("\n_____(%d.)Enter Course Teacher Name(ex:Safikul_Islam):",i);
       scanf("%s",&ctn);
       printf("\n______(%d.)Enter Course Schedule(ex:Sunday(4pm-6pm):",i);
       scanf("%s",&cs);
       FILE * fp;
       fp= fopen("course.txt","a");
       fprintf(fp,"%s %s %s %s %s\n",&cc,&ct,&cy,&cre,&ctn,&cs);
       fclose(fp);
   }
   system("cls");
       printf("         \n         1. Add Again(press 1):\n");
       printf("         \n         2. Add in Another format(press 2):\n");
       printf("         \n         3. Go to Search page(press 3):\n\n");
       char z;
       ll:
            z = getch();
            if(z=='1') goto ac;
            else if(z=='2') addinfo_home();
            else if(z=='3') search_home();
            else goto ll;
}

int a_teacher()
{
    system("cls");
   int i,n;
   char tn[100],tp[100],dept[100];
   at:
     printf("\n\n_How many Teacher information you want to add:");
     scanf("%d",&n);
     for(i=1;i<=n;i++)
   {
    printf("\n__(%d.)Enter Teacher name(ex:Mohammad_Asraful_Islam):",i);
    scanf("%s",&tn);
    printf("\n___(%d.)Enter Profession Position(ex:Lecturer):",i);
    scanf("%s",&tp);
    printf("\n____(%d.)Enter Department(ex:CSE):",i);
    scanf("%s",&dept);
    FILE * fp;
    fp=fopen("Teacher.txt","a");
    fprintf(fp,"%s  %s  %s\n",&tn,&tp,&dept);
    fclose(fp);
    }
    system("cls");
       printf("         \n         1. Add Again(press 1):\n");
       printf("         \n         2. Add in Another format(press 2):\n");
       printf("         \n         3. Go to Search page(press 3):\n\n");
       char z;
       ll:
            z = getch();
            if(z=='1') goto at;
            else if(z=='2') addinfo_home();
            else if(z=='3') search_home();
            else goto ll;
}

int search_home()
{
    system("cls");
    printf("\n_1. Search By Student ID (press 1)\n");
    printf("\n__2. Search By Course Code (press 2)\n");
    printf("\n___3. Search By Teacher Name (press 3)\n");
    printf("\n____4. Search Routine By Semester (press 4)\n");
    printf("\n_____5. Back to Home page (press b)\n\n");


    char x;
    en:
        x = getch();
        if(x=='1') s_student();
        else if(x=='2') s_course();
        else if(x=='3') s_teacher();
        else if(x=='4') s_routine();
        else if(x=='b') search();
        else goto en;
}
int s_student()
{
    system("cls");
    FILE* fp;
    char a[250];
    char line[1000];
    char s_roll[100];
    int check = 0;
    int i=0;
    S_S:
        fp = fopen("Student.txt","r");
        system("cls");
        printf("\n\n   Enter student roll(ex: CE-16046):");
        scanf("%s",&s_roll);
        while(fgets(line,sizeof(line),fp)){
            char roll[100],name[100],year[100],dis[100],phone[100],r[100];
            sscanf(line,"%s %s %s %s %s %s",&roll,&year,&r,&dis,&phone,&name);
            i++;
            int z = strcmp(s_roll,roll);
            if(z==0){
                printf("      \n    Student ID   : %s\n",roll);
                printf("      \n    Student Name : %s\n",name);
                printf("      \n    Study Year   : %s\n",year);
                printf("      \n    CGPA         : %s\n",r);
                printf("      \n    Home District: %s\n",dis);
                printf("      \n    Phone Number : %s\n",phone);
                printf("      \n  Information found in line: %d\n",i);
                printf("  ---Showing wrong info...\n ____Want to update it press 'u':\n_______Delete/replace press'e':\n\n");
                check = 1;
                i=0;
                break;
                    }
            }
        i=0;
        fclose(fp);
        if(check==0)
            {
            printf("      \n      Sorry!! The entry is not found!!.\a\n");
            printf("     This may be your typing mistake or you are not following the example...\n ");
            printf("    Please type correctly and try again.\n");
            }

        printf("         \n         1. Search Again(press 1).\n");
        printf("         \n         2. Search in Another Format(press 2).\n");
        printf("         \n         3. Add/Edit (press 3).\n\n");
        char z;
        ll:
            z = getch();
            if(z=='e') e_student();
            else if(z=='1') goto S_S;
            else if(z=='2') search_home();
            else if(z=='3') f_edit();
            else if(z=='u') u_student();
            else goto ll;
        }
int u_student()
{
    int g;
    printf(" ***Enter The line no. where the information is found:");
    scanf("%d",&g);
    ss:
        {
            int i=0;
        char sid[100],sid1[100],sy[100],sy1[100],sn[100],sn1[100],a[350],line[1000];
        char sdis[100],sdis1[100],sphone[100],sphone1[100],scg[100],scg1[100];
                  {FILE * fptr1 ;
                  FILE * fptr2 ;
                  FILE *f;
                  f=fopen("Student.txt","r");
                  while(fgets(line,sizeof(line),f)){
            i++;}
            fclose(f);
            int lno=g;
            g=i;
            i=0;
                  int line = 0;
                  char str[300];
                  char r[200] = "Student.txt";
                char newln[300], temp[] = "temp.txt";
                fptr1 = fopen(r, "r");
                fptr2 = fopen(temp, "w");
           while (!feof(fptr1))
           {
            strcpy(str, "\0");
            fgets(str, 300, fptr1);
            if (!feof(fptr1))
            {
                line++;
                if (line != lno)
                    {
                        fprintf(fptr2, "%s", str);
                    }
                else
                {
                    strcpy(a,str);
                }
                }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(r);
        rename(temp, r);}

                system("cls");
                printf("\n_Update Name press 1:\n");
                printf("\n__Update ID press 2:\n");
                printf("\n___Update Year press 3:\n");
                printf("\n____Update CGPA press 4:\n");
                printf("\n_____Update Home District press 5:\n");
                printf("\n______Update Phone no. press 6:\n\n");
                char m;
                rr:
                    m=getch();
                    if (m=='1')
                    {
                       system("cls");
                       printf("\nEnter Correct name(ex:Anup_Kumar):\n");
                       scanf("%s",&sn1);
                       sscanf(a,"%s %s %s %s %s %s",&sid,&sy,&scg,&sdis,&sphone,&sn);
                       strcpy(sn,sn1);
                       FILE * fp1;
                        fp1= fopen("Student.txt","a");
                        fprintf(fp1,"%s %s %s %s %s %s\n",&sid,&sy,&scg,&sdis,&sphone,&sn);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");

                           tt:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto tt;}
                    }
                    else if(m=='2')
                    {
                        system("cls");
                        printf("\nEnter Correct Id(ex:CE-16046):\n");
                       scanf("%s",&sid1);
                       sscanf(a,"%s %s %s %s %s %s",&sid,&sy,&scg,&sdis,&sphone,&sn);
                       strcpy(sid,sid1);
                       FILE * fp1;
                        fp1= fopen("Student.txt","a");
                        fprintf(fp1,"%s %s %s %s %s %s\n",&sid,&sy,&scg,&sdis,&sphone,&sn);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");
                       w:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto w;}
                    }
                    else if(m=='3')
                    {
                           system("cls");
                        printf("\nEnter Correct Study Year(ex:2-1):\n");
                       scanf("%s",&sy1);
                       sscanf(a,"%s %s %s %s %s %s",&sid,&sy,&scg,&sdis,&sphone,&sn);
                       strcpy(sy,sy1);
                       FILE * fp1;
                        fp1= fopen("Student.txt","a");
                        fprintf(fp1,"%s %s %s %s %s %s\n",&sid,&sy,&scg,&sdis,&sphone,&sn);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");
                       f:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto f;}
                    }
                    else if(m=='4')
                    {

                    system("cls");
                        printf("\nEnter Correct CGPA(ex:3.44):\n");
                       scanf("%s",&scg1);
                       sscanf(a,"%s %s %s %s %s %s",&sid,&sy,&scg,&sdis,&sphone,&sn);
                       strcpy(scg,scg1);
                       FILE * fp1;
                        fp1= fopen("Student.txt","a");
                        fprintf(fp1,"%s %s %s %s %s %s\n",&sid,&sy,&scg,&sdis,&sphone,&sn);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");

                        p:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto p;}
                    }
                    else if(m=='5')
                    {

                    system("cls");
                        printf("\nEnter Correct Home District(Kushtia):\n");
                       scanf("%s",&sdis1);
                       sscanf(a,"%s %s %s %s %s %s",&sid,&sy,&scg,&sdis,&sphone,&sn);
                       strcpy(sdis,sdis1);
                       FILE * fp1;
                        fp1= fopen("Student.txt","a");
                        fprintf(fp1,"%s %s %s %s %s %s\n",&sid,&sy,&scg,&sdis,&sphone,&sn);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");

                        h:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto h;}
                    }
                    else if(m=='6')
                    {

                    system("cls");
                        printf("\nEnter Correct Phone number(ex:017*******):\n");
                       scanf("%s",&sphone1);
                       sscanf(a,"%s %s %s %s %s %s",&sid,&sy,&scg,&sdis,&sphone,&sn);
                       strcpy(sphone,sphone1);
                       FILE * fp1;
                        fp1= fopen("Student.txt","a");
                        fprintf(fp1,"%s %s %s %s %s %s\n",&sid,&sy,&scg,&sdis,&sphone,&sn);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");

                        x:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto x;}
                    }
                    else goto rr;
    }
}

int u_course()
{
  int g;
    printf(" ***Enter The line no. where the information is found:");
    scanf("%d",&g);
    ss:
        {
            int i=0;
            char cc[100],ct[100],ctn[100],cy[100],cs[250],cre[100],tmp[300],line[1000],a[250];
                  {FILE * fptr1 ;
                  FILE * fptr2 ;
                  FILE *f;
                  f=fopen("course.txt","r");
                  while(fgets(line,sizeof(line),f)){
            i++;}
            fclose(f);
            int lno=g;
            g=i;
            i=0;
                  int line = 0;
                  char str[300];
                  char r[200] = "course.txt";
                char newln[300], temp[] = "temp.txt";
                fptr1 = fopen(r, "r");
                fptr2 = fopen(temp, "w");
           while (!feof(fptr1))
           {
            strcpy(str, "\0");
            fgets(str, 300, fptr1);
            if (!feof(fptr1))
            {
                line++;
                if (line != lno)
                    {
                        fprintf(fptr2, "%s", str);
                    }
                else
                {
                    strcpy(a,str);
                }
                }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(r);
        rename(temp, r);}

                system("cls");
                printf("\n_Update course code press 1:\n");
                printf("\n__Update course title press 2:\n");
                printf("\n___Update course year press 3:\n");
                printf("\n____Update course credit press 4:\n");
                printf("\n_____Update course teacher press 5:\n");
                printf("\n______Update course schedule press 6:\n\n");
                char m;
                rr:
                   {
                    m=getch();
                    if (m=='1')
                    {
                       system("cls");
                       printf("\nEnter Correct course code(ex:CSE-2211):\n");
                       scanf("%s",&tmp);
                       sscanf(a,"%s %s %s %s %s %s",&cc,&ct,&cy,&cre,&ctn,&cs);
                       strcpy(cc,tmp);
                       FILE * fp1;
                        fp1= fopen("course.txt","a");
                        fprintf(fp1,"%s %s %s %s %s %s\n",&cc,&ct,&cy,&cre,&ctn,&cs);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");

                           tt:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto tt;}
                    }
                    else if(m=='2')
                    {
                        system("cls");
                        printf("\nEnter Correct Course Title(ex:Math-4):\n");
                       scanf("%s",&tmp);
                       sscanf(a,"%s %s %s %s %s %s",&cc,&ct,&cy,&cre,&ctn,&cs);
                       strcpy(ct,tmp);
                       FILE * fp1;
                        fp1= fopen("course.txt","a");
                        fprintf(fp1,"%s %s %s %s %s %s\n",&cc,&ct,&cy,&cre,&ctn,&cs);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");
                       w:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto w;}
                    }
                    else if(m=='3')
                    {
                           system("cls");
                        printf("\nEnter Correct Course Year(ex:2-1):\n");
                       scanf("%s",&tmp);
                       sscanf(a,"%s %s %s %s %s %s",&cc,&ct,&cy,&cre,&ctn,&cs);
                       strcpy(cy,tmp);
                       FILE * fp1;
                        fp1= fopen("course.txt","a");
                        fprintf(fp1,"%s %s %s %s %s %s\n",&cc,&ct,&cy,&cre,&ctn,&cs);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");
                       f:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto f;}
                    }
                    else if(m=='4')
                    {

                    system("cls");
                        printf("\nEnter Course Credit(ex:3.0):\n");
                       scanf("%s",&tmp);
                       sscanf(a,"%s %s %s %s %s %s",&cc,&ct,&cy,&cre,&ctn,&cs);
                       strcpy(cre,tmp);
                       FILE * fp1;
                        fp1= fopen("course.txt","a");
                        fprintf(fp1,"%s %s %s %s %s %s\n",&cc,&ct,&cy,&cre,&ctn,&cs);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");

                        p:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto p;}
                    }
                    else if(m=='5')
                    {

                    system("cls");
                        printf("\nEnter Correct Course Teacher Name(Safiul_Islam):\n");
                       scanf("%s",&tmp);
                       sscanf(a,"%s %s %s %s %s %s",&cc,&ct,&cy,&cre,&ctn,&cs);
                       strcpy(ctn,tmp);
                       FILE * fp1;
                        fp1= fopen("course.txt","a");
                        fprintf(fp1,"%s %s %s %s %s %s\n",&cc,&ct,&cy,&cre,&ctn,&cs);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");

                        h:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto h;}
                    }
                    else if(m=='6')
                    {

                    system("cls");
                        printf("\nEnter Course Schedule(Sunday(4pm-6pm);Monday(4pm-5pm)):\n");
                       scanf("%s",&tmp);
                       sscanf(a,"%s %s %s %s %s %s",&cc,&ct,&cy,&cre,&ctn,&cs);
                       strcpy(cs,tmp);
                       FILE * fp1;
                        fp1= fopen("course.txt","a");
                        fprintf(fp1,"%s %s %s %s %s %s\n",&cc,&ct,&cy,&cre,&ctn,&cs);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");

                        x:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto x;}
                    }
                    else goto rr;}
    }

}

int s_course()
{
    system("cls");
       FILE* fp;
       char line[1000];
       char c_code[100];
       int check = 0;
       int i=0;
    C_C:
        fp = fopen("course.txt","r");
        system("cls");
        printf("    \n \n     Enter the course code(ex: CSE-2211): ");
        scanf("%s",c_code);
        while(fgets(line,sizeof(line),fp))
            {
            char code[100],subject[100],year[100],tn[100],cs[250],cre[100];
            sscanf(line,"%s %s %s %s %s %s",&code,&subject,&year,&cre,&tn,&cs);
            i++;
            int z = strcmp(code,c_code);
            if(z==0){
                check = 1;
                printf("      \n   Course Code   :   %s\n",code);
                printf("      \n   Course Title  :   %s\n",subject);
                char year[100];
                year[0] = code[4];
                year[1] = code[5];
                find_year(year);
                printf("      \n   Year          :   %s\n",year);
                printf("      \n   Course Credit :   %s\n",cre);
                printf("      \n   Course Teacher:   %s\n",tn);
                printf("      \n   Course Schedule:  %s\n",cs);
                printf("      \n Information found in line: %d\n",i);
                printf("  ---Showing wrong info...\n\n____Want to Update it press 'u':\n____Replace/Delete press'e':\n\n");
                i=0;
            }
        }
        i=0;
        fclose(fp);
        if(check==0) {printf("      \n     Sorry!! The entry not found!!\a\n");
        printf("     This may be your typing mistake or you are not following the example...\n ");
        printf("     Please type correctly and try again.\n");}

       printf("         \n         1. Search Again(press 1).\n");
       printf("         \n         2. Search In Another Format(press 2).\n");
       printf("         \n         3. Add/Edit Information (press 3).\n\n");
       char z;
       ll:
            z = getch();
            if (z=='e') e_course();
            else if(z=='1') goto C_C;
            else if(z=='2') search_home();
            else if(z=='3') f_edit();
            else if(z=='u') u_course();
            else goto ll;
}
int s_teacher()
{
    system("cls");
    char line[1000],line1[1000],t_n[100],tn[100],tp[100],dept[100];
    int check=0, i=0,j=0,d;
    S_T:
        system("cls");
      printf("\n\n  Enter Teacher Name(ex:Mohammad_Asraful_Islam):");
      scanf("%s",tn);
      FILE* fp;
      fp = fopen("Teacher.txt","r");
      while(fgets(line,sizeof(line),fp))
      {
      sscanf(line,"%s %s %s",&t_n,&tp,&dept);
      i++;
      j++;
      int z = strcmp(t_n,tn);
      if(z==0)
           {
            check++;
            printf("      \n   Name               :   %s\n",t_n);
            printf("      \n   Profession Position:   %s\n",tp);
            printf("      \n   Department         :   %s\n",dept);
            printf("      \n   Course Information :\n\n");

            if((d=strcmp("Mohammad_Motiur_Rahman",tn))==0)
            {
                char fn[100]="Motiur_s.txt";
                course_info(fn);
            }

            else if((d=strcmp("Mostofa_Kamal_Nasir",tn))==0)
            {
                char fn[100]="Nasir_s.txt";
                course_info(fn);
            }
            else if((d=strcmp("Mohammad_Hadifur_Rahman",tn))==0)
            {
                char fn[100]="Hadifur_s.txt";
                course_info(fn);
            }
            else if((d=strcmp("Delowar_Hossain",tn))==0)
            {
                char fn[100]="Delowar_s.txt";
                course_info(fn);
            }
            else if((d=strcmp("Mosaddik_Hasan",tn))==0)
            {
                char fn[100]="Mosaddik_s.txt";
                course_info(fn);
            }
            else if((d=strcmp("Mahfuz_Reza",tn))==0)
            {
                char fn[100]="Mahfuz_s.txt";
                course_info(fn);
            }
            else if((d=strcmp("Mahbuba_Begum",tn))==0)
            {
                char fn[100]="Mahbuba_m.txt";
                course_info(fn);
            }
            else if((d=strcmp("Mohammad_Asraful_Islam",tn))==0)
            {
                char fn[100]="Asraful_s.txt";
                course_info(fn);
            }
            else if((d=strcmp("Lubna_Yasmin_Pinky",tn))==0)
            {
                char fn[100]="Pinky_m.txt";
                course_info(fn);
            }
            else if((d=strcmp("Mezbahul_Islam",tn))==0)
            {
                char fn[100]="Mezbahul_s.txt";
                course_info(fn);
            }
            else if((d=strcmp("Masum_Haider",tn))==0)
            {
                char fn[100]="Masum_s.txt";
                course_info(fn);
            }
            else if((d=strcmp("Mijanoor_Rahman",tn))==0)
            {
                char fn[100]="Mijanur_s.txt";
                course_info(fn);
            }
            else if((d=strcmp("Abu_Rashed",tn))==0)
            {
                char fn[100]="Rashed_s.txt";
                course_info(fn);
            }
            else if((d=strcmp("Safikul_Islam",tn))==0)
            {
                char fn[100]="Safikul_s.txt";
                course_info(fn);
            }
            else
            {
                printf("***Your Updated name is not Matching with our Library!!\n");
                printf("_____To show Course Schedule Please Update it Correctly!!\n");
            }
            printf("         \n  ______Information Found in line: %d\n",j);
            printf("****Showing wrong Information*****\n");
            printf("\n_____Update information press 'u':\n");
            printf("_______Replace or Delete press 'e':\n");
           }

      }
      i=0;
      j=0;
      fclose(fp);
      if(check==0)
           {
            printf("\n  Sorry!!\a\n  Your Entry is not Found!!\n");
            printf("     This may be your typing mistake or you are not following the example...\n ");
            printf("     Please type correctly and try again.\n");
            }
      printf("         \n         1. Search Again(press 1).\n");
      printf("         \n         2. Search In Another Format(press 2).\n");
      char m;
      ll:
            m = getch();
            if(m=='1') goto S_T;
            else if(m=='2') search_home();
            else if(m=='u') u_teacher();
            else if(m=='e') e_teacher();
            else goto ll;
}

int u_teacher()
{
    int g;
    printf(" ***Enter The line no. where the information is found:");
    scanf("%d",&g);
    ss:
        {
            int i=0;
           char tn[100],tp[100],dept[100], tmp[400],line[1000],a[250];
                  {FILE * fptr1 ;
                  FILE * fptr2 ;
                  FILE *f;
                  f=fopen("Teacher.txt","r");
                  while(fgets(line,sizeof(line),f)){
            i++;}
            fclose(f);
            int lno=g;
            g=i;
            i=0;
                  int line = 0;
                  char str[300];
                  char r[200] = "Teacher.txt";
                char newln[300], temp[] = "temp.txt";
                fptr1 = fopen(r, "r");
                fptr2 = fopen(temp, "w");
           while (!feof(fptr1))
           {
            strcpy(str, "\0");
            fgets(str, 300, fptr1);
            if (!feof(fptr1))
            {
                line++;
                if (line != lno)
                    {
                        fprintf(fptr2, "%s", str);
                    }
                else
                {
                    strcpy(a,str);
                }
                }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(r);
        rename(temp, r);}

                system("cls");
                printf("\n_Update Teacher Name 1:\n");
                printf("\n__Update Profession Position 2:\n");
                printf("\n___Update Department Name 3:\n\n");
                char m;
                rr:
                   {
                    m=getch();
                    if (m=='1')
                    {
                       system("cls");
                       printf("\nEnter Correct Name(ex:Mohammad_Asraful_Islam):\n");
                       scanf("%s",&tmp);
                       sscanf(a,"%s %s %s",&tn,&tp,&dept);
                       strcpy(tn,tmp);
                       FILE * fp1;
                        fp1= fopen("Teacher.txt","a");
                        fprintf(fp1,"%s %s %s\n",&tn,&tp,&dept);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");

                           tt:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto tt;}
                    }
                    else if(m=='2')
                    {
                        system("cls");
                        printf("\nEnter Profession Position(ex:Lecturer):\n");
                       scanf("%s",&tmp);
                       sscanf(a,"%s %s %S",&tn,&tp,&dept);
                       strcpy(tp,tmp);
                       FILE * fp1;
                        fp1= fopen("Teacher.txt","a");
                        fprintf(fp1,"%s %s %s\n",&tn,&tp,&dept);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");
                       w:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto w;}
                    }
                    else if(m=='3')
                    {
                           system("cls");
                        printf("\nEnter Correct Department(ex:Computer_Science_and_Engineering):\n");
                       scanf("%s",&tmp);
                       sscanf(a,"%s %s %s",&tn,&tp,&dept);
                       strcpy(dept,tmp);
                       FILE * fp1;
                        fp1= fopen("Teacher.txt","a");
                        fprintf(fp1,"%s %s %s\n",&tn,&tp,&dept);
                        fclose(fp1);
                       printf("\n_____Information has been updated!!\n\n");
                       printf("___1.Update in Another format press 1:\n");
                       printf("____2.Go to Search Page press 2:\n\n");
                       f:
                           {char j;
                           j=getch();
                           if(j=='1') goto ss;
                           else if (j=='2') search_home();
                           else goto f;}
                    }
        else goto rr;}
        }
}

int s_routine()
{
   system("cls");
   printf("__1.View 1st Year 2nd Semester Class Schedule(press 1)\n");
   printf("\n___2.View 2nd Year 2nd Semester Class Schedule(press 2)\n");
   printf("\n____3.View 3rd Year 1st Semester Class Schedule(press 3)\n");
   printf("\n_____4.View 3rd Year 2nd Semester Class Schedule(press 4)\n");
   printf("\n______5.View 3rd Year 2nd Semester Class Schedule(press 5)\n\n");
   char m;
   ll:
      m=getch();
      if(m=='1')
        {system("cls");
        printf("_____1st Year 2nd Semester class schedule:\n\n");
            char fn[100]="1-2.txt";
                routine(fn);
                printf("\n****Showing wrong Schedule****\n");
                printf("\n____Update It press 'u':\n");
                printf("\n____Or,,Press any key to show other option:\n");
                    char r[100]="1-2.txt";
                    char m;
                    m=getch();
                    if(m=='u') u_routine(r);
                }
       else if(m=='2')
       {system("cls");
        printf("_____2nd Year 2nd Semester class schedule:\n\n");
           char fn[100]="2-2.txt";
                routine(fn);
                printf("\n****Showing wrong Schedule****\n");
                printf("\n____Update It press 'u':\n");
                printf("\n____Or,,Press any key to show other option:\n");
                    char r[100]="2-2.txt";
                    char m;
                    m=getch();
                    if(m=='u') u_routine(r);
       }
       else if(m=='3')
        {system("cls");
        printf("_____3rd Year 1st Semester class schedule:\n\n");
            char fn[100]="3-1.txt";
                routine(fn);
                printf("\n****Showing wrong Schedule****\n");
                printf("\n____Update It press 'u':\n");
                printf("\n____Or,,Press any key to show other option:\n");
                    char r[100]="3-1.txt";
                    char m;
                    m=getch();
                    if(m=='u') u_routine(r);
        }
        else if(m=='4')
        {
            system("cls");
        printf("_____3rd Year 2nd Semester class schedule:\n\n");
        char fn[100]="3-2.txt";
                routine(fn);
                printf("\n****Showing wrong Schedule****\n");
                printf("\n____Update It press 'u':\n");
                printf("\n____Or,,Press any key to show other option:\n");
                    char r[100]="3-2.txt";
                    char m;
                    m=getch();
                    if(m=='u') u_routine(r);
                }
        else if(m=='5')
        {system("cls");
        printf("_____4th Year 2nd Semester class schedule:\n\n");
            char fn[100]="4-2.txt";
                routine(fn);
                printf("\n****Showing wrong Schedule****\n");
                printf("\n____Update It press 'u':\n");
                printf("\n____Or,,Press any key to show other option:\n");
                    char r[100]="4-2.txt";
                    char m;
                    m=getch();
                    if(m=='u') u_routine(r);
        }
        else goto ll;
      printf("         \n         1. Search Again(press 1).\n");
      printf("         \n         2. Search In Another Format(press 2).\n");
      char n;
      rr:
            n = getch();
            if(n=='1') s_routine();
            else if(n=='2') search_home();
            else goto rr;
}

int u_routine(char *fn)
{
    ll:
        {
    int i=0,check=0,line=0;
    char day[100],d[100],n[50],sc[500],line1[1000],str[200],s[300],sem[100];
    strcpy(sem,fn);
    printf("___Enter the day name for update:(Sunday):");
    scanf("%s",&day);
    FILE *f;
    f=fopen(fn,"r");
    while(fgets(line1,sizeof(line1),f))
      {
      sscanf(line1,"%s %s %s",&d,&n,&sc);
      i++;
      int z = strcmp(d,day);
      if(z==0)
      {
          check++;
         break;
      }
      }
      fclose(f);
      if(check!=0)
      {
           FILE *fptr1,*fptr2;
           char temp[] = "temp.txt";
          printf(" \nEnter the Updated Schedule(ex:CSE-2203(9am-10am;___;___;):\n");
          getchar();
          gets(s);
        int lno=i;
        i=0;
        fptr1 = fopen(sem, "r");
        fptr2 = fopen(temp, "w");
        while (!feof(fptr1))
        {
            strcpy(str, "\0");
            fgets(str, 500 , fptr1);
            if (!feof(fptr1))
            {
                line++;
                if (line == lno)
                    {
                fprintf(fptr2,"     %s %s %s\n",d,n,s);
                 }
            else
                    {
                        fprintf(fptr2, "%s", str);
                    }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(sem);
        rename(temp, sem);
        printf(" \nInformation Updated successfully..!! \n");
      }
      else if(check==0)
      {
          printf("_____Your Given Information Is Not Correct!!\n");
      }
      i=0;
      printf("\n_Update again press 1:\n");
      printf("\n__Go to Search Page press 2:\n");
      rr:
          {
              char m;
              m=getch();
              if(m=='1') goto ll;
              else if(m=='2') search_home();
              else goto rr;
          }
          }

}

int routine(char * fn)
{
    FILE *f;
    char line1[1000];
                f=fopen(fn,"r");
                while(fgets(line1,sizeof(line1),f))
                {
                    printf("%s\n",line1);
                }
                fclose(f);
}

int course_info(char * fn)
{
    FILE *f;
    char line1[1000];
                f=fopen(fn,"r");
                while(fgets(line1,sizeof(line1),f))
                {
                    printf("%s\n",line1);
                }
                fclose(f);
}

int f_edit()
{ system("cls");
    char m;
    printf("  ___1.Add Information press 1:\n\n");
    printf("   ____2.Edit Information press 2:\n\n");
    ll:
    m = getch();
    if(m=='1') addinfo_home();
    else if(m=='2') File_edit();
    else goto ll;
}

int File_edit()
{
    system("cls");
    char m;
   printf("    \n___1.Edit Student Information(press 1):\n");
   printf("    \n_____2.Edit Course Information(press 2):\n\n\n");
   ll:
   m = getch();
    if(m=='1') e_student();
    else if(m=='2') e_course();
    else goto ll;
}

int e_student()
{
    system("cls");
    printf("***In Case of replacing,, Input should be as:***\n");
    printf("   Student_ID  Study_year  CGPA  Home_District  Phone_number  Student_name  \n");
    ss:
         {char fn[300]="Student.txt";
          rep_del(fn);
          printf("         \n         1. Edit again (press a).\n");
          printf("         \n         2. Add/Edit (press e).\n");
          printf("         \n         3. Go to search home(press s).\n\n");
      char m;
      ee:
            m = getch();
            if(m=='s') {search_home();}
            else if(m=='a') goto ss;
            else if(m=='e') {f_edit();}
            else goto ee;
            return 0;}

}

int e_course()
{
    system("cls");
    printf("***In Case of replacing,, Input should be as:***\n");
    printf("   Course_Code  Course_Title  Course_year  Course_Credit  Course_Teacher_name  Course_Schedule   \n");
    ee:
      {
      char fn[300]="course.txt";
      rep_del(fn);
        printf("         \n         1. Edit again (press a).\n");
        printf("         \n         2. Add/Edit (press e).\n");
        printf("         \n         3. Go to search home(press s).\n\n");
      char m;
      ss:
            m = getch();
            if(m=='e') {f_edit();}
            else if(m=='a') goto ee;
            else if(m=='s') {search_home();}
            else goto ss;
            return 0;}

}

int e_teacher()
{
    system("cls");
    printf("***In Case of replacing,, Input should be as:***\n");
    printf("   Teacher_name   Profession_Position   Department   \n");
    ee:
      {
      char fn[300]="Teacher.txt";
      rep_del(fn);
        printf("         \n         1. Edit again (press a).\n");
        printf("         \n         3. Go to search home(press s).\n\n");
      char m;
      ss:
            m = getch();
            if(m=='a') goto ee;
            else if(m=='s') {search_home();}
            else goto ss;
            return 0;}
}

int rep_del(char *r)
  {
        FILE *fptr1, *fptr2;
        int lno, line = 0;
        char str[300];
        char newln[300], temp[] = "temp.txt";
        char m;
        printf("    \n___ For Replace Information press 1:\n");
        printf("    \n_____For Delete Information press 2:\n");
        rd:
            m = getch();
            if(m=='1') {
                getchar();
        printf(" \nEnter the content for the line you want to replace:\n");
        fgets(newln,300,stdin);
        printf(" \nInput the line no. you want to replace : ");
        scanf("%d", &lno);
        fptr1 = fopen(r, "r");
        fptr2 = fopen(temp, "w");
        while (!feof(fptr1))
        {
            strcpy(str, "\0");
            fgets(str, 300, fptr1);
            if (!feof(fptr1))
            {
                line++;
                if (line != lno)
                    {
                        fprintf(fptr2, "%s", str);
                    }
                else
                    {
                        fprintf(fptr2, "%s", newln);
                    }
                }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(r);
        rename(temp, r);
        printf(" \nReplacement did successfully..!! \n");
            }

        else if(m='2')
                {
        printf(" \nInput the line no. you want to delete : ");
        scanf("%d", &lno);
        fptr1 = fopen(r, "r");
        fptr2 = fopen(temp, "w");
        while (!feof(fptr1))
        {
            strcpy(str, "\0");
            fgets(str, 300, fptr1);
            if (!feof(fptr1))
            {
                line++;
                if (line != lno)
                    {
                        fprintf(fptr2, "%s", str);
                    }
                }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(r);
        rename(temp, r);
        printf(" \nLine deleted successfully..!! \n");
        }

        else goto rd;


  }
int find_year(char* x)
{
    if(x[0]=='1' && x[1]=='1'){
        strcpy(x,"1st Year 1st Semester");
    }
    else if(x[0]=='1' && x[1]=='2'){
        strcpy(x,"1st Year 2nd Semester");
    }
    else if(x[0]=='2' && x[1]=='1'){
        strcpy(x,"2nd Year 1st Semester");
    }
    else if(x[0]=='2' && x[1]=='2'){
        strcpy(x,"2nd Year 2nd Semester");
    }
    else if(x[0]=='3' && x[1] == '1'){
        strcpy(x,"3rd Year 1st Semester");
    }
    else if(x[0]=='3' && x[1]=='2'){
        strcpy(x,"3rd Year 2nd Semester");
    }
    else if(x[0]=='4' && x[1]=='1'){
        strcpy(x,"4th Year 1st Semester");
    }
    else if(x[0]=='4' && x[1]=='2'){
        strcpy(x,"4th Year 2nd Semester");
    }
}

int search()
{
    char x;
    printf("\n   1.Search Information (press 1):\n\n   2.Add Information (press 2):\n\n");
     en:
        x = getch();
        if(x=='1') search_home();
        else if(x=='2') addinfo_home();
        else goto en;
}

int main()
{

    printf("\n______Welcome To My Academic Search Engine !!\n\n");
    search();

    return 0;
}
