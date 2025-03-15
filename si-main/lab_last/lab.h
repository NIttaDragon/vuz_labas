struct Node
{
  int data;
  struct Node *next;
};

struct Node *create(int _data)
{
  struct Node *element=(struct Node*) malloc(sizeof(struct Node));
  element->data=_data;
  element->next=NULL;
  return element;
}

// struct Node *addFirst(int data, struct Node *head)
// {
//   struct Node *tmp=(struct Node*)malloc(sizeof(struct Node));
//   tmp->value=data;
//   tmp->next=head;
//   return(tmp);
// }

void addLast(struct Node *_head,int _data)
{
  if(!_head)
  {
    printf("NULL-pointer head!\n");
    return (-1);
  }
  while(_head->next)
    _head=_head->next;
  _head->next=(struct Node*)malloc(sizeof(struct Node));
  _head=_head->next;
  _head->data=_data;
  _head->next=NULL;
  return (0);
}

// struct Node *addN(int data, int n,struct Node *head)
// {
//   struct Node *p=head;
//   int count=1;
//   while((count<n-1)&&(p->next!=NULL))
//   {
//     p=p->next;
//     count++;
//   }
//   struct Node *tmp=(struct Node*)malloc(sizeof(struct Node));
//   tmp->value=data;
//   tmp->next=p->next;
//   p->next=tmp;
//   return head;
// }

// struct Node *remA(struct Node *head)
// {
//   while(head!=NULL)
//   {
//     struct Node *p=head;
//     head=head->next;
//     free(p);
//   }
//   return NULL;
// }

// struct Node *remN(int data, struct Node *head)
// {
//   struct Node *tmp=head, *p=NULL;
//   if(head==NULL)
//     return NULL;
//   while(tmp&&tmp->value!=data)
//   {
//     p=tmp;
//     tmp=tmp->next;
//   }
//   if(tmp==head)
//   {
//     free(head);
//     return tmp->next;
//   }
//   if(!tmp)
//     return head;
//   p->next=tmp->next;
//   free(tmp);
//   return head;
// }

struct Node* findelem(struct Node* _head, int _index)
{
  if(!_head)
  {
    printf("NULL-pointer head!\n");
    return NULL;
  }
  if(_index<0)
  {
    printf("The index must bbe greater than 0. Or can be 0.\n");
    return NULL;
  }
  int index=0;
  while(_head->next && _index!=index)
  {
    ++index;
    _head=_head->next;
  }
  if(_index!=index)
    return NULL;
  return _head;
}
