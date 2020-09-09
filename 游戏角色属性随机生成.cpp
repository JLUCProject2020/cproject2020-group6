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
     {case 0:cout<<"力量：";
             break;
      case 1:cout<<"体质：";
             break;
      case 2:cout<<"体型：";
             break;
      case 3:cout<<"敏捷：";
             break;
      case 4:cout<<"外貌：";
	         break;
	  case 5:cout<<"智力：";
	         break;
	  case 6:cout<<"意志：";
	         break;
	  case 7:cout<<"教育：";
	         break;
	  case 8:cout<<"幸运：";
	         break; 
	  case 9:cout<<"生命值：";
	         break;
	  case 10:cout<<"移动速度：";
	          break;
	  case 11:cout<<"理智值：";
	          break;
	  case 12:cout<<"魔法值：";
	          break;
	  case 13:cout<<"伤害加值：";
	  		  break;
	  case 14:cout<<"体格：";
	          break;
	 }
	cout<<A[i]<<endl;
   }
   return;
}

void roles::print2(int k)
{switch(k)
	{
		case 0:cout<<"斗殴：";
			break;
		case 1:cout<<"医疗：";
		    break;
		case 2:cout<<"急救：";
		    break;
		case 3:cout<<"闪避：";
			break;
		case 4:cout<<"攀爬：";
			break;
		case 5:cout<<"跳跃：";
			break;
		case 6:cout<<"艺术：";
			break;
		case 7:cout<<"生物学：";
			break;
		case 8:cout<<"射击：";
			break; 
		}
}

