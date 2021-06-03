
**<u>AVL-based BST with custom node data augmentation feature</u>**

It is a AVL tree based BST library with added functionality to augment data in the tree node and provides you the flexibility to create augmented BST such as <b>Interval tree</b>.<br />
You can design your own node structure alongwith updates function necessary after each insertion and deletion operation for the augmented node data and this library will create the rest necessary requirements for balanced BST<br /><br />
**<u>How to use this library for creating your custom augmented balanced BST</u>**

To create your augmented node structure design, you need to do following steps:
* Navigate to <b>custom.cpp</b>
* Add the extra node variables for your BST in <b>struct Node</b>
* Define getKey function by returning node's key required for operation in BST
* Define the augmentationUpdate function that defines the update required for a node if the same data for its children are known.


To help you understand better about how and what these functions do, i have provided the same for interval tree in <b>interval_tree.cpp</b>.<br /><br />
**<u>How to use the library in your cpp files</u>**

Finally after modifying <b>custom.cpp</b>, include <b>avl_update.h</b> in your cpp file say <b>main.cpp</b> where you want to use your custom-defined BST and type <b>make arg1=main.cpp</b>. This will create executable <b>a.out</b> to run your <b>main.cpp</b> program.
