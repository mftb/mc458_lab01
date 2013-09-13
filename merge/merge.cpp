#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

#define MAX 1000

// mergesort main function
void mergesort(int*,int,int);

// mergesort merge auxiliary function
void merge(int*,int,int,int,int);


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
        // random data
        //for(i=0;i<MAX;i++)
            //v[i]=(rand() % 1000000) + 1;
        mergesort(v,0,n-1);

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


void mergesort(int * vector, int begin, int end){
    int medium, i;
    // base case, unitary vector
    if(begin == end)
        return;
    else
    {
        // calculates the medium of the vector in order to split it in 2
        medium = (end+begin)/2;
        // the first half of the vector goes into recursion
        mergesort(vector,begin,medium);
        // the second half of the vector goes into recursion
        mergesort(vector,medium+1,end);
        // back from recursion, merge both
        merge(vector,begin,medium,medium+1,end);
        return;
    }
}

void merge(int * vector, int begin1, int end1, int begin2, int end2){
    // aux vector
    int v[MAX];
    int i, j, k;
    k=begin1;
    i=begin1;
    j=begin2;
    // merges the 2 subvectors
    while(i<=end1 && j<=end2)
    {
        if(vector[i]>vector[j])
            v[k]=vector[j++];
        else
            v[k]=vector[i++];
        k++;
    }
    // checks if there is some subvector which wasn't fully put onto aux vector
    if(i>end1)
        for(;j<=end2;j++)
            v[k++]=vector[j];
    if(j>end2)
        for(;i<=end1;i++)
            v[k++]=vector[i];
    // copies aux vector onto original vector
    for(i=begin1;i<=end2;i++)
        vector[i]=v[i];
}
