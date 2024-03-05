/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-01 18:06:16
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-04 11:53:08
 * @FilePath: \c\hello.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>

typedef struct LinkListNode_type
{
    unsigned int data;
    struct LinkListNode_type *next;
}LinkListNode_t;

typedef struct LinkList_type
{
    unsigned int len;
    LinkListNode_t *heat;
}LinkList_t;

LinkList_t LinkList;
LinkList_t* pLinkList;


void LinkListInit(LinkList_t *plist)   //链表初始化
{
    plist->heat = malloc(sizeof(LinkListNode_t));
    plist->heat->next = NULL;
    plist->len = 0;
}
void LinkListCreate(LinkList_t *plist,int data[],int n) //头插法
{
    LinkListNode_t *pheat = plist->heat;  
    int i = 0;
    for (i = 0; i < n; i++)
    {
        LinkListNode_t *node = malloc(sizeof(LinkListNode_t));
        node->data = data[i];
        node->next = pheat->next;
        pheat->next = node;
    }
}
void LinkListCreate1(LinkList_t *plist,int data[],int n) //尾插法
{
    LinkListNode_t *pheat = plist->heat;  
    int i = 0;
    for (i = 0; i < n; i++)
    {
        LinkListNode_t *node = malloc(sizeof(LinkListNode_t));
        node->data = data[i];
        node->next = pheat->next;
        pheat->next = node;
        pheat = node;
    }
    plist->len = i;
}
int LinkListInsertNode(LinkList_t *plist,int index,int data) //插入
{
    LinkListNode_t *pheat = plist->heat;  
    int i = 0;

    if(index > plist->len+1)
    {
        return -1;
    }
    for ( i = 0; i < index-1; i++)
    {
        pheat = pheat->next;
    }
    LinkListNode_t *node = malloc(sizeof(LinkListNode_t));
    node->data = data;
    node->next = pheat->next;
    pheat->next = node;
    plist->len++;

}
int LinkListDelNodeOfIndex(LinkList_t *plist,int index) //按下表删除
{
    LinkListNode_t *pheat = plist->heat;  
    int i = 0;
    LinkListNode_t *p = NULL;
    if(index > plist->len)
    {
        return -1;
    }
    for ( i = 0; i < index-1; i++)
    {
        pheat = pheat->next;
    }
    p = pheat->next;
    pheat->next = p->next;
    free(p);
    plist->len--;
}
int LinkListDelNodeOfData(LinkList_t *plist,int data) //按数据删除
{
    LinkListNode_t *p = plist->heat->next; 
    LinkListNode_t *q = NULL; 
    int i = 0;
    
    while (p != NULL)
    {
        if(p->data == data)
        {
            q->next = p->next;
            free(p);
            plist->len--;
            break;
        }
        q = p;
        p = q->next;
    }
}
void LinkListShow(LinkList_t *plist)    //List输出
{
    printf(" --------- \r\n");
    LinkListNode_t *pCur = plist->heat->next;
    while (pCur->next != NULL)
    {
        printf("DATA %d\r\n",pCur->data);
        pCur = pCur->next;
    }
    printf("DATA %d\r\n",pCur->data);
}
LinkList_t *LinkListReverse(LinkList_t *plist)
{
    LinkListNode_t *node = plist->heat;
    LinkListNode_t *p = node->next;
    LinkListNode_t *heat;
    node->next = NULL;
    while (p)
    {
        heat = p;
        p = p->next;
        heat->next = node->next;
        node->next = heat;
    }
}

LinkList_t *LinkListReverse1(LinkList_t *plist)
{
    LinkListNode_t *heat = plist->heat;
    LinkListNode_t *p = heat->next;
    LinkListNode_t *s;
    heat->next = NULL;

    while (p)
    {
        s = p;
        p = p->next;
        s->next = heat->next;
        heat->next = s;
    }
}
int main(){
    int data[] = {0,1,2,3,4,5,6,7,8,9};
    LinkListInit(&LinkList);
    LinkListCreate1(&LinkList,data,10);
    // LinkListInsertNode(&LinkList,11,11);
    // LinkListDelNodeOfIndex(&LinkList,5);
    // LinkListDelNodeOfData(&LinkList,11);
    LinkListShow(&LinkList);
    LinkListReverse1(&LinkList);
    LinkListShow(&LinkList);
    return 0;
}