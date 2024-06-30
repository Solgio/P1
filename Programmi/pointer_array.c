void fun(int* a){
   a[1]=a[1]*2;
   a[2]=a[2]*2; 
}
int main(void) {
   int x[]={0,1,2,3,4}; 
   fun(x+2);      
   for(int i=0; i<5; i+=1) {
      printf(" %d", x[i]);
   }
   printf("\n");
}