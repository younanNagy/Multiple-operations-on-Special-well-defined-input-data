// Multiple operations on string with c++.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;

int get_days(string date)
{
    int days[3];string days1[3];int x=0,n=0,a=0;
    for(int i=0;i<=date.length();i++)
    {
        if(date[i]=='/'||i==(date.length()))
        {
            days1[a]=date.substr(x,n);
            x=x+((days1[a].length())+1);
            n=n-((days1[a].length())+1);
            days[a]=atoi(days1[a].c_str());
            a++;
        }
        n++;
    }
    int i,days2=0;
    for(i=2000;i<days[2];i++)
    {
        if((i%4==0&&i%100!=0)||i%400==0)
         days2+=366;

         else
            days2=365;
    }
    for(i=1;i<days[1];i++)
    {
        if(i==2)
        {
          if((days[2]%4==0&&days[2]%100!=0)||days[2]%400==0)
          days2+=29;

          else
            days2+=28;
        }
        else if(i==4||i==6||i==9||i==11)
            days2+=30;

        else
            days2+=31;

    }
    days2+=days[0];

    return days2;
}

//function of courses number
int Number_Courses (string courses_exams_data)
{
   int i;
   int n=0;
    for(i=0;i<courses_exams_data.length();i++)
 {
    if(courses_exams_data[i]==';')
   {
       n=n+1;
   }
}
 return n+1;
}

