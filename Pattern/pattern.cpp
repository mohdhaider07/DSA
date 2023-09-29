// boiler plate for c++
#include <iostream>

using namespace std;

    /*
    *****
    ****
    ***
    **
    *
    */

 void pattern3(int n=5){
   
    for(int i=1;i<=n;i++){
        for(int j=n-i;j>=0;j--){
            cout<<"* ";
        }
        cout<<endl;
    }
 }

/*
4.  1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
*/
void pattern4(int n=5){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<' ';
        }
        cout<<endl;
    }
}

/*
5.
    *
    **
    ***
    ****
    *****
    ****
    ***
    **
    *

*/

void pattern5(int n=4){
    for (int i = 1; i <= 2*n+1; i++)
    {   
       if(i<=n+1){
            for(int j=1;j<=i;j++){
            cout<<"* ";
        }
       }else{
        for(int j=(2*n+1)-i;j>=0;j--){
            cout<<"* ";
        }
       }
        cout<<endl;
    }

}

/*

6.       *
        **
       ***
      ****
     *****

*/

void pattern6(int n=5){
    for(int i=1;i<=n;i++){
        for(int k=n-i;k>=1;k--){
            cout<<" ";
        }
        for(int j=i;j>=1;j--){
            cout<<"*";
        }
        cout<<endl;
    }
}


/*

7.   *****
      ****
       ***
        **
         *

*/

void pattern7(int n=5){
    for(int i=1;i<=n;i++){
        for(int k=1;k<i;k++){
            cout<<" ";
        }
        for(int j=n-i;j>=0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
}

/*

8.      *
       ***
      *****
     *******
    *********

*/
void pattern8(int n=5){
    //start qual to row-1
    for(int i=1;i<=n;i++){
       for(int j=n-i;j>=0;j--){
            cout<<" ";
       }
       for(int k=1;k<=2*(i-1);k++){
       cout<<"*";        
       }
       cout<<"*";
        cout<<endl;
    }
}

/*

9.  *********
     *******
      *****
       ***
        *

*/

void pattern9(int n=5){
    //spacing row-1

    for(int row=1;row<=n;row++){
       for(int j=1;j<=row-1;j++){
            cout<<" ";
       }
       for(int k=2*(n-row);k>=1;k--){
       cout<<"*";        
       }
       cout<<"*";
        cout<<endl;
    }
}


/*

10.      *
        * *
       * * *
      * * * *
     * * * * *

*/

void pattern10(int n=5){
    //spacing=n-row
    //starts=row
    for(int row=1;row<=n;row++){
       for(int j=1;j<=n-row;j++){
            cout<<" ";
       }
       for(int k=1;k<=row;k++){
       cout<<" *";        
       }
        cout<<endl;
    }
}

/*

11.  * * * * *
      * * * *
       * * *
        * *
         *
*/

void pattern11(int n=5){
    //spacing=row-1;
    //starts=n-row+1
    for(int row=1;row<=n;row++){
       for(int j=1;j<=row-1;j++){
            cout<<" ";
       }
       for(int k=1;k<=(n-row+1);k++){
       cout<<" *";        
       }
        cout<<endl;
    }
}


/*
12.  * * * * *
      * * * *
       * * *
        * *
         *
         *
        * *
       * * *
      * * * *
     * * * * *
*/

void pattern12(int n=5){

    for(int row=1;row<=2*n;row++){
       if(row<=n){
            for(int j=1;j<=row-1;j++){
                cout<<" ";
            }
            for(int k=1;k<=(n-row+1);k++){
                cout<<" *";        
            }
        
       }else{
             for(int j=1;j<=2*n-row;j++){
                cout<<" ";
            }
            for(int k=1;k<=(row-n);k++){
                cout<<" *";        
            }

       }
            cout<<endl;
    }
}

/*
13.      *
        * *
       *   *
      *     *
     *********
*/

void pattern13(int n=5){
    //spacing=n-row
    //starts=1 at row 1
    // starts 2 at all roe except for row==n;
    // startes 2*n-1 if n==row
    //middle spacing spacing = 2*(row-2)+1
    for(int row=1;row<=n;row++){
        // left spacing
       for(int j=1;j<=n-row;j++){
            cout<<" ";
       }
       if(row==1){
        cout<<"*";
       }else if(n==row){
        //last stars 2*n-1 rimes
       
        for(int p=1;p<=2*n-1;p++){
            cout<<"*";
        }
       }else{
            cout<<"*";   
            // middle spacing
            for(int k=1;k<=2*(row-2);k++){
                cout<<" ";
            }   
            
            cout<<" *";  
       }
       
        cout<<endl;
    }
}

/*

14.  *********
      *     *
       *   *
        * *
         *

*/


void pattern14(int n=5){
    //left spacing=row-1
    //starts=1 2*n-1
    // starts 2 at all row except for row==n;
    // startes 1 if n==row
    //middle spacing spacing = 2*(n-row-1)
    for(int row=1;row<=n;row++){
        // left spacing
       for(int j=1;j<=row-1;j++){
            cout<<" ";
       }
       if(row==1){
        // first row starts 2*n-1
        for(int i=0;i<2*n-1;i++){
            cout<<"*";
        }
       }else if(n==row){
        //last stars 1 times
            cout<<"*";
        
       }else{
            cout<<"*";   
            // middle spacing
            for(int k=1;k<=2*(n-row-1)+1;k++){
                cout<<" ";
            }   
            
            cout<<"*";  
       }
       
        cout<<endl;
    }
}

/*

15.      *
        * *
       *   *
      *     *
     *       *
      *     *
       *   *
        * *
         *

*/

void pattern15(int n=5){
for(int row=1;row<=2*n-1;row++){
    if(row<=n){
        for(int j=1;j<=n-row;j++){
            cout<<" ";
       }
       if(row==1){
        cout<<"*";        
          }else{
        cout<<'*';
            for(int i=1;i<=2*(row-2)+1;i++){
                cout<<' ';
            }
            cout<<'*';
       }

    }else{
        //left spacing
        for(int i=1;i<=row-n;i++){
            cout<<" ";
        }
        if(row==2*n-1){
            cout<<"*";
        }else{
            cout<<"*";
            //middle spacng
            for(int i=0;i<=2*(2*n-row-2);i++){
                cout<<" ";
            }
            cout<<"*";
        }
    }

    cout<<endl;
}
}


/*

16.           1
            1   1
          1   2   1
        1   3   3   1
      1   4   6   4   1

*/

void pattern16(int n=5){
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 1; j <= n - i ; j++) {
            std::cout << "  ";
        }
        
        // Calculate and print values
        int num = 1;
        for (int j = 1; j <= i; j++) {
            std::cout << num << "   ";
            num = num * (i - j) / (j);
        }
        
        std::cout << std::endl;
    }

}



