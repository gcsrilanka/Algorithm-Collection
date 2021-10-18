#include <vector>
#include <iostream>
using namespace std;
//Quick sort
int partition(vector<int> &prices,vector<int> &amount, int left, int right)
{
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = prices[pivotIndex];
    int i = left, j = right;
    int temp;
    while(i <= j)
	{
        while(prices[i] < pivotValue)
		{
            i++;
        }
        while(prices[j] > pivotValue)
		{
            j--;
        }
        if(i <= j)
		{
            temp = prices[i];
            prices[i] = prices[j];
            prices[j] = temp;
            
            temp = amount[i];
            amount[i] = amount[j];
            amount[j] = temp;
            
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(vector<int> &prices,vector<int> &amount, int left, int right)
{
    if(left < right)
	{
        int pivotIndex = partition(prices,amount, left, right);
        quicksort(prices,amount ,left, pivotIndex - 1);
        quicksort(prices,amount, pivotIndex, right);
    }
}
//finding the maximum profit
int findprof(vector<int> weight,vector<int>price,int n)
{
	int sum=0;
	quicksort(price,weight, 0, price.size() - 1);
	
	for(int i=0;i<weight.size();i++)
	{
		if(n==0)
		{
			return sum;
		}
		else if(n>weight[i])
		{
			n=n-weight[i];
			sum=sum+ price[i]*weight[i];
		}
		else
		{
			sum=sum+n*price[i];
			n=0;
		}
	}
	return sum;
}

int main()
{
	int n,m;
	cout<<"Maximum weight of sack:";
	cin>>n;
	cout<<"Number of weights:";
	cin>>m;
	vector <int> weight;
	vector <int> price;
	
	cout<<"Enter the weights:";
	for(int i=0;i<m;i++)
	{
		int c;
		cin>>c;
		weight.push_back(c);
	}
	cout<<"Enter the prices:";
	for(int i=0;i<m;i++)
	{
		int c;
		cin>>c;
		price.push_back(c);
	}
	
	
    
	//getting the unit price
	for(int i=0;i<m;i++)
	{
		price[i]=price[i]/weight[i];
	}    
 	cout<<"\n";
	
	
	cout<<"Total profit :"<<findprof(weight,price,n)<<"\n";		   
	
	return 0;
}
