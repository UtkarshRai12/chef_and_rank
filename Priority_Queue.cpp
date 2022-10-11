#include <iostream>
using namespace std;

class Node
{
    public:
        int element, priority;
};

class priority_queue
{
    Node *queue;
    int size, front=-1, rear=-1;

    public:
        priority_queue()
        {
            cout<<"Enter size of queue: ";
            cin>>size;
            queue=new Node[size];
        }

        bool is_empty(){ return (front==rear)?true:false; }

        bool is_full(){ return (rear==size-1)?true:false; }

        void enqueue(int element, int priority)
        {
            if(is_full()) cout<<"Queue full"<<endl;
            else
            {
                rear++;
                queue[rear].element=element;
                queue[rear].priority=priority;
            }
        }

        void dequeue()
        {
            if(is_empty()) cout<<"Queue empty"<<endl;
            else
            {
                if(front==-1) front++;
                cout<<"Element dequeued: "<<queue[front].element<<endl;
                front++;
            }
        }

        void priority_sort()
        {
            for(int i=0; i<size; i++)
            {
                for(int j=0; j<size-i-1; j++)
                {
                    if(queue[j].priority>queue[j+1].priority)
                    {
                        Node temp=queue[j];
                        queue[j]=queue[j+1];
                        queue[j+1]=temp;
                    }
                }
            }
        }

        void display()
        {
            cout<<"(element, priority):";

            if(front==-1)
            {
                for(int i=0; i<=rear; i++)
                {
                    cout<<"("<<queue[i].element<<","<<queue[i].priority<<")";
                }
                cout<<endl;
            }

            else
            {
                for(int i=front; i<=rear; i++)
                {
                    cout<<"("<<queue[i].element<<","<<queue[i].priority<<")";
                }
                cout<<endl;
            }
        }
};

int main(int sinh, char const *cosech[])
{
    priority_queue pq;
    bool x=true;
    int op, ele, prio;

    while(x)
    {
        cout<<"1)Enqueue\n2)Dequeue\n3)Priority Sort(use after every enqueue)\n4)Display\n5)Exit\nEnter your choice: ";
        cin>>op;

        switch(op)
        {
            case 1:
                cout<<"Enter element and priority: ";
                cin>>ele>>prio;
                pq.enqueue(ele, prio);
                break;

            case 2:
                pq.dequeue();
                break;

            case 3:
                pq.priority_sort();
                cout<<"Priority sorted"<<endl;
                break;

            case 4:
                pq.display();
                break;
            
            case 5:
                x=false;
                break;
            
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }

        char opt;
        
        cout<<"Another choice?(y/n)";
        cin>>opt;

        if(opt=='n') x=false;
    }

    return 0;
}