/*

17.      1
        212
       32123
      4321234
       32123
        212
         1

*/

void pattern17(int n=4){
    for (int i = 1; i <= 2*n-1; i++) {
        // Print spaces
     if(i<=n){
           for (int j = 1; j <= n - i ; j++) {
            cout << " ";
        }

        for(int j=i;j>=1;j--){
            cout<<j;
        }
        for(int j=2;j<=i;j++){
            cout<<j;
        }
     }else{
          for (int j=i-n;j>=1;j--) {
            cout << " ";
        }

        for(int j=2*n-i;j>=1;j--){
            cout<<j;
        }
        for(int j=2;j<=2*n-i;j++){
            cout<<j;
        }
     }
        cout<<endl;
        
     
    }

}


/*


18.   **********
      ****  ****
      ***    ***
      **      **
      *        *
      *        *
      **      **
      ***    ***
      ****  ****
      **********

*/

void pattern18(int n=5){
    for (int row = 1; row <= 2*n; row++)
    {   
        
        if(row<=n){
        // print start
        for (int i = 1; i <=n-row+1; i++)
        {
           
            cout<<"*";
        }
        //middle space
        for (int i = 1; i <=2*(row-1); i++)
        {
            cout<<" ";
        }
        //right stars 
        for (int i = 1; i <=n-row+1; i++)
        {
            cout<<"*";
        }
         }else{

             // print start
        for (int i = 1; i <=row-n; i++)
        {
           
            cout<<"*";
        }
        //middle space
        for (int i = 1; i <=2*(2*n-row); i++)
        {
            cout<<" ";
        }
        //right stars 
        for (int i = 1; i <=row-n; i++)
        {
            cout<<"*";
        }

         }
         cout<<endl;
        
    }
    
}


/*

19.    *        *
       **      **
       ***    ***
       ****  ****
       **********
       ****  ****
       ***    ***
       **      **
       *        *


*/

void pattern19(int n=5){
    for (int row = 1; row <=2*n-1; row++)
    {
        if(row<=n){
                //left start
                for(int i=1;i<=row;i++){
                    cout<<"*";
                }
                //space
                for (int i = 1; i <= 2*(n-row); i++)
                {
                    cout<<" ";
                }
                //right start
                for(int i=1;i<=row;i++){
                    cout<<"*";
                }
        }else{

                 //left start
                for(int i=1;i<=2*n-row;i++){
                    cout<<"*";
                }
                //space
                for (int i = 1; i <= 2*(row-n); i++)
                {
                    cout<<" ";
                }
                //right start
                for(int i=1;i<=2*n-row;i++){
                    cout<<"*";
                }

        }
        cout<<endl;
    }
    
}



/*


20.    ****
       *  *
       *  *
       *  *
       ****


*/

void pattern20(int n=5){
    for (int  row = 1; row <= n; row++)
    {
       if(row==1||row==5){
        for (int i = 0; i < 4; i++)
        {
            cout<<"*";
        }
        
       }else{
        cout<<"*  *";
       }
       cout<<endl;
    }
    
}


