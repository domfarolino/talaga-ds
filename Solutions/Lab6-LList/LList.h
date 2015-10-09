#ifndef LLIST_H
#define LLIST_H

#include <ostream>
#include <stdexcept>
using namespace std;

template <class T>
struct node_t
{
    T data;
    node_t* next;
}
;

template <class T>
class LList
{
    public:
    LList()
    {
        head = NULL;
       // L_size=0;
    }
    ~LList()
    {
    node_t<T>* temp = head;
    while(temp) {
      node_t<T>* to_delete = temp;
      temp = temp->next;
      delete to_delete;
    }

    head = NULL;
    }

    LList(const LList& other)
    {
    	head = NULL;

    	node_t<T>* temp = other.head;
    	while(temp) {
    	  push_back(temp->data);
    	  temp = temp->next;
    	}
    }

    //Assignment operator.
    LList<T>& operator= (const LList& other)
    {

	   if(this != &other) {
     clear();
     head = NULL;

      node_t<T>* temp = other.TakeMeTo(0);
      while(temp) {
        push_back(temp->data);
        temp = temp->next;
      }
    }
    return *this;
    }

    //gets the node's value at 'pos'.
    T getAt(int pos) const
    {
        //////cout<<"::"<<pos<<endl;
        if(pos<0)
        {
            pos=size()+pos;
        }
       if(pos<0)
        {
					throw logic_error("out of bounds 1");
        }
				if(pos>=size())
        {
					throw logic_error("out of bounds 1");
        }
        //////cout<<"::"<<pos<<endl;
        node_t<T>* temp;
        temp=head;
        int i=0;
        while((temp) && i!=pos)
        {
            temp=temp->next;
            i++;
        }
        return temp->data;
    }

    //return the size of the linked list.
    unsigned int size() const
    {
    if(!head) {
      return 0;
    }

    unsigned int L_size = 1;
    node_t<T>* temp = head;
    while(temp && temp->next) {
      temp = temp->next;
      L_size++;
    }
        return L_size;
    }

    // adds an entry to the back.
    void push_back(T value)
    {
  	  if(!head) {
  	    push_front(value);
  	    return;
  	  }

        node_t<T>* temp;
        temp = head;
        while(temp->next)
        {
            temp=temp->next ;
            
        }
        node_t<T>* new_node = new node_t<T>;
        new_node->data= value;
        new_node->next= NULL;
        temp->next= new_node;
       
    }

    //adds an entry to the front.
    void push_front(T value)
    {
        node_t<T>* temp = new node_t<T>;
        temp->data = value;
        temp->next = head;
        head = temp;
       
    }

    node_t<T>* TakeMeTo(int pos) const
    {
        node_t<T>* temp = new node_t<T>;
        temp=head;
        int i=0;
        while ((temp) && i!=pos)
        {
            temp=temp->next;
            i++;
        }
        return temp;
    }
    //sets the value at i
    void setAt(T value, int pos)
    {
        if(pos<0)
        {
            pos=size()+pos;
        }
       if(pos<0)
        {
					throw logic_error("out of bounds 1");
        }
				if(pos>=size())
        {
					throw logic_error("out of bounds 1");
        }
        node_t<T>* temp ;
        temp=head;
        int i=0;
        while((temp) && i!=pos)
        {
            temp=temp->next;
            i++;
        }
        temp->data = value;
        ////cout<<"setat value :"<< value<<endl;
        ////cout<<"i value :"<< i<<endl;
    }
    void remove(int pos)
    {
    if(pos < 0) {
      pos = size() + pos;
    }
    if(pos < 0) {
      throw logic_error("out of bounds1");
    }
    if(pos >= size()) {
      throw logic_error("out of bounds2");
    }
		if(size()==0)
		{
			throw logic_error("empty");
		}

    if(pos == 0 && head) {

      node_t<T>* to_delete = head;
      head = head->next;
      delete to_delete;
		//	L_size--;

    }
else{

        node_t<T>* temp;
        temp=head;
        int i=0;

        while((temp) && i!=pos-1)
        {
            temp=temp->next;
            i++;
        }
        node_t<T>* to_delete = temp->next;
				if(temp->next->next){
					temp->next=temp->next->next;
				}else
				{
				temp->next=NULL;
				}

        delete to_delete;
   
}
    }

    LList<T> reverse() const
    {
        T temp_array[size()];
        node_t<T>* temp ;
        temp=head;
       
				int i=0;
				while (temp && i<size())
				{
            temp_array[i]=temp->data;
            temp=temp->next;
						i++;
				}
				

				LList<T> tempLL;
        for(int i=0;i<size();i++)
        {
            tempLL.push_front(temp_array[i]);

        }

        return tempLL;
    }

    LList<T> operator+(const LList<T>& other) const
    {
		    LList<T> tempLL;

    // push in this's values
    node_t<T>* temp = head;
    while(temp) {
      tempLL.push_back(temp->data);
      temp = temp->next;
    }

    // push in other's values
    temp = other.head;
    while(temp) {
      tempLL.push_back(temp->data);
      temp = temp->next;
    }

    return tempLL;
    }

    bool operator==(const LList<T>& other) const
    {
    node_t<T>* temp1 = head;
    node_t<T>* temp2 = other.head;
    
    while(temp1 && temp2) {
      if(temp1->data != temp2->data) {
        return false;
      }

      temp1 = temp1->next;
      temp2 = temp2->next;
    }

    
    return !temp1 && !temp2;
   
    }
    bool operator!=(const LList<T>& other) const
    {
return !(*this==other);
   
    }
    void clear()
    {
        node_t<T>* temp;
        temp=head;
				
        while((temp))
        {
						
            node_t<T>* to_delete = temp;
            temp=temp->next;
            
            delete to_delete;
        }				
				head=NULL;
			
    }
    private:
    
    node_t<T> *head;
    
}
;
template <class T>
ostream& operator<<(ostream& out, const LList<T> other)
{
  out << "[";

  for(int i = 0; i < (int) other.size() - 1; i++) {
    out << other.getAt(i) << ",";
  }

  if(other.size() > 0) {
    out << other.getAt(other.size() - 1);
  }

  return out << "]";
}
#endif
