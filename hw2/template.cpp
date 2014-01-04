#include <iostream>
#include <queue>
#include <vector>

using namespace std;


// use adjacency matrix since we are only dealing with small graph
class Graph {
private:
    int vertexNum;
    int edgeNum;
    vector< vector<double> > adjMatrix;

public:
    Graph() 
    {
        vertexNum = 0;
        edgeNum   = 0;
    };

    Graph(int vertexNum): adjMatrix(vertexNum, vector<double>(vertexNum))
    {
        this->vertexNum = vertexNum;
        this->edgeNum   = 0;
        
        // init adj matrix
        for(int i = 0;i < vertexNum; ++i) {
            for(int j = 0;j < vertexNum; ++j) {
                adjMatrix[i][j] = 0.0;
            }
        }
    }

    int E()
    {
        return this->edgeNum;
    }
    
    int V()
    {
        return this->vertexNum;
    }

    int adjacent(int v1, int v2)
    {
        // first check illegal situations
        if(v1 >= vertexNum || v2 >= vertexNum) {
            cout<<"Error: one of the vertex doesn't exist!"<<endl;
            return -1;
        }
        else if(this->adjMatrix[v1][v2] == 0.0) {
            return 0;
        }
        else
            return 1;

    }

    int neighbors(int v)
    {

        // first check illegal situations
        if(v >= vertexNum) {
            cout<<"Error: the vertex doesn't exist!"<<endl;
            return -1;
        }
        else {
            for(int i = 0; i < vertexNum; ++i) {
                if(adjMatrix[v][i] > 0.0)
                    cout<<i<<" ";
            }
            cout<<endl;
        }

        return 0;
    }

    int add(int v1, int v2, double weight=1.0) 
    {
        // first check illegal situations
        if(v1 == v2) {
            cout<<"Error: can't add edge of same vertex!"<<endl;
            return -1;
        }
        else if(v1 >= vertexNum || v2 >= vertexNum) {
            cout<<"Error: at least one of the vertex doesn't exist!"<<endl;
            return -1;
        }
        else if(this->adjMatrix[v1][v2] > 0.0) {
            cout<<"Error: edge already exist!"<<endl;
            return -1;
        }
        else{
            this->adjMatrix[v1][v2] = weight;
            this->edgeNum++;
        }
    
        return 1;
    }


    int set_edge_value(int v1, int v2, double weight) 
    {
        // first check illegal situations
        if(weight <= 0) {
            cout<<"Error: weight should be greater than zero"<<endl;
        }
        else if(v1 == v2) {
            cout<<"Error: can't set edge weight of same vertex!"<<endl;
            return -1;
        }
        else if(v1 >= vertexNum || v2 >= vertexNum) {
            cout<<"Error: at least one of the vertex doesn't exist!"<<endl;
            return -1;
        }
        else if(adjMatrix[v1][v2] == 0.0) {
            cout<<"Error: edge doesn't exist"<<endl;
            return -1;
        }
        else if(adjMatrix[v1][v2] > 0.0) {
            adjMatrix[v1][v2] = weight;
            edgeNum++;
        }
    
        return -1;
    }

    double get_edge_value(int v1, int v2) 
    {
        // first check illegal situations
        if(v1 == v2) {
            cout<<"Error: same vertex!"<<endl;
            return 0.0;
        }
        else if(v1 >= vertexNum || v2 >= vertexNum) {
            cout<<"Error: at least one of the vertex doesn't exist!"<<endl;
            return 0.0;
        }
        else if(adjMatrix[v1][v2] > 0.0) {
            return adjMatrix[v1][v2];
        }
    
        return 0.0;
    }

    int delete_edge(int v1, int v2) 
    {
        // first check illegal situations
        if(v1 == v2) {
            cout<<"Error: can't delete edge of same vertex!"<<endl;
            return -1;
        }
        else if(v1 >= vertexNum || v2 >= vertexNum) {
            cout<<"Error: one of the vertex doesn't exist!"<<endl;
            return -1;
        }
        else if(adjMatrix[v1][v2] == 0.0) {
            cout<<"Error: edge already exist!"<<endl;
            return -1;
        }
        else if(adjMatrix[v1][v2] > 0){
            this->adjMatrix[v1][v2] = 0;
            this->edgeNum--;
        }
    
        return 1;
    }

    ~Graph()
    {

    }

};

class PriorityQueue {
public:
    void chgPrioirity(PQ, priority)
    {
        
    }
    
    // removes the top element of the queue.
    void minPrioirty(PQ)
    {
    
        
    }
    
    // does the queue contain queue_element
    bool contains(PQ, queue_element)
    {
    
    }
    
    // insert queue_element into queue
    Insert(PQ, queue_element)
    {
    
    }
    // returns the top element of the queue
    top(PQ)
    {
    
    }

    // return the number of queue_elements
    size(PQ)
    {
    
    }
}

class ShortestPath
{
    // list of vertices in G(V,E).
    void vertices(List)
    {
    
    }
    
    // find shortest path between u-w and returns the sequence of vertices representing shorest path u-v1-v2-…-vn-w.
    int path(u, w)
    {
    
    }
    
    // return the path cost associated with the shortest path.
    int path_size(u, w)
    {
    
    }
}

int main(int argc, char *argv[])
{
    Graph a(50);
    cout<<"Graph size:"<<a.V()<<endl;
    //a.add(0,1);
    a.add(0,1,10);
    a.add(0,2);
    cout<<"Weight of (0,2): "<<a.get_edge_value(0,2)<<endl;
    cout<<"Change weight of (0,2) to 10"<<endl;
    a.set_edge_value(0,2,10.5);

    cout<<"Weight of (0,2): "<<a.get_edge_value(0,2)<<endl;
    cout<<(a.adjacent(0,1)==0?"Not adjacent":"adjacent")<<endl;
    a.neighbors(0);
    return 0;
}

