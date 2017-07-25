//
//  main.c
//  test
//
//  Created by 刘子琪 on 2017/7/25.
//  Copyright © 2017年 LinkList. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}Node,*head;

head create_list(int number,int local)
{
    head tail=NULL;
    head temp=NULL;
    head head=NULL;

    for(int i=0;i<number;i++)
    {
        temp=(Node*)malloc(sizeof(Node));
        temp->data=number-i;
        if(head==NULL)
        {
            tail=temp;
        }
        temp->next=head;
        head=temp;
    }
    int i;
    for(i=0,temp=head;i<local;i++)
    {
        temp=temp->next;
    }
    tail->next=temp;
    return head;
}

void output(head p)
{
    while (p!=NULL) {
        printf("%d\t",p->data);
        p=p->next;
        getchar();
    }
    printf("\n");
}

int get_circle_local(head p)
{
    head fast=NULL;
    head slow=NULL;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            for(slow=p;slow!=fast;)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow->data;
        }
    }
    return 0;
}

int main()
{
    int local=0;
    int number=0;
    printf("please input number and local");
    scanf("%d",&number);
    scanf("%d",&local);
    head p=NULL;
    p=create_list(number,local);
    if(get_circle_local(p)>0)
    {
        printf("%d\n",get_circle_local(p));
    }
    else
    {
        printf("no circle\n");
    }
}
















