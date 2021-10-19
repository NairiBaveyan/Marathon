#ifndef BTREE_H
#define BTREE_H

//Header file BinaryTree.h
//of abstruct Binary tree

//#include "TreeExeption.h"
#include "TreeNode.h"   //Including the Declarations of
			//class TreeNode and class TreeItemType


typedef void(*FunctionType)(TreeItemType& an_item);


class BinaryTree
{
	private:
	TreeNode* m_root;//the root of the tree

	public:
		BinaryTree();
		BinaryTree(const TreeItemType &root_item);
		BinaryTree(const TreeItemType &root_item,
					BinaryTree & rigth_tree,
					BinaryTree & left_tree);
		BinaryTree(const BinaryTree& tree);
		virtual ~BinaryTree();
	
	public:  				//Binary operations with tree

	virtual bool IsEmpty()const;
	//throw(TreeExeption);
	virtual TreeItemType getRootData()const;
	//throw(TreeExeption);
	virtual void setRootData(const TreeItemType &new_nodes_data);
	//throw(TreeExeption);
	virtual void attachLeft(const TreeItemType &new_nodes_data);
	//throw(TreeExeption);
	virtual void attachRigth(const TreeItemType &new_nodes_data);
	//throw(TreeExeption);
	virtual void attacheLeftSubtree(BinaryTree &left_tree);
	//throw(TreeExeption);
	virtual void attacheRigthSubtree(BinaryTree &rigth_tree);
	//throw(TreeExeption);
	virtual void detachLeftSubtree(BinaryTree &left_tree);
	//throw(TreeExeption);
	virtual void detachRigthSubtree(BinaryTree &rigth_tree);
	//throw(TreeExeption);
	virtual BinaryTree getRigthSubtree()const;
	virtual BinaryTree getLeftSubtree()const;
	
	virtual void preorderTraverse(FunctionType visit);
	virtual void inorderTravese(FunctionType visit);
	virtual void postorderTravese(FunctionType visit);

	//overloaded operator  =

	virtual BinaryTree& operator= (const BinaryTree& rhs);

	//protected Constructor
	
	protected:


	BinaryTree(TreeNode* node_ptr);    //Constructor

	void copyTree(TreeNode* tree_ptr,TreeNode*& new_tree_ptr)const;
	//new_tree_ptr = tree_ptr
	//Do copy the three with root,if cant do copy throw TreeExeption 	
	void destroyTree(TreeNode*& tree_ptr);
	//Frees the memory used by the tree.
	// The next two functions retrieve and set the value
	// private member of the root node
	TreeNode* getRootPtr()const;
	void setRootPtr(TreeNode* new_root_ptr);

	// The next two functions retrieve and set values
	// of pointers to the left and right child nodes
	// of root node
	void setChildPtrs(TreeNode* node_ptr,
					  TreeNode* leftChildPtr,
					  TreeNode* rigthChildPtr)const;
	void getChildPtrs(TreeNode* node_ptr,
					  TreeNode* leftChildPtr,
					  TreeNode* rigthChildPtr);//????
	void preorder(TreeNode* tree_ptr,FunctionType visit);
	void inorder(TreeNode* tree_ptr,FunctionType visit);
	void postorder(TreeNode* tree_ptr,FunctionType visit);

};


#endif 
