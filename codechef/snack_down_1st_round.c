#include <stdio.h>
#include <stdint.h>

//merges sorted arrays [start, ... , mid] and [mid + 1, ... ,end]
void merge(uint32_t* arr, uint32_t start, uint32_t mid, uint32_t end)
{
    uint32_t size1 = mid - start + 1;
    uint32_t size2 = end - mid;
    uint32_t arr1[size1 + 1], arr2[size2 + 1];
    arr1[size1] = arr2[size2] = 0; 
    uint32_t i,j,k;
    //printf("start:%d mid:%d end:%d\n", arr[start], arr[mid], arr[end]);
    
    for(i = 0; i < size1; i++) {
        arr1[i] = arr[start + i];
      //  printf("%d", arr1[i]);   
    }
    
    for(i = 0; i < size2; i++) {
        arr2[i] = arr[mid + 1 + i];
        //printf("%d", arr2[i]);    
    }
    
    i = j = 0;
    for(k = start; k <= end; k++) {
        if(arr2[j] >= arr1[i]) {
            arr[k] = arr2[j++];
        } else {
            arr[k] = arr1[i++];
        }
        //printf("%d %d %d\n",arr[k],arr1[i], arr2[j]);
    }
}

void merge_sort(uint32_t* arr, uint32_t start, uint32_t end)
{
    uint32_t mid;
    if(start < end) {
        mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }    
}

int main(void) 
{
    uint32_t total_test_cases, no_of_teams, qualifying_rank, qualified_team_count;
    uint32_t i, j, k;
    uint32_t curr;
    scanf("%d", &total_test_cases);
    for(i=0; i < total_test_cases; i ++) {
        scanf("%d %d", &no_of_teams, &qualifying_rank);
        uint32_t arr[no_of_teams+1];
        arr[no_of_teams] = -1;
        for(j=0; j < no_of_teams; j ++) {
            scanf("%d", &arr[j]);
        }
        merge_sort(arr, 0, no_of_teams - 1);
        
  //  for(j = 0; j < no_of_teams; j++) {
 //            printf("%d\t", arr[j]);
  //  }

        qualified_team_count = -1;
        k = 0;
        curr = arr[0];
        for(j= 0; (j < qualifying_rank) && (k <= no_of_teams); k++ ){
            if(curr != arr[k]) {
                curr = arr[k];
                j++;
            } 
            if(arr[k] != -1)
                qualified_team_count ++;
        }
        printf("%d\n", qualified_team_count);
    }
    
    // your code goes here
    return 0;
}


