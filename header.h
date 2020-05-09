#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long int u64;
typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef signed long long int s64;
typedef float f32;
typedef double f64;
typedef struct nodeee
{
     u32 age;
    char name[40];

    char gender[10];
    u32 ID;
struct node *next;
}node;


typedef struct{

 node *head;

}linkedList;
linkedList createLinkedList(void);



 void addNode (linkedList *listt,char pname[40],u32 page ,char pgender[10],u32 pID) ;
 void print (node *lisst);
 node* searchID (linkedList *listt,u32 pID);
 void editNode ( node* patient_node,char pname[40],u32 page ,char pgender[10]);



#endif // HEADER_H_INCLUDED