void roles::print3()
{
	print1();
	cout<<"职业：";
	switch(career)
	{
		case 1:cout<<"艺术家";
				break;
		case 2:cout<<"医生";
				break;
		case 3:cout<<"警察";
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
	cout<<"形象描述："<<story[0];
	cout<<endl<<"思想与信念："<<story[1];
	cout<<endl<<"重要之人："<<story[2];
	cout<<endl<<"意义非凡之地:"<<story[3];
	cout<<endl<<"宝贵之物:"<<story[4];
	cout<<endl<<"特质："<<story[5];
	cout<<endl<<"伤口和疤痕："<<story[6];
	cout<<endl<<"恐惧症和躁狂症："<<story[7];
	cout<<endl<<"神话典籍、法术和魔法物品："<<story[8];
	cout<<endl<<"第三类接触："<<story[9];
}
void roles::Addpoint(int i)
{
	int k;
	cout<<"初始技能加点："<<endl;
	for(k=0;k<9;k++)
	{
		skill[k]=15;
		print2(k);
		cout<<skill[k]<<endl;
	}
	cout<<"请为你可选择的技能加点："<<endl;
	int l=point,n,s; 
	for(k=0,s=0;k<9;k++)
	{		
		if(i==1&&(k==5||k==7||k==8))
			continue;
		if(i==2&&(k==0||k==6||k==8))
			continue;
		if(i==3&&(k==2||k==6||k==7))
			continue;
		cout<<"你剩余的技能点有 "<<l<<" 点"<<endl; 
		print2(k);
		cout<<skill[k]<<"+"; 
		cin>>n;	
		if(l-n<0)
			{cout<<"您没有足够的技能点为这项技能加点，请重新输入！"<<endl;
			 k--;
			 continue;
			}
		skill[k]+=n;
		l-=n;
		s++;
		if(l==0)
			break;
		if(s==6&&l>0)
			{cout<<"你仍有技能点剩余，是否继续加点?"<<endl<<"（输入‘1’继续加点，输入‘0’放弃加点）";
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
	cout<<"形象描述：";
	getline(cin,story[0]);
	cout<<"思想与信念：";
	getline(cin,story[1]);
	cout<<"重要之人：";
	getline(cin,story[2]);
	cout<<"意义非凡之地：";
	getline(cin,story[3]);
	cout<<"宝贵之物：";
	getline(cin,story[4]);
	cout<<"特质：";
	getline(cin,story[5]);
	cout<<"伤口和疤痕：";
	getline(cin,story[6]);
	cout<<"恐惧症和躁狂症：";
	getline(cin,story[7]);
	cout<<"神话典籍、法术和魔法物品：";
	getline(cin,story[8]);
	cout<<"第三类接触：";
	getline(cin,story[9]);
}

void roles::print4()
{
	FILE *fp;
	fp=fopen("card.txt","a");
	fprintf(fp,"名字：%s       年龄：%d\n",Name.c_str(),Age);
	fprintf(fp,"力量：%d       体质：%d         体型：%d     \n",A[0],A[1],A[2]);
	fprintf(fp,"敏捷：%d       外貌：%d         智力：%d     \n",A[3],A[4],A[5]);
	fprintf(fp,"意志：%d       教育：%d         幸运：%d     \n",A[6],A[7],A[8]);
	fprintf(fp,"生命值：%d     移动速度：%d      理智值：%d     \n",A[9],A[10],A[11]);
	fprintf(fp,"魔法值：%d     伤害加值：%d      体格：%d     \n",A[12],A[13],A[14]);
	switch(career)
	{
		case 1:fprintf(fp,"职业：%s     职业特有技能 %s：%d\n","艺术家","艺术",skill[6]);
		       break;
		case 2:fprintf(fp,"职业：%s     职业特有技能 %s：%d\n","医生","生物学",skill[7]);
			   break;
		case 3:fprintf(fp,"职业：%s     职业特有技能 %s：%d\n","警察","射击",skill[8]);
			   break;
		 
	}
    fprintf(fp,"斗殴：%d       医疗：%d       急救：%d     \n",skill[0],skill[1],skill[2]);
    fprintf(fp,"闪避：%d       攀爬：%d       跳跃：%d     \n",skill[3],skill[4],skill[5]);
    fprintf(fp,"形象描述：%s\n",story[0].c_str());
    fprintf(fp,"思想和信念：%s\n",story[1].c_str());
    fprintf(fp,"重要之人：%s\n",story[2].c_str());
    fprintf(fp,"意义非凡之地：%s\n",story[3].c_str());
    fprintf(fp,"宝贵之物：%s\n",story[4].c_str());
    fprintf(fp,"特质：%s\n",story[5].c_str());
    fprintf(fp,"伤口和疤痕：%s\n",story[6].c_str());
    fprintf(fp,"恐惧症和躁狂症：%s\n",story[7].c_str());
    fprintf(fp,"神话典籍、法术和魔法物品：%s\n",story[8].c_str());
    fprintf(fp,"第三类接触：%s\n",story[9].c_str());
    fclose(fp);
    cout<<"数据录入成功！"; 
    
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
   cout<<"在扮演游戏里，属性越高，角色的游戏成功率就越高。" <<endl;
   cout<<"但在克苏鲁的呼唤中，低属性却不尽然，低属性并不意味着你的调查员就是一个短板，就无法参与进团队。"<<endl;
   cout<<"相比那些超属性的超人，一到两个较低属性有时更能让调查员“活下去”且更为真实。"<<endl;
   cout<<"不要随意放弃你的低掷骰结果。尝试接纳它成为你调查员的一部分。"<<endl;
   cout<<"也许低敏捷代表着你的调查员曾在战火中受过肢体损伤，低教育可以说明你的调查员没念过书，被迫在黑街上成长求生。"<<endl;
   while(true)
   {cout<<"是否需要重新随机："<<endl<<"(‘是’输入‘Y’/‘否’输入‘N’)";
    cin>>c;
    if(c=='N'||c=='n')
    	break;
    player[i].getdata2();
    player[i].getdata3();
    player[i].print1();
   }
   cout<<endl<<"请输入姓名：";
   cin>>name;
   cout<<"请输入年龄：";
   cin>>age;
   if(age<15)
     {cout<<"您的年龄太小，不适合参赛。"<<endl;
      continue;
     }
   else if(age>=90)
     {cout<<"您的年龄太大，不适合参赛。"<<endl; 
      continue;
     }
   player[i].getdata1(name,age);
   player[i].edustrength();
   cout<<" 请选择你的职业："<<endl;
   cout<<"1：艺术家；2：医生；3：警察。";
   int m;
   cin>>m;
   player[i].getCareer(m);
   player[i].getdata4();
   player[i].getdata5();
   player[i].print3();
   cout<<endl<<"是否继续生成角色？（输入“0”退出，输入其他继续）";
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
