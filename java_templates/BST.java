class node
{
	public int data;
	public node left, right;
	public node(int x)
	{
		data=x;
		left=null;
		right=null;
		
	}
};

class Tree
{
	private node root;
	public Tree()
	{
		root=null;
	}

	private node insert(node curr,int data)
	{
		if(curr==null)
		{
			curr = new node(data);
			return curr;
		}
		if(curr.data>data)
			curr.left=insert(curr.left,data);
		else
			curr.right=insert(curr.right,data);

		return curr;
	}

	public node get_root()
	{
		return root;
	}

	public void insert_to_tree(int data)
	{
		root=insert(root,data);
	}
	public void inorder(node curr)
	{
		if(curr==null)
			return;

		inorder(curr.left);
		System.out.println(curr.data);
		inorder(curr.right);
		
	}
};

class BST{
	public static void main(String[] args) {
		System.out.println("hi\n");
		Tree t= new Tree();
		t.insert_to_tree(5);
		t.insert_to_tree(2);
		t.insert_to_tree(7);
		t.insert_to_tree(6);
		t.insert_to_tree(4);
		t.inorder(t.get_root());
		
	}
	
};