//************************************************************************************//
//function of students number
int Number_student (string students_data)
{
   int i;
   int n=0;
    for(i=0;i<students_data.length();i++)
 {
    if(students_data[i]==';')
   {
       n=n+1;
   }
}
 return n+1;
}
//*********************************************************************************************//
int main(void)
{
string courses_exams[100][4];


    int i,row=0,n=-14/*the last letter of the data element*/,
    coloumn1=0/*the length of previous element of data*/,
    coloumn=0,
    x=14;/*the first letter of the data element*/ ;//loumn3=0,coloumn4=0;

    string courses_exams_data;
     string students_data;
    getline(cin,courses_exams_data);

  getline(cin,students_data);//cout<<courses_exams_data.substr(15,n);for(u=0;u<courses_exams_data.length();u++)


   for(i=0;i<courses_exams_data.length();i++)
 {

  if(courses_exams_data[i]==','||courses_exams_data[i]==']'||courses_exams_data[i]==';')
   {

    courses_exams[row][coloumn]=courses_exams_data.substr(x,n);

    coloumn1=(courses_exams[row][coloumn].length())+1;

       x=x+coloumn1;
       n=n-coloumn1;

    coloumn=coloumn+1;

   }

     if(coloumn==4)
    {
     row=row+1;
     coloumn=0;
    }
   n=n+1;

 }
 //**************************************************//
 //**********************************************************************************************//تقطيع السترينج بتاعة الطلبه
 string students[100][12];
 int courses_number[100];
 i=0;n=-10;x=10;row=0;coloumn1=0;coloumn=0;
 int cn=0,S=0,k=0;
   for(i=0;i<students_data.length();i++)
 {
     if(students_data[i]=='(')
     {
         x++;n--;
     }
      if(students_data[i]==')')
     {
         n--;
     }
      if(students_data[i]==',')
      {
          cn++;
      }

      if(students_data[i]==';'||students_data[i]==']')
      {
          courses_number[S]=cn-1;
          cn=0;
          S++;
      }

  if(students_data[i]==','||students_data[i]==']'||students_data[i]==';')
   {

    students[row][coloumn]=students_data.substr(x,n);

    coloumn1=(students[row][coloumn].length())+1;

       x=x+coloumn1;
       n=n-coloumn1;

    coloumn=coloumn+1;

   }

     if(students_data[i]==';')
    {
     row=row+1;
     coloumn=0;
     x++;
    }
   n=n+1;

 }
 //***************************************************************************************************//تقطيعة التاريخ
 int R=Number_student(students_data);
 int z=Number_Courses(courses_exams_data);

//float MAX_year,MAX_month,MAX_day,MIN_year,MIN_month,MIN_day,days_number;

    string exams_date[100][3]; float exams_date2[100][3];

     i=0;
     int q=0;
     x=0;
     n=0,row=0;
     coloumn=0;
     coloumn1=0;
     int A=-1;


    for(i;i<courses_exams[q][2].length()+1;i++)
    {
      if(courses_exams[q][2][i]=='/'||A==(courses_exams[q][2].length())-1)
       {

         exams_date[row][coloumn]=courses_exams[q][2].substr(x,n);

        exams_date2[row][coloumn]= atof((exams_date[row][coloumn]).c_str());

         coloumn1=(exams_date[row][coloumn].length())+1;

         x=x+coloumn1;
         n=n-coloumn1;

        coloumn=coloumn+1;

       }

           if(coloumn==3)
            {

              row=row+1;
              coloumn=0;
              q=q+1; i=0; A=-1; n=n+1; x=0;
            }

    n=n+1;A=A+1;
       if(q==z)
      {
        break;
      }

    }//the end of the loop
 float min_year=(pow(2.0,16.0)-1),min_month=(pow(2.0,16.0)-1),min_day=(pow(2.0,16.0)-1); int c=0,r=0;

 for(c;c<z;c++)
 {
     min_year=(( min_year+exams_date2[r][2])-fabs(min_year-exams_date2[r][2]))/2;
     r++;
}
c=0;r=0;

  for(c;c<z;c++)
 {
     if(exams_date2[r][2]==min_year)
   {

     min_month=(( min_month+exams_date2[r][1])-fabs(min_month-exams_date2[r][1]))/2;
     r++;
   }
     else
      {
           r++;
      }
 }
 c=0;r=0;
  for(c;c<z;c++)
 {
     if(exams_date2[r][2]==min_year&&exams_date2[r][1]==min_month)
   {

     min_day=(( min_day+exams_date2[r][0])-fabs(min_day-exams_date2[r][0]))/2;
     r++;
   }
     else
      {
           r++;
      }
 }
//***************************************************************************************************************************//
  float max_year=0,max_month=0,max_day=0;

   c=0,r=0;

 for(c;c<z;c++)
 {
     max_year=(( max_year+exams_date2[r][2])+fabs(max_year-exams_date2[r][2]))/2;
     r++;
}
c=0;r=0;

  for(c;c<z;c++)
 {
     if(exams_date2[r][2]==max_year)
   {

     max_month=(( max_month+exams_date2[r][1])+fabs(max_month-exams_date2[r][1]))/2;
     r++;
   }
     else
      {
           r++;
      }
 }
 c=0;r=0;
  for(c;c<z;c++)
 {
     if(exams_date2[r][2]==max_year&&exams_date2[r][1]==max_month)
   {

     max_day=(( max_day+exams_date2[r][0])+fabs(max_day-exams_date2[r][0]))/2;
     r++;
   }
     else
      {
           r++;
      }
 }
 int exams_period,no_of_days=1;
 exams_period=fabs(((max_year-min_year)*12)-fabs(max_month-min_month));

 if(min_month==1||min_month==3||min_month==5||min_month==7||min_month==8||min_month==10||min_month==12)
 {
     no_of_days=no_of_days+(31-min_day);
 }
 else if(min_month==4||min_month==6||min_month==9||min_month==11)
 {
     no_of_days=no_of_days+(30-min_day);
 }
 else if(min_month==2&&(min_year==2016||min_year==2012||min_year==2008||min_year==2020))
        {
            no_of_days=no_of_days+(29-min_day);
        }
        else
            {
                no_of_days=no_of_days+(28-min_day);
            }

 //****************************************************************************************************************/
 int s=min_month+1,Q=1;

 for(Q;Q<exams_period;Q++)
 {
     if(s==1||s==3||s==5||s==7||s==8||s==10||s==12)
   {
     no_of_days=no_of_days+31;
   }
   else if(s==4||s==6||s==9||s==11)
   {
     no_of_days=no_of_days+(30);
   }
   else
   {
     if(s==2&&(min_year==2016||min_year==2012||min_year==2008||min_year==2020))
        {
            no_of_days=no_of_days+(29);
        }
        else
            {
                no_of_days=no_of_days+(28);
            }
   }
  s=s+1;
 }
 no_of_days=no_of_days+max_day;
 if(max_month==min_month)
 {
     no_of_days=max_day-min_day;
 }

//days_number =no_of_days;
//MAX_year=max_year;MAX_month=max_month;MAX_day=max_day;
 //MIN_year=min_year;MIN_month=min_month;MIN_day=min_day;

 //min and max id***************************************************************//
  float student_id[100]; i=0;
 for(i;i<R;i++)
 {
      student_id[i]=atof( students[i][0].c_str());
 }

int max_id=0,min_id=(pow(2.0,16.0)-1);i=0;
for(i;i<R;i++)
{
      min_id=(( min_id+student_id[i])-fabs( min_id-student_id[i]))/2;

      max_id=(( max_id+student_id[i])+fabs(max_id-student_id[i]))/2;
}
//*******************************************************************************// z,float &MAX_year,float &MAX_month,float &MAX_day,float &MIN_year,float &MIN_month,float &MIN_day,float &days_number,string courses_exams[][4],int p
/*courses s1;
 float MAX_year,MAX_month,MAX_day,MIN_year,MIN_month,MIN_day,days_number;
s1.start_date(z,MAX_year,MAX_month,MAX_day,MIN_year,MIN_month,MIN_day,courses_exams,100);*/
//****************************************************************************//Number of halls
 string halls[100];
 i=0;
 for(i;i<z;i++)
 {
      halls[i]=courses_exams[i][3];
 }
i=0;
int halls_number=z,d=0;
for(i;i<(z);i++)
{
    for(d;d<i;d++)
    {
        if(halls[i]==halls[d])
      {
          halls_number=halls_number-1;

          break;
      }

    }
    d=0;
}

 int N=min_id;int dropped_id=min_id,flag=0;
       int M=0;

//**************************************************************************************************//
string operations,ids,hal;
int t=2,cv=0,f;
int number=0,number1;
for(;;)
{
   getline(cin,operations);
   if(operations=="Number_Students")
   {
       cout<<R<<endl;
   }
   if(operations=="Number_Courses")
   {
       cout<<z<<endl;
   }
   if(operations=="Number_Halls")
   {
      cout<<halls_number<<endl;
   }
   if(operations=="Student_ID_Min")
   {
     cout<<min_id<<endl;
   }
   if(operations=="Student_ID_Max")
   {
       cout<<max_id<<endl;
   }
   if(operations=="Students_Dropped_IDs")
   {flag=0;

       for(N;N<=max_id;N++)
       {
           for(M=0;M<R;M++)
           {
              if(dropped_id==student_id[M])
              {
                 flag=1;
              }
           }
           if(flag==0)
           {
              cout<<dropped_id<<endl;

           }

           dropped_id++;
         flag=0;
           M=0;
          }
          N=min_id;
    }
   if(operations=="Exams_Start_Date")
   {
       cout<<min_day<<"/"<<min_month<<"/"<<min_year<<endl;
   }
   if(operations=="Exams_End_Date")
   {
       cout<<max_day<<"/"<<max_month<<"/"<<max_year<<endl;
   }
   if(operations=="Exams_Period_InDays")
   {
       cout<<no_of_days<<endl;
   }

   //***************************************************************************************************//level 2
   if(operations.substr(0,16)=="Student_Courses ")
   {flag=0;
      // getline(cin,ids);
   for(f=0;f<R;f++) // R is the student number
   {
     if(operations.substr(16,((operations.length())-16))==students[f][0])
     {
         for(cv=0;cv<courses_number[f];cv++)
         {
             cout<<students[f][t]<<endl;
             flag=1;
             t++;
         }
     }
   }
     if(flag==0)
     {
         cout<<"none";
     }
   }
   //****************************************************************************************************//
   if(operations.substr(0,16)=="Course_Students ")
   {t=2;flag=0;
      // getline(cin,ids);
    for(i=0;i<R;i++)
    {
      for(f=0;f<courses_number[i];f++)
      {
          if(operations.substr(16,((operations.length())-16))==students[i][t])
          {
              cout<<students[i][0]<<endl;
              flag=1;
          }
          t++;
      }
      t=2;
    }
    if(flag==0)
     {
         cout<<"none";
     }
   }
   //*******************************************************************************************************8//
  if(operations.substr(0,26)=="List_Course_Students More ")
  {flag=0;
      t=2;number=0;
      number1=atoi(operations.substr(26,((operations.length())-26)).c_str());

    for(int a=0;a<z;a++)
    {
      for(i=0;i<R;i++)
      {
        for(int f=0;f<courses_number[i];f++)
        {
          if(courses_exams[a][0]==students[i][t])
          {
              number++;
          }
          t++;
        }
        t=2;
      }
     if(number>number1)
     {
         cout<<courses_exams[a][0]<<endl;flag=1;

     }number=0;
   }
   if(flag==0)
     {
         cout<<"none";
     }
  }
//****************************************************************************************************//
    if(operations.substr(0,27)=="List_Course_Students Equal ")
  {flag=0;
      t=2;number=0;

      number1=atoi(operations.substr(27,((operations.length())-27)).c_str());

    for(int a=0;a<z;a++)
    {
      for(i=0;i<R;i++)
      {
        for(int f=0;f<courses_number[i];f++)
        {
          if(courses_exams[a][0]==students[i][t])
          {
              number++;
          }
          t++;
        }
        t=2;
      }
     if(number==number1)
     {
         cout<<courses_exams[a][0]<<endl;flag=1;

     }number=0;
   }
    if(flag==0)
     {
         cout<<"none";
     }
  }
//****************************************************************************************************//
  if(operations.substr(0,26)=="List_Course_Students Less ")
  {flag=0;
      t=2;number=0;

      number1=atoi(operations.substr(26,((operations.length())-26)).c_str());

    for(int a=0;a<z;a++)
    {
      for(i=0;i<R;i++)
      {
        for(int f=0;f<courses_number[i];f++)
        {
          if(courses_exams[a][0]==students[i][t])
          {
              number++;
          }
          t++;
        }
        t=2;
      }
     if(number<number1)
     {
         cout<<courses_exams[a][0]<<endl;flag=1;

     }number=0;
   }
   if(flag==0)
     {
         cout<<"none";
     }
  }
  //********************************************************************************************//
   if(operations.substr(0,26)=="List_Student_Courses More ")
   {flag=0;
      number1=atoi(operations.substr(26,((operations.length())-26)).c_str());

      for(t=0;t<R;t++)
      {
          if(courses_number[t]>number1)
          {
              cout<<students[t][0]<<endl;flag=1;
          }

      }
       if(flag==0)
     {
         cout<<"none";
     }
   }
//****************************************************************************************************//
      if(operations.substr(0,27)=="List_Student_Courses Equal ")
   {flag=0;
      number1=atoi(operations.substr(27,((operations.length())-27)).c_str());

      for(t=0;t<R;t++)
      {
          if(courses_number[t]==number1)
          {
              cout<<students[t][0]<<endl;flag=1;
          }

      }
       if(flag==0)
     {
         cout<<"none";
     }
   }
//****************************************************************************************************//
      if(operations.substr(0,26)=="List_Student_Courses Less ")
   {flag=0;
      number1=atoi(operations.substr(26,((operations.length())-26)).c_str());

      for(t=0;t<R;t++)
      {
          if(courses_number[t]<number1)
          {
              cout<<students[t][0]<<endl;flag=1;
          }

      }
       if(flag==0)
     {
         cout<<"none"<<endl;
     }
   }

  //*******************************************************************************************************//
  string studentid[1000];

   if(operations.substr(0,19)=="List_Hall_Students ")
  {i=0;flag=0;int flag1=0;k=0;
    for(t=0;t<operations.length();t++)
    {
      if(operations[t]==',')
      {
          hal=operations.substr(19,(t-19));
          ids=operations.substr(t+1,(operations.length()-t-1));
      }
    }
    for(t=0;t<z;t++)
    {
        if(hal==courses_exams[t][3]&&ids==courses_exams[t][2])
        {
            for(f=0;f<R;f++)
            {
                 for(S=2;S<courses_number[f]+2;S++)
                {
                    if(courses_exams[t][0]==students[f][S])
                    {
                        studentid[k]=students[f][0];
                        k++;
                    }
                }
            }
        }
    }
for(i;i<(k+1);i++)
{
    for(d;d<i;d++)
    {
        if(studentid[i]==studentid[d])
      {
         flag=1;
          break;
      }

    }
    if(flag==0)
    {
        cout<<studentid[i]<<endl;
        flag1=1;
    }
    d=0;flag=0;
  }
  if(flag1==0)
     {
         cout<<"none";
     }
}
//****************************************************************************************************//
int flag1=0;
 if(operations.substr(0,28)=="List_Hall_Students_InAnyday ")
  {flag1=0;
    hal=operations.substr(28,(operations.length()-28));

    for(t=0;t<z;t++)
    {
        if(hal==courses_exams[t][3])
        {
            for(f=0;f<R;f++)
            {
                 for(S=2;S<courses_number[f]+2;S++)
                {
                    if(courses_exams[t][0]==students[f][S])
                    {
                        studentid[k]=students[f][0];
                        k++;
                    }
                }
            }
        }
    }
i=0;flag=0;
d=0;
for(i;i<(k+1);i++)
{
    for(d;d<i;d++)
    {
        if(studentid[i]==studentid[d])
      {
         flag=1;
          break;
      }

    }
    if(flag==0)
    {
        cout<<studentid[i]<<endl;flag1=1;
    }
    d=0;flag=0;
}
 if(flag1==0)
     {
         cout<<"none";
     }
}
//****************************************************************************************************//
 if(operations.substr(0,28)=="List_Day_Students_InAnyHall ")
  {flag1=0;
    hal=operations.substr(28,(operations.length()-28));

    for(t=0;t<z;t++)
    {
        if(hal==courses_exams[t][2])
        {
            for(f=0;f<R;f++)
            {
                 for(S=2;S<courses_number[f]+2;S++)
                {
                    if(courses_exams[t][0]==students[f][S])
                    {
                        studentid[k]=students[f][0];
                        k++;
                    }
                }
            }
        }
    }
i=0;flag=0;
int halls_number=z,d=0;
for(i;i<(k+1);i++)
{
    for(d;d<i;d++)
    {
        if(studentid[i]==studentid[d])
      {
         flag=1;
          break;
      }

    }
    if(flag==0)
    {
        cout<<studentid[i]<<endl;flag1=1;
    }
    d=0;flag=0;
}
 if(flag1==0)
     {
         cout<<"none";
     }
}
//****************************************************************************************************//level 3
  if(operations.substr(0,11)=="List_Exams ")
  {flag=0;
    hal=operations.substr(11,(operations.length()-11));

    for(t=0;t<z;t++)
    {
        if(hal==courses_exams[t][2])
        {
            cout<<courses_exams[t][0]<<endl;flag=1;
        }
    }
    if(flag==0)
     {
         cout<<"none";
     }
  }
//****************************************************************************************************//
  if(operations.substr(0,15)=="List_StudyDays ")
  {
     int y,m; i=0;flag=0;int course_date,courses_dates[10];k=0;
     string course_code[10];
    for(t=0;t<operations.length();t++)
    {
      if(operations[t]==',')
      {
          hal=(operations.substr(15,(t-15)));
          ids=(operations.substr(t+1,(operations.length()-t-1)));
      }
    }
   for(i=0;i<z;i++)
   {
      if(ids==courses_exams[i][0])
      {
        course_date=get_days(courses_exams[i][2]);
      }
   }
   t=0;
   for(i=0;i<R;i++)
   {
       if(hal==students[i][0])
       {
         y=courses_number[i];
         for(k=2;k<(y+2);k++)
          {
              course_code[t]=students[i][k];
              //cout<<course_code[t]<<endl;
              t++;
          }
       }
   }
   for(i=0;i<y;i++)
   {
       for(k=0;k<z;k++)
       {
           if(course_code[i]==courses_exams[k][0])
           {
           courses_dates[i]=get_days(courses_exams[k][2]);
           //cout<<courses_dates[i]<<endl;
           }
       }
   }

   for (k=0;k<y-1;k++)
    {
      for (m=k+1;m<y;m++)
       {
        if(courses_dates[m]<courses_dates[k])
         {
            t=courses_dates[m];
           courses_dates[m]=courses_dates[k];
           courses_dates[k]=t;
         }
       }

    }
    for (i=0;i<y;i++)
    {
     if(course_date==courses_dates[i])
        {
            if(i==0)
               {if(courses_dates[i]==courses_dates[i+1])
             {cout<<"0";}
             else
               { cout<<"7";}
               }
               else{
               if(courses_dates[i]==courses_dates[i-1]||courses_dates[i]==courses_dates[i+1])
             {cout<<"0";}
             else
             {cout<<(courses_dates[i]-courses_dates[i-1])-1;}}
        }
    }
}
//***************************************************************************************************//
  if(operations.substr(0,31)=="List_StudyDays_ForEveryStudent ")
  {
     int y,m; i=0;flag=0;int course_date,courses_dates[10];k=0;
     string course_code[10];
      ids=operations.substr(31,(operations.length()-31));

   for(i=0;i<z;i++)
   {
      if(ids==courses_exams[i][0])
      {
        course_date=get_days(courses_exams[i][2]);
      }
   }

   for(int S=0;S<R;S++)
   {
       t=0;flag=0;
       for(i=2;i<(courses_number[S]+2);i++)
       {
           if(ids==students[S][i])
           {flag=1;}
       }



   if(flag==1)
   {//cout<<students[S][0]<<endl;
    for(i=0;i<R;i++)
    {
       if(students[S][0]==students[i][0])
       {
         y=courses_number[i];
         for(k=2;k<(y+2);k++)
          {
              course_code[t]=students[i][k];

              t++;
          }
       }
    }
   for(i=0;i<y;i++)
   {
       for(k=0;k<z;k++)
       {
           if(course_code[i]==courses_exams[k][0])
           {
           courses_dates[i]=get_days(courses_exams[k][2]);

           }
       }
   }

   for (k=0;k<y-1;k++)
    {
      for (m=k+1;m<y;m++)
       {
        if(courses_dates[m]<courses_dates[k])
         {
            t=courses_dates[m];
           courses_dates[m]=courses_dates[k];
           courses_dates[k]=t;
         }
       }

    }
    for (i=0;i<y;i++)
    {
     if(course_date==courses_dates[i])
        {
            if(i==0)
               {
                   if(courses_dates[i]==courses_dates[i+1])
             {cout<<students[S][0]<<" "<<"0"<<endl;}
             else
                {cout<<students[S][0]<<" "<<"7"<<endl;}}
               }
             else{
                 if(courses_dates[i]==courses_dates[i-1]||courses_dates[i]==courses_dates[i+1])
             {cout<<students[S][0]<<" "<<"0"<<endl;}
             else
             {cout<<students[S][0]<<" "<<(courses_dates[i]-courses_dates[i-1]-1)<<endl;}}

        }
}
}
}
//***************************************************************************************************//
  if(operations.substr(0,30)=="List_StudyDays_ForEveryCourse ")
  {
     int y,m; i=0;flag=0;int course_date,courses_dates[10];k=0;
     string course_code[10];
      ids=operations.substr(30,(operations.length()-30));
       t=0;flag=0;

     for(i=0;i<R;i++)
     {
       if(ids==students[i][0])
       {
         y=courses_number[i];
         for(k=2;k<(y+2);k++)
          {
            course_code[t]=students[i][k];
              t++;
          }
       }
     }
     for(i=0;i<y;i++)
     {
       for(k=0;k<z;k++)
       {
           if(course_code[i]==courses_exams[k][0])
           {
           courses_dates[i]=get_days(courses_exams[k][2]);

           }
       }
     }
     int dates[10];
     for(i=0;i<y;i++)
     {
    dates[i]=courses_dates[i];
     }
     string as;
     for (k=0;k<y-1;k++)
     {
      for (m=k+1;m<y;m++)
       {
        if(courses_dates[m]<courses_dates[k])
         {
            as=course_code[m];
           course_code[m]=course_code[k];
           course_code[k]=as;

               t=courses_dates[m];
           courses_dates[m]=courses_dates[k];
           courses_dates[k]=t;
         }
       }

      }

     for (i=0;i<y;i++)
     {
      {
        if(i==0)
         {if(courses_dates[i]==courses_dates[i+1])
         {cout<<course_code[i]<<" "<<"0"<<endl;}
           else
           {cout<<course_code[i]<<" "<<" 7"<<endl;}
         }
         else
         {if(courses_dates[i]==courses_dates[i-1]||courses_dates[i]==courses_dates[i+1])
         {cout<<course_code[i]<<" "<<"0"<<endl;}
         else
         {cout<<course_code[i]<<" "<<(courses_dates[i]-courses_dates[i-1]-1)<<endl;}}
         }
     }
}
//***************************************************************************************************//
  if(operations.substr(0,31)=="List_Minimum_Student_StudyDays ")
  {
     int y,m; i=0;flag=0;int course_date,courses_dates[10];k=0;
     string course_code[10];
      ids=operations.substr(31,(operations.length()-31));
       t=0;flag=0;

   for(i=0;i<R;i++)
   {
       if(ids==students[i][0])
       {
         y=courses_number[i];
         for(k=2;k<(y+2);k++)
          {
            course_code[t]=students[i][k];
              t++;
          }
       }
   }
   for(i=0;i<y;i++)
   {
       for(k=0;k<z;k++)
       {
           if(course_code[i]==courses_exams[k][0])
           {
           courses_dates[i]=get_days(courses_exams[k][2]);

           }
       }
   }
int dates[10];
for(i=0;i<y;i++)
{
    dates[i]=courses_dates[i];
}
string as;
   for (k=0;k<y-1;k++)
    {
      for (m=k+1;m<y;m++)
       {
        if(courses_dates[m]<courses_dates[k])
         {
            as=course_code[m];
           course_code[m]=course_code[k];
           course_code[k]=as;

               t=courses_dates[m];
           courses_dates[m]=courses_dates[k];
           courses_dates[k]=t;
         }
       }

    }
int study[11];
    for (i=0;i<y;i++)
    {
      {
        if(i==0)
         {if(courses_dates[i]==courses_dates[i+1])
            {study[i]=0;}
            else
           {study[i]=7;}
         }
        else
        {study[i]=(courses_dates[i]-courses_dates[i-1]-1);
        if(courses_dates[i]==courses_dates[i-1])
            {study[i]=0;study[i-1]=0;}}

        }
    }
    int minstudy;
    for(i=0;i<y;i++)
    {
        minstudy=(( minstudy+study[i])-fabs((float)minstudy-study[i]))/2;
    }
    for(i=0;i<y;i++)
    {
        if(minstudy==study[i])
    { cout<<course_code[i]<<" "<<minstudy;}}
}
//***************************************************************************************************//
 if(operations.substr(0,30)=="List_Minimum_Course_StudyDays ")
  {
     int y,m,zo=0,study[100];; i=0;flag=0;int course_date,courses_dates[10];k=0;
     string course_code[10];
      ids=operations.substr(30,(operations.length()-30));

   for(i=0;i<z;i++)
   {
      if(ids==courses_exams[i][0])
      {
        course_date=get_days(courses_exams[i][2]);
      }
   }

   for(int S=0;S<R;S++)
   {
       t=0;flag=0;
       for(i=2;i<(courses_number[S]+2);i++)
       {
           if(ids==students[S][i])
           {flag=1;}
       }



   if(flag==1)
   {//cout<<students[S][0]<<endl;
   for(i=0;i<R;i++)
   {
       if(students[S][0]==students[i][0])
       {
         y=courses_number[i];
         for(k=2;k<(y+2);k++)
          {
              course_code[t]=students[i][k];

              t++;
          }
       }
   }
   for(i=0;i<y;i++)
   {
       for(k=0;k<z;k++)
       {
           if(course_code[i]==courses_exams[k][0])
           {
           courses_dates[i]=get_days(courses_exams[k][2]);

           }
       }
   }
string as;
   for (k=0;k<y-1;k++)
    {
      for (m=k+1;m<y;m++)
       {
        if(courses_dates[m]<courses_dates[k])
         {
              as=course_code[m];
           course_code[m]=course_code[k];
           course_code[k]=as;


            t=courses_dates[m];
           courses_dates[m]=courses_dates[k];
           courses_dates[k]=t;
         }
       }

    }

    for (i=0;i<y;i++)
    {
     if(course_date==courses_dates[i])
        {
            if(i==0)
               {if(courses_dates[i]==courses_dates[i+1])
              {study[zo]=0;}
               else
                {study[zo]=7;zo++;
                break;}
               }
            study[zo]=(courses_dates[i]-courses_dates[i-1]-1);
            if(courses_dates[i]==courses_dates[i-1]||courses_dates[i]==courses_dates[i+1])
            {study[zo]=0;study[zo-1]=0;}
            //cout<<study[zo]/*courses_dates[i]<<"  "<<courses_dates[i-1]*/<<endl;
            zo++;
            break;
        }
    }

}
}
int minstudy=study[0];
for(i=0;i<=zo;i++)
{
    minstudy=(( minstudy+study[i])-fabs((float)minstudy-study[i]))/2;
}
     cout<<minstudy;
}
//***************************************************************************************************//
 if(operations=="List_Minimum_StudyDays")
  {
     int y,m,zo=0,study[1000]; i=0;flag=0;int course_date,courses_dates[10];k=0;
     string course_code[10];
      //ids=operations.substr(30,(operations.length()-30));

   for(int AX=0;AX<z;AX++)
   {
     course_date=get_days(courses_exams[AX][2]);

   for(int S=0;S<R;S++)
   {
       t=0;flag=0;
       for(i=2;i<(courses_number[S]+2);i++)
       {
           if(courses_exams[AX][0]==students[S][i])
           {flag=1;}
       }



   if(flag==1)
   {//cout<<students[S][0]<<endl;
   for(i=0;i<R;i++)
   {
       if(students[S][0]==students[i][0])
       {
         y=courses_number[i];
         for(k=2;k<(y+2);k++)
          {
              course_code[t]=students[i][k];

              t++;
          }
       }
   }
   for(i=0;i<y;i++)
   {
       for(k=0;k<z;k++)
       {
           if(course_code[i]==courses_exams[k][0])
           {
           courses_dates[i]=get_days(courses_exams[k][2]);

           }
       }
   }
string as;
   for (k=0;k<y-1;k++)
    {
      for (m=k+1;m<y;m++)
       {
        if(courses_dates[m]<courses_dates[k])
         {
            t=courses_dates[m];
           courses_dates[m]=courses_dates[k];
           courses_dates[k]=t;
         }
       }

    }

    for (i=0;i<y;i++)
    {
      if(i==0)
        {
         study[zo]=7;zo++;
        }
      else
        {
        study[zo]=(courses_dates[i]-courses_dates[i-1]-1);
        //cout<<study[zo]/*courses_dates[i]<<"  "<<courses_dates[i-1]*/<<endl;
        if(courses_dates[i]==courses_dates[i-1])
            {study[zo]=0;study[zo-1]=0;}
        zo++;
        }
    }
}
}
}
int minstudy=study[0];
for(i=0;i<zo;i++)
{
    minstudy=(( minstudy+study[i])-fabs((float)minstudy-study[i]))/2;
}
     cout<<minstudy;
}
//***************************************************************************************************//
 if(operations.substr(0,20)=="List_Exam_InSameDay ")
  {flag1=0;
     int y,m,zo=0; i=0;flag=0;int course_date;string courses_dates[10];k=0;
     string course_code[10];
      ids=operations.substr(20,(operations.length()-20));
t=0;
   for(i=0;i<R;i++)
   {
       if(ids==students[i][0])
       {
         y=courses_number[i];
         for(k=2;k<(y+2);k++)
          {
            course_code[t]=students[i][k];
              t++;
          }
       }
   }
     for(i=0;i<y;i++)
   {
       for(k=0;k<z;k++)
       {
           if(course_code[i]==courses_exams[k][0])
           {
           courses_dates[i]=courses_exams[k][2];

           }
       }
   }

   i=0;flag=0;
int halls_number=z,d=0;
for(i;i<y;i++)
{
    for(d;d<i;d++)
    {
        if(courses_dates[i]==courses_dates[d])
      {
         studentid[zo]=course_code[i];zo++;
          studentid[zo]=course_code[d];zo++;flag1=1;

          break;
      }

    }
    d=0;
}
i=0;flag=0;
d=0;
for(i;i<zo;i++)
{
    for(d;d<i;d++)
    {
        if(studentid[i]==studentid[d])
      {
         flag=1;
          break;
      }

    }
    if(flag==0)
    {
       cout<<studentid[i]<<endl;
    }
    d=0;flag=0;
}
 if(flag1==0)
     {
         cout<<"none";
     }
}
//***************************************************************************************************//
 if(operations=="List_Exam_InSameDay_ForEveryStudent")
  {
     int y,m,zo=0; i=0;flag=0;int course_date;string courses_dates[10];k=0;int S=0;
     string course_code[10];
      //ids=operations.substr(20,(operations.length()-20));

for(S=0;S<R;S++)
{t=0;flag1=0;
         y=courses_number[S];
         for(k=2;k<(y+2);k++)
          {
            course_code[t]=students[S][k];
              t++;
          }
     for(i=0;i<y;i++)
   {
       for(k=0;k<z;k++)
       {
           if(course_code[i]==courses_exams[k][0])
           {
           courses_dates[i]=courses_exams[k][2];

           }
       }
   }

   i=0;flag=0;
int d=0;
for(i;i<y;i++)
{
    for(d;d<i;d++)
    {
        if(courses_dates[i]==courses_dates[d])
      {
         studentid[zo]=course_code[i];zo++;flag1=1;
          studentid[zo]=course_code[d];zo++;
          break;
      }

    }
    d=0;
}
i=0;flag=0;
d=0;

cout<<students[S][0]<<" ";
for(i;i<zo;i++)
{
    for(d;d<i;d++)
    {
        if(studentid[i]==studentid[d])
      {
         flag=1;
          break;
      }

    }
    if(flag==0)
    {
       cout<<studentid[i]<<" ";
    }
d=0;flag=0;
}
zo=0;
if(flag1==0)
{
    cout<<"none";flag1=0;
}
cout<<endl;//*/
}
}
//***************************************************************************************************//
 if(operations.substr(0,21)=="List_Exam_InSameHall ")
  {flag1=0;
     int y,m,zo=0; i=0;flag=0;int course_date;string courses_dates[100];k=0;
     string course_code[100];
      ids=operations.substr(21,(operations.length()-21));
t=0;
   for(i=0;i<z;i++)
   {
       if(ids==courses_exams[i][2])
       {
            course_code[t]=courses_exams[i][0];
              t++;
       }
   }
     for(i=0;i<t;i++)
   {
       for(k=0;k<z;k++)
       {
           if(course_code[i]==courses_exams[k][0])
           {
           courses_dates[i]=courses_exams[k][3];
           }
       }
   }

   i=0;flag=0;
int halls_number=z,d=0;
for(i;i<t;i++)
{
    for(d;d<i;d++)
    {
        if(courses_dates[i]==courses_dates[d])
      {
         studentid[zo]=course_code[i];zo++;
          studentid[zo]=course_code[d];zo++;flag1=1;

          break;
      }

    }
    d=0;
}
i=0;flag=0;
d=0;
for(i;i<zo;i++)
{
    for(d;d<i;d++)
    {
        if(studentid[i]==studentid[d])
      {
         flag=1;
          break;
      }

    }
    if(flag==0)
    {
       cout<<studentid[i]<<endl;
    }
    d=0;flag=0;
}
 if(flag1==0)
     {
         cout<<"none";
     }
}
//***************************************************************************************************//
if(operations.substr(0,21)=="List_Exam_InSameHall_Simultaneously_InAnyDay")
  {flag1=0;
     int y,m,zo=0,d=0; i=0;flag=0;int course_date,ax=0;string courses_dates[100],nonrep[100];k=0;
     string course_code[100];
 //ids=operations.substr(21,(operations.length()-21));
for(i=0;i<z;i++)
{
    for(d;d<i;d++)
    {
        if(courses_exams[i][2]==courses_exams[d][2])
      {
         flag=1;
          break;
      }

    }
    if(flag==0)
    {
       nonrep[ax]=courses_exams[i][2];cout<<nonrep[ax]<<endl;
       ax++;
    }
    d=0;flag=0;
}
 for(S=0;S<ax;S++)
 {
t=0;
   for(i=0;i<z;i++)
   {
       if(nonrep[S]==courses_exams[i][2])
       {
            course_code[t]=courses_exams[i][0];
              t++;
       }
   }
     for(i=0;i<t;i++)
   {
       for(k=0;k<z;k++)
       {
           if(course_code[i]==courses_exams[k][0])
           {
           courses_dates[i]=courses_exams[k][3];
           }
       }
   }

   i=0;flag=0;
for(i;i<t;i++)
{
    for(d;d<i;d++)
    {
        if(courses_dates[i]==courses_dates[d])
      {
         studentid[zo]=course_code[i];zo++;
          studentid[zo]=course_code[d];zo++;flag1=1;

          break;
      }

    }
    d=0;
}
i=0;flag=0;
d=0;
cout<<nonrep[S]<<" ";
for(i;i<zo;i++)
{
    for(d;d<i;d++)
    {
        if(studentid[i]==studentid[d])
      {
         flag=1;
          break;
      }

    }
    if(flag==0)
    {
       cout<<studentid[i]<<" ";
    }
    d=0;flag=0;
}
 if(flag1==0)
     {
         cout<<"none";
     }
    cout<<endl;zo=0;flag1=0;
}
}
//***************************************************************************************************//

   if(operations=="Quit")
   {
       cout<<"thanks!";
       break;
   }

}
return 0;
}



