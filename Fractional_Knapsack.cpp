//C++ Program to Perform Cycle Detection using Disjoint Set
//MST weight is not PRINTED. IT WILL BE UPDATED after sometime

#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int weight,profit;
    Item(int w,int p)
    {
        weight =w;
        profit=p;   
    }
};


bool comparator(struct Item a, struct Item b)
{
    double r1= a.profit/a.weight;
    double r2= a.profit/a.weight;
    return r1 > r2;
}

double FractionalKnapsack(struct Item items[], int n,int W)
{
  sort(items, items+n , comparator);
	
double profit =0.0;
	
	for(int i=0;i<n;i++)
	{
		if(items[i].weight <= W)
		{
			W -= items[i].weight;
			profit +=items[i].value;
		}
		else
		{
			profit+ = items[i].value * ((double) W/(double) items[i].weight);
			break;
		}
	}
	return profit;
}


int main(){
    int n,w,p;
	int bagweight;
	cin>>bagweight;
	
    cout<<"Enter no of Items ";
	cin>>n;
    vector<Item> items;
    for(int i=0;i<n;i++)
    {
        cin>>w >> p;
        items.push_back(Item(w,p));
    }
    cout<<"Max Profit Earned="<<FractionalKnapsack(items,n,bagweight);
    
    // for(auto e:mst)
    //   cout<<e.u<<" "<<e.v<<" "<<e.weight<<"\n";
    return 0;
}  //end of main()
