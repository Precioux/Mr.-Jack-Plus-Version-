#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int random9(){
    return ((rand() % 9));
}
typedef struct{
char name[20];
int key;      //poeple number
int j[4];    // position
int s;        //side
int p;       //ordering number
}tile;
int turn,sherlock_f,jack_H;  //counters
tile t[9];
void whitechapel(void)
{
    //adding data to tiles
    for(int i=0;i<9;i++)
    {
       for(int s=0;s<4;s++) //1 1 1 0 (default position)
       {
           if(s!=3)
           t[i].j[s]=1;
           else t[i].j[s]=0;
       }
       t[i].s=1;  //set upside as defualt
    }
    //Adding names:
    strcpy(t[0].name,"Insp. Lestrade");
    t[0].key=0;
    strcpy(t[1].name,"Jeremy Bert");
    t[1].key=1;
    strcpy(t[2].name,"John Pizer");
    t[2].key=2;
    strcpy(t[3].name,"John Smith");
    t[3].key=3;
    strcpy(t[4].name,"Joseph Lane");
    t[4].key=4;
    strcpy(t[5].name,"Madame");
    t[5].key=5;
    strcpy(t[6].name,"Miss Stealthy");
    t[6].key=6;
    strcpy(t[7].name,"Sgt Goodley");
    t[7].key=7;
    strcpy(t[8].name,"Wiliam Gull");
    t[8].key=8;
}
//nodes for linked list
typedef struct{
  tile info;
  struct tode *next;
}tode;
tode *head;
tode *new_tile(tile T)    //making a new node
{
    tode *n=malloc(sizeof(tode));
    if(n==NULL){
        return NULL;}
    n->info=T;
    n->next=NULL;

    return n;
}//checked
void head_maker(tode** head,  tode* nn) //set head node
 {
  nn->next = *head;
  *head = nn;
} //checked
void tile_adder(tode *head,tode *n) //adding a node to the list
{
  tode* current;
  for(current = head; current-> next != NULL; current = current-> next);

  current->next = n;
  n->next = NULL;
}//checked
void whitechapel_print(tode *head) //prints linked list
{
    tode *current;
    puts("White chapel : ");
    for(current=head;current!=NULL;current=current->next)
    {
       printf("%d %s\n",current->info.p+1,current->info.name);

    }
}
tode* finder(int r,int choice)// searches for given tile in todes
{

    int flag=0;
    tode* current=head;
    if(choice==0)
    {
    if(head->info.key==r)
        return head;
    else{
      while (current != NULL)
    {
        if (current->info.key == r)
        {
            flag=1;
            return current;
        }

        current = current->next;
    }
    if(flag==0)
    {
        puts("not found");
        return ;
    }
    }
    }
     if(choice==1)
    {
     if(head->info.p==r)
        return head;
     else{
      while (current != NULL)
    {
        if (current->info.p == r)
        {
            flag=1;
            return current;
        }

        current = current->next;
    }
    if(flag==0)
    {
        puts("not found");
        return ;
    }
    }
    }

}
int detector_t[3];   //detectors:
void token_start(void)  //detectors situation
{
    detector_t[0]=11;  //sherlock
    detector_t[1]=3;   //watson
    detector_t[2]=7;   //toby
}

