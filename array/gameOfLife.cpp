#include <iostream>
#include <vector>
#include <stack>
#include <string> 
#include <map>


using namespace std;

//function declarations
vector<vector<int> > gameOfLife(vector< vector<int> >*);
int update(int, int, vector<vector<int> >*);
int applyRule(int , int);
void printBoard(vector<vector<int> > *board);


int main(){
    int x, y, element;
    cin >> x >> y; // x - rows, y - columns
    vector<vector<int> >* board = new vector<vector<int> >(x, vector<int>(y));
    
    // process input
    for (int i = 0; i<x; i++){
        for (int j=0; j<y; j++){
            cin >> element;
            (*board)[i][j] = element;
        }
    }

    // tests
    
    cout<<endl<< "old board"<<endl;
    printBoard(board);
    cout << endl <<endl;
    
    vector<vector<int> > newBoard = vector<vector<int> >(x, vector<int>(y));
    newBoard = gameOfLife(board);
    vector<vector<int> >* p = &newBoard;
    
    cout<<"new board"<<endl;
    printBoard(p);
    cout<<endl;
    
    return 0;
}

vector<vector<int> > gameOfLife(vector<vector<int> >* board){
    auto newBoard((*board)); // init new board
    for (int i = 0; i<newBoard.size(); i++){
        for (int j=0; j<newBoard[i].size(); j++){
            newBoard[i][j] = update(i,j,board);
        }
    }
    return newBoard;
}

// given (i,j) returns the updated (i,j)
int update(int i, int j, vector<vector<int> >* board){
    
    int x = (*board).size();
    int y = (*board)[i].size();
    int neighborStatus = 0;
    int currentStatus = (*board)[i][j];
    
    // define which neighbors are valid to consider
    vector<int> v0{i-1,j-1}, v1{i,j-1}, v2{i+1,j-1}, v3{i-1,j}, v4{i+1,j},
                v5{i-1,j+1}, v6{i,j+1}, v7{i+1,j+1};
    
    map <int, vector<int> > neighborMap = {
        {0, v0},{1, v1},{2, v2},{3, v3},
        {4, v4},{5, v5},{6, v6},{7, v7}
    };
    
    vector<int> neighborFlags = vector<int>(8,1);
    
    // corner cases
    if (i == 0){ //  left edge
        neighborFlags[0] = 0;
        neighborFlags[3] = 0;
        neighborFlags[5] = 0;
    }
    
    if (i == x-1){ // right edge
        neighborFlags[2] = 0;
        neighborFlags[4] = 0;
        neighborFlags[7] = 0;
    }
    
    if (j == 0){ // top
        neighborFlags[0] = 0;
        neighborFlags[1] = 0;
        neighborFlags[2] = 0;
    }
    
    if (j == y-1){ // bottom
        neighborFlags[5] = 0;
        neighborFlags[6] = 0;
        neighborFlags[7] = 0;
    }
    
    // get neighbor status
    for (int k = 0; k<8; k++){
        if (neighborFlags[k] == 1){
            int n1 = (neighborMap[k])[0];
            int n2 = (neighborMap[k])[1];
            neighborStatus += (*board)[n1][n2];
        }
    }
    return applyRule(currentStatus,neighborStatus);
}


int applyRule(int currentStatus, int neighborStatus){
    if (currentStatus == 1 && neighborStatus < 2){
        return 0;
    }
    if (currentStatus == 1 && neighborStatus  <= 3 ){
        return 1;
    }
    if (currentStatus == 1 && neighborStatus > 3){
        return 0;
    }
    if (currentStatus == 0 && neighborStatus == 3){
        return 1;
    }
    return 0;
}

void printBoard(vector<vector<int> >* board){
    for (int i = 0; i<(*board).size(); i++){
        cout << endl;
        for (int j = 0; j<(*board)[i].size(); j++){
            cout << (*board)[i][j] << " ";
        }
    }
}

