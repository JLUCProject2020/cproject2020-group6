using namespace std;
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstdio>
#include<time.h>
#include<string>
class roles{string Name;
            int Age;
            int A[15];
            int career;
            int point;
            int skill[9];
            string story[10];
    public: void getdata1(string name,int age){Name=name;Age=age;}
            void getdata2();
            void getdata3();
            void getdata4();
            void getdata5();
            void getCareer(int i){career=i;}
            void edustrength();
            void Addpoint(int i);
            void print1();
            void print2(int k);
            void print3();
            void print4();
};
int random(int i)
{int n;
 n=rand()%(i+1);
 return n;
}
void roles::getdata2()
{int M[23],n=0,i;
 srand((unsigned)time(NULL));
 for(i=0;i<23;i++)                              
    M[i]=1+rand()%6;
 for(i=0;i<9;i++)
    {if(i==0||i==1||i==3||i==6||i==8)
      {A[i]=(M[n]+M[n+1]+M[n+2])*5;
       n+=3;
	  }
    else
      {A[i]=(M[n]+M[n+1]+6)*5;
       n+=2;
	  } 
       if(A[i]>99)
         A[i]=99;
	}
}
void roles::getdata3()
{A[9]=(A[1]+A[2])/10;
 if(A[3]<A[2]&&A[0]<A[2])
   A[10]=7;
 else if(A[3]>A[2]&&A[0]>A[2])
   A[10]=9;
 else
   A[10]=8;
 A[11]=A[6];
 A[12]=A[5]/5;
 return;
}
void f1(int *A,int i,int k)
{int n,m,l;
 n=random(i);
 if(n==i)
    m=0;
 else
    m=random(i-n);
 l=i-m-n;
 if(A[0]+A[1]+A[3]<=i)
  {A[0]=0;
   A[1]=0;
   A[3]=0;
  }
 A[0]-=m;
 A[1]-=n;
 A[3]-=l;
 for(;A[0]<0||A[1]<0||A[3]<0;)
   {if(A[0]<0)
       {A[0]+=2;
        A[1]-=1;
        A[3]-=1;
	   }
	if(A[1]<0)
	   {A[1]+=2;
	    A[0]-=1;
	    A[3]-=1;
	   }
	if(A[3]<0)
	   {A[3]+=2;
	    A[0]-=1;
	    A[1]-=1;
	   }
   }
 A[4]-=k;
 return;
}
int edu(int i)
{int n=0;
 for(int j=0;j<i;j++)
  n+=(1+rand()%10);
 return n;
}
void roles::edustrength()
{switch(Age/10)
   {case 4:A[10]-=1;
           break;
    case 5:A[10]-=2;
           break;
    case 6:A[10]-=3;
           break;
    case 7:A[10]-=4;
           break;
    case 8:A[10]-=5;
           break;
   } 
 if(Age>=15&&Age<20)
  {int k=0,n,m;
   n=random(5);
   A[0]-=n;
   A[2]-=(5-n);
   A[7]-=5;
   for(int i=0;i<3;i++)
      k+=(1+rand()%6);
   if(k*5>A[8])
      A[8]=k*5;
  }
 else if(Age<40)
  {A[7]+=edu(1);
   if(A[7]>99)
    A[7]=99;
  }
 else if(Age<50)
  {f1(A,5,5);
   A[7]+=edu(2);
   if(A[7]>99)
    A[7]=99;
  }
 else if(Age<60)
  {f1(A,10,10);
   A[7]+=edu(3);
   if(A[7]>99)
    A[7]=99;
  }
 else if(Age<70)
  {f1(A,20,15);
   A[7]+=edu(4);
   if(A[7]>99)
    A[7]=99;
  }
 else if(Age<80)
  {f1(A,40,20);
   A[7]+=edu(4);
   if(A[7]>99)
    A[7]=99;
  }
 else 
  {f1(A,80,25);
   A[7]+=edu(4);
   if(A[7]>99)
    A[7]=99;
  }
  int k=A[0]+A[1];
  if(k>1&&k<65)
  {
  	A[13]=-2;
  	A[14]=-2;
  }
  else if(k>=65&&k<85)
  {
  	A[13]=-1;
  	A[14]=-1;
  }
  else if(k>=85&&k<125)
  {
  	A[13]=0;
  	A[14]=0;
  }
}
void roles::print1()
{for(int i=0;i<15;i++)
   {switch(i)
     {case 0:cout<<"������";
             break;
      case 1:cout<<"���ʣ�";
             break;
      case 2:cout<<"���ͣ�";
             break;
      case 3:cout<<"���ݣ�";
             break;
      case 4:cout<<"��ò��";
	         break;
	  case 5:cout<<"������";
	         break;
	  case 6:cout<<"��־��";
	         break;
	  case 7:cout<<"������";
	         break;
	  case 8:cout<<"���ˣ�";
	         break; 
	  case 9:cout<<"����ֵ��";
	         break;
	  case 10:cout<<"�ƶ��ٶȣ�";
	          break;
	  case 11:cout<<"����ֵ��";
	          break;
	  case 12:cout<<"ħ��ֵ��";
	          break;
	  case 13:cout<<"�˺���ֵ��";
	  		  break;
	  case 14:cout<<"���";
	          break;
	 }
	cout<<A[i]<<endl;
   }
   return;
}

