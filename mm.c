#include "header.h"
extern u32 enteredValue;




linkedList createLinkedList(void)
{


    linkedList listt ;

    listt.head = NULL ;

    return listt;

}


  void addNode ( linkedList *listt,char pname[40],u32 page ,char pgender[10],u32 pID)
{

    node *newNode;
    newNode = (node*)malloc(sizeof(node)) ;
    strcpy(newNode->name,pname);
    newNode->age = page ;
    strcpy(newNode->gender,pgender);
    newNode->ID = pID ;
    newNode->next = NULL;
    node*Temp;


     Temp = ( listt->head );


    if (Temp==NULL) //first NODE
    {

       (listt->head) = newNode;


    }
    else if ((Temp ->next) == NULL)
    {

    (listt->head )-> next = newNode;


    }
    else
    {


        while (Temp->next != NULL)
    {
        Temp = Temp->next;

    }
    (Temp->next) = newNode;

    }

}
void print (node *listt)

{
  printf("\n\nPatien's name is :%s\n",listt->name);
  printf("Patien's age is :%d\n",listt->age);
  printf("Patien's gender is :%s\n",listt->gender);
  printf("Patien's ID is :%d\n\n\n",listt->ID);


}
    node*  searchID (linkedList *listt,u32 pID)
    {
    node *Temp;
    Temp =( listt->head ) ;
    if (Temp == NULL)
    {
        return NULL;
    }

     while ( Temp != NULL )
     {


    if ( (Temp->ID) == pID)

    {


        return Temp;
    }
     Temp =( Temp->next);
    }

     return NULL;
      }

  void editNode ( node *patient_node,char pname[40],u32 page ,char pgender[10])
{



    strcpy(patient_node->name,pname);
    patient_node->age = page ;
    strcpy(patient_node->gender,pgender);



}