void table(void)  //Game Map
{
    tode* id[9];
     id[0]=finder(0,1);
     id[1]=finder(1,1);
     id[2]=finder(2,1);
     id[3]=finder(3,1);
     id[4]=finder(4,1);
    id[5]=finder(5,1);
    id[6]=finder(6,1);
    id[7]=finder(7,1);
    id[8]=finder(8,1);
    puts(" Map Guide \n");
    puts("For each column: ");
    puts("1-side 1: upside 0: downside");
    puts("2-Murderer Number (shown in followed list)");
    puts("3-Tile code -> read Round Clock , 1 means Road - 0 means Wall\n\n");
    if(detector_t[0]==0 || detector_t[0]==1 || detector_t[0]==2 || detector_t[1]==0 || detector_t[1]==1 || detector_t[1]==2 || detector_t[2]==0 || detector_t[2]==1 || detector_t[2]==2 )
    {
        if(detector_t[0]==0 && detector_t[1]==0 && detector_t[2]==0)
        {
            printf("           S W T\n");
        }
        if(detector_t[0]==0 && detector_t[1]!=0 && detector_t[2]!=0)
        {
            printf("           S\n");
        }
        if(detector_t[0]!=0 && detector_t[1]==0 && detector_t[2]!=0)
        {
            printf("             W\n");
        }
        if(detector_t[0]!=0 && detector_t[1]!=0 && detector_t[2]==0)
        {
            printf("               T\n");
        }
        if(detector_t[0]==0 && detector_t[1]==0 && detector_t[2]!=0)
        {
            printf("           S W\n");
        }
        if(detector_t[0]==0 && detector_t[1]!=0 && detector_t[2]==0)
        {
            printf("           S   T\n");
        }
        if(detector_t[0]!=0 && detector_t[1]==0 && detector_t[2]==0)
        {
            printf("             W T\n");
        }
        if(detector_t[0]==1 && detector_t[1]==1 && detector_t[2]==1)
        {
            printf("                     S W T\n");
        }
         if(detector_t[0]==1 && detector_t[1]!=1 && detector_t[2]!=1)
        {
            printf("                     S\n");
        }
        if(detector_t[0]!=1 && detector_t[1]==1 && detector_t[2]!=1)
        {
            printf("                       W\n");
        }
        if(detector_t[0]!=1 && detector_t[1]!=1 && detector_t[2]==1)
        {
            printf("                        T\n");
        }
        if(detector_t[0]==1 && detector_t[1]==1 && detector_t[2]!=1)
        {
            printf("                     S W\n");
        }
        if(detector_t[0]==1 && detector_t[1]!=1 && detector_t[2]==1)
        {
            printf("                     S   T\n");
        }
        if(detector_t[0]!=1 && detector_t[1]==1 && detector_t[2]==1)
        {
            printf("                       W T\n");
        }
         if(detector_t[0]==2 && detector_t[1]==2 && detector_t[2]==2)
        {
            printf("                               S W T\n");
        }
         if(detector_t[0]==2 && detector_t[1]!=2 && detector_t[2]!=2)
        {
            printf("                               S\n");
        }
        if(detector_t[0]!=2 && detector_t[1]==2 && detector_t[2]!=2)
        {
            printf("                                 W\n");
        }
        if(detector_t[0]!=2 && detector_t[1]!=2 && detector_t[2]==2)
        {
            printf("                                   T\n");
        }
        if(detector_t[0]==2 && detector_t[1]==2 && detector_t[2]!=2)
        {
            printf("                               S W\n");
        }
        if(detector_t[0]==2 && detector_t[1]!=2 && detector_t[2]==2)
        {
            printf("                               S   T\n");
        }
        if(detector_t[0]!=2 && detector_t[1]==2 && detector_t[2]==2)
        {
            printf("                                 W T\n");
        }

    }
      for(int i=0;i<16;i++)
    {
    if(i==0 || i==15 || i==5 || i==10)
    {
        printf("        ");
    for(int j=0;j<16;j++)
    {
        printf("- ");
    }
    }
    else
    {
    if(i==2 || i==7 || i==12 || i==3 || i==8 || i==13 || i==1 || i==6 || i==11)
    {
        if(i==1)
        {
                printf("        %c%5d%5c%5d%5c%5d%5c",'-',id[0]->info.s,'-',id[1]->info.s,'-',id[2]->info.s,'-');
        }
        if(i==2)
        {
                if(detector_t[0]==11 || detector_t[0]==3 || detector_t[1]==11 || detector_t[1]==3 || detector_t[2]==11 || detector_t[2]==3)
            {
                if(detector_t[0]==11 && detector_t[1]==11 && detector_t[2]==11)
                    printf(" S W T  %c%5d%5c%5d%5c%5d%5c",'-',1,'-',2,'-',3,'-');
else{
                if(detector_t[0]==3 && detector_t[1]==3 && detector_t[2]==3)
                    printf("        %c%5d%5c%5d%5c%5d%5c  S W T  ",'-',1,'-',2,'-',3,'-');
 else{
                 if(detector_t[0]!=11 && detector_t[1]==11 && detector_t[2]==11)
                 {
                     if(detector_t[0]!=3)
                         printf("   W T  %c%5d%5c%5d%5c%5d%5c",'-',1,'-',2,'-',3,'-');
                     else  printf("   W T  %c%5d%5c%5d%5c%5d%5c  S",'-',1,'-',2,'-',3,'-');

                 }
  else{
                if(detector_t[0]==11 && detector_t[1]!=11 && detector_t[2]==11)
                {
                    if(detector_t[1]!=3)
                       printf(" S   T  %c%5d%5c%5d%5c%5d%5c",'-',1,'-',2,'-',3,'-');
                    else   printf(" S   T  %c%5d%5c%5d%5c%5d%5c    W",'-',1,'-',2,'-',3,'-');
                }
   else{
                 if(detector_t[0]==11 && detector_t[1]==11 && detector_t[2]!=11)
                 {
                     if(detector_t[2]!=3)
                        printf(" S W    %c%5d%5c%5d%5c%5d%5c",'-',1,'-',2,'-',3,'-');
                     else printf(" S W    %c%5d%5c%5d%5c%5d%5c      T",'-',1,'-',2,'-',3,'-');
                 }
     else{
                 if(detector_t[0]==11 && detector_t[1]!=11 && detector_t[2]!=11)
                 {
                     if(detector_t[1]!=3 && detector_t[2]!=3)
                      printf(" S      %c%5d%5c%5d%5c%5d%5c",'-',1,'-',2,'-',3,'-');
                    else
                    {
                        if(detector_t[1]==3 && detector_t[2]!=3)
                             printf(" S      %c%5d%5c%5d%5c%5d%5c    W",'-',1,'-',2,'-',3,'-');
                        if(detector_t[2]==3 && detector_t[1]!=3)
                             printf(" S      %c%5d%5c%5d%5c%5d%5c      T",'-',1,'-',2,'-',3,'-');
                        if(detector_t[1]==3 && detector_t[2]==3)
                             printf(" S      %c%5d%5c%5d%5c%5d%5c    W T",'-',1,'-',2,'-',3,'-');
                    }
                 }
        else{
                if(detector_t[0]!=11 && detector_t[1]==11 && detector_t[2]!=11)
                 {
                     if(detector_t[0]!=3 && detector_t[2]!=3)
                      printf("   W    %c%5d%5c%5d%5c%5d%5c",'-',1,'-',2,'-',3,'-');
                    else
                    {
                        if(detector_t[0]==3 && detector_t[2]!=3)
                             printf("   W    %c%5d%5c%5d%5c%5d%5c  S",'-',1,'-',2,'-',3,'-');
                        if(detector_t[2]==3 && detector_t[0]!=3)
                             printf("   W    %c%5d%5c%5d%5c%5d%5c      T",'-',1,'-',2,'-',3,'-');
                        if(detector_t[0]==3 && detector_t[2]==3)
                             printf("   W    %c%5d%5c%5d%5c%5d%5c  S   T",'-',1,'-',2,'-',3,'-');
                    }
                 }
         else{
                   if(detector_t[0]!=11 && detector_t[1]!=11 && detector_t[2]==11)
                 {
                     if(detector_t[0]!=3 && detector_t[1]!=3)
                      printf("     T  %c%5d%5c%5d%5c%5d%5c",'-',1,'-',2,'-',3,'-');
                    else
                    {
                        if(detector_t[0]==3 && detector_t[1]!=3)
                             printf("     T  %c%5d%5c%5d%5c%5d%5c  S",'-',1,'-',2,'-',3,'-');
                        if(detector_t[1]==3 && detector_t[0]!=3)
                             printf("     T  %c%5d%5c%5d%5c%5d%5c    W",'-',1,'-',2,'-',3,'-');
                        if(detector_t[0]==3 && detector_t[1]==3)
                             printf("     T  %c%5d%5c%5d%5c%5d%5c  S W",'-',1,'-',2,'-',3,'-');
                    }
                 }
          else{
                if(detector_t[0]!=3 && detector_t[1]==3 && detector_t[2]==3 && detector_t[0]!=11)
                    printf("        %c%5d%5c%5d%5c%5d%5c    W T  ",'-',1,'-',2,'-',3,'-');
            else{
                if(detector_t[0]==3 && detector_t[1]!=3 && detector_t[2]==3 && detector_t[1]!=11)
                    printf("        %c%5d%5c%5d%5c%5d%5c  S   T  ",'-',1,'-',2,'-',3,'-');
             else{
                if(detector_t[0]==3 && detector_t[1]==3 && detector_t[2]!=3 && detector_t[2]!=11)
                    printf("        %c%5d%5c%5d%5c%5d%5c  S W    ",'-',1,'-',2,'-',3,'-');
                else{
                if(detector_t[0]==3 && detector_t[1]!=3 && detector_t[2]!=3 && detector_t[1]!=11 && detector_t[2]!=11 )
                    printf("        %c%5d%5c%5d%5c%5d%5c  S      ",'-',1,'-',2,'-',3,'-');
                else{
                if(detector_t[0]!=3 && detector_t[1]==3 && detector_t[2]!=3 && detector_t[0]!=11 && detector_t[2]!=11)
                    printf("        %c%5d%5c%5d%5c%5d%5c    W    ",'-',1,'-',2,'-',3,'-');
                    else{
                if(detector_t[0]!=3 && detector_t[1]!=3 && detector_t[2]==3 && detector_t[1]!=11 && detector_t[0]!=11)
                    printf("        %c%5d%5c%5d%5c%5d%5c      T  ",'-',1,'-',2,'-',3,'-');
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
  }
 }
}
            }
             else printf("        %c%5d%5c%5d%5c%5d%5c",'-',1,'-',2,'-',3,'-');
        }
        if(i==3)
        {

            printf("        %c%4d%d%d%d%3c%4d%d%d%d%3c%4d%d%d%d%3c",'-',id[0]->info.j[0],id[0]->info.j[1],id[0]->info.j[2],id[0]->info.j[3],'-',id[1]->info.j[0],id[1]->info.j[1],id[1]->info.j[2],id[1]->info.j[3],'-',id[2]->info.j[0],id[2]->info.j[1],id[2]->info.j[2],id[2]->info.j[3],'-');
        }
         if(i==6)
        {
                printf("        %c%5d%5c%5d%5c%5d%5c",'-',id[3]->info.s,'-',id[4]->info.s,'-',id[5]->info.s,'-');
        }
         if(i==7)
        {
             if(detector_t[0]==10 || detector_t[0]==4 || detector_t[1]==10 || detector_t[1]==4 || detector_t[2]==10 || detector_t[2]==4)
            {
                if(detector_t[0]==10 && detector_t[1]==10 && detector_t[2]==10)
                    printf(" S W T  %c%5d%5c%5d%5c%5d%5c",'-',4,'-',5,'-',6,'-');
else{
                if(detector_t[0]==4 && detector_t[1]==4 && detector_t[2]==4)
                    printf("        %c%5d%5c%5d%5c%5d%5c  S W T  ",'-',4,'-',5,'-',6,'-');
 else{
                 if(detector_t[0]!=10 && detector_t[1]==10 && detector_t[2]==10)
                 {
                     if(detector_t[0]!=4)
                         printf("   W T  %c%5d%5c%5d%5c%5d%5c",'-',4,'-',5,'-',6,'-');
                     else  printf("   W T  %c%5d%5c%5d%5c%5d%5c  S",'-',4,'-',5,'-',6,'-');

                 }
  else{
                if(detector_t[0]==10 && detector_t[1]!=10 && detector_t[2]==10)
                {
                    if(detector_t[1]!=4)
                       printf(" S   T  %c%5d%5c%5d%5c%5d%5c",'-',4,'-',5,'-',6,'-');
                    else   printf(" S   T  %c%5d%5c%5d%5c%5d%5c    W",'-',4,'-',5,'-',6,'-');
                }
   else{
                 if(detector_t[0]==10 && detector_t[1]==10 && detector_t[2]!=10)
                 {
                     if(detector_t[2]!=4)
                        printf(" S W    %c%5d%5c%5d%5c%5d%5c",'-',4,'-',5,'-',6,'-');
                     else printf(" S W    %c%5d%5c%5d%5c%5d%5c      T",'-',4,'-',5,'-',6,'-');
                 }
     else{
                 if(detector_t[0]==10 && detector_t[1]!=10 && detector_t[2]!=10)
                 {
                     if(detector_t[1]!=4 && detector_t[2]!=4)
                      printf(" S      %c%5d%5c%5d%5c%5d%5c",'-',4,'-',5,'-',6,'-');
                    else
                    {
                        if(detector_t[1]==4 && detector_t[2]!=4)
                             printf(" S      %c%5d%5c%5d%5c%5d%5c    W",'-',4,'-',5,'-',6,'-');
                        if(detector_t[2]==4 && detector_t[1]!=4)
                             printf(" S      %c%5d%5c%5d%5c%5d%5c      T",'-',4,'-',5,'-',6,'-');
                        if(detector_t[1]==4 && detector_t[2]==4)
                             printf(" S      %c%5d%5c%5d%5c%5d%5c    W T",'-',4,'-',5,'-',6,'-');
                    }
                 }
        else{
                if(detector_t[0]!=10 && detector_t[1]==10 && detector_t[2]!=10)
                 {
                     if(detector_t[0]!=4 && detector_t[2]!=4)
                      printf("   W    %c%5d%5c%5d%5c%5d%5c",'-',4,'-',5,'-',6,'-');
                    else
                    {
                        if(detector_t[0]==4 && detector_t[2]!=4)
                             printf("   W    %c%5d%5c%5d%5c%5d%5c  S",'-',4,'-',5,'-',6,'-');
                        if(detector_t[2]==4 && detector_t[0]!=4)
                             printf("   W    %c%5d%5c%5d%5c%5d%5c      T",'-',4,'-',5,'-',6,'-');
                        if(detector_t[0]==4 && detector_t[2]==4)
                             printf("   W    %c%5d%5c%5d%5c%5d%5c  S   T",'-',4,'-',5,'-',6,'-');
                    }
                 }
         else{
                   if(detector_t[0]!=10 && detector_t[1]!=10 && detector_t[2]==10)
                 {
                     if(detector_t[0]!=4 && detector_t[1]!=4)
                      printf("     T  %c%5d%5c%5d%5c%5d%5c",'-',4,'-',5,'-',6,'-');
                    else
                    {
                        if(detector_t[0]==4 && detector_t[1]!=4)
                             printf("     T  %c%5d%5c%5d%5c%5d%5c  S",'-',4,'-',5,'-',6,'-');
                        if(detector_t[1]==4 && detector_t[0]!=4)
                             printf("     T  %c%5d%5c%5d%5c%5d%5c    W",'-',4,'-',5,'-',6,'-');
                        if(detector_t[0]==4 && detector_t[1]==4)
                             printf("     T  %c%5d%5c%5d%5c%5d%5c  S W",'-',4,'-',5,'-',6,'-');
                    }
                 }
          else{
                if(detector_t[0]!=4 && detector_t[1]==4 && detector_t[2]==4 && detector_t[0]!=10)
                    printf("        %c%5d%5c%5d%5c%5d%5c    W T  ",'-',4,'-',5,'-',6,'-');
            else{
                if(detector_t[0]==4 && detector_t[1]!=4 && detector_t[2]==4 && detector_t[1]!=10)
                    printf("        %c%5d%5c%5d%5c%5d%5c  S   T  ",'-',4,'-',5,'-',6,'-');
             else{
                if(detector_t[0]==4 && detector_t[1]==4 && detector_t[2]!=4 && detector_t[2]!=10)
                    printf("        %c%5d%5c%5d%5c%5d%5c  S W    ",'-',4,'-',5,'-',6,'-');
                else{
                if(detector_t[0]==4 && detector_t[1]!=4 && detector_t[2]!=4 && detector_t[1]!=10 && detector_t[2]!=10 )
                    printf("        %c%5d%5c%5d%5c%5d%5c  S      ",'-',4,'-',5,'-',6,'-');
                else{
                if(detector_t[0]!=4 && detector_t[1]==4 && detector_t[2]!=4 && detector_t[0]!=10 && detector_t[2]!=10)
                    printf("        %c%5d%5c%5d%5c%5d%5c    W    ",'-',4,'-',5,'-',6,'-');
                    else{
                if(detector_t[0]!=4 && detector_t[1]!=4 && detector_t[2]==4 && detector_t[1]!=10 && detector_t[0]!=10)
                    printf("        %c%5d%5c%5d%5c%5d%5c      T  ",'-',4,'-',5,'-',6,'-');
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
  }
 }
}
            }
             else printf("        %c%5d%5c%5d%5c%5d%5c",'-',4,'-',5,'-',6,'-');
        }
        if(i==8)
        {

            printf("        %c%4d%d%d%d%3c%4d%d%d%d%3c%4d%d%d%d%3c",'-',id[3]->info.j[0],id[3]->info.j[1],id[3]->info.j[2],id[3]->info.j[3],'-',id[4]->info.j[0],id[4]->info.j[1],id[4]->info.j[2],id[4]->info.j[3],'-',id[5]->info.j[0],id[5]->info.j[1],id[5]->info.j[2],id[5]->info.j[3],'-');
        }
         if(i==11)
        {
                printf("        %c%5d%5c%5d%5c%5d%5c",'-',id[6]->info.s,'-',id[7]->info.s,'-',id[8]->info.s,'-');
        }
         if(i==12)
        {
              if(detector_t[0]==9 || detector_t[0]==5 || detector_t[1]==9 || detector_t[1]==5 || detector_t[2]==9 || detector_t[2]==5)
            {
                if(detector_t[0]==9 && detector_t[1]==9 && detector_t[2]==9)
                    printf(" S W T  %c%5d%5c%5d%5c%5d%5c",'-',7,'-',8,'-',9,'-');
else{
                if(detector_t[0]==5 && detector_t[1]==5 && detector_t[2]==5)
                    printf("        %c%5d%5c%5d%5c%5d%5c  S W T  ",'-',7,'-',8,'-',9,'-');
 else{
                 if(detector_t[0]!=9 && detector_t[1]==9 && detector_t[2]==9)
                 {
                     if(detector_t[0]!=5)
                         printf("   W T  %c%5d%5c%5d%5c%5d%5c",'-',7,'-',8,'-',9,'-');
                     else  printf("   W T  %c%5d%5c%5d%5c%5d%5c  S",'-',7,'-',8,'-',9,'-');

                 }
  else{
                if(detector_t[0]==9 && detector_t[1]!=9 && detector_t[2]==9)
                {
                    if(detector_t[1]!=5)
                       printf(" S   T  %c%5d%5c%5d%5c%5d%5c",'-',7,'-',8,'-',9,'-');
                    else   printf(" S   T  %c%5d%5c%5d%5c%5d%5c    W",'-',7,'-',8,'-',9,'-');
                }
   else{
                 if(detector_t[0]==9 && detector_t[1]==9 && detector_t[2]!=9)
                 {
                     if(detector_t[2]!=5)
                        printf(" S W    %c%5d%5c%5d%5c%5d%5c",'-',7,'-',8,'-',9,'-');
                     else printf(" S W    %c%5d%5c%5d%5c%5d%5c      T",'-',7,'-',8,'-',9,'-');
                 }
     else{
                 if(detector_t[0]==9 && detector_t[1]!=9 && detector_t[2]!=9)
                 {
                     if(detector_t[1]!=5 && detector_t[2]!=5)
                      printf(" S      %c%5d%5c%5d%5c%5d%5c",'-',7,'-',8,'-',9,'-');
                    else
                    {
                        if(detector_t[1]==5 && detector_t[2]!=5)
                             printf(" S      %c%5d%5c%5d%5c%5d%5c    W",'-',7,'-',8,'-',9,'-');
                        if(detector_t[2]==5 && detector_t[1]!=5)
                             printf(" S      %c%5d%5c%5d%5c%5d%5c      T",'-',7,'-',8,'-',9,'-');
                        if(detector_t[1]==5 && detector_t[2]==5)
                             printf(" S      %c%5d%5c%5d%5c%5d%5c    W T",'-',7,'-',8,'-',9,'-');
                    }
                 }
        else{
                if(detector_t[0]!=9 && detector_t[1]==9 && detector_t[2]!=9)
                 {
                     if(detector_t[0]!=5 && detector_t[2]!=5)
                      printf("   W    %c%5d%5c%5d%5c%5d%5c",'-',7,'-',8,'-',9,'-');
                    else
                    {
                        if(detector_t[0]==5 && detector_t[2]!=5)
                             printf("   W    %c%5d%5c%5d%5c%5d%5c  S",'-',7,'-',8,'-',9,'-');
                        if(detector_t[2]==5 && detector_t[0]!=5)
                             printf("   W    %c%5d%5c%5d%5c%5d%5c      T",'-',7,'-',8,'-',9,'-');
                        if(detector_t[0]==5 && detector_t[2]==5)
                             printf("   W    %c%5d%5c%5d%5c%5d%5c  S   T",'-',7,'-',8,'-',9,'-');
                    }
                 }
         else{
                   if(detector_t[0]!=9 && detector_t[1]!=9 && detector_t[2]==9)
                 {
                     if(detector_t[0]!=5 && detector_t[1]!=5)
                      printf("     T  %c%5d%5c%5d%5c%5d%5c",'-',7,'-',8,'-',9,'-');
                    else
                    {
                        if(detector_t[0]==5 && detector_t[1]!=5)
                             printf("     T  %c%5d%5c%5d%5c%5d%5c  S",'-',7,'-',8,'-',9,'-');
                        if(detector_t[1]==5 && detector_t[0]!=5)
                             printf("     T  %c%5d%5c%5d%5c%5d%5c    W",'-',7,'-',8,'-',9,'-');
                        if(detector_t[0]==5 && detector_t[1]==5)
                             printf("     T  %c%5d%5c%5d%5c%5d%5c  S W",'-',7,'-',8,'-',9,'-');
                    }
                 }
          else{
                if(detector_t[0]!=5 && detector_t[1]==5 && detector_t[2]==5 && detector_t[0]!=9)
                    printf("        %c%5d%5c%5d%5c%5d%5c    W T  ",'-',7,'-',8,'-',9,'-');
            else{
                if(detector_t[0]==5 && detector_t[1]!=5 && detector_t[2]==5 && detector_t[1]!=9)
                    printf("        %c%5d%5c%5d%5c%5d%5c  S   T  ",'-',7,'-',8,'-',9,'-');
             else{
                if(detector_t[0]==5 && detector_t[1]==5 && detector_t[2]!=5 && detector_t[2]!=9)
                    printf("        %c%5d%5c%5d%5c%5d%5c  S W    ",'-',7,'-',8,'-',9,'-');
                else{
                if(detector_t[0]==5 && detector_t[1]!=5 && detector_t[2]!=5 && detector_t[1]!=9 && detector_t[2]!=9 )
                    printf("        %c%5d%5c%5d%5c%5d%5c  S      ",'-',7,'-',8,'-',9,'-');
                else{
                if(detector_t[0]!=5 && detector_t[1]==5 && detector_t[2]!=5 && detector_t[0]!=9 && detector_t[2]!=9)
                    printf("        %c%5d%5c%5d%5c%5d%5c    W    ",'-',7,'-',8,'-',9,'-');
                    else{
                if(detector_t[0]!=5 && detector_t[1]!=5 && detector_t[2]==5 && detector_t[1]!=9 && detector_t[0]!=9)
                    printf("        %c%5d%5c%5d%5c%5d%5c      T  ",'-',7,'-',8,'-',9,'-');
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
  }
 }
}
            }

             else printf("        %c%5d%5c%5d%5c%5d%5c",'-',7,'-',8,'-',9,'-');
        }
        if(i==13)
        {

            printf("        %c%4d%d%d%d%3c%4d%d%d%d%3c%4d%d%d%d%3c",'-',id[6]->info.j[0],id[6]->info.j[1],id[6]->info.j[2],id[6]->info.j[3],'-',id[7]->info.j[0],id[7]->info.j[1],id[7]->info.j[2],id[7]->info.j[3],'-',id[8]->info.j[0],id[8]->info.j[1],id[8]->info.j[2],id[8]->info.j[3],'-');
        }
    }

    else  printf("        %c%10c%10c%10c",'-','-','-','-');
    }
    puts("");
    }
      if(detector_t[0]==8 || detector_t[0]==7 || detector_t[0]==6 || detector_t[1]==8 || detector_t[1]==7 || detector_t[1]==6 || detector_t[2]==8 || detector_t[2]==7 || detector_t[2]==6 )
    {
        if(detector_t[0]==8 && detector_t[1]==8 && detector_t[2]==8)
        {
            printf("           S W T\n");
        }
        if(detector_t[0]==8 && detector_t[1]!=8 && detector_t[2]!=8)
        {
            printf("           S\n");
        }
        if(detector_t[0]!=8 && detector_t[1]==8 && detector_t[2]!=8)
        {
            printf("             W\n");
        }
        if(detector_t[0]!=8 && detector_t[1]!=8 && detector_t[2]==8)
        {
            printf("               T\n");
        }
        if(detector_t[0]==8 && detector_t[1]==8 && detector_t[2]!=8)
        {
            printf("           S W\n");
        }
        if(detector_t[0]==8 && detector_t[1]!=8 && detector_t[2]==8)
        {
            printf("           S   T\n");
        }
        if(detector_t[0]!=8 && detector_t[1]==8 && detector_t[2]==8)
        {
            printf("             W T\n");
        }
        if(detector_t[0]==7 && detector_t[1]==7 && detector_t[2]==7)
        {
            printf("                     S W T\n");
        }
         if(detector_t[0]==7 && detector_t[1]!=7 && detector_t[2]!=7)
        {
            printf("                     S\n");
        }
        if(detector_t[0]!=7 && detector_t[1]==7 && detector_t[2]!=7)
        {
            printf("                       W\n");
        }
        if(detector_t[0]!=7 && detector_t[1]!=7 && detector_t[2]==7)
        {
            printf("                        T\n");
        }
        if(detector_t[0]==7 && detector_t[1]==7 && detector_t[2]!=7)
        {
            printf("                     S W\n");
        }
        if(detector_t[0]==7 && detector_t[1]!=7 && detector_t[2]==7)
        {
            printf("                     S   T\n");
        }
        if(detector_t[0]!=7 && detector_t[1]==7 && detector_t[2]==7)
        {
            printf("                       W T\n");
        }
         if(detector_t[0]==6 && detector_t[1]==6 && detector_t[2]==6)
        {
            printf("                               S W T\n");
        }
         if(detector_t[0]==6 && detector_t[1]!=6 && detector_t[2]!=6)
        {
            printf("                               S\n");
        }
        if(detector_t[0]!=6 && detector_t[1]==6 && detector_t[2]!=6)
        {
            printf("                                 W\n");
        }
        if(detector_t[0]!=6 && detector_t[1]!=6 && detector_t[2]==6)
        {
            printf("                                   T\n");
        }
        if(detector_t[0]==6 && detector_t[1]==6 && detector_t[2]!=6)
        {
            printf("                               S W\n");
        }
        if(detector_t[0]==6 && detector_t[1]!=6 && detector_t[2]==6)
        {
            printf("                               S   T\n");
        }
        if(detector_t[0]!=6 && detector_t[1]==6 && detector_t[2]==6)
        {
            printf("                                 W T\n");
        }
    }
    puts("\n");
    whitechapel_print(head);
    printf("\n");
}
void W_C_maker(void)
{
    whitechapel();  //calls the tile maker function
    int d=random9();    //choose a tile randomly to set as head
    int st[9];
    for(int t=0;t<9;t++)   //list of tiles
        st[t]=0;
    st[d]=1;
    t[d].p=0;
    head_maker(&head,new_tile(t[d]));  //set the choosen tile as head
    int w;
    int all_S=1;
   while(all_S!=9)
    {
        w=random9();
        if(st[w]==0)
        {
         t[w].p=all_S;   //sets ordering number
         if(all_S==2) //changes position for 2 -|
        {
    t[w].j[0]=1;
    t[w].j[1]=0;
    t[w].j[2]=1;
    t[w].j[3]=1;
        }
        if(all_S==7) //changes position for 7 _|_
        {
    t[w].j[0]=1;
    t[w].j[1]=1;
    t[w].j[2]=0;
    t[w].j[3]=1;
        }

        tile_adder(head,new_tile(t[w]));  //adds new tile to whitechapel
            st[w]=1;
        all_S++;
        }
    }
}
//Cards :
typedef struct {
 char name[25];
 int hourglass;
 int key;
 int jack;
}card;
card c[9];
int card_order[9];
void card_maker(void)
{
    strcpy(c[0].name,"Insp. Lestrade");
    c[0].hourglass=0;
    c[0].key=0;
    strcpy(c[1].name,"Jeremy Bert");
    c[1].hourglass=1;
     c[1].key=1;
    strcpy(c[2].name,"John Pizer");
    c[2].hourglass=1;
     c[2].key=2;
    strcpy(c[3].name,"John Smith");
    c[3].hourglass=1;
     c[3].key=3;
    strcpy(c[4].name,"Joseph Lane");
    c[4].hourglass=1;
     c[4].key=4;
    strcpy(c[5].name,"Madame");
    c[5].hourglass=2;
     c[5].key=5;
    strcpy(c[6].name,"Miss Stealthy");
    c[6].hourglass=1;
     c[6].key=6;
    strcpy(c[7].name,"Sgt Goodley");
    c[7].hourglass=0;
     c[7].key=7;
    strcpy(c[8].name,"Wiliam Gull");
    c[8].hourglass=1;
     c[8].key=8;
}

//turns:
turn=1;
//ordering cards randomly
void card_and_id(void)
{
    for(int i=0;i<9;i++)
    {
        c[i].jack=0;
    }
    card_maker();
    int tot,z;
    //srand(time(NULL));
    tot=1;
    while(tot<10)
    {
        z=random9();
        if(card_order[z]==0)
        {
            card_order[z]=tot;
            tot++;
        }
    }
for(int i=0;i<9;i++)
{
    if(card_order[i]==1)
    {
        c[i].jack=1;
        printf("Mr.Jack's identity will be defined. (Detective must close his/her eyes)\n\n");

    }
    else c[i].jack=0;
}
int jack_IDen;
void jack_id(void)
{

for(int i=0;i<9;i++)
{
    if(c[i].jack==1)
    {
        printf("Mr Jack : %s\n\n",c[i].name);
        jack_IDen=c[i].key;
        break;
    }
}

}
//cards procedure checked
int card_finder(void)
{
    int flag=0;
    int i=0;
    int co;
for(int y=1;y<10;y++)
{
   for(int e=0;e<9;e++)
   {
       if(card_order[e]==y && c[e].jack==0)
        return e;
   }
}
}

int swap(tode *list, int p1, int p2)
{
    int tmp1,tmp2,tmp3,tmp4;
    int t5[4];
    int t6[4];
    int pos1=p1+1;
    int pos2=p2+1;
    tode *node1, *node2, *prev1, *prev2, *temp;
    int i;

    // Get the far position among both
    const int maxPos = (pos1 > pos2) ? pos1 : pos2;

    // Get total nodes in the list
    const int totalNodes = 8;

    // Validate swap positions
    if ((pos1 <= 0 || pos1 > totalNodes) || (pos2 <= 0 || pos2 > totalNodes))
    {
        return -1;
    }

    // If both positions are same then no swapping required
    if (pos1 == pos2)
    {
        return 1;
    }


    // Identify both nodes to swap
    i = 1;
    temp  = list;
    prev1 = NULL;
    prev2 = NULL;

    // Find nodes to swap
    while (temp != NULL && (i <= maxPos))
    {
        if (i == pos1 - 1)
            prev1 = temp;
        if (i == pos1)
            node1 = temp;

        if (i == pos2 - 1)
            prev2 = temp;
        if (i == pos2)
            node2 = temp;

        temp = temp->next;
        i++;
    }
    tmp1=node1->info.p;
    tmp2=node2->info.p;
    tmp3=node1->info.s;
    tmp4=node2->info.s;
    // If both nodes to swap are found.
    if (node1 != NULL && node2 != NULL)
    {
        // Link previous of node1 with node2
        if (prev1 != NULL)
            prev1->next = node2;

        // Link previous of node2 with node1
        if (prev2 != NULL)
            prev2->next = node1;

        // Swap node1 and node2 by swapping their
        // next node links
        temp        = node1->next;
        node1->next = node2->next;
        node2->next = temp;

        // Make sure to swap head node when swapping
        // first element.
        if (prev1 == NULL)
            head = node2;
        else if (prev2 == NULL)
            head = node1;
    }
    node1->info.p=tmp2;
    node2->info.p=tmp1;
    return 1;

}
//actions:
typedef struct{
int side;
int check;
}action;
int sherlock_check(void)
{
    int sh=0;
    tode* sher;
    for(int i=0;i<9;i++)
    {
        sher=finder(i,1);
        sh+=sher->info.s;
    }
    if(sh==1)
        return 1;
    else return 0;
}

int turn_checker(void)//checks if game is ended or not
{

    int result=0;
     if(sherlock_check())
        result=1;
     if(jack_H>=6)
        result=2;
     if(turn>8)
        result=3;
    return result;
}
void Token1(int side,int player)
{
    int f,step;
    tode* fi;
           //action for token 1
      if(side==1)  //upside to downside   checked
       {
           if(player==1)
           {
           f=card_finder();
           fi=finder(c[f].key,0);

           if(fi->info.s==1)
            {
           fi->info.s=0;
            printf("First card : %s\nTile %d turned downside\n",fi->info.name,fi->info.p+1);
           }
           else
           {
               if(fi->info.s==0)
               printf("First card : %s was downside\n",fi->info.name);
           }
           }
           else
            {
            if(player==0)
            {
             puts("Welldone, Jack!");
             f=card_finder();
             c[f].jack=-1;
             jack_H=jack_H+c[f].hourglass;

            }
            }
       }
      else
       {
            if(side==0)  //move forward 1,2  checked
       {
         puts("How many steps you wanna take? 1 or 2 ? (sherlock)");
         scanf("%d",&step);
         if(step==1 || step==2)
         {
         detector_t[0]+=step;
         if(detector_t[0]>11)
         {
             detector_t[0]=detector_t[0]-12;
         }
         }
         else puts("You cannot move this much!");
       }
       }
       table();

}
void Token2(int side)    //checked
{
    int step;
     //action for token 2
      if(side==1)
       {
         puts("How many steps you wanna take? 1 or 2 ? (toby)");
         scanf("%d",&step);
         if(step==1 || step==2)
         {
         detector_t[2]+=step;
         if(detector_t[2]>11)
         {
             detector_t[2]=detector_t[2]-12;
         }
         }
         else puts("You cannot move this much!");
       printf("Toby is on %d\n",detector_t[2]);
       }
       else
        {
       if(side==0)
       {
         puts("How many steps you wanna take? 1 or 2 ? (watson)");
         scanf("%d",&step);
           if(step==1 || step==2)
         {
         detector_t[1]+=step;
         if(detector_t[1]>11)
         {
             detector_t[1]=detector_t[1]-12;
         }
         }
         else puts("You cannot move this much!");
       }
       }
       table();
}
void Token3(int side)  //checked
{
    int ti,rotate,tp,a,b,res;
    tode* rt;
   //action for token 3
       if(side==1)
       {
           puts("Which tile do you want to rotate?");
           scanf("%d",&ti);
           puts("Rotation 180 or 90?");
           scanf("%d",&rotate);
           rt=finder(ti-1,1);
           if(rotate==180)
           {
               for(int i=0;i<2;i++)
               {
                tp=rt->info.j[3];
                rt->info.j[3]=rt->info.j[2];
                rt->info.j[2]=rt->info.j[1];
                rt->info.j[1]=rt->info.j[0];
                rt->info.j[0]=tp;
               }
           }
           else
            {
            if(rotate==90)
            {
                tp=rt->info.j[3];
                rt->info.j[3]=rt->info.j[2];
                rt->info.j[2]=rt->info.j[1];
                rt->info.j[1]=rt->info.j[0];
                rt->info.j[0]=tp;
            }
            }
       }
       else
      {
      if(side==0 )   //swaping tiles checked
       {
           puts("Which tiles do you want to sweep?");
           scanf("%d%d",&a,&b);
           res=swap(head,a-1,b-1);
       }
       }
       table();
}
void Token4(int side,int player)
{
    int ti,rotate,tp,step;
    tode* rt;

       if(side==1)
       {
          puts("Which tile do you want to rotate?");
           scanf("%d",&ti);
           puts("Rotation 180 or 90?");
           scanf("%d",&rotate);
           rt=finder(ti-1,1);
           if(rotate==180)
           {
               for(int i=0;i<2;i++)
               {
                tp=rt->info.j[3];
                rt->info.j[3]=rt->info.j[2];
                rt->info.j[2]=rt->info.j[1];
                rt->info.j[1]=rt->info.j[0];
                rt->info.j[0]=tp;
               }
           }
           else
            {
            if(rotate==90)
            {
                tp=rt->info.j[3];
                rt->info.j[3]=rt->info.j[2];
                rt->info.j[2]=rt->info.j[1];
                rt->info.j[1]=rt->info.j[0];
                rt->info.j[0]=tp;
            }
            }
       }
       else
        {
        if(side==0)
        {
            if(player==1)
            {
         puts("Which detector do you want to move?\n1-Sherlock\n2-Watson\n3-Toby");
         scanf("%d",&step);
         step=step-1;
         if(step==0)
         {
           detector_t[0]++;
           if(detector_t[0]>11)
         {
             detector_t[0]=detector_t[0]-12;
         }
         }
         else
            {
            if(step==1)
              {
            detector_t[1]++;
           if(detector_t[1]>11)
         {
             detector_t[1]=detector_t[1]-12;
         }
              }
            else
                {
                if(step==2)
                {
            detector_t[2]++;
           if(detector_t[2]>11)
         {
             detector_t[2]=detector_t[2]-12;
         }
                }
                }
            }
        }
        else
            {
            if(player==0)
            {
             puts("Which detector do you want to move?\n1-Sherlock\n2-Watson\n3-Toby\n4-No movement");
         scanf("%d",&step);
         step=step-1;
         if(step==0)
         {
           detector_t[0]++;
           if(detector_t[0]>11)
         {
             detector_t[0]=detector_t[0]-12;
         }
         }
         else
            {
            if(step==1)
              {
            detector_t[1]++;
           if(detector_t[1]>11)
         {
             detector_t[1]=detector_t[1]-12;
         }
              }
            else
                {
                if(step==2)
                {
            detector_t[2]++;
           if(detector_t[2]>11)
         {
             detector_t[2]=detector_t[2]-12;
         }
                }
                }
            }
            }
            }
        }
        }
        table();
}
int cj[9];
int whereisJack(int d)
{
    int i,p;
    tode* where;
    int loc=0;
    if(d==0 || d==11) //tile 1
    {
        where=finder(0,1);
        if(d==0) //detective can see this direction
        {
            if(where->info.j[0]==1)
            {
                cj[0]++;
                if(jack_IDen==where->info.key){
                    loc++;
                }
                else
                    {
                        if(where->info.j[2]==1)
                        {
                        where=finder(3,1);
                         if(where->info.j[0]==1)
                         {
                             cj[3]++;
                             if(jack_IDen==where->info.key){
                                 loc++;
                             }
                             else
                             {
                                 if(where->info.j[2]==1)
                                 {
                                     where=finder(6,1);
                                     if(where->info.j[0]==1)
                                     {
                                          cj[6]++;
                                         if(jack_IDen==where->info.key){
                                            loc++;
                                            }
                                     }
                                 }
                             }
                         }



                        }
                    }
            }
        }
        if(d==11)
        {
            if(where->info.j[3]==1)
            {
                 cj[0]++;
                if(jack_IDen==where->info.key){
                    loc++;
                }
                else
                    {
                    if(where->info.j[1]==1)
                    {
                     where=finder(1,1);
                     if(where->info.j[3]==1)
                     {
                          cj[1]++;
                         if(jack_IDen==where->info.key){
                            loc++;
                         }
                         else
                         {
                             if(where->info.j[1]==1)
                             {
                                 where=finder(2,1);
                                 if(where->info.j[3]==1)
                                 {
                                      cj[2]++;
                                    if(jack_IDen==where->info.key){
                                        loc++;
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
    if(d==2 || d==3) //tile 3
    {
        where=finder(2,1);
        if(d==2) //detective can see this direction
        {
            if(where->info.j[0]==1)
            {
                cj[2]++;
                if(jack_IDen==where->info.key){
                    loc++;
                }
                else
                    {
                        if(where->info.j[2]==1)
                        {
                        where=finder(5,1);
                         if(where->info.j[0]==1)
                         {
                            cj[5]++;
                             if(jack_IDen==where->info.key){
                             loc++;
                             }
                             else
                             {
                                 if(where->info.j[2]==1)
                                 {
                                     where=finder(8,1);
                                     if(where->info.j[0]==1)
                                     {
                                         cj[8]++;
                                         if(jack_IDen==where->info.key){
                                            loc++;
                                         }
                                     }
                                 }
                             }
                         }



                        }
                    }
            }
        }
        if(d==3)
        {
            if(where->info.j[1]==1)
            {
                cj[2]++;
                if(jack_IDen==where->info.key){
                    loc++;
                }
                else
                    {
                    if(where->info.j[3]==1)
                    {
                     where=finder(1,1);
                     if(where->info.j[1]==1)
                     {
                          cj[1]++;
                         if(jack_IDen==where->info.key){
                            loc++;
                         }
                         else
                         {
                             if(where->info.j[3]==1)
                             {
                                 where=finder(0,1);
                                 if(where->info.j[1]==1)
                                 {
                                     cj[0]++;
                                    if(jack_IDen==where->info.key){
                                        loc++;
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
      if(d==5 || d==6) //tile 9
    {
        where=finder(8,1);
        if(d==5) //detective can see this direction
        {
            if(where->info.j[1]==1)
            {
                 cj[8]++;
                if(jack_IDen==where->info.key){
                    loc++;
                }
                else
                    {
                        if(where->info.j[3]==1)
                        {
                        where=finder(7,1);
                         if(where->info.j[1]==1)
                         {
                                cj[7]++;
                             if(jack_IDen==where->info.key){
                             loc++;
                             }
                             else
                             {
                                 if(where->info.j[3]==1)
                                 {
                                     where=finder(6,1);
                                     if(where->info.j[1]==1)
                                     {
                                          cj[6]++;
                                         if(jack_IDen==where->info.key){
                                            loc++;
                                         }
                                     }
                                 }
                             }
                         }



                        }
                    }
            }
        }
        if(d==6)
        {
            if(where->info.j[2]==1)
            {
                cj[8]++;
                if(jack_IDen==where->info.key){
                    loc++;
                }
                else
                    {
                    if(where->info.j[0]==1)
                    {
                     where=finder(5,1);
                     if(where->info.j[2]==1)
                     {
                          cj[5]++;
                         if(jack_IDen==where->info.key){
                            loc++;
                         }
                         else
                         {
                             if(where->info.j[0]==1)
                             {
                                 where=finder(2,1);
                                 if(where->info.j[2]==1)
                                 {
                                     cj[2]++;
                                    if(jack_IDen==where->info.key){
                                        loc++;

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

 if(d==8 || d==9) //tile 7
    {
        where=finder(6,1);
        if(d==8) //detective can see this direction
        {
            if(where->info.j[2]==1)
            {
                 cj[6]++;
                if(jack_IDen==where->info.key){
                    loc++;
                }
                else
                    {
                        if(where->info.j[0]==1)
                        {
                        where=finder(3,1);
                         if(where->info.j[2]==1)
                         {
                             cj[3]++;
                             if(jack_IDen==where->info.key){
                             loc++;
                             }
                             else
                             {
                                 if(where->info.j[0]==1)
                                 {
                                     where=finder(0,1);
                                     if(where->info.j[2]==1)
                                     {
                                         cj[0]++;
                                         if(jack_IDen==where->info.key){
                                            loc++;
                                         }
                                     }
                                 }
                             }
                         }



                        }
                    }
            }
        }
        if(d==9)
        {
            if(where->info.j[3]==1)
            {
                cj[6]++;
                if(jack_IDen==where->info.key){
                    loc++;
                }
                else
                    {
                    if(where->info.j[1]==1)
                    {
                     where=finder(7,1);
                     if(where->info.j[3]==1)
                     {
                         cj[7]++;
                         if(jack_IDen==where->info.key){
                            loc++;
                         }
                         else
                         {
                             if(where->info.j[1]==1)
                             {
                                 where=finder(8,1);
                                 if(where->info.j[3]==1)
                                 {
                                     cj[8]++;
                                    if(jack_IDen==where->info.key){
                                        loc++;
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
 if(d==1) //tile2
    {
        where=finder(1,1);
            if(where->info.j[0]==1)
            {
                cj[1]++;
                if(jack_IDen==where->info.key){
                    loc++;
                }
                else
                    {
                        if(where->info.j[2]==1)
                        {
                        where=finder(4,1);
                         if(where->info.j[0]==1)
                         {
                              cj[4]++;
                             if(jack_IDen==where->info.key){
                             loc++;
                             }
                             else
                             {
                                 if(where->info.j[2]==1)
                                 {
                                     where=finder(7,1);
                                     if(where->info.j[0]==1)
                                     {
                                         cj[7]++;
                                         if(jack_IDen==where->info.key){
                                            loc++;
                                         }
                                     }
                                 }
                             }
                         }



                        }
                    }
            }

        }

 if(d==4) //tile 6
    {
        where=finder(5,1);
            if(where->info.j[1]==1)
            {
                 cj[5]++;
                if(jack_IDen==where->info.key){
                    loc++;
                }
                else
                    {
                    if(where->info.j[3]==1)
                    {
                     where=finder(4,1);
                     if(where->info.j[1]==1)
                     {
                          cj[4]++;
                         if(jack_IDen==where->info.key){
                            loc++;
                         }
                         else
                         {
                             if(where->info.j[3]==1)
                             {
                                 where=finder(3,1);
                                 if(where->info.j[1]==1)
                                 {
                                    cj[3]++;
                                    if(jack_IDen==where->info.key){
                                        loc++;
                                    }
                                 }
                             }
                         }
                     }
                    }
                    }
            }
    }
     if(d==7) //tile 8
    {
        where=finder(7,1);
            if(where->info.j[2]==1)
            {
                cj[7]++;
                if(jack_IDen==where->info.key){
                    loc++;
                }
                else
                    {
                        if(where->info.j[0]==1)
                        {
                        where=finder(4,1);
                         if(where->info.j[2]==1)
                         {
                              cj[4]++;
                             if(jack_IDen==where->info.key){
                             loc++;
                             }
                             else
                             {
                                 if(where->info.j[0]==1)
                                 {
                                     where=finder(1,1);
                                     if(where->info.j[2]==1)
                                     {
                                         cj[1]++;
                                         if(jack_IDen==where->info.key){
                                            loc++;
                                         }
                                     }
                                 }
                             }
                         }




                    }
            }
        }


    }
     if(d==10) //tile 4
    {
        where=finder(3,1);
            if(where->info.j[3]==1)
            {
                cj[3]++;
                if(jack_IDen==where->info.key){
                    loc++;
                }
                else
                    {
                    if(where->info.j[1]==1)
                    {
                     where=finder(4,1);
                     if(where->info.j[3]==1)
                     {
                          cj[4]++;
                         if(jack_IDen==where->info.key){
                            loc++;
                         }
                         else
                         {
                             if(where->info.j[1]==1)
                             {
                                 where=finder(5,1);
                                 if(where->info.j[3]==1)
                                 {
                                    cj[5]++;
                                    if(jack_IDen==where->info.key){
                                        loc++;
                                    }
                                 }
                             }
                         }
                     }
                    }

            }
        }

    }
    return loc;
    }
void jack_seen(void)
{
    tode* clean;
    for(int i=0;i<9;i++)
    {
        if(cj[i]==0)
        {
         clean=finder(i,1);
         clean->info.s=0;
        }
    }
}
void jack_unseen(void)
{
    tode* clean;
     for(int i=0;i<9;i++)
    {
        if(cj[i]!=0)
        {
         clean=finder(i,1);
         clean->info.s=0;
        }
    }
}
void check_tile(int d)
{
    tode* where;
if(d==0 || d==11) //tile 1
    {
        where=finder(0,1);
        if(d==0) //detective can see this direction
        {
            if(where->info.j[0]==1)
            {
                cj[0]+=2;
                 if(where->info.j[2]==1)
            {
            where=finder(3,1);
            if(where->info.j[0]==1)
            {
            cj[3]+=2;
            if(where->info.j[2]==1)
            {
             if(where->info.j[0]==1)
            {
            cj[6]+=2;

            }
            }
            }
            }
            }


        }
        if(d==11)
        {
            if(where->info.j[3]==1)
            {
                cj[0]+=2;
                 if(where->info.j[1]==1)
            {
            where=finder(1,1);
            if(where->info.j[3]==1)
            {
            cj[1]+=2;
             if(where->info.j[1]==1)
            {
            where=finder(2,1);
             if(where->info.j[3]==1)
            {
            cj[2]+=2;

            }
            }
            }
            }
            }


            }

    }
    if(d==2 || d==3) //tile 3
    {
        where=finder(2,1);
        if(d==2) //detective can see this direction
        {
            if(where->info.j[0]==1)
            {
                cj[2]+=2;
                  if(where->info.j[2]==1)
            {
            where=finder(5,1);
            if(where->info.j[0]==1)
            {
            cj[5]+=2;
            if(where->info.j[2]==1)
            {
            where=finder(8,1);
             if(where->info.j[0]==1)
            {
            cj[8]+=2;

            }
            }
            }
            }
            }


        }
        if(d==3)
        {
            if(where->info.j[1]==1)
            {
                cj[2]+=2;
                if(where->info.j[3]==1)
            {
            where=finder(1,1);
            if(where->info.j[1]==1)
            {
            cj[1]+=2;
             if(where->info.j[3]==1)
            {
            where=finder(0,1);
             if(where->info.j[1]==1)
            {
            cj[0]+=2;

            }
            }
            }
            }
            }


            }

    }
       if(d==5 || d==6) //tile 3
    {
        where=finder(8,1);
        if(d==6) //detective can see this direction
        {
            if(where->info.j[2]==1)
            {
               cj[8]+=2;
                 if(where->info.j[0]==1)
            {
            where=finder(5,1);
            if(where->info.j[2]==1)
            {
            cj[5]+=2;
             if(where->info.j[0]==1)
            {
            where=finder(2,1);
             if(where->info.j[2]==1)
            {
            cj[2]+=2;

            }
            }
            }
            }
            }


        }
        if(d==5)
        {
            if(where->info.j[1]==1)
            {
     //           puts("You entered tile 8");
                cj[8]+=2;
                 if(where->info.j[3]==1)
            {
       //     puts("You left tile 8");
            where=finder(7,1);
            if(where->info.j[1]==1)
            {
         //   puts("You entered tile 7");
            cj[7]+=2;
             if(where->info.j[3]==1)
            {
           // puts("You left tile 7");
            where=finder(6,1);
             if(where->info.j[1]==1)
            {
   //         puts("You entered tile 6");
            cj[6]+=2;

            }
            }
            }
            }
            }


            }

    }
       if(d==9 || d==8) //tile 3
    {
        where=finder(6,1);
        if(d==8) //detective can see this direction
        {
     //       printf("Checking d=8 :\n");
            if(where->info.j[2]==1)
            {
       //         puts("You entered tile 6");
                cj[6]+=2;
                 if(where->info.j[0]==1)
            {
         //   puts("You left tile 6");
            where=finder(3,1);
            if(where->info.j[2]==1)
            {
   //         puts("You entered tile 3");
            cj[3]+=2;
             if(where->info.j[0]==1)
            {
     //       puts("You left tile 3");
            where=finder(0,1);
             if(where->info.j[2]==1)
            {
       //     puts("You entered tile 0");
            cj[0]+=2;

            }
            }
            }
            }
            }



        if(d==9)
        {
//         printf("Checking d=9 :\n");
            if(where->info.j[3]==1)
            {
  //              puts("You entered tile 6");
                cj[6]+=2;
                 if(where->info.j[1]==1)
            {
    //        puts("You left tile 6");
            where=finder(7,1);
            if(where->info.j[3]==1)
            {
      //      puts("You entered tile 7");
            cj[7]+=2;
             if(where->info.j[1]==1)
            {
        //    puts("You left tile 1");
            where=finder(8,1);
             if(where->info.j[3]==1)
            {
          //  puts("You entered tile 8");
            cj[8]+=2;

            }
            }
            }
            }
            }


            }
    }
    }
    if(d==4)
    {
        where=finder(5,1);
   //         printf("Checking d=4 :\n");
            if(where->info.j[1]==1)
            {
     //           puts("You entered tile 5");
                cj[5]+=2;
                    if(where->info.j[3]==1)
            {
       //     puts("You left tile 5");
            where=finder(4,1);
            if(where->info.j[1]==1)
            {
         //   puts("You entered tile 4");
            cj[4]+=2;
             if(where->info.j[3]==1)
            {
           // puts("You left tile 4");
            where=finder(3,1);
             if(where->info.j[1]==1)
            {
      //      puts("You entered tile 3");
            cj[3]+=2;

            }

            }
            }
            }
            }



    }
      if(d==7)
    {
        where=finder(7,1);
    //        printf("Checking d=7 :\n");
            if(where->info.j[2]==1)
            {
      //          puts("You entered tile 7");
                cj[7]+=2;
                 if(where->info.j[0]==1)
            {
   //         puts("You left tile 7");
            where=finder(4,1);
            if(where->info.j[2]==1)
            {
     //       puts("You entered tile 4");
            cj[4]+=2;
             if(where->info.j[0]==1)
            {
       //     puts("You left tile 4");
            where=finder(1,1);
             if(where->info.j[2]==1)
            {
         //   puts("You entered tile 1");
            cj[1]+=2;

            }

            }
            }
            }
            }


    }
     if(d==1)
    {
        where=finder(1,1);
//            printf("Checking d=1 :\n");
            if(where->info.j[0]==1)
            {
  //              puts("You entered tile 1");
                cj[1]+=2;
                 if(where->info.j[2]==1)
            {
    //        puts("You left tile 1");
            where=finder(4,1);
            if(where->info.j[0]==1)
            {
      //      puts("You entered tile 4");
            cj[4]+=2;
            if(where->info.j[2]==1)
            {
        //    puts("You left tile 4");
            where=finder(7,1);
             if(where->info.j[0]==1)
            {
          //  puts("You entered tile 7");
            cj[7]+=2;

            }

            }
            }
            }
            }


    }
      if(d==10)
    {
        where=finder(3,1);
  //          printf("Checking d=10 :\n");
            if(where->info.j[3]==1)
            {
    //            puts("You entered tile 3");
                cj[3]++;
                 if(where->info.j[1]==1)
            {
      //      puts("You left tile 3");
            where=finder(4,1);
            if(where->info.j[3]==1)
            {
            cj[4]++;
             if(where->info.j[1]==1)
            {
            where=finder(5,1);
             if(where->info.j[3]==1)
            {
            cj[5]++;

            }

            }
            }
            }
            }


    }
}
int deduction_time(int who)
{
    for(int i=0;i<9;i++)
        cj[i]=0;
    int Jack_L=0;
    int res=0;
     if(who==1)//detective
     {
         for(int i=0;i<3;i++)
         {
             Jack_L=Jack_L+whereisJack(detector_t[i]);

         }
         if(Jack_L>0)
         {
            puts("You can see Jack!");
            res=1;

            for(int i=0;i<3;i++)
                check_tile(detector_t[i]);
            jack_seen();
         }
         else {
                puts("You cannot see Jack!");
                jack_unseen();

         }
     }
     else
        {
        if(who==0)
        {
             for(int i=0;i<3;i++)
         {
             Jack_L=Jack_L+whereisJack(detector_t[i]);
         }
        }
        if(Jack_L>0)
         {
            puts("You can see Jack!");
            res=1;
             for(int i=0;i<3;i++)
                check_tile(detector_t[i]);
            jack_seen();
         }
         else {
                puts("You cannot see Jack!");
                jack_unseen();
         }
        }
        return res;
}
int save;
int gamenumber;
char n[10];
int password;
int role;
char gname[20];
action act[4];
int game_saver(int who)
{
    tode* sav;
    int ans;
    puts("Pause Menu\n1- Resume\n2-Save Game\n3-Exit without saving\n");
    int cs;
    scanf("%d",&cs);
    if(cs==2)
    {
    FILE* fpin;
    fpin=fopen("D:\\Games.txt","a+");
    if(fpin == NULL)
    {
    printf("Cannot open file\n");
    return -1;
    }
    puts("Are you saving a game you saved before?\n1-yes\n2-No");
    scanf("%d",&ans);
    if(ans==1)
    {
        puts("Enter Game's name again with saving time(like JACK2)");
        scanf("%s",gname);
    }
    fprintf(fpin,"%s\n",gname);
    fprintf(fpin,"%d\n",password);
    fprintf(fpin,"%d\n",turn);
    fprintf(fpin,"%d\n",role);
    for(int i=0;i<9;i++)
    {

        sav=finder(i,1);
        fprintf(fpin,"%d  %d  %d %d %d %d  ",sav->info.key,sav->info.s,sav->info.j[0],sav->info.j[1],sav->info.j[2],sav->info.j[3]);//tile number-key to murderer-side of tile-position of tile-jack or not
        if(jack_IDen==sav->info.key)
            fprintf(fpin,"1\n");
        else fprintf(fpin,"0\n");
    }
    fprintf(fpin,"%d\n",jack_H); //hourglass
    fprintf(fpin,"%d %d %d\n",detector_t[0],detector_t[1],detector_t[2]); //detectives location
    for(int i=0;i<9;i++)
    {
        fprintf(fpin,"%d %d\n",card_order[i],c[i].jack);
    }
    fprintf(fpin,"%d %d %d %d\n",act[0].side,act[1].side,act[2].side,act[3].side);
    puts("\n");
    fclose(fpin);
    puts("Game saved Successfully");
    puts("1-Resume\n2-Exit\n");
    scanf("%d",&cs);
    if(cs==2)
        return -1;
    }
    if(cs==3)
        return -1;
}
void Exit(void)
{
    puts("See You Soon!");
}
void game_is_on(int c,int game)
{
    int soc=0;
    int k;
    int h=0;
   int ch[4];      //choices
     //actions' tokens
   if(game==1){
   card_and_id(); //cards are set randomly and jack identity has chosen.
   W_C_maker();  //whitechapel is ready
   token_start();// tokens are set
    for(int i=0;i<4;i++)
   {
       act[i].side=-1; //setting sides as unwanted side
   }
   }
   if(c==1)
    jack_id();
while(turn_checker()==0 && save==0) //till turn checker is 0
{
    printf("turn : %d\n\n",turn);  //prints turn
    table();
   if(turn%2!=0)   //Detector turn
   {
       puts("Detectors turn");
       for(int i=0;i<4;i++) //side of action token gonna be set 1: up / 0: down
       {
           act[i].side=rand()%2;
           act[i].check=0; //set action token unchosen
           printf("Token %d : %d\n",i+1,act[i].side);
       }
       puts("Detector, choose your first action: ");
       scanf("%d",&ch[0]);
       ch[0]=ch[0]-1;
       if(ch[0]==0)
       {
           Token1(act[0].side,1);
           act[0].check=1;
       }
        if(ch[0]==1)
       {
           Token2(act[1].side);
           act[1].check=1;
       }
        if(ch[0]==2)
       {
           Token3(act[2].side);
           act[2].check=1;
       }
        if(ch[0]==3)
       {
           Token4(act[3].side,1);
           act[3].check=1;
       }
       puts("Jack,choose 2 actions from available tokens: ");
       for(int i=0;i<4;i++)
       {
           if(act[i].check==0)
            printf("Token %d : %d\n",i+1,act[i].side);
       }
       scanf("%d%d",&ch[1],&ch[2]);
       ch[1]=ch[1]-1;

       if(ch[1]==0)
       {
           Token1(act[0].side,0);
           act[0].check=1;
           if(ch[2]==1)
            {
             Token2(act[1].side);
             act[1].check=1;
           }
           if(ch[2]==2)
           {
             Token3(act[2].side);
             act[2].check=1;
           }
           if(ch[2]==3)
            {
             Token4(act[3].side,0);
             act[3].check=1;
            }
       }
       else
        {
         if(ch[1]==1)
       {
           Token2(act[1].side);
           act[1].check=1;
           if(ch[2]==0){
             Token1(act[0].side,0);
             act[0].check=1;
           }
           if(ch[2]==2){
             Token3(act[2].side);
             act[2].check=1;
           }
           if(ch[2]==3){
             Token4(act[3].side,0);
             act[3].check=1;
           }
       }
       else
        {
         if(ch[1]==2)
       {
           Token3(act[2].side);
           act[2].check=1;
           if(ch[2]==1){
             Token2(act[1].side);
             act[1].check=1;
           }
           if(ch[2]==0){
             Token1(act[0].side,0);
             act[0].check=1;
           }
           if(ch[2]==3){
             Token4(act[3].side,0);
             act[3].check=1;
           }
       }
       else
        {
         if(ch[1]==3)
       {
           Token4(act[3].side,0);
           act[3].check=1;
           if(ch[2]==1){
             Token2(act[1].side);
             act[1].check=1;
           }
           if(ch[2]==2){
             Token3(act[2].side);
             act[2].check=1;}
           if(ch[2]==0){
             Token1(act[0].side,0);
             act[0].check=1;
           }
       }
        }
        }
        }
       puts("Detector,choose an action from available tokens: ");
       for(int i=0;i<4;i++)
       {
           if(act[i].check==0)
            printf("Token %d : %d\n",i+1,act[i].side);
       }
       scanf("%d",&ch[3]);
       ch[3]=ch[3]-1;
       if(ch[3]==0)
       {
           Token1(act[0].side,1);
           act[0].check=1;
       }
        if(ch[3]==1)
       {
           Token2(act[1].side);
           act[1].check=1;
       }
        if(ch[3]==2)
       {
           Token3(act[2].side);
           act[2].check=1;
       }
        if(ch[3]==3)
       {
           Token4(act[3].side,1);
           act[3].check=1;
       }
       h=deduction_time(1);
       if(h==0)
          jack_H++;
       puts("(In order to stop the game enter 1 otherwise enter another number and we'll continue)");
       scanf("%d",&soc);
       if(soc==1)
         {
        k=game_saver(1);
        if(k==-1)
            break;
        }
  }
    else  //jack turn
    {
     puts("Jack turn");
     for(int i=0;i<4;i++) //other side of action token gonna be set 1: up / 0: down
       {
           if(act[i].side==1) //other side
              act[i].side=0;
          else
          {
              if(act[i].side==0)
                act[i].side=1;
          }
          act[i].check=0;
          ch[i]=-1;
          printf("Token %d : %d\n",i+1,act[i].side);
       }
    puts("Jack, choose your first action: ");
       scanf("%d",&ch[0]);
       ch[0]=ch[0]-1;
       if(ch[0]==0)
       {
           Token1(act[0].side,0);
           act[0].check=1;
       }
        if(ch[0]==1)
       {
           Token2(act[1].side);
           act[1].check=1;
       }
        if(ch[0]==2)
       {
           Token3(act[2].side);
           act[2].check=1;
       }
        if(ch[0]==3)
       {
           Token4(act[3].side,0);
           act[3].check=1;
       }
       puts("Detector,choose 2 actions from available tokens: ");
       for(int i=0;i<4;i++)
       {
           if(act[i].check==0)
            printf("Token %d : %d\n",i+1,act[i].side);
       }
       scanf("%d%d",&ch[1],&ch[2]);
       ch[1]=ch[1]-1;
       ch[2]=ch[2]-1;
       if(ch[1]==0)
       {
           Token1(act[0].side,1);
           act[0].check=1;
           if(ch[2]==1)
            {
             Token2(act[1].side);
             act[1].check=1;
           }
           if(ch[2]==2)
           {
             Token3(act[2].side);
             act[2].check=1;
           }
           if(ch[2]==3)
            {
             Token4(act[3].side,1);
             act[3].check=1;
            }
       }
       else
        {
         if(ch[1]==1)
       {
           Token2(act[1].side);
           act[1].check=1;
           if(ch[2]==0){
             Token1(act[0].side,1);
             act[0].check=1;
           }
           if(ch[2]==2){
             Token3(act[2].side);
             act[2].check=1;
           }
           if(ch[2]==3){
             Token4(act[3].side,1);
             act[3].check=1;
           }
       }
       else
        {
         if(ch[1]==2)
       {
           Token3(act[2].side);
           act[2].check=1;
           if(ch[2]==1){
             Token2(act[1].side);
             act[1].check=1;
           }
           if(ch[2]==0){
             Token1(act[0].side,1);
             act[0].check=1;
           }
           if(ch[2]==3){
             Token4(act[3].side,1);
             act[3].check=1;
           }
       }
       else
        {
         if(ch[1]==3)
       {
           Token4(act[3].side,1);
           act[3].check=1;
           if(ch[2]==1){
             Token2(act[1].side);
             act[1].check=1;
           }
           if(ch[2]==2){
             Token3(act[2].side);
             act[2].check=1;}
           if(ch[2]==0){
             Token1(act[0].side,1);
             act[0].check=1;
           }
       }
        }
        }
        }
       puts("Jack,choose an action from available tokens: ");
       for(int i=0;i<4;i++)
       {
           if(act[i].check==0)
            printf("Token %d : %d\n",i+1,act[i].side);
       }
       scanf("%d",&ch[3]);
       ch[3]=ch[3]-1;
       if(ch[3]==0)
       {
           Token1(act[0].side,0);
           act[0].check=1;
       }
        if(ch[3]==1)
       {
           Token2(act[1].side);
           act[1].check=1;
       }
        if(ch[3]==2)
       {
           Token3(act[2].side);
           act[2].check=1;
       }
        if(ch[3]==3)
       {
           Token4(act[3].side,0);
           act[3].check=1;
       }
        h=deduction_time(0);
        if(h==0)
          jack_H++;
         puts("(In order to stop the game enter 1 otherwise enter another number and  we'll continue)");
       scanf("%d",&soc);
       if(soc==1)
         {
        k=game_saver(1);
        if(k==-1)
            break;
        }
    }

    turn++;
}
if(turn_checker()==1)
  {
      puts("Detector Won!");
      jack_id();
  }
if(turn_checker()==2 || turn_checker()==3)
{
    puts("Mr Jack Won!");
    if(turn_checker()==2)
      puts("By reaching 6 hourglasses!");
    if(turn_checker()==3)
        puts("Because Detective didn't find him!");
}
}
void newgame(void)
{
    puts("Please enter the name of this Game:");
    scanf("%s",gname);
    puts("Set Password: (an 4 digit number is only allowed) ");
    scanf("%d",&password);
    printf("Welcome!\n");
    puts("Which role do you want to play?\n1-Mr.Jack\n2-Detectors");
    int c;
    scanf("%d",&c);
    if(c==1)
        role=0;
    if(c==2)
        role=1;
   game_is_on(c,1);
}
char read[20];
int pcheck;
char pchecke[10];
char passworde[10];
int jack[9];
int load_game(void)
{
    int z=0;
    FILE* fp;
    int flag=0;
    fp=fopen("D:\\Games.txt","r");
    if(fp==NULL)
        puts("Nope");
  while(1)
        {
    fscanf(fp,"%s",read);
   if(strcmp(gname,read)==0)
    {
      //  printf("%s is found\n",m);
        flag=1;
    }
  if(flag==1)
  {
    fscanf(fp,"%s",passworde);
    password=atoi(passworde);
       if(password==pcheck)
  {
         fscanf(fp,"%d",&turn);
       fscanf(fp,"%d",&role);
   for(int i=0;i<9;i++)
   {
    t[i].p=i;
   fscanf(fp,"%d  %d  %d %d %d %d  %d",&t[i].key,&t[i].s,&t[i].j[0],&t[i].j[1],&t[i].j[2],&t[i].j[3],&jack[i]);
     if(jack[i]==1)
        jack_IDen=t[i].key;
   }
   fscanf(fp,"%d",&jack_H);
   fscanf(fp,"%d %d %d",&detector_t[0],&detector_t[1],&detector_t[2]);
   for(int i=0;i<9;i++)
   {
       fscanf(fp,"%d %d",&card_order[i],&c[i].jack);
   }
   fscanf(fp,"%d %d %d %d",&act[0].side,&act[1].side,&act[2].side,&act[3].side);
    z=1;
  }
  }
  if(feof(fp))
    break;
        }
    strcpy(t[0].name,"Insp. Lestrade");
    strcpy(t[1].name,"Jeremy Bert");
    strcpy(t[2].name,"John Pizer");
    strcpy(t[3].name,"John Smith");
    strcpy(t[4].name,"Joseph Lane");
    strcpy(t[5].name,"Madame");
    strcpy(t[6].name,"Miss Stealthy");
    strcpy(t[7].name,"Sgt Goodley");
    strcpy(t[8].name,"Wiliam Gull");
    strcpy(c[0].name,"Insp. Lestrade");
    c[0].hourglass=0;
    c[0].key=0;
    strcpy(c[1].name,"Jeremy Bert");
    c[1].hourglass=1;
     c[1].key=1;
    strcpy(c[2].name,"John Pizer");
    c[2].hourglass=1;
     c[2].key=2;
    strcpy(c[3].name,"John Smith");
    c[3].hourglass=1;
     c[3].key=3;
    strcpy(c[4].name,"Joseph Lane");
    c[4].hourglass=1;
     c[4].key=4;
    strcpy(c[5].name,"Madame");
    c[5].hourglass=2;
     c[5].key=5;
    strcpy(c[6].name,"Miss Stealthy");
    c[6].hourglass=1;
     c[6].key=6;
    strcpy(c[7].name,"Sgt Goodley");
    c[7].hourglass=0;
     c[7].key=7;
    strcpy(c[8].name,"Wiliam Gull");
    c[8].hourglass=1;
     c[8].key=8;


    for(int i=0;i<9;i++)
    {
     for(int ii=0;ii<9;ii++)
     {
         if(t[ii].p==i)
         {
             if(i==0)
               head_maker(&head,new_tile(t[ii]));  //set the choosen tile as head
             else  tile_adder(head,new_tile(t[ii]));  //adds new tile to whitechapel
         }
     }

    }
    whitechapel_print(head);
    fclose(fp);
    return z;
}
void previousgame(void)
{
    puts("please enter the name of the game you want to load:");
    scanf("%s",gname);
    puts("Enter Your Password:");
    scanf("%d",&pcheck);
    int response=load_game();
    if(response==1){
        puts("Signed in Successfully");
        game_is_on(role,0);
    }
    else puts("Signed in Failed");
}
void menu(void)
{
    puts("* Mr.Jack Pocket *");
    puts("---------------------------");
    printf("1- New Game\n2- Load Game\n3- Exit\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        newgame();
    else{
    if(choice==2)
       previousgame();
    Exit();
    }
}
int main()
{
    srand(time(NULL));
    menu();
    return 0;
}
