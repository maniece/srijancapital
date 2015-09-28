#include<stdio.h>
#include<conio.h>
int arr[10],cnt[10],n;
int decimalposition(int);
int arrangearray();
int sort(int);
int main()
{
    int i,l;
   double number=0,m;
    
    printf("Enter the number of inputs going to be given\n");  //Getting the number of inputs going to be given
    scanf("%d",&n);
    
    if((n<=0) || (n>5)){  //check whether the n exceeds the limit
      while((n<=0) || (n>5)){printf("Please give the input value from 1 to 5:"); scanf("%d",&n);}
      printf("\n\n");
    }
    printf("\nEnter the array values\n");
    for(i=0;i<n;i++){
    printf("\nArray[%d]=",i);
    scanf("%d",&arr[i]);
    
    if(arr[i]<0 || arr[i]>=100)  //Check whether given number is Positive or Negative
      {
           while((arr[i]<0)||(arr[i]>=100))
           {
               printf("\nEnter the positive value and range between  1 to 100:");
               scanf("%d",&arr[i]);
           }
         printf("\nArray[%d]=%d",i,arr[i]);
      }
    }
   
    for(i=0;i<n;i++){cnt[i]=decimalposition(arr[i]);} //Getting the highest placevalue of a number
    

    arrangearray(); //Sorting the array

     printf("\n\n**********THIS IS THE OUTPUT FROM THE SORTED ARRAY**************\n");
    printf("\n\nThe smallest number we will get from the combination array list is\n");
    for(i=0;i<n;i++)
    {
         printf("%d",arr[i]); //Directly displaying the array elements
    }
    printf("\n\n**********THIS IS THE OUTPUT AS NUMBER**************\n");
    number=arr[n-1];
    for(l=n-2;l>=0;l--)
    {
        m=decimalposition(number)*10;
        number=number+(arr[l]*m);
    }
    printf("\nThe smallest number we will get from the inputs is\n%.0f",number);
  
 
    getch();
    return 0;
}


//Functions
//1. Function to find the highest placevalue of a number
int decimalposition(int a)
{
    int dummy=0; double mod=1;
     while((a/10)!=0)
    {
        a/=10;
        mod=mod*10;           
    }
    return mod;
}

//2. Function for sorting the array
int arrangearray()
{
     int temp1,temp2,i,k,tempvalue;
 for(i=0;i<n;i++)
 {
	for(k=0;k<n-1;k++) //Here there some condition to perfect sorting to be occur
	{
   	if(((arr[k]/cnt[k])==(arr[k+1]/cnt[k+1])) && (arr[k]<arr[k+1])){sort(k);  }
		if((arr[k]/cnt[k])>(arr[k+1]/cnt[k+1]) || ((cnt[k]==cnt[k+1]) && (arr[k]>arr[k+1]))){	sort(k); }
	
	 
	 			tempvalue=(arr[k]*cnt[k+1]*10)/cnt[k];
		if((tempvalue==(arr[k+1]*10)) &&(arr[k]>arr[k+1]) &&(arr[k]!=(arr[k+1]*cnt[k])/cnt[k+1]) ) {sort(k);}
		if((arr[k]==(arr[k+1]*cnt[k])/cnt[k+1]) && ((arr[k]<arr[k+1]))) {sort(k);}
 	if((tempvalue>(arr[k+1]*10))&&((tempvalue%10)>(arr[k+1]))) {sort(k);}
 	

  	
		}
 }
    return 0;
}

	int sort(int k)  //This function dones the sorting
	{
			int temp1,temp2;
			temp1=arr[k];
			arr[k]=arr[k+1];
			arr[k+1]=temp1;
			
			temp2=cnt[k];
			cnt[k]=cnt[k+1];
			cnt[k+1]=temp2;
	}
