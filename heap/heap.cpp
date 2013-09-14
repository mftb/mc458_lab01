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
    std::clock_t start;
    double duration;
    /* Your algorithm here */
    int v[MAX]; 
    //int original[MAX];
    int i,j,k,n;
    // reading data from stdin
    
    scanf("%d, ", &n);
    for(i=0;i<n-1;i++)
        scanf("%d, ", &v[i]);
    scanf("%d;", &v[i]);
    
    //for(i=0;i<n;i++)
        //original[i]=v[i];
    //srand(time(NULL));
    j=0;
    start = std::clock();
    for(k=0;k<1000;k++)
    {
        //for(i=0;i<MAX;i++)
            //v[i]=(rand() % 1000000) + 1;
        heapsort(v,n);

        // correctness tester, doesn't work for some reason...
        for(i=n-1;i>0;i--)
            if(v[i]<v[i-1]) j=1;
    }    
    if(j) std::cout<<"TEST FAILED\n";
    else std::cout<<"TEST PASSED\n";
    // CSV correctness test generator
    /*
    std::cout<<"Original,Sorted\n";
    for(i=0;i<n;i++)
        std::cout<< original[i] << ',' << v[i] << '\n';
    */
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"duration "<< duration <<'\n';
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


void heapify(int* vector,int count){
    int start;
    start=(count-2)/2;
    while(start>=0)
        sift_down(vector,start--,count-1);
}


void sift_down(int* vector, int start, int end){
    int root,child,aux,swap;
    root=start;
    while((root*2+1)<=end)
    {
        child=root*2+1;
        swap=root;
        if(vector[swap]<vector[child])
            swap=child;
        if(((child+1)<=end)&&(vector[swap]<vector[child+1]))
            swap=child+1;
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