void roles::print2(int k)
{switch(k)
	{
		case 0:cout<<"��Ź��";
			break;
		case 1:cout<<"ҽ�ƣ�";
		    break;
		case 2:cout<<"���ȣ�";
		    break;
		case 3:cout<<"���ܣ�";
			break;
		case 4:cout<<"������";
			break;
		case 5:cout<<"��Ծ��";
			break;
		case 6:cout<<"������";
			break;
		case 7:cout<<"����ѧ��";
			break;
		case 8:cout<<"�����";
			break; 
		}
}

void roles::print3()
{
	print1();
	cout<<"ְҵ��";
	switch(career)
	{
		case 1:cout<<"������";
				break;
		case 2:cout<<"ҽ��";
				break;
		case 3:cout<<"����";
				break;
	}
	cout<<endl;
	for(int k=0;k<9;k++)
	{
		if(career==1&&(k==7||k==8))
			continue;
		if(career==2&&(k==6||k==8))
			continue;
		if(career==3&&(k==6||k==7))
			continue;
		print2(k);
		cout<<skill[k]<<endl;
	}
	cout<<"����������"<<story[0];
	cout<<endl<<"˼�������"<<story[1];
	cout<<endl<<"��Ҫ֮�ˣ�"<<story[2];
	cout<<endl<<"����Ƿ�֮��:"<<story[3];
	cout<<endl<<"����֮��:"<<story[4];
	cout<<endl<<"���ʣ�"<<story[5];
	cout<<endl<<"�˿ںͰ̺ۣ�"<<story[6];
	cout<<endl<<"�־�֢�����֢��"<<story[7];
	cout<<endl<<"�񻰵伮��������ħ����Ʒ��"<<story[8];
	cout<<endl<<"������Ӵ���"<<story[9];
}
void roles::Addpoint(int i)
{
	int k;
	cout<<"��ʼ���ܼӵ㣺"<<endl;
	for(k=0;k<9;k++)
	{
		skill[k]=15;
		print2(k);
		cout<<skill[k]<<endl;
	}
	cout<<"��Ϊ���ѡ��ļ��ܼӵ㣺"<<endl;
	int l=point,n,s; 
	for(k=0,s=0;k<9;k++)
	{		
		if(i==1&&(k==5||k==7||k==8))
			continue;
		if(i==2&&(k==0||k==6||k==8))
			continue;
		if(i==3&&(k==2||k==6||k==7))
			continue;
		cout<<"��ʣ��ļ��ܵ��� "<<l<<" ��"<<endl; 
		print2(k);
		cout<<skill[k]<<"+"; 
		cin>>n;	
		if(l-n<0)
			{cout<<"��û���㹻�ļ��ܵ�Ϊ����ܼӵ㣬���������룡"<<endl;
			 k--;
			 continue;
			}
		skill[k]+=n;
		l-=n;
		s++;
		if(l==0)
			break;
		if(s==6&&l>0)
			{cout<<"�����м��ܵ�ʣ�࣬�Ƿ�����ӵ�?"<<endl<<"�����롮1�������ӵ㣬���롮0�������ӵ㣩";
			 int n;
			 cin>>n;
			 if(n==0)
			 	break;
			 else if(n==1)
			 	k=-1;
			}
	}
}

void roles::getdata4()
{
	switch(career)
	{
		case 1:point=(A[7]+A[6])*2;
		       break;
		case 2:point=A[7]*4;
			   break;
		case 3:point=(A[7]+A[0])*2;
		       break;
	}
	Addpoint(career);
}

void roles::getdata5()
{
	char c=cin.get();
	cout<<"����������";
	getline(cin,story[0]);
	cout<<"˼�������";
	getline(cin,story[1]);
	cout<<"��Ҫ֮�ˣ�";
	getline(cin,story[2]);
	cout<<"����Ƿ�֮�أ�";
	getline(cin,story[3]);
	cout<<"����֮�";
	getline(cin,story[4]);
	cout<<"���ʣ�";
	getline(cin,story[5]);
	cout<<"�˿ںͰ̺ۣ�";
	getline(cin,story[6]);
	cout<<"�־�֢�����֢��";
	getline(cin,story[7]);
	cout<<"�񻰵伮��������ħ����Ʒ��";
	getline(cin,story[8]);
	cout<<"������Ӵ���";
	getline(cin,story[9]);
}

