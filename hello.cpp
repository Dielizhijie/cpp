#include <iostream>
#include <cstdio>
#define ZLEN 5


using namespace std;
typedef int zip_dig[ZLEN];
typedef struct _float
{
    int w:23;
    int j:8;
    int s:1;
}Float;

union ele{
    struct{
        int *p;
        int y;
    } e1;
    struct{
        int x;
        union ele* next;
    } e2;
    int z;
} uni;
struct {
    double c;
    long long g;
    float e;
    char *a;
    void *h;
    short b;
    char d;
    char f;
} foo;
int main()
{
   int checkCpu();
   void returnAddress(unsigned char *p,int len);
   void convertFloat(float t,char str[33]);
   void convertDouble(double t,char str[65]);
   void combineofMatirx(int*a ,int*b, int*c ,int m ,int n);
   int v1=0x12345678;
   long v2=0x12345678;
   double v3=-2.1;
   float v4=-2.1f;
   cout<<"ÊµÑé1:"<<endl;
   if(checkCpu())
   {
       cout<<"It is a big endian"<<endl;
   }
   else
   {
       cout<<"It is a little endian"<<endl;
   }
   cout<<v1<<endl;
   returnAddress((unsigned char*)&v1,sizeof(v1));
   cout<<v2<<endl;
   returnAddress((unsigned char*)&v2,sizeof(v2));
   cout<<v3<<endl;
   returnAddress((unsigned char*)&v3,sizeof(v3));
   cout<<v4<<endl;
   returnAddress((unsigned char*)&v4,sizeof(v4));

   cout<<"ÊµÑé2:"<<endl;
   cout<<v4<<endl;
   char str1[33];
   convertFloat(v4,str1);
   for(int i=0;i<32;i++)
   {
       cout<<str1[i];
   }
   cout<<endl;
   char str2[65];
   convertDouble(v3,str2);
   cout<<v3<<endl;
   for(int i=0;i<64;i++)
   {
       cout<<str2[i];
   }
   cout<<endl;
   cout<<"ÊµÑé3:"<<endl;
   float f1=0;    //0
   float f2=__FLT_MAX__;   //×î´óµÄ¹æ¸ñ»¯Êý
   float f3 = 0;
   float f4 = 0;
   Float obj;
   obj.s = 0;
   obj.j = 0xff;
   obj.w = 0x0;
   f3 = *(float*)(&obj);
   obj.w=0x01;
   f4= *(float*)(&obj); //NaN
   cout<<"test f1 "<<endl;
   returnAddress((unsigned char*)&f1,sizeof(f1));
   cout<<"test f2 "<<endl;
   returnAddress((unsigned char*)&f2,sizeof(f2));
   cout<<"test f3 "<<endl;
   returnAddress((unsigned char*)&f3,sizeof(f3));; printf(" f3 is %f (ÎÞÇî´ó£©\n", f3);
   cout<<"test f4 "<<endl;
   returnAddress((unsigned char*)&f4,sizeof(f4));; printf(" f4 is %f £¨NaN£©\n", f4);

   cout<<"ÊµÑé4:"<<endl;
   zip_dig cmu = { 1, 5, 2, 1, 3 };
   zip_dig mit = { 0, 2, 1, 3, 9 };
   zip_dig ucb = { 9, 4, 7, 2, 0 };
   cout<<"cmu"<<endl;
   for(int i=0;i<5;i++)
   {
       cout<<cmu[i]<<" µÄµØÖ· "<<&cmu[i]<<endl;
   }
   cout<<"mit"<<endl;
   for(int i=0;i<5;i++)
   {
       cout<<mit[i]<<" µÄµØÖ· "<<&mit[i]<<endl;
   }
   cout<<"ucb"<<endl;
   for(int i=0;i<5;i++)
   {
       cout<<ucb[i]<<" µÄµØÖ· "<<&ucb[i]<<endl;
   }

   cout<<"ÊµÑé5:"<<endl;
   cout<<"½á¹ûÊÇ"<<endl;
   combineofMatirx(cmu, mit, ucb, 5, 3 );

   cout<<"ÊµÑé6£º"<<endl;
   cout<<"cµÄµØÖ·:"<<&foo.c<<endl;
   cout<<"gµÄµØÖ·:"<<&foo.g<<endl;
   cout<<"eµÄµØÖ·:"<<&foo.e<<endl;
   cout<<"aµÄµØÖ·:"<<&foo.a<<endl;
   cout<<"hµÄµØÖ·:"<<&foo.h<<endl;
   cout<<"bµÄµØÖ·:"<<&foo.b<<endl;
   cout<<"fµÄµØÖ·:"<<&foo.f<<endl;
   cout<<"ÊµÑé7:"<<endl;
   printf("int *p : %p \n" , &uni.e1.p);
   printf("int y : %p \n" , &uni.e1.y);
   printf("int x : %p \n" , &uni.e2.x);
   printf("union ele *next : %p \n" , &uni.e2.next);
   printf("int z : %p \n" , &uni.z);
}
int checkCpu()
{
    int num=0x12345678;
    if(*(char*)&num==0x12)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void returnAddress(unsigned char *p,int len)
{   cout<<"ÊýÖµ:";
    for(int i=0;i<len;i++)
    {
        printf("%x ",*(p++));
        cout<<'\t';
    }
    cout<<endl;
    cout<<"µØÖ·:";
    for(int i=0;i<len;i++)
    {
        printf("%x ",(p++));
        cout<<'\t';
    }
    cout<<endl;
}
void convertFloat(float t,char str[33])
{
    unsigned int p=(( unsigned int*)&t)[0];
    for(int i=0;i<32;i++)
    {
        str[31-i]= (char)(p&1)+'0';
        p>>=1;

    }
    str[32]='\0';
}
void convertDouble(double t,char str[65])
{
    long long p=(( long long*)&t)[0];
    for(int i=0;i<64;i++)
    {
        str[63-i] = (char)(p&1)+'0';
        p>>=1;
    }
    str[64]='\0';

}
void combineofMatirx(int*a ,int*b, int*c ,int m ,int n){

     int forReturn[m][m];
     int arr[m][n];
     int i,j;
     for(i=0;i<n;i++){
         arr[0][i]=a[i];
         arr[1][i]=b[i];
         arr[2][i]=c[i];
     }
    int k; int num=0;
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            for(k=0;k<n;k++){
                num+=arr[i][k]*arr[j][k];
            }
            forReturn[i][j]=num;
            num=0;
        }
    }
    int i2,j2;
    for(i2=0;i2<3;i2++){
        for(j2=0;j2<3;j2++){
            cout <<forReturn[i2][j2]<<'\t';
        }
        cout<<endl;
    }
}

