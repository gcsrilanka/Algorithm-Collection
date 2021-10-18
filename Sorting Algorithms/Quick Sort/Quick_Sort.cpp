#include <vector>
#include <iostream>
using namespace std;

int partition(vector<int> &nums, int left, int right)
{
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = nums[pivotIndex];
    int i = left, j = right;
    int temp;
    while(i <= j)
	{
        while(nums[i] < pivotValue)
		{
            i++;
        }
        while(nums[j] > pivotValue)
		{
            j--;
        }
        if(i <= j)
		{
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            
            
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(vector<int> &nums, int left, int right)
{
    if(left < right)
	{
        int pivotIndex = partition(nums, left, right);
        quicksort(nums,left, pivotIndex - 1);
        quicksort(nums,pivotIndex, right);
    }
}


int main(){
	vector<int> nums;
	
	nums.push_back(10);
	nums.push_back(30);
	nums.push_back(50);
	nums.push_back(60);
	nums.push_back(5);
	
	quicksort(nums,0, nums.size() - 1);
	
	for(int i=0; i < nums.size(); i++){
		cout << nums.at(i) << ' ';
	}
   
	return 0;
}
