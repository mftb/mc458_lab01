#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

#define MAX 1000

// insertionsort main function
void insertion(int*,int,int);

int main(){
    std::clock_t start;
    double duration;
    /* Your algorithm here */
    int v[MAX]; 
    int original[MAX];
    int i,j,k,n,count;
    count=0;
    while(scanf("%d, ", &n)!=EOF){
    // reading data from stdin
    //scanf("%d, ", &n);
    for(i=0;i<n-1;i++)
        scanf("%d, ", &v[i]);
    scanf("%d;\n", &v[i]);
    for(i=0;i<n;i++)
        original[i]=v[i];
    //srand(time(NULL));
    j=0;
    start = std::clock();
    for(k=0;k<1000;k++)
    {
        for(i=0;i<n;i++)
            v[i]=original[i];
        // random data generator
        //for(i=0;i<MAX;i++)
            //v[i]=(rand() % 1000000) + 1;
        insertion(v,0,n-1);

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
    duration = ((std::clock()-start)/(double)CLOCKS_PER_SEC);
    std::cout<< duration <<'\n';
    std::cout<<n<<", ";
    for(i=0;i<n-1;i++)
        std::cout<<v[i]<<", ";
    std::cout<<v[n-1]<<";\n";
    }
    return 0;
}

void insertion(int* vector,int begin,int end){
	int i,j,key;
	/* base case, unitary vector */
	if ( begin == end)
		return;
	else{	
		/*walks on the vector, starting on the second element vector[1], ordering the list*/
		for(j=1;j<end+1;j++){
			/*selects key element*/
			key = vector[j];
			i = j - 1;
			/*compares if the previous elements are bigger than the key, 
			walking backwords until reach the beggining of the vector 
			or finding a bigger element, if so, the key goes immediately 
			before the bigger element*/ 
			while(vector[i]>key && i>=0){
				vector[i+1] = vector[i];
				i--;
			}
			vector[i+1] = key;
	   }
	}
}

