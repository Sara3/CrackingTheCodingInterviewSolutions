Find the maximum path from the top of the pyramid to the bottom. The only valid move is down a level to one of the two neighboring nodes. 
// down left and down right
Example:

   3
  7 4
 2 4 6
8 5 9 3

All possible paths:
3 + 7 + 2 + 8 = 20
3 + 7 + 2 + 5 = 17
3 + 7 + 4 + 5 = 19
3 + 7 + 4 + 9 = 23 <— This is the max path.
3 + 4 + 4 + 5 = 16
3 + 4 + 4 + 9 = 20
3 + 4 + 6 + 9 = 22
3 + 4 + 6 + 3 = 16

int DFS(root){
    if (root->left == null && root->right == null) {
       return root->value;
    }
    int leftSum = DFS(root->left);
    int rightSum = DSF(root->right);
    return max(leftSum, rightSum) + root->value;
}

 struct Node{
      int value;
      Node *left; 
      Node *right; 
 }

 
 int max =0; 
 int MaxSum(root){
 int sum =0; 
     if(root->left!=NULL){
         sum+=root->value;
     }
     maxSum(root->left);
     
     if(max<sum){
         max=sum;
     }
 }

 
 
 

