/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    struct node{
        int val;
        node* next;
        node(int v){
            val=v;
            next=NULL;
        }
    };
    node *head;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        int n=nums.size();
        head=NULL;
        if(n)
            head=new node(nums[0]);
        node* iter=head;
        for(int i=1;i<n;i++)
        {
            iter->next=new node(nums[i]);
            iter=iter->next;
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return head->val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int val=head->val;
        head=head->next;
        return val;
	}
	
	bool hasNext() const {
	    return (head!=NULL);
	}
};