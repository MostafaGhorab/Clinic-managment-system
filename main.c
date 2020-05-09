
#include "header.h"
#include "mm.c"
u32 enteredValue;
int slot[5] = {0}; // initializing all slots with zero which means all are free





int main()
{
    u8 choice;
    u8 flag =0; //flag to maintain looping
    u32 pass = 1234; //default pass for admin mode
    u32 enteredpass ; // entered bass scanned by user
    u32 adminflag = 0; //flag for admin mode to maintain the looping
    u32 userflag = 0;
    u32 k = 0;
    char pname[40];
    u32 page;
    char pgender[10];
    u32 pID;
   node *search = NULL;
  linkedList clinic = createLinkedList(); //creating object from linked list





    printf("Welcome\n");

    while (flag==0){
             printf("To enter Admin Mode press 1\nTo enter User Mode press 2\nTo exit press 3\nYour Choice :");
             scanf("%d",&choice);
  switch (choice)
{

        case 1 : //admin  mode
    k=0;

    printf("Enter the password please:");

    do{
            if( (k==1) | (k ==2) ) //indication for number of times the pass is entered wrong
            {
            printf("Invalid password!! olny %d trial/s left \nEnter the password again please:",3-k);
            }
              if (k==3)
            {
                printf("SYSTEM CLOSED!");
                return 0;
            }
            k++;

            scanf("%d",&enteredpass);
    }while(enteredpass!= pass);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n----------WELCOME TO ADMIN MODE----------\n\n\n");
    adminflag =0; //stay in admin mode until flag changes in return back
    userflag = 0;

      while (adminflag == 0)
                {

    printf("To add new patient press 1\nTo edit a patient record press 2\nTo reserve a slot press 3\nTo cancel a reservation press 4\nTo return back press 5\n");
    printf("Your choice:");
    scanf("%d",&choice);
if(choice ==1)
    {
        printf("Enter patient's name: ");
        getchar();
        scanf("%[^\n]",pname);
        printf("%s\n",pname);
        printf("Enter patient's age: ");
        scanf("%d",&page);
        printf("Enter patient's gender: ");
        getchar();
        gets(pgender);
        do {
        printf("Enter patient's ID: ");
        scanf("%d",&pID);
        search = searchID (&clinic, pID); //returns a pointer to the node which id exists if it exists or return null
        if (search !=NULL)
        {
            printf("\nID Exists!\n");
        }


        } while (search !=NULL) ;




        addNode(&clinic,pname , page ,pgender, pID) ;
        printf("patient is added!\n");
        printf("\n\n");
    }
if (choice ==2)
{
    int k =1;
do
{

    printf("Enter patient's ID to edit record:");

    scanf("%d",&pID);
    search = searchID (&clinic, pID);
    if(k == 3) //if the users enter wrong ID more than 3 times program return back to menu
    {
        printf("Check the ID then try again\n\n\n\n\n");
        break;
    }
    if(search == NULL) // didn't find the id
    {
        printf("ID DOESN'T EXIST!!\n");
        k++;
    }

}while ( search ==NULL)  ;
    if ( (search != NULL) && (k!=3) ) //so id to edit is there enter the new data for the patient
    {


      node *edit_node = search;
     printf("Enter patient's new name: ");
        getchar();
        scanf("%[^\n]",pname);
        printf("%s\n",pname);
        printf("Enter patient's new age: ");
        scanf("%d",&page);
        printf("Enter patient's new gender: ");
        getchar();
        gets(pgender);
        /*
    do {
        printf("Enter patient's new ID: ");
        scanf("%d",&pID);
        search = searchID (&clinic, pID);
        if (search !=NULL)
        {
            printf("\nID Exists!\n\n");
        }


    } while (search !=NULL) ;
*/

        editNode(edit_node,pname , page ,pgender) ;
        printf("Record is edited!\n");
        printf("\n\n");
    }

} //end of choice 2

  if (choice == 3)
  {
      int k =1; //same code to check if ID availble (from here to line 167<<
do
{

    printf("Enter patient's ID to reserve a slot today :");

    scanf("%d",&pID);
    search = searchID (&clinic, pID);
    if(k == 3) //if the users enter wrong ID more than 3 times program return back to menu
    {
        printf("Check the ID then try again\n\n\n\n\n");
        break;
    }
    if(search == NULL) // didn't find the id
    {
        printf("ID DOESN'T EXIST!!\n");
        k++;
    }

}while ( search ==NULL)  ;
        if ( (search != NULL) && (k!=3) )//then the ID exists
        {
int i;
printf("-----------------------------------------------------------------------------------------\n\n");
printf("\n\n\nThere are 5 slots\nslot 0: from 2pm to 2:30\nslot 1: from 2:30pm to 3\nslot 2: from 3pm to 3:30\nslot 3: from 4pm to 4:30\nslot 4: from 4:30 to 5\n");
printf("\n\n\n\n\n-----------------------------------------------------------------------------------------\n\n\n");
    for (i=0;i<5;i++)

    {
    if (slot[i] == 0)
    printf("Slot %d is available\n",i);
    }
     printf("Enter the slot number you wish to reserve in:");
     int slott_no;
     scanf("%d",&slott_no);
     if ( (slot[slott_no] ==0 )&& (slott_no<=4)  )
     {
        slot[slott_no] = search->ID ;
         printf("slot is reserved!\n\n\n");

     }
     else
        {

        printf("SORRY this slot is unavailable..\n\n\n");

        }

      } //end of if the id exists
} //end of choice 3
if (choice ==4) //cancel a reservation <emptying a slot from the array>
{
    printf("Enter the ID you wish to cancel its reservation:");
    int cancelling_ID;
    int i;
    int fflag = 0;
    scanf("%d",&cancelling_ID);
    for (i=0;i<5;i++)
    {
        if (slot[i] == cancelling_ID)
        {
            slot[i] = 0;
            printf("Reservation for slot %d is cancelled!\n\n\n",i);
            fflag =1;
        }
    }
    if (fflag == 0) //this if no reservation for the id entered or the id doesnt already exits
    {
        printf("INVALID ID or RESERVATION!\n\n\n");
    }

}
if (choice ==5)
{
    printf("Admin mode is Terminated\n\n\n\n\n\n\n");
    adminflag = 1;
}

}//end of admin mode
        break;

       case 2 : //user mode
           printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n----------WELCOME TO USER MODE----------\n\n\n");

      while (userflag == 0)
      {
          int choicee;
          int patientID;
          printf("To view a patient record please press 1\nTo view today's reservations please press 2\nTo return back press 3\n");
          printf("Your choice:");
          scanf("%d",&choicee);
          switch (choicee)
          {
      case 1 :
do{
      printf("Enter patient's ID you wish to view:");
      scanf("%d",&patientID);

    search = searchID (&clinic, patientID);
    if(k == 3) //if the users enter wrong ID more than 3 times program return back to menu
    {
        printf("Check the ID then try again\n\n\n\n\n");
        break;
    }
    if(search == NULL) // didn't find the id
    {
        printf("ID DOESN'T EXIST!!\n");
        k++;
    }

}while ( search ==NULL)  ;
    if ( (search != NULL) && (k!=3) ) //if found
    {
       print(search);
    }
      break;
      case 2 :
        printf("-----------------------------------------------------------------------------------------\n\n");
        printf("\n\n\nThere are 5 slots\nslot 0: from 2pm to 2:30\nslot 1: from 2:30pm to 3\nslot 2: from 3pm to 3:30\nslot 3: from 4pm to 4:30\nslot 4: from 4:30 to 5\n");
        printf("\n\n\n\n\n-----------------------------------------------------------------------------------------\n\n\n");
        int i;
        for (i=0;i<5;i++)
        {
    if (slot[i] != 0)
    printf("Slot %d is reserved by %d\n",i,slot[i] );
    else  printf("Slot %d is available\n",i );
        }
        printf("\n\n\n");
    break;
      case 3 :
          printf("USER mode is Terminated\n\n\n\n\n\n\n");
        userflag = 1; //to exit this mode and return back
        break;

        default : printf("INVALIDDDDD!\n\n\n");
        break;
          }//for end of  switch case of user mode





      } //for end of while of userflag
        break;
        case 3 :
            printf("Good bye ");
            flag = 1; break;
        default : printf("INVALIDDDDD!\n\n\n"); break;
    } //switch case


}

    return 0;
}
