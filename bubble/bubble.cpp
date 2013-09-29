#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

#define MAX 1000

// bubblesort main function
void bubble(int*,int,int);

int main(){
    std::clock_t start;
    double duration;
    /* Your algorithm here */
    int v[MAX]; 
    int original[MAX];
    int i,j,k,n,count;
    // reading data from stdin
    count=0;
    while(scanf("%d, ", &n)!=EOF){
    for(i=0;i<n-1;i++)
        scanf("%d, ", &v[i]);
    scanf("%d;\n", &v[i]);
    for(i=0;i<n;i++)
        original[i]=v[i];
    //srand(time(NULL));
    j=0;
    start = std::clock();
    for(k=0;k<1000000;k++)
    {
        for(i=0;i<n;i++)
            v[i]=original[i];
        // random data generator
        //for(i=0;i<MAX;i++)
            //v[i]=(rand() % 1000000) + 1;
        bubble(v,0,n-1);

        // correctness tester
        for(i=n-1;i>0;i--)
            if(v[i]<v[i-1]) j=1;
    }    
    if(j) std::cout<<"TEST "<<count++<<" FAILED\n";
    else std::cout<<"TEST "<<count++<<" PASSED\n";
    // CSV correctness test generator
    /*
    std::cout<<"Original,Sorted\n";
    for(i=0;i<n;i++)
        std::cout<< original[i] << ',' << v[i] << '\n';
    */
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<< duration <<'\n';
    std::cout<<n<<", ";
    for(i=0;i<n-1;i++)
        std::cout<<v[i]<<", ";
    std::cout<<v[n-1]<<";\n";
    }
    return 0;
}

void bubble(int* vector,int begin,int end){
	int swapped = 1;
	int i,aux;
	/* base case, unitary vector */
	if ( begin == end)
		return;
	
	else {
		/*stays here until no more swappes are made, which means the vector is in the corret order*/	
    	while (swapped){
    		swapped = 0;
    		/*walks trought the vector*/
    		for (i=1;i<end+1;i++){
    			/*compares two elements, if the first is bigger than the second, 
				swaps them and remember something has changed*/
    			if (vector[i-1]>vector[i]){
    				aux = vector[i-1];
    				vector[i-1]=vector[i];
    				vector[i]=aux;
    				swapped = 1;
    			}
    		}
    	}     
	}
}
