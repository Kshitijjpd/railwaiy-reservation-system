#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include "conio2.h"
#include "rlyres.h"
int enterchoice()
{
    int choice,i;
  gotoxy(28,1);
    textcolor(GREEN);
    printf("RAILWAY RESERVATION SYSTEM\n");
    textcolor(YELLOW);
    for(i=0;i<40;i++)
        printf("- ");
        textcolor(BLUE);
    printf("\n\t\t\t1- view trains\n\t\t\t2- book_ticket\n\t\t\t3-view Ticket\n\t\t\t4- Search Ticket No\n\t\t\t5- View ALL Booking\n\t\t\t6- View Train Booking\n\t\t\t7- Cancle Ticket\n\t\t\t8- cancle train\n");
 printf("\t\t\t9- quit!\n");
printf("\n\t\t\tENTER CHOICE :");
scanf("%d",&choice);
return choice;
}
void add_trains()
{
   Train alltrains[4]={
        {"123","BPL","GWA",2100,1500},
        {"546","BPL","DEL",3500,2240},
        {"345","HBJ","AGR",1560,1135},
        {"896","HBJ","MUM",4500,3360},

    };
    FILE *fp=fopen("d:\\myprojectfiles\\alltrains.txt","rb");
    if(fp==NULL)
    {
      fp=fopen("d:\\myprojectfiles\\alltrains.txt","wb");
      fwrite(alltrains,4*sizeof(Train),1,fp);
      printf("File created and saved!\n");

    }
    else
        printf("File already present\n");
    fclose(fp);

}
void view_trains()
{
    textcolor(LIGHTMAGENTA);
    printf("\tTRAIN NO\tFROM\tTO\tFRIST AC FARE\tSECOND AC FARE\n");
    for(int i=0;i<40;i++)
        printf("- ");
  FILE *fp=fopen("d:\\myprojectfiles\\alltrains.txt","rb");
  Train tr;

  while(fread(&tr,sizeof(tr),1,fp)==1)
  {
      printf("\n\t%s\t\t%s\t%s\t%d\t\t%d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
  }
  printf("\n\n\n\n");
  fclose(fp);
   }
   int check_train_no(char *trainno)
   {
      FILE *fp=fopen("d:\\myprojectfiles\\alltrains.txt","rb");
      Train tr;
      while(fread(&tr,sizeof(tr),1,fp)==1)
      {
          if(strcmp(tr.train_no,trainno)==0)
          {
              fclose(fp);
              return 1;
          }
      }
      fclose(fp);
      return 0;
   }
   int check_mob_no(char*p_mob)
   {
       if(strlen(p_mob)!=10)
       return 0;
       while(*p_mob!='\0')
       {
           if(isdigit(*p_mob)==0)
            return 0;
           p_mob++;
       }
       return 1;
   }
Passenger*get_passenger_detail()
{
    clrscr();
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("press 0 to exit");
    gotoxy(1,1);
    textcolor(LIGHTCYAN);
    static Passenger psn;
    printf("Enter passenger name:");
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char*pos;
    pos= strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("reservation cancelled");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
    }
    int valid;
    printf("Enter gender(M/F):");
    do
    {
         valid=1;
        fflush(stdin);
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
        {
            textcolor(LIGHTRED);
             gotoxy(1,25);
              printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
               gotoxy(1,25);
              printf("reservation cancelled");
               getch();
                textcolor(YELLOW);
                  clrscr();
                    return NULL;
        }
            if(psn.gender!='M'&&psn.gender!='F')
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("Error!Gender should be M or F(in uppercase)!");
                 valid=0;
                 getch();
                 gotoxy(20,2);
                 printf("\b");
                 textcolor(YELLOW);
            }

    }while(valid==0);
         gotoxy(1,25);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
       gotoxy(1,3);
       printf("Enter train number:");
       do
       {
           fflush(stdin);
           scanf("%s",psn.train_no);
           if(strcmp(psn.train_no,"0")==0)
           {
              textcolor(LIGHTRED);
              gotoxy(1,25);
              printf("reservation cancelled");
              getch();
              textcolor(YELLOW);
              clrscr();
              return NULL;
           }
          valid= check_train_no(psn.train_no);
           if(valid==0)
           {
              textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("Error!invalid train no");

                 getch();
                 gotoxy(20,3);
                 printf("\t\t\t\t");
                 gotoxy(20,3);
                 textcolor(YELLOW);
           }

       }while(valid==0);
       gotoxy(1,25);
       printf("\t\t\t\t\t\t");
       gotoxy(1,4);
       printf("Enter travelling class(First AC:F,Second AC:S):");
        do
    {
         valid=1;
        fflush(stdin);
        scanf("%c",&psn.p_class);
        if(psn.p_class=='0')
        {
            textcolor(LIGHTRED);
             gotoxy(1,25);
              printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
               gotoxy(1,25);
              printf("reservation cancelled");
               getch();
                textcolor(YELLOW);
                  clrscr();
                    return NULL;
        }
            if(psn.p_class!='F'&&psn.p_class!='S')
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("Error!Travelling class should be F or S!");
                 valid=0;
                 getch();
                 gotoxy(49,4);
                 printf("\b");
                 textcolor(YELLOW);
            }

    }while(valid==0);
    gotoxy(1,25);
       printf("\t\t\t\t\t\t");
        gotoxy(1,5);
        printf("Enter address:");
        fflush(stdin);
        fgets(psn.address,20,stdin);
        pos= strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation cancelled");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
    }
     printf("enter age:");
     do
     {
         valid=1;
         fflush(stdin);
         scanf("%d",&psn.age);
         if(psn.age==0)
         {
         gotoxy(1,25);
       printf("\t\t\t\t\t\t");
       gotoxy(1,25);
       printf("Reservation cancelled");
       getch();
       textcolor(YELLOW);
       clrscr();
       return NULL;

     }
     if(psn.age<0)
     {
         textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("Error!age should be positive!");
                 valid=0;
                 getch();
                 gotoxy(11,6);
                 printf("\t\t\t\t\t");
                 gotoxy(11,6);
                 textcolor(YELLOW);
     }

       }while(valid==0);
       gotoxy(1,25);
       printf("\t\t\t\t\t\t");
       gotoxy(1,7);
       printf("Enter mobile number:");
       do
        {
            fflush(stdin);
       fgets(psn.mob_no,12,stdin);
       pos=strchr(psn.mob_no,'\n');
       if(pos!=NULL)
       *pos='\0';
       if(strcmp(psn.mob_no,"0")==0)
       {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation cancelled");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
       }
        valid=check_mob_no(psn.mob_no);
        if(valid==0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Error!invalid Mobile no!");
        getch();
        gotoxy(21,7);
        printf("\t\t\t\t\t\t");
         gotoxy(21,7);
        textcolor(YELLOW);

        }
       }while(valid==0);
       return &psn;
}



