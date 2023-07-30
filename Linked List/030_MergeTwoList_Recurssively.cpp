Node* merge(Node*a , Node* b){
    if(!a)   return b;
    if(!b)   return a;
    Node* ans=NULL;
    
    if(a->data < b->data) {
        ans=a;
        a->next=merge(a->next,b);
    }
    
    else{
        ans=b;
        b->next=merge(a,b->next);
    }
    
    return ans;
}    
