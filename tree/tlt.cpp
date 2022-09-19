int traverse(Node* root, int* tilt)
{
    if (!root)
        return 0;
 
    // Compute tilts of left and right subtrees
    // and find sums of left and right subtrees
    int left = traverse(root->left, tilt);
    int right = traverse(root->right, tilt);
 
    // Add current tilt to overall
    *tilt += abs(left - right);
 
    // Returns sum of nodes under current tree
    return left + right + root->val;
}
 
/* Driver function to print Tilt of whole tree */
int Tilt(Node* root)
{
    int tilt = 0;
    traverse(root, &tilt);
    return tilt;
}