void roles::print4()
{
	FILE *fp;
	fp=fopen("card.txt","a");
	fprintf(fp,"���֣�%s       ���䣺%d\n",Name.c_str(),Age);
	fprintf(fp,"������%d       ���ʣ�%d         ���ͣ�%d     \n",A[0],A[1],A[2]);
	fprintf(fp,"���ݣ�%d       ��ò��%d         ������%d     \n",A[3],A[4],A[5]);
	fprintf(fp,"��־��%d       ������%d         ���ˣ�%d     \n",A[6],A[7],A[8]);
	fprintf(fp,"����ֵ��%d     �ƶ��ٶȣ�%d      ����ֵ��%d     \n",A[9],A[10],A[11]);
	fprintf(fp,"ħ��ֵ��%d     �˺���ֵ��%d      ���%d     \n",A[12],A[13],A[14]);
	switch(career)
	{
		case 1:fprintf(fp,"ְҵ��%s     ְҵ���м��� %s��%d\n","������","����",skill[6]);
		       break;
		case 2:fprintf(fp,"ְҵ��%s     ְҵ���м��� %s��%d\n","ҽ��","����ѧ",skill[7]);
			   break;
		case 3:fprintf(fp,"ְҵ��%s     ְҵ���м��� %s��%d\n","����","���",skill[8]);
			   break;
		 
	}
    fprintf(fp,"��Ź��%d       ҽ�ƣ�%d       ���ȣ�%d     \n",skill[0],skill[1],skill[2]);
    fprintf(fp,"���ܣ�%d       ������%d       ��Ծ��%d     \n",skill[3],skill[4],skill[5]);
    fprintf(fp,"����������%s\n",story[0].c_str());
    fprintf(fp,"˼������%s\n",story[1].c_str());
    fprintf(fp,"��Ҫ֮�ˣ�%s\n",story[2].c_str());
    fprintf(fp,"����Ƿ�֮�أ�%s\n",story[3].c_str());
    fprintf(fp,"����֮�%s\n",story[4].c_str());
    fprintf(fp,"���ʣ�%s\n",story[5].c_str());
    fprintf(fp,"�˿ںͰ̺ۣ�%s\n",story[6].c_str());
    fprintf(fp,"�־�֢�����֢��%s\n",story[7].c_str());
    fprintf(fp,"�񻰵伮��������ħ����Ʒ��%s\n",story[8].c_str());
    fprintf(fp,"������Ӵ���%s\n",story[9].c_str());
    fclose(fp);
    cout<<"����¼��ɹ���"; 
    
}
int main()
{int i;  
 roles player[10000];
 for(i=0;i<10000;i++)
  {int n,age;
   string name;
   player[i].getdata2();
   player[i].getdata3();
   player[i].print1();
   char c;
   cout<<"�ڰ�����Ϸ�����Խ�ߣ���ɫ����Ϸ�ɹ��ʾ�Խ�ߡ�" <<endl;
   cout<<"���ڿ���³�ĺ����У�������ȴ����Ȼ�������Բ�����ζ����ĵ���Ա����һ���̰壬���޷�������Ŷӡ�"<<endl;
   cout<<"�����Щ�����Եĳ��ˣ�һ�������ϵ�������ʱ�����õ���Ա������ȥ���Ҹ�Ϊ��ʵ��"<<endl;
   cout<<"��Ҫ���������ĵ�������������Խ�������Ϊ�����Ա��һ���֡�"<<endl;
   cout<<"Ҳ������ݴ�������ĵ���Ա����ս�����ܹ�֫�����ˣ��ͽ�������˵����ĵ���Աû����飬�����ںڽ��ϳɳ�������"<<endl;
   while(true)
   {cout<<"�Ƿ���Ҫ���������"<<endl<<"(���ǡ����롮Y��/�������롮N��)";
    cin>>c;
    if(c=='N'||c=='n')
    	break;
    player[i].getdata2();
    player[i].getdata3();
    player[i].print1();
   }
   cout<<endl<<"������������";
   cin>>name;
   cout<<"���������䣺";
   cin>>age;
   if(age<15)
     {cout<<"��������̫С�����ʺϲ�����"<<endl;
      continue;
     }
   else if(age>=90)
     {cout<<"��������̫�󣬲��ʺϲ�����"<<endl; 
      continue;
     }
   player[i].getdata1(name,age);
   player[i].edustrength();
   cout<<" ��ѡ�����ְҵ��"<<endl;
   cout<<"1�������ң�2��ҽ����3�����졣";
   int m;
   cin>>m;
   player[i].getCareer(m);
   player[i].getdata4();
   player[i].getdata5();
   player[i].print3();
   cout<<endl<<"�Ƿ�������ɽ�ɫ�������롰0���˳�����������������";
   cin>>n;
   if(n==0)
     break;
   else
     continue;
 }
 for(int j=0;j<=i;j++)
 {
 	cout<<endl;
 	player[j].print4();
 }
 return 0;
}
