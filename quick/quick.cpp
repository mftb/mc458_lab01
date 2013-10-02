#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

#define MAX 1000

// quicksort main function
void quicksort(int*,int,int);

// quicksort partition auxiliary function
int partition(int*,int,int,int);

int main(){
    std::clock_t start;
    double duration;
    /* Your algorithm here */
    int v[MAX]; 
    //int original[MAX];
    int i,n;
    //int j,k,count;
    
    //count=0;
    // reading data from stdin
    // scans the whole file until EOF
    while(scanf("%d, ", &n)!=EOF){    
    for(i=0;i<n-1;i++)
        scanf("%d, ", &v[i]);
    scanf("%d;\n", &v[i]);
    // saves the original vector
    //for(i=0;i<n;i++)
        //original[i]=v[i];
        
    // correctness tester flag
    //j=0;
    
    // timing device
    //start = std::clock();
    // this is done in order to get precision timing with std::clock()
    //for(k=0;k<1000;k++)
    {
        // this is done in order to restore the original vector to be sorted
        //for(i=0;i<n;i++)
            //v[i]=original[i];

        quicksort(v,0,n-1);

        // correctness tester
        //for(i=n-1;i>0;i--)
            //if(v[i]<v[i-1]) j=1;
    }    
    // correctness tester output    
    //if(j) std::cout<<"TEST "<<count++<<" FAILED\n";
    //else std::cout<<"TEST "<<count++<<" PASSED\n";

    // timing device
    //duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    //std::cout<<duration <<'\n';
    
    // prints the sorted vector
    std::cout<<n<<", ";
    for(i=0;i<n-1;i++)
        std::cout<<v[i]<<", ";
    std::cout<<v[n-1]<<";\n";
    }
    return 0;
}

void quicksort(int* vector,int l,int r){
    int pivot,new_pivot;
    // base case
    if(l>=r)
        return;
    else
    {
        // sets the pivot as the element in the middle of the vector
        // according to http://en.wikipedia.org/wiki/Quicksort#Choice_of_pivot
        // this is a better choice of pivot than simply selection the first
        // element of the array
        // maybe should be better use pivot=l in order to make optimizations
        // appear more
        pivot=l;
        // partition of the vector
        new_pivot=partition(vector,l,r,pivot);
        // recursive call to the left subvector
        quicksort(vector,l,new_pivot-1);
        // recursive call to the right subvector
        quicksort(vector,new_pivot+1,r);
    }
}

int partition(int* vector,int l,int r,int pivot_index){
    int pivot,store_index,aux,i;
    // finds out the value of the pivot
    pivot=vector[pivot_index];
    // sends the pivot to the end of the subvector
    aux=vector[r];
    vector[r]=vector[pivot_index];
    vector[pivot_index]=aux;
    store_index = l;
    // partitions the subvector according to the pivot
    for(i=l;i<r;i++)
    {
        if(vector[i]<pivot)
        {
            aux=vector[i];
            vector[i]=vector[store_index];
            vector[store_index++]=aux;
        }
    }
    // sends the pivot back to its proper location
    aux=vector[store_index];
    vector[store_index]=vector[r];
    vector[r]=aux;
    // returns where the pivot is now
    return store_index;
}



