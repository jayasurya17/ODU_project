#include<iostream>
using namespace std;
int matrix[10][10];
int max_m,max_n;
int sum;
//struct array holds information about all the pebbles
struct array{
    int value; //value of the pebble
    int i; //row of the pebble
    int j //col of the pebble
    int sum; //sum if the pebble is considered
}array[100],temp;


//The following function sorts the struct in descending order of pebble value using bubble sort
void sort_value(int x){
    int i,j;
    for(i=0;i<x;i++)
    for (j=0;j<x;j++){
        if (array[j+1].value > array[j].value){
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
    }
    return;
}

//The following function sorts the struct in descending order of sum value using bubble sort
void sort_sum(int x){
    int i,j;
    for(i=0;i<x;i++)
    for (j=0;j<x;j++){
        if (array[j+1].sum > array[j].sum){
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
    }
    return;
}

//The following function calculates and returns the cost of having the pebble at position (m,n) in its path. Flag is set to 1 only when path needs to be displayed
int calc_cost(int m,int n,int flag){
    int i,j;
    i=j=0;  //Initial position is (0,0)
    sum = 0; //Initital sum is 0

    do{
        if(flag == 1) //Flag is set to 1 only when path needs to be displayed
            cout<<"("<<i+1<<","<<j+1<<")->";
        sum += matrix[i][j]; //The cell value is added to the sum
        if((matrix[i+1][j] > matrix[i][j+1] && i!=m) || (j == n)) //Checks which of the cells(right or left) has higher value and moves to that cell.
            i++;
        else if((j!=n) || (i == m))
            j++;
    }while(i!=m || j!=n);
    i=m;j=n;
    do{
        if(flag == 1 && i<=m+1 && j<=n+1) //Flag is set to 1 only when path needs to be displayed
            if(i==m+1 && j==n+1)
                cout<<"("<<i+1<<","<<j+1<<")"<<endl;
            else
                cout<<"("<<i+1<<","<<j+1<<")->";
        sum += matrix[i][j]; //The cell value is added to the sum
        if(matrix[i+1][j] > matrix[i][j+1] && i!=max_m)//Checks which of the cells(right or left) has higher value and moves to that cell.
            i++;
        else if(j!=max_n)
            j++;
        else
            i++;
    }while(i!=max_m || j!=max_n);
    return sum;
}

int main()
{
    cout<<"Enter number of rows : ";
    cin>>max_m;
    cout<<"Enter number of columns : ";
    cin>>max_n;
    int i,j,k;
    k=0; //k is used to specify the struct array position
    cout<<"Enter values of pebbles \n";
    for(i=0;i<max_m;i++)
        for(j=0;j<max_n;j++){
            cin>>matrix[i][j]; //The pebble value is taken as input
            array[k].value = matrix[i][j]; //Pebble value is stored in the struct
            array[k].i=i; //The row position is stored in the struct
            array[k].j=j; //The col position is stored in the struct
            k++;
        }
    sort_value(max_m*max_n); //The struct is sorted based on the pebble values
    int max_count = max_m+max_n-1; //The max path length is calculated
    for(i=0;i<max_count;i++) //For the highest *max path length* pebble values path cost is calculated
        array[i].sum = calc_cost(array[i].i,array[i].j,0); //Flag is set to 0 since we need not display the path for all possible paths
    sort_sum(max_count); //Struct is sorted based on the sum values
    cout<<"Max sum of pebbles is : "<<array[0].sum<<endl; //The highest sum value is displayed
    cout<<"The path taken is";
    int max_sum = calc_cost(array[0].i,array[0].j,1); //Flag is set to 1 as we need to display the path taken
    return 0;
}
