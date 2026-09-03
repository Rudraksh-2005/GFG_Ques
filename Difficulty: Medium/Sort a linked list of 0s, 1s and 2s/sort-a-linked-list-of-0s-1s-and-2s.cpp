/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zeroh=new Node(-1);
        Node* oneh=new Node(-1);
        Node* twoh=new Node(-1);
        
        
        Node* zero=zeroh;
        Node* one=oneh;
        Node* two=twoh;
        
        Node* temp=head;
        
        while(temp!=NULL){
            if(temp->data==0){
                zero->next=temp;
                zero=zero->next;
            }
            else if(temp->data==1){
                one->next=temp;
                one=one->next;
            }
            else{
                two->next=temp;
                two=two->next;
            }
            
            temp=temp->next;
        }
        
        
        zero->next=(oneh->next)?oneh->next : twoh->next;
        one->next=twoh->next;
        two->next=NULL;
        
        delete oneh,twoh;
        
        return zeroh->next;
        
        
    }
};