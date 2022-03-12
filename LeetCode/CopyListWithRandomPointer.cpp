/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node* iter=head;
        Node* headC=new Node(head->val);
        Node* iterC=headC;
        map<Node*,Node*> copyHelper;
        copyHelper.insert({head,headC});
        do{
            iter=iter->next;
            if(!iter)break;
            iterC->next=new Node(iter->val);
            iterC=iterC->next;
            copyHelper.insert({iter,iterC});
        }while(iter->next);
        iterC->next=NULL;
        map<Node*,Node*>:: iterator it=copyHelper.begin();
        Node* targetNode;
        while(it!=copyHelper.end()){
            if((*it).first->random==NULL)
                targetNode=NULL;
            else 
            {
                targetNode=copyHelper[(*it).first->random];
            }
            (*it).second->random=targetNode;
            it++;
        }
        return headC;
    }
};

/*
    BETTER SOLUTION
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node* temp = head;
        
        while(temp){
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = node->next;
        }
        
        temp = head;
        while(temp){
            temp->next->random = (temp->random)?temp->random->next:NULL;
            temp = temp->next->next;
        }
        
        Node* ans = head->next;
        temp = head->next;
        while(head){
            head->next = temp->next;
            head = head->next;
            if(!head) break;
            temp->next = head->next;
            temp = temp->next;
        }
        return ans;
    }
};