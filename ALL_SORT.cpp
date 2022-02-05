#include<iostream>
using namespace std;
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

////////////////////////////////////////  BUBBBLE SORT /////////////////////////////////////////////////


// void bubblesort(int A[],int n)
// {
//  int i,j,flag=0;
 
//  for(i=0;i<n-1;i++)
//  {
//     flag=0;
//     for(j=0;j<n-i-1;j++){
//         if(A[j]>A[j+1])
//         {
//            swap(&A[j],&A[j+1]);
//             flag=1;}
//         }
//     if(flag==0)
//     break;
//  }
//}


////////////////////////////////////////  BINARY-INSERTION SORT /////////////////////////////////////////////////




// void BinaryInsertionSort (int a[], int n) 
// { 
//  int ins, i, j; 
//  for (i = 1; i < n; i++) { 
//  int x=a[i];
//  j=i-1;
//  int ins = BinarySearch (a, 0, i, a[i]); 
//  while(j>=ins){
//      a[j+1]=arr[j];
//      j--;
//      }
//      a[ins]=a[x];
//  }




// int BinarySearch (int a[], int low, int high, int key) 
// { 
//  int mid; 
//  if (low == high) 
//  return low; 
//  mid = low + ((high - low) / 2); 
//  if (key > a[mid]) 
//  return BinarySearch (a, mid + 1, high, key); 
//  else if (key < a[mid]) 
//  return BinarySearch (a, low, mid, key); 
//  return mid; 
// }



////////////////////////////////////////  INSERTION SORT /////////////////////////////////////////////////


//  void insertionsort(int arr[],int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         int x=arr[i];
//         int j=i-1;
//         while (j>-1&&arr[j]>x)
//         {
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=x;
//     }
    
// }



////////////////////////////////////////  SHELL SORT /////////////////////////////////////////////////



// void shellsort(int arr[],int count){
//    for (int gap = count/2; gap >= 1; gap/=2)
//    {
//        for (int i = gap; i < count; i++)
//        {
//            int j = i-gap;
//            int x= arr[i];
//            while(j>-1&&arr[j]>x){
//                arr[j+gap]=arr[j];
//                j=j-gap;
//            }
//            arr[j+gap]=x;
//        }
       
//    }}


////////////////////////////////////////  SELECTION SORT /////////////////////////////////////////////////



// void selectionsort(int arr[],int count){
//     int i,j,k;
//     for(int i=0;i<count-1;i++){
//         for(j=i,k=i;j<count;j++){
//             if(arr[j]<arr[k]){
//                 k=j;
//             }
//         }
//         swap(&arr[k],&arr[i]);
//     }
// }


////////////////////////////////////////  QUICK SORT /////////////////////////////////////////////////


// int partition(int A[],int l,int h){
//     int pivot = A[l];
//     int i= l,j=h;
//     do
//     {
//         do{i++;}while(A[i]<=pivot);
//         do{j--;}while(A[j]>pivot);
//         if(j>i){
//             swap(&A[i],&A[j]);
//         }
//     } while (j>i);
//     swap(&A[j],&A[l]);
//     return j;
// }
//  void quicksort(int A[],int l,int h){
//      if(l<h){
//          int bound = partition(A,l,h);
//          quicksort(A,l,bound);
//          quicksort(A,bound+1,h);
//      }
//  }


////////////////////////////////////////  COUNT SORT /////////////////////////////////////////////////


// int max(int arr[],int count){
//      int max=arr[0];
//     for (int i = 1; i < count; i++)
//     {
//         if(arr[i]>max){
//             max=arr[i];
//         }
//     }
//     return max;
// }

// void countsort(int arr[],int count){
//     int maxno = max(arr,count);
//     int *arr2=new int[maxno+1]{};
//     for(int i=0;i<count;i++){
//         ++arr2[arr[i]];
//     }
//     for(int i=1;i<=maxno;i++){
//         arr2[i]=arr2[i]+arr2[i-1];
//     }
//     int *output= new int[count]{};
//     for(int i=count;i>=0;i--){
//         output[arr2[arr[i]]-1]=arr[i];
//         --arr2[arr[i]];
//     }
//     for(int i=0;i<count;i++){
//         arr[i]=output[i];
//     }
// }


////////////////////////////////////////  RADIX SORT /////////////////////////////////////////////////


// void countsort(int arr[],int count,int div){
//     int maxno = max(arr,count);
//     int *arr2=new int[maxno+1]{};
//     for(int i=0;i<count;i++){
//         ++arr2[(arr[i]/div) % 10];
//     }
//     for(int i=1;i<=maxno;i++){
//         arr2[i]=arr2[i]+arr2[i-1];
//     }
//     int *output= new int[count]{};
//     for(int i=count;i>=0;i--){
//         output[arr2[(arr[i]/div)%10]-1]=arr[i];
//         --arr2[(arr[i]/div)%10];
//     }
//     for(int i=0;i<count;i++){
//         arr[i]=output[i];
//     }
// }

// void radixsort(int arr[],int count){
//     int maxno= max(arr,count);
//     for(int div=1;maxno/div>0;div*=10){
//         countsort(arr,count,div);
//     }
// }


////////////////////////////////////////  MERGE SORT /////////////////////////////////////////////////
// void merge(int arr[],int l,int h,int mid){
//     int i=l,j=mid+1,k=l;
//     int temp[100];
//     while(i<=mid&&j<=h){
//         if(arr[i]<arr[j]){
//             temp[k]=arr[i];
//             k++;i++;        
//         }
//         else{
//             temp[k]=arr[j];
//             k++;j++;
//         }
//     }
//     for(;i<=mid;i++){
//         temp[k]=arr[i];
//         k++; 
//     }
//      for(;j<=h;j++){
//         temp[k]=arr[j];
//         k++; 
//     }
//     for(int i=l;i<=h;i++)
//     arr[i]=temp[i];
// }

// void mergesort(int arr[],int l,int h){
//     if(l<h){
//         int mid = (l+h)/2;
//         mergesort(arr,l,mid);
//         mergesort(arr,mid+1,h);
//         merge(arr,l,h,mid);
//     }
// }



int main(){
int A[]={11,13,7,12,16,9,24,5,10,3},n=10;
 //bubblesort(A,n);
 //insertionsort(A,n);
 //shellsort(A,n);
 //selectionsort(A,n);
 //quicksort(A,0,n);
 //countsort(A,n);
 //radixsort(A,n);
 //mergesort(A,0,n-1);
 for (int i = 0; i < 10; i++)
 {
     cout<<A[i]<<" ";
 }
 
}