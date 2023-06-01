#include <iostream>
#include <climits>
using namespace std;
//Number of Vertices
const int Vertices = 6;
//minimum time array and visited array
int minTime(int minimumTimes[], bool Visited[])
{   
    
    int min = INT_MAX;
    int min_time = -1;

    for (int x = 0; x < Vertices; x++)
    {
        if (Visited[x] == false && minimumTimes[x] <= min)
        {
            min = minimumTimes[x];
            min_time = x;
        }
    }

    return min_time;
}


//Function dijkstra
void dijkstra(int graph[Vertices][Vertices], int source)
{   
    
    int minimumTimes[Vertices];
    bool Visited[Vertices];

    for (int x = 0; x < Vertices; x++)
    {
        minimumTimes[x] = INT_MAX;
        Visited[x] = false;
    }

    minimumTimes[source] = 0;

    for (int count = 0; count < Vertices - 1; count++)
    {
        int u = minTime(minimumTimes, Visited);

        Visited[u] = true;

        for (int v = 0; v < Vertices; v++)
        {
            if (!Visited[v] && graph[u][v] && minimumTimes[u] != INT_MAX)
            {
                if(minimumTimes[u] + graph[u][v] < minimumTimes[v]){
                    minimumTimes[v] = minimumTimes[u] + graph[u][v];
                }
                
            }
        }
    }

    
    cout<<"-------------------source city is "<<source<<"-------------"<<endl;
    double sum=0;
    double average=0.0;
    //for loop for printing values
    for (int x = 0; x < Vertices; x++)
    {
        if(x!=source){
            cout<<"Distance From"<<"\t"<< source<<"\t"<<"to " <<"\t"<<x<<"\t" <<"is ";
            
        if (minimumTimes[x] == INT_MAX)
            cout << "infinity";
        else
            cout << minimumTimes[x];
            //taking sum of minimum tomes related to city
            sum+=minimumTimes[x];
            
        cout << "\n";
            
        }
        
    }
    //taking average of minimum times
    average=sum/5;
    cout<<"Average Time for city"<<"\t"<<source<<"\t"<<"is "<<average<<endl;
}

int main()
{   
    
    int graph[Vertices][Vertices] = {
        {0,10,0,0,15,5}
        ,{10,0,10,30,0,0}
        ,{0,10,0,12,5,0}
        ,{0,30,12,0,0,20}
        ,{15,0,5,0,0,0}
        ,{5,0,0,20,0,0}
    };

    dijkstra(graph, 0);
    dijkstra(graph, 1);
    dijkstra(graph, 2);
    dijkstra(graph, 3);
    dijkstra(graph, 4);
    dijkstra(graph, 5);
    

    return 0;
}
