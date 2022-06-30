#include<iostream> //Recurssive and Iterative DFS 
#include<bits/stdc++.h>
using namespace std;
#define MAX 10
class listgraph; //forward declaration
class graphnode
{
	public:
	int vertex; // vertes of the graph
	graphnode *next; // next pointer to point to the next vertex
	graphnode(int n) // constructor
	{
		vertex=n;
		next=NULL;
	}
	friend class listgraph;
};
class listgraph
{
	graphnode *list[MAX]; //array of pointers
	int n; // number of vertices
	int visited[MAX];
	int cost[30][30];
	public:
	listgraph(int nov) // nov- number of vertices
	{
		n=nov;
		for(int j=0; j<n;j++) // intializing each vertices of the array of pointer as NULL as we dont have any edges
		{
		list[j]=NULL;
		for(int i=0;i<n;i++)
		cost[i][j]=INT_MAX;
		}
		for(int i=0;i<=n;i++)
		visited[i]=0;
	}
	void create(); // function for create the graph
	void display(); // function for displaying the graph
	void dfs(int v); // function for depth first search Graph Traversal
	void dfs_non_rec();
};

void listgraph :: create() // function for creating the graph
{
	int i,j;
	graphnode *temp; // temp pointer for travering
	char ans;
	for(i=0; i<n;i++) // 1st for loop is for the list of vertices
	{
		for(j=0;j<n;j++) // 2nd for the corresponding edges of the vertices
		{
			if(i!=j)
			{
				cout<<"\nIs there an edge between vertex "<<i+1<<" and "<<j+1<<" (y/n) : ";
				cin>>ans;
				if (ans=='y' || ans=='Y')
				{
					graphnode *newnode=new graphnode(j+1); //making a new node by calling the graphnode constructor
					if(list[i]==NULL) // if the newnode is the first node
					{
					list[i]=newnode;
					temp=newnode; // making temp to point to newnode for the travesing
					}
					else
					{
						temp->next=newnode; // making the existing node to point to the newnode
						temp=temp->next; // making temp to point to the newnode
					}
					if(i!=j)
					{
					cout<<"Enter the weight of the edge "<<i+1<<"-"<<j+1<<" : ";
					cin>>cost[i][j];
				}
				}
				if(i==j)
				cost[i][j]=0;
			}
		}
	}
}

void listgraph :: display() // function for the displaying the graph
{
	graphnode *temp;
	int i;
	for(i=0;i<n;i++) // for traversing through the array of pointer list of vertices
	{
		cout<<endl;
		cout<<"Vertex "<< i+1 <<" -> ";
		temp=list[i];
		while(temp!=NULL) // traversing through the vertices
		{
			cout<<"v"<<temp->vertex<<"->";
			temp=temp->next;
		}
		cout<<"NULL";
	}
}

void listgraph :: dfs(int v)
{
	graphnode *temp; // temp node for the traversing purpose
	int x;
	if(visited[v]==0) // checking whether the particular vertex is visited or not
	{
		cout<<"v"<<v<<" ";
		visited[v]=1; // marking the visited vertex = 1
		for(int i=0;i<n;i++)
		{
			temp=list[v-1]; // temp is pointing the respective vertex
			while(temp!=NULL) // traversing through the vertices
			{
				if(visited[temp->vertex]!=1) // checking whether the vertex is already visited or not
				{
					x=temp->vertex;
					dfs(x); // recursive call to the dfs function
				}
				else
				{
				temp=temp->next; // if the vertex is already visited then we move to the next vertex
				}
			}
		}
	}
}

class stack1 // stack class for the non recursive dfs
{
	int top;
	int item[30];
	public:
	stack1() // default constructor
	{
		top=-1; // initially maming top = -1
	}
	void push(int t) // push function
	{
		item[++top]=t;
	}
	int pop() // pop function
	{
		return item[top--];
	}
	int topnode() // return the top element
	{
		return item[top];
	}
	bool isfull() // isfull function
	{
		return (top==30);
	}
	bool isempty() // isempty function
	{
		return (top==-1);
	}
};

void listgraph :: dfs_non_rec()
{
	stack1 s;
	cout<<"\n\n Dfs Non Recursive Traversal : ";
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
		int v=0;
		visited[v]=1;
		cout<<"v"<<v+1<<" ";
		s.push(v);
		while(s.isempty()!=true)
		{
			graphnode *temp=list[v];
			while(temp!=NULL)
			{
				int w=temp->vertex;
				if(visited[w-1]==0)
				{
					visited[w-1]=1;
					cout<<"v"<<w<<" ";
					s.push(w-1);
					temp=list[w-1];
				}
				else
				{
					temp=temp->next;
				}
			}
			v=s.pop();
		}	
	}
}
	
int main()
{
	int ch,k,a,v;
	cout<<"\nEnter the number of vertices : ";
	cin>>a;
	listgraph g(a);
	do
	{
		cout<<"\n------MENU------";
		cout<<"\n1. Create Graph";
		cout<<"\n2. Display Graph";
		cout<<"\n3. Depth-First-Search Traversal (Recursive)";
		cout<<"\n4. Depth-First-Search Traversal (Non Recusrive)";
		cout<<"\n\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 : g.create();
			break;
			case 2 : cout<<"\nDisplaying Graph\n";
			g.display();
			break;
			case 3 : cout<<"\nEnter the Starting Vertex : ";
			cin>>v;
			cout<<"\nDFS Traversal : ";
			g.dfs(v);
			break;
			case 4 : g.dfs_non_rec();
			break;
			default : cout<<"\nInvalid Input!!!!";
		}
		cout<<"\n\nDo you want to Continue press 1 : ";
		cin>>k;
	}while(k==1);
}


