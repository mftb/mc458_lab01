#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

#define MAX 1000

// heapsort main function
void heapsort(int*,int);

// heapsort heapify auxiliary function
void heapify(int*,int);

// heapsort sift down auxiliary function
void sift_down(int*,int,int);

int main(){
    //std::clock_t start;
    //double duration;
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

        heapsort(v,n);
        
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

void heapsort(int* vector,int count){
    int end,aux;
    // puts the vector in a max-heap order
    heapify(vector,count);
    end=count-1;
    // begins the sorting of the vector by pushing values down the heap
    while(end>0)
    {
        aux=vector[end];
        vector[end--]=vector[0];
        vector[0]=aux;
        sift_down(vector,0,end);
    }
}


// builds the heap bottom-up using sift_down
void heapify(int* vector,int count){
    int start;
    // start is the index of the last parent node
    start=(count-2)/2;
    // creates the heap
    while(start>=0)
        sift_down(vector,start--,count-1);
}

// this function puts values in the heap from bottom-up
void sift_down(int* vector, int start, int end){
    int root,child,aux,swap;
    root=start;
    // do while the root has at least one child
    while((root*2+1)<=end)
    {
        // left child
        child=root*2+1;
        swap=root;
        // checks whether the root is smaller than the child
        if(vector[swap]<vector[child])
            swap=child;
        // checks whether the child to the right exists and if it is bigger than
        // the value we are willing to swap
        if(((child+1)<=end)&&(vector[swap]<vector[child+1]))
            swap=child+1;
        // checks if it is in need to swap
        if(swap!=root)
        {
            aux=vector[root];
            vector[root]=vector[swap];
            vector[swap]=aux;
            root=swap;
        }
        else
            return;
    }
}
