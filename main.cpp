#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;


class heapSort
{
private:
    int *harr;
    int index;

    int leftChild(int n){
        return (2*n)+1;
    }
    int rightChild(int n){
        return (2*n)+2;
    }

public:
    int capacity;
    heapSort()
    {
        capacity = 7;
        harr = new int[capacity];
        for(int i=0; i<capacity; i++)
            harr[i] = rand()%10 +1;
    }

    void sorting()
    {
        int cap = capacity;
        int sortedArray[capacity];
        cout<<"\nfinal sorted array\n";
        for(int i=0; i<cap; i++)
        {
            sortedArray[i] = extractMin();
            cout<<sortedArray[i]<<" ";
            //print();
        }
    }

    void heapify(int index)
    {
        int l,r;
        while(2>1)
        {
        l = leftChild(index);
        r = rightChild(index);

        if(r<capacity && harr[r]<harr[index]&& harr[r]<harr[l])
        {
            swap(harr[r],harr[index]);
            index = r;
        }
        else if(l<capacity && harr[l]<harr[index])
        {
            swap(harr[l],harr[index]);
            index = l;
        }
        else
            return;
        }
    }
    void print()
    {
        for(int i=0; i<capacity; i++)
        {
            printf("%d ",harr[i]);
        }
    }
    int extractMin()
        {
            if(capacity <= 0)
                return INT_MAX;

            else if(capacity==1)
            {
                capacity--;
                return harr[0];
            }
            int result = harr[0];
            capacity--;
            harr[0] = harr[capacity];

            heapify(0);
            return result;
        }
};
int main()
{
    heapSort obj;
    printf("~CURRENT ARRAY~\n");
    obj.print();
    for(int i=obj.capacity/2-1; i>=0; i--)
    {
        obj.heapify(i);
        printf("\n(%d) ",i);
        obj.print();
    }
    obj.sorting();

    return 0;
}

