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

        insertion(v,0,n-1);

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