//function 2 decleration---------------------------------------------------------------------------


int get_booked_ticket_count(char*train_no,char tc)
{
    FILE *fp=fopen("d:\\myprojectfiles\\allbookings.txt","rb");
    if(fp==NULL)
        return 0;
    Passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0&&pr.p_class==tc)
            count=count+1;
    }
    fclose(fp);
    return count;
}
int last_ticket_no()
{
 FILE *fp=fopen("d:\\myprojectfiles\\allbookings.txt","rb");
    if(fp==NULL)
    {

        return 0;
    }
        Passenger pr;
        fseek(fp,-1L*sizeof(pr),SEEK_END);
        fread(&pr,sizeof(pr),1,fp);
        fclose(fp);
        return pr.ticketno;

}
int book_ticket(Passenger p)
{
    int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count==2)
    {
        textcolor(LIGHTRED);
        printf("All seats in train no%s in class%c are full",p.train_no,p.p_class);
        return -1;
    }
    int ticket_no= last_ticket_no()+1;
    {
        p.ticketno=ticket_no;
        FILE *fp=fopen("d:\\myprojectfiles\\allbookings.txt","ab");
        if(fp==NULL)
        {
            textcolor(LIGHTRED);
            printf("sorry! file cannot be opened");
            return -1;
        }
        fwrite(&p,sizeof(p),1,fp);
        fclose(fp);
        return ticket_no;
    }
}
int accept_ticket_no()
{
    printf("Enter a valid ticket no:");
    int valid;
    int ticket_no;
    do
    {
        valid=1;
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
       gotoxy(1,25);
       printf("\t\t\t\t\t\t");
       gotoxy(1,25);
       printf("cancelling input.....");
       getch();
       textcolor(YELLOW);
       clrscr();
       return 0;
        }
        if(ticket_no<0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Error!Ticket number should be positive");
        getch();
        valid=0;
        gotoxy(24,1);
        printf("\t\t\t\t\t\t");
         gotoxy(24,1);
        textcolor(YELLOW);
        }
    }while(valid==0);
    return ticket_no;
}

