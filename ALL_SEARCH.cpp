#include<iostream>
#include<math.h>
using namespace std;


////////////////////////////////////////  LINEAR SEARCH /////////////////////////////////////////////////


// int linearsearch(int arr[],int count,int data){
//     for (size_t i = 0; i < count; i++)
//     {
//         if(arr[i]==data){
//             return i;
//         }
//     }
//     return -1;
// }

////////////////////////////////////////  BINARY SEARCH /////////////////////////////////////////////////


// int binarysearch(int arr[],int l,int h,int data){
//     if(l<=h){
//         int mid=(l+h)/2;
//         if(arr[mid]==data){
//             return mid;
//         }
//         else{
            
//             if(arr[mid]>data){
//                 return binarysearch(arr,l,mid-1,9);
//             }
//             else{
//                 return binarysearch(arr,mid+1,h,9);
//             }
//         }
//     }
//     return -1;
// }


////////////////////////////////////////  INETRPOLATION SEARCH /////////////////////////////////////////////////



// int interpolationsearch(int arr[],int l,int h,int data){
//     if(l<=h){
//         int mid=l+(((l-h)/(arr[l]-arr[h]))*(data-arr[l]));
//         if(arr[mid]==data){
//             return mid;
//         }
//         else{
            
//             if(arr[mid]>data){
//                 return interpolationsearch(arr,l,mid-1,9);
//             }
//             else{
//                 return interpolationsearch(arr,mid+1,h,9);
//             }
//         }
//     }
//     return -1;
// }

////////////////////////////////////////  JUMP SEARCH /////////////////////////////////////////////////

// int jumpsearch(int arr[],int count,int data){
//     int jump= sqrt(count);
//     int prev=0;
//     while(arr[min(jump,count)]<data&&jump<=count){
//         prev=jump;
//         jump = jump +sqrt(count);
//         if(prev>=count){
//             return -1;
//         }
//     }
//     for(int i=prev;i<jump;i++){
//         if(arr[i]==data){
//             return i;
//         }
//     }
//     return -1;
// }


////////////////////////////////////////  EXPONENTIAL SEARCH /////////////////////////////////////////////////


// int binarysearch(int arr[],int l,int h,int data){
//     if(l<=h){
//         int mid=(l+h)/2;
//         if(arr[mid]==data){
//             return mid;
//         }
//         else{
            
//             if(arr[mid]>data){
//                 return binarysearch(arr,l,mid-1,9);
//             }
//             else{
//                 return binarysearch(arr,mid+1,h,9);
//             }
//         }
//     }
//     return -1;
// }

// int exponentialsearch(int array[], int start, int end, int key){
//       int i = 1; // as 2^0 = 1
//       while(array[i] < key)
//             i *= 2;
//    return binarysearch(array, i/2, i, key); //search item in the smaller range
// }

int main(){
int A[]={2,3,4,5,6,7,8,9,10,11};
int n=10;
//cout<<"Found at index : "<<linearsearch(A,n,9);
//cout<<"Found at index : "<<binarysearch(A,0,n-1,9);
//cout<<"Found at index : "<<interpolationsearch(A,0,n-1,9);
//cout<<"Found at index : "<<jumpsearch(A,n,9);
//cout<<"Found at index : "<<exponentialsearch(A,0,n-1,9);
 return 0;
 }