using namespace std; 
#include <utility>
#include <vector>
#include <iostream>


struct Node { 
    int ID;
    int inform;
    //if have subordinants to report to other wise zero
    vector<Node *> child; 
}; 
//makes set up faster 
Node *newNode(int ID,int inform) 
{ 
   Node *temp = new Node; 
    temp-> inform = inform;
    temp->ID = ID; 
   return temp; 
} 


class Solution {    
    
public: 
    int hashFunction(int x,int N) { 
                if (x ==-1 ){
                    return N-1;
                }
                else {
                    return x;
                }
            } 

     
  
        void insertItem(int key,int ID, int N, vector<vector<pair<int,int>>>& table) { 
            int index = hashFunction(key,N); 
            table[index].push_back(key,ID);  
            cout << "Inserting:" << key << " at index: " << index << endl;
                

            } 
            
        void createtree(Node*root, vector<int>& manager, vector<int>& informTime,int k, int N){

        if (root -> inform == 0){
            return;
        }

        if (k ==0){
            vector<vector<pair<int,int>>> table; 
         for (int i =0; i<informTime.size();i++) {
            int key = hashFunction(i,N);
            insertItem (key,i,N,table);
             }
        }   
            k++;
            int key = root -> ID;
            int index = hashFunction(key,N); 
            vector<pair<int,int>>::iterator i;
           for (i = table[index].begin(); i < table[index].end(); i++){
               (root->child.push_back(newNode(i->second,informTime[i->second])));
                createtree(root->child.back(),manager,informTime,k,N);
    
                }
            return;
         }
            
            
        
        
        //in the case that we reach the end of this branch  
    

    
    //why DOESNT work
   
    
    int maxTime(struct Node *root) { 
        //base case and in the case that we get a dud 
        int maxtime = 0;
        if (root->inform == 0) {
           // cout<<"ROOT =0 "<<"ID: "<< root -> ID<<"inform time: " << root -> inform << endl;
            return maxtime; 
        }
    
        for (vector<Node*>::iterator it = root->child.begin(); it != root->child.end(); it++){
            //wrong
            //cout<<"FOR LOOP :"<<"ID:"<< root -> ID<<"inform time: " << root -> inform <<endl;
            //cout << "just began for loop"<<endl;
            maxtime = max(maxtime, maxTime(*it));
            //cout <<"just returned in the four loop,max Val: " << maxtime<<endl;
            }
       // cout << "final maxtime value " << maxtime<<endl;  
        maxtime += root -> inform;  
        cout << "final maxtime value " << maxtime<<endl;   
        return maxtime; 
        } 

    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if (n==1){
            return 0;
        }
   
        Node *root = newNode(headID,informTime[headID]);
        createtree(root,manager,informTime,0,n);
        return maxTime(root);
        }
    };

int main() {
    //n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
    //n= 15, head = 0, manager = [-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6] inform time = [1,1,1,1,1,1,1,0,0,0,0,0,0,0,0]
    vector<int> informTime;
    informTime.push_back(1);//1
    informTime.push_back(1);
    informTime.push_back(1);
    informTime.push_back(1);
    informTime.push_back(1);
    informTime.push_back(1);
    informTime.push_back(1);
    informTime.push_back(0);
    informTime.push_back(0);
    informTime.push_back(0);
    informTime.push_back(0);
    informTime.push_back(0);
    informTime.push_back(0);
    informTime.push_back(0);
    informTime.push_back(0);

    vector<int> manager; 
    manager.push_back(-1);
    manager.push_back(0);
    manager.push_back(0);
    manager.push_back(1);
    manager.push_back(1);
    manager.push_back(2);
    manager.push_back(2);
    manager.push_back(3);
    manager.push_back(3);
    manager.push_back(4);
    manager.push_back(4);
    manager.push_back(5);
    manager.push_back(5);
    manager.push_back(6);
    manager.push_back(6);

  
    Solution K; 
    Node *root = newNode(2,1);
    
    K.numOfMinutes(15,0,manager,informTime);

}