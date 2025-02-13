/**Kth Call
 * 
 * Here 
 */

 #include <stdio.h>

 void utility()
 {
    // declare the variable count here
    static int count = 0;
    // increases the value of count by 1
    count++;

    // print count
    printf("%d",count);
 }

 int main(int argc, char const *argv[])
 {
    int t;
    scanf("%d",&t);

    int n;
    scanf("%d",&n);

    while (n--)
    {
        utility();
        printf(" ");
    }

    printf("\n");
    return 0;
 }
 