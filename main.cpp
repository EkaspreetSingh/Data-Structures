#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

class minHeap
{
    private:
        int *harr; //pointer to heap array
        int capacity;
        int heapSize;

        int parent(int n){
        return (n-1)/2;
        }
        int leftChild(int n){
        return (2*n)+1;
        }
        int rightChild(int n){
        return (2*n)+2;
        }

    public:
        minHeap(int cap) //parameterized constructor
        {
            capacity = cap;
            heapSize =0;
            harr = new int[capacity];
        }
        void printArray()
        {
            for(int i=0; i<heapSize; i++)
                cout<<harr[i]<<" ";
            cout<<endl;
        }
        int height()
        {
            return ceil(log2(heapSize+1))-1;
        }
        void insertion(int key)
        {
            if(heapSize == capacity)
            {
                cout<<"overflow";
                return;
            }
            int i = heapSize;
            heapSize++;
            harr[i] = key;

            while(i!=0 && harr[i]<harr[parent(i)])
            {
                swap(harr[i],harr[parent(i)]);
                i = parent(i);
            }
        }

        void heapify(int index)
        {
                int i= index;
                int l= leftChild(index);
                int r= rightChild(index);

            while(l<heapSize)
            {
                if(r>heapSize)
                {
                    if(harr[l]<harr[i])
                        swap(harr[l],harr[i]);
                    return;
                }

                if((harr[l]>harr[i])&&(harr[r]>harr[i]))
                    return;
                else{
                    if(harr[l]<harr[r])
                     {
                        swap(harr[i],harr[l]);
                         i = l;
                     }
                    else
                    {
                        swap(harr[i],harr[r]);
                        i = r;
                    }
                    l= leftChild(i);
                    r= rightChild(i);
                }
            }
        }
        int extractMin()
        {
            if(heapSize <= 0)
                return INT_MAX;

            else if(heapSize==1)
            {
                heapSize--;
                return harr[0];
            }
            int result = harr[0];
            heapSize--;
            harr[0] = harr[heapSize];

            heapify(0);
            return result;
        }
        int deleteKey(int index)
        {
            if(heapSize <= index)
                return INT_MAX;

            else if(heapSize-1==index)
            {
                heapSize--;
                return harr[index];
            }
            int result = harr[index];
            heapSize--;
            harr[index] = harr[heapSize];

            heapify(index);
            return result;
        }
        int fsearch(int ele)
        {
            int i;
            for(i=0; harr[i] != ele; i++);
            return i;
        }
};
int main()
{
    int siz=15, option = INT_MAX;
//    cout<<"enter size of min heap: ";
//    cin>>siz;
    minHeap obj(siz);

    for(int i=0; i<7; i++)
    {
        obj.insertion(1+rand()%10);
    }
    cout<<"\nyour MIN HEAP is created congrats sir!!!!!\n";
    obj.printArray();

    while(option != 0)
    {
        cout<<"\n1.insertion\n2.extract min\n3.delete key\n4.height of heap\n5.print/traverse heap values\n6.clear screen\n0.exit\n";
        cin>>option;

        if(option == 1)
        {
            int ele;
            cout<<"\nenter element to be entered: ";
            cin>>ele;
            obj.insertion(ele);
            obj.printArray();
        }
        else if(option == 2)
        {
            int x= obj.extractMin();
            if(x==INT_MAX)
                cout<<"\nunderflow";
            else
            cout<<endl<<x<<" is extracted\n";
            obj.printArray();
        }
        else if(option == 3)
        {
            cout<<"\nenter element to be deleted: ";
            int ele;
            cin>>ele;
            printf("\n%d is deleted\n",obj.deleteKey(obj.fsearch(ele)));
            obj.printArray();
        }
        else if(option == 4)
            printf("\nheight of min heap is: %d",obj.height());

        else if(option==5)
            obj.printArray();

        else if(option == 6)
            system("cls");

        else if(option==0)
            break;

        else
            cout<<"\nenter again!!";
    }
    return 0;
}