/*


21.    1
       2  3
       4  5  6
       7  8  9  10
       11 12 13 14 15


*/

void pattern21(int n=5){
    int num=1;
    for (int row = 1; row <= n; row++)
    {
        for (int  j = 1; j <=row; j++)
        {   cout<<num<<" ";
            num++;
            /* code */
        }
        cout<<endl;
        
        /* code */
    }
    
}


/*


22.    1
       0 1
       1 0 1
       0 1 0 1
       1 0 1 0 1

*/

void pattern22(int n=48){
    bool x=1;
     for (int row = 1; row <= n; row++)
    {   
         if(row%2!=0){
                x=1;
            }else{
                x=0;
            }
        
        for (int  j = 1; j <=row; j++){
           cout<<x<<" ";
           x=!x;
        }
        cout<<endl;
    }
}


/*

23.        *      *
         *   *  *   *
       *      *      *

*/

void pattern23(int n=5){

}


/*

       *        *
       **      **
       * *    * *
       *  *  *  *
       *   **   *
       *   **   *
       *  *  *  *
       * *    * *
       **      **
       *        *

*/

void  pattern24(int n=5){
    for (int row = 1; row <= 2*n; row++)
    {
    
    if(row<=n){
        if(row==1){
            //first line
            cout<<"*";
            for(int i=1;i<=2*(n-1);i++){
                cout<<" ";
            }
            cout<<"*";
        }else{
            //left start
            cout<<"*";
            //middle gap
            for(int i=1;i<=row-2;i++){
                cout<<" ";
            }
            cout<<"*";
            
            // middle space
            for(int i=1;i<=2*(n-row);i++){
                cout<<" ";
            }

            //right start
            cout<<"*";
            //middle gap
            for(int i=1;i<=row-2;i++){
                cout<<" ";
            }
            cout<<"*";




            }

    }else{

        if(row==2*n){
        //    last line
            cout<<"*";
            for(int i=1;i<=2*(n-1);i++){
                cout<<" ";
            }
            cout<<"*";
        }else{
            //left start
            cout<<"*";
            //middle gap
            for(int i=1;i<=2*n-row-1;i++){
                cout<<" ";
            }
            cout<<"*";
            
            // middle space
            for(int i=1;i<=2*(row-n-1);i++){
                cout<<" ";
            }

            //right start
            cout<<"*";
            //middle gap
            for(int i=1;i<=2*n-row-1;i++){
                cout<<" ";
            }
            cout<<"*";

    }


    }
        cout<<endl;
    

}
}


/*

25.       *****
         *   *
        *   *
       *   *
      *****

*/

void pattern25(int n=5){
    for (int row = 1; row <= n; row++)
    {
        /* code */
        for(int i=1;i<=n-row;i++){
            cout<<" ";

        }
        if(row==1||row==n){
            for (int i = 0; i < n; i++)
            {
                cout<<"*";
            }
            
        }
        else{
            cout<<"*";
            for (int i = 0; i < n-2; i++)
            {
                cout<<" ";
            }
            cout<<"*";
        }
        cout<<endl;

    }
    
}

/*

26.   1 1 1 1 1 1
      2 2 2 2 2
      3 3 3 3
      4 4 4
      5 5
      6

*/

void pattern26(int n=6){
    int num=1;
    for (int row = 1; row <=n; row++)
    {
        /* code */
        for(int i=1;i<=n-row+1;i++){
            cout<<num<<" ";
        }  
        num++;
        cout<<endl;      

    }
    
}


/*

27.   1 2 3 4  17 18 19 20
        5 6 7  14 15 16
          8 9  12 13
            10 11

*/
void pattern27(int n=4){
    int num1=1;
    int num2=n*n;
    for (int row = 1; row <=n; row++)
    {
        // print space
        for (int  i = 1; i <=row-1-1; i++)
        {
            cout<<" ";
        }

        //primt left numbers
        for (int i = 1; i <= n-row+1; i++)
        {
            /* code */
            cout<<" "<<num1;
            num1++;
        }
        cout<<"     ";
         for (int i = 1; i <= n-row+1; i++)
        {
            /* code */
            num2++;
            cout<<" "<<num2;
        }

        cout<<endl;
        num2=num2-n+row;
        num2=num2-n+row-1;
        

    }
    
}


/*

31.      4 4 4 4 4 4 4  
         4 3 3 3 3 3 4   
         4 3 2 2 2 3 4   
         4 3 2 1 2 3 4   
         4 3 2 2 2 3 4   
         4 3 3 3 3 3 4   
         4 4 4 4 4 4 4   

*/

void pattern31(int n=4){

            for (int  row = 1; row <=n; row++)
            {
                /* code */
               
                

            }
            


}

int main() {
    cout << "Pattern Problem Kunal kushvaha" << endl;
    pattern27(4);
 return 0;
}