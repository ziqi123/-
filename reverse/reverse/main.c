//
//  main.c
//  reverse
//
//  Created by 刘子琪 on 2017/7/25.
//  Copyright © 2017年 LinkList. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int iData;
    struct node *next;
}LNode,*LinkList;

LinkList Link_insert(LinkList p,int num)
{
    LinkList temp=NULL;
    temp=(LinkList)malloc(sizeof(LNode));
    if(temp==NULL)
    {
        perror("malloc");
    }
    temp->iData=num;
    temp->next=p;
    p=temp;
    return p;
}

void Link_print(LinkList temp)
{
    while(temp!=NULL)
    {
        printf("%d\t",temp->iData);
        temp=temp->next;
    }
    printf("\n");
}

LinkList reverse_link(LinkList list)
{
    if(list==NULL||list->next==NULL)
    {
        return list;
    }
    LinkList temp,prev,next;
    
    prev=list;
    temp=list->next;
    prev->next=NULL;
    
    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
}

int main(int argc,char *argv[])
{
    LinkList head=NULL;
    int temp=0;
    int i;
    for(i=0;i<10;i++)
    {
        printf("input number:");
        scanf("%d",&temp);
        head=Link_insert(head,temp);
        Link_print(head);
    }
    printf("after reverse:\n");
    head=reverse_link(head);
    Link_print(head);
}