void view_ticket(int ticket_no)
{
    int i;
    FILE *fp=fopen("d:\\myprojectfiles\\allbookings.txt","rb");
    if(fp==NULL)
        {
            textcolor(LIGHTRED);
            printf("sorry! file cannot be opened");
            return ;
        }
        Passenger pr;
        int found=0;
        while(fread(&pr,sizeof(pr),1,fp)==1)
        {
          if(pr.ticketno==ticket_no)
          {
        printf("\nNAME:%s\nAGE:%d\nMOBILE NO:%s\nTICKET NO:%d",pr.p_name,pr.age,pr.mob_no,pr.ticketno);
          printf("\nGENDER:%c",pr.gender);
          printf("\nTRAIN NO:%s",pr.train_no);
          printf("\nCLASS:%c",pr.p_class);
          printf("\nADDRESS:%s",pr.address);
          printf("\n\n");
          found=1;
          break;
          }
        }
        if(!found)
        {
            textcolor(LIGHTRED);
            printf("\nNo details ofthe ticket no %d found!",ticket_no);
        }
        fclose(fp);
}
//function 4  decleration--------------------------------------------------------------------------------------
char*accept_mob_no()
{
    static char mob_no[12];
    char*pos;
    int valid;
    textcolor(LIGHTMAGENTA);
    printf("Enter valid mobile number:");
    do
    {
        fflush(stdin);
        fgets(mob_no,13,stdin);
        pos=strchr(mob_no,'\n');
        if(pos!=NULL);
        *pos='\0';
        if(strcmp(mob_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
             printf("\t\t\t\t\t\t");
             gotoxy(1,25);
             printf("cancelled input...!");
              getch();
              textcolor(YELLOW);
              clrscr();
              return NULL;
        }
        valid=check_mob_no(mob_no);
        if(valid==0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Error!invalid Mobile no!");
        getch();
        gotoxy(27,1);
        printf("\t\t\t\t\t\t");
         gotoxy(27,1);
        textcolor(YELLOW);

        }
    }while(valid==0);
       clrscr();
       return mob_no;
       }

int*get_ticket_no(char*p_mob_no)
{
    int count=0;
    FILE *fp=fopen("d:\\myprojectfiles\\allbookings.txt","rb");
        if(fp==NULL)
        {
            textcolor(LIGHTRED);
            printf("sorry! file cannot be opened");
            return NULL;
        }


    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            count=count+1;
        }
    }
    if(!count)
    {
        fclose(fp);
        return NULL;
    }
    int *p=(int*)malloc((count+1)*sizeof(int));
           rewind(fp);
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
          *(p+i)=pr.ticketno;
          i++;
        }
    }
    *(p+i)=-1;
    fclose(fp);
    return p;
}


