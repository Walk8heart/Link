

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

void LinkListInit(LinkList_t *plist);   //链表初始化
void LinkListCreate(LinkList_t *plist,int data[],int n); //头插法
void LinkListCreate1(LinkList_t *plist,int data[],int n); //尾插法
int LinkListInsertNode(LinkList_t *plist,int index,int data); //插入
int LinkListDelNodeOfIndex(LinkList_t *plist,int index); //按下表删除
int LinkListDelNodeOfData(LinkList_t *plist,int data); //按数据删除
void LinkListShow(LinkList_t *plist);    //List输出
