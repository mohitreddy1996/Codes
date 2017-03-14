//
// Created by mohit on 14/3/17.
//

#include <bits/stdc++.h>

using namespace std;

// grid declaration.
const int width=60;
const int height=60;
// create a width x height 2D matrix.
static int graphMap[width][height];
// map with positions which have been tried out.
static int closed_nodes_map[width][height];
// map with positions which are not yet reached.
static int open_nodes_map[width][height]; // map of open (not-yet-tried) nodes
// direction map.
static int dir_map[width][height];
const int dir=8;
static int dx[dir]={1, 1, 0, -1, -1, -1, 0, 1};
static int dy[dir]={0, 1, 1, 1, 0, -1, -1, -1};

class node
{
private:
    int xPos, yPos;
    int level;
    int priority;  // score. f(n) = g(n) + h(n) in A* algorithm.

public:
    node(int xp, int yp, int d, int p) {
        xPos=xp;
        yPos=yp;
        level=d;
        priority=p;
    }

    int getxPos() const {
        return xPos;
    }

    int getyPos() const {
        return yPos;
    }

    int getLevel() const {
        return level;
    }

    int getPriority() const {
        return priority;
    }

    void updatePriority(const int & xDest, const int & yDest) {
        // the real score function update. heuristics = estimate.
        priority=level+estimate(xDest, yDest)*10; //A*
    }

    // score mechanism.
    void nextLevel(const int & i) {
        level += dir == 8 ? (i % 2 == 0 ? 10 : 14) : 10;
    }

    const int & estimate(const int & xDest, const int & yDest) const {
        static int xd, yd, d;
        xd=xDest-xPos;
        yd=yDest-yPos;
        // can use manhattan distance.
        d=static_cast<int>(sqrt(xd*xd+yd*yd));
        return(d);
    }
};

// keep lower priority nodes at beginning. (comparator operator)
bool operator<(const node & a, const node & b) {
    return a.getPriority() > b.getPriority();
}

// A-star algorithm.
void Initialise(){
    for(int y=0; y<height; y++)
    {
        for(int x=0; x<width; x++)
        {
            closed_nodes_map[x][y]=0;
            open_nodes_map[x][y]=0;
        }
    }
}

string pathFind( const int & xStart, const int & yStart, const int & xFinish, const int & yFinish )
{
    static priority_queue<node> openScoredNodes[2]; // list of open nodes
    static int pqInd; // pq index
    static node* n0;
    static node* m0;
    static int i, j, x, y, xdx, ydy;
    pqInd=0;

    Initialise();

    // create the start node and push into list of open nodes
    n0=new node(xStart, yStart, 0, 0);
    n0->updatePriority(xFinish, yFinish);
    openScoredNodes[pqInd].push(*n0);
    // mark the node as open.
    open_nodes_map[x][y]=n0->getPriority();

    // A* search
    while(!openScoredNodes[pqInd].empty())
    {
        n0=new node( openScoredNodes[pqInd].top().getxPos(), openScoredNodes[pqInd].top().getyPos(), openScoredNodes[pqInd].top().getLevel(), openScoredNodes[pqInd].top().getPriority());

        x=n0->getxPos();
        y=n0->getyPos();

        // remove from open node list and make it closed.
        openScoredNodes[pqInd].pop();
        open_nodes_map[x][y]=0;
        closed_nodes_map[x][y]=1;
        char c;
        string path = "";
        if(x==xFinish && y==yFinish)
        {
            while(!(x==xStart && y==yStart))
            {
                j=dir_map[x][y];
                c = '0' + (j + dir/2)%dir;
                x += dx[j];
                y += dy[j];
                path = c + path;
            }

            delete n0;
            while(!openScoredNodes[pqInd].empty())
                openScoredNodes[pqInd].pop();
            return path;
        }

        // generate moves (child nodes) in all possible directions
        for(i=0;i<dir;i++)
        {
            xdx=x+dx[i]; ydy=y+dy[i];

            if(!(xdx<0 || xdx>width-1 || ydy<0 || ydy>height-1 || graphMap[xdx][ydy]==1
                 || closed_nodes_map[xdx][ydy]==1))
            {
                // generate a child node
                m0=new node( xdx, ydy, n0->getLevel(),
                             n0->getPriority());
                m0->nextLevel(i);
                m0->updatePriority(xFinish, yFinish);

                // if it is not in the open list then add into that
                if(open_nodes_map[xdx][ydy]==0)
                {
                    open_nodes_map[xdx][ydy]=m0->getPriority();
                    openScoredNodes[pqInd].push(*m0);
                    // mark its parent node direction
                    dir_map[xdx][ydy]=(i+dir/2)%dir;
                }
                else if(open_nodes_map[xdx][ydy]>m0->getPriority())
                {
                    // update the priority info
                    open_nodes_map[xdx][ydy]=m0->getPriority();
                    // update the parent direction info
                    dir_map[xdx][ydy]=(i+dir/2)%dir;

                    // replace the node
                    // by emptying one pq to the other one
                    // except the node to be replaced will be ignored
                    // and the new node will be pushed in instead
                    while(!(openScoredNodes[pqInd].top().getxPos()==xdx &&
                            openScoredNodes[pqInd].top().getyPos()==ydy))
                    {
                        openScoredNodes[1-pqInd].push(openScoredNodes[pqInd].top());
                        openScoredNodes[pqInd].pop();
                    }
                    openScoredNodes[pqInd].pop(); // remove the wanted node

                    // empty the larger size pq to the smaller one
                    if(openScoredNodes[pqInd].size()>openScoredNodes[1-pqInd].size()) pqInd=1-pqInd;
                    while(!openScoredNodes[pqInd].empty())
                    {
                        openScoredNodes[1-pqInd].push(openScoredNodes[pqInd].top());
                        openScoredNodes[pqInd].pop();
                    }
                    pqInd=1-pqInd;
                    openScoredNodes[pqInd].push(*m0); // add the better node instead
                }
                else delete m0; // garbage collection
            }
        }
        delete n0; // garbage collection
    }
    return "";
}

int main()
{
    srand(time(NULL));

    // create empty map
    for(int y=0; y<width; y++)
    {
        for(int x=0; x<height; x++)
            graphMap[x][y]=0;
    }

    // fillout the map matrix with a '+' pattern
    for(int x=width/8; x < width*7/8; x++)
    {
        graphMap[x][height/2]=1;
    }
    for(int y=height/8; y < height*7/8;y++)
    {
        graphMap[width/2][y]=1;
    }

    // randomly select start and finish locations
    int xA, yA, xB, yB;

    xA=0;yA=0;xB=width-1;yB=height-1;

    cout<<"Start: "<<xA<<","<<yA<<endl;
    cout<<"Finish: "<<xB<<","<<yB<<endl;
    // get the route

    clock_t start = clock();
    string path = pathFind(xA, yA, xB, yB);
    clock_t end = clock();

    cout<<"Length of the path : "<<path.size()<<endl;
    double time_elapsed = double(end - start);
    cout<<"Time to calculate the route (ms): "<<time_elapsed<<endl;

    return(0);
}