void view_all_tickets(char*pmob_no,int*pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry!No tickets booked against mobile no%s",pmob_no);
        textcolor(WHITE);
        printf("\nPress any key to go back to main screen");
        textcolor(YELLOW);
        getch();
        return;
    }
    printf("Following are tickets booked for the mobile number:%s",pmob_no);
    int i;
    printf("\n\nTICKET NUMBER\n");
    printf("-------------------------------------");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n%d",*(pticket_no+i));
        textcolor(WHITE);
        printf("\npress any key to go back to main screen");
        textcolor(YELLOW);
         getch();
         free(pticket_no);

}
//case 6 decleration-----------------------------------------------------------------------------------------------------


char*accept_train_no()
{
    static char train_no[10];
    int valid;
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("press 0 to exit");
    gotoxy(1,1);
    textcolor(LIGHTGRAY);
    printf("Enter train number:");

    do
    {
        fflush(stdin);
        scanf("%s",train_no);
        if(strcmp(train_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("cancelling  input....!");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        valid= check_train_no(train_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error!invalid Train no!");
            getch();
            gotoxy(20,1);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(20,1);
            textcolor(YELLOW);
        }
    }while(valid==0);
      clrscr();
      return train_no;
}
void view_booking(char*train_no)
{
int found=0,i;
    FILE *fp=fopen("d:\\myprojectfiles\\allbookings.txt","rb");
        if(fp==NULL)
        {
            textcolor(LIGHTRED);
            printf("sorry! file cannot be opened");
            return;
        }
        Passenger pr;
        printf("TICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
        for(i=1;i<=80;i++)
        {
            printf("-");
        }
        int row=3;
        while(fread(&pr,sizeof(pr),1,fp)==1)
        {
          if(strcmp(pr.train_no,train_no)==0)

          {
            printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
            row++;
            found=1;
          }

        }
if(!found)
{
clrscr();
textcolor(LIGHTRED);
printf("\nNo detail of bookings in train no %s found",train_no);
}
textcolor(YELLOW);
getch();
fclose(fp);
}
//CASE 7 DECLERATION -----------------------------------------------------------------------------------

int cancel_ticket(int ticket_no)
{
    int result;
FILE*fp1=fopen("d:\\myprojectfiles\\allbookings.txt","rb");
if(fp1==NULL)
{
    textcolor(LIGHTRED);
    printf("\nNo booking done yet");
    return -1;
}
FILE*fp2=fopen("d:\\myprojectfiles\\temp.txt","wb");
Passenger pr;
int found=0;
while(fread(&pr,sizeof(pr),1,fp1)==1)
{
    if(pr.ticketno==ticket_no)
    {
       found=1;
    }
       else
       {

        fwrite(&pr,sizeof(pr),1,fp2);
       }

}
 fclose(fp1);
 fclose(fp2);
 if(found==0)
 {
     remove("d:\\myprojectfiles\\temp.txt");
 }
 else
 {
    result= remove("d:\\myprojectfiles\\allbookings.txt");
    if(result!=0)
        return 2;

    result= rename("d:\\myprojectfiles\\temp.txt","d:\\myprojectfiles\\allbookings.txt");
    if(result!=0)
        return 2;
 }
 return found;

}

//case 5 decleration------------------------------------------------------------------------------------------------------------------------------------

void view_all_bookings()
{
    int found=0,i;
  FILE *fp=fopen("d:\\myprojectfiles\\allbookings.txt","rb");
        if(fp==NULL)
        {
            textcolor(LIGHTRED);
            printf("sorry! file cannot be opened");
            return;
        }
        Passenger pr;
        printf("TICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
        for(i=1;i<=80;i++)
        {
            printf("-");
        }
        int row=3;
         while(fread(&pr,sizeof(pr),1,fp)==1)
        {

            printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
            row++;
            found=1;
          }
}

//case 8 decleration-----------------------------------------------------------------------------------------------------------------------------

int cancel_train(char*train_no);







