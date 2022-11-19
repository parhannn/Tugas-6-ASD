/*
    Nama    : Farhan Apri Kesuma
    NIM     : 121140179
    Kelas   : RC
    Algoritma & Struktur Data - Tree - Tugas 6
*/

/*Link source code : https://github.com/parhannn/Tugas-6-ASD.git*/

/*
    Soal:
        Buat kode program untuk menambah elemen pada pohon, jika elemen tersebut 
        kurang dari akarnya maka tempatkan di sebelah kiri, sedangkan jika lebih 
        besar dari atau sama dengan akar maka tempatkan di sebelah kanan
*/

#include <iostream>

using namespace std;

typedef int infotype;
typedef struct TNode *addressNode;
typedef addressNode BinTree;
typedef struct TNode
{
    infotype info;
    addressNode left;
    addressNode right;
    addressNode parent;
} Node;

addressNode root;

/* Selector */
#define Root(T)     (T)->info //{Nilai Akar pohon biner T}
#define Left(T)     (T)->left //{Subpohon kiri pohon biner T}
#define Right(T)    (T)->right //{Subpohon kanan pohon biner T}

#define Nil NULL

//untuk meletakkan infotype x pada Tree
addressNode Allocation(infotype x)
{
    addressNode NewNode;

    NewNode = new Node;
    NewNode->info = x;
    NewNode->left = Nil;
    NewNode->right = Nil;
    NewNode->parent = Nil;

    return NewNode;
}

//membuat Tree baru dengan infotype x sebagai parent
void CreateRoot(infotype x)
{
    if(root != Nil)
    {
        cout << "\nTree is already created!" << endl;
    }
    else
    {
        root = Allocation(x);
        cout << "\nData " << x << " successfully become root" << endl;
    }
}

//memasukkan data di sebelah kiri parent
addressNode InsertLeft(addressNode NodeParent, infotype x)
{
    if(NodeParent->left != Nil)
    {
        cout << "\nParent Node with value " << NodeParent->info << " already has child" << endl;

        return Nil;
    }
    else
    {
        addressNode NewNode;

        NewNode = Allocation(x);
        NodeParent->left = NewNode;
        NewNode->parent = NodeParent;
        cout << "InsertLeft " << x << " is succssesful on parent : " << NodeParent->info << endl;

        return NewNode;
    }
}

//memasukkan data di sebelah kanan parent
addressNode InsertRight(addressNode NodeParent, infotype x)
{
    if(NodeParent->right != Nil)
    {
        cout << "\nParent Node with value " << NodeParent->info << " already has child" << endl;

        return Nil;
    }
    else
    {
        addressNode NewNode;

        NewNode = Allocation(x);
        NodeParent->right = NewNode;
        NewNode->parent = NodeParent;
        cout << "InsertRight " << x << " is succssesful on parent : " << NodeParent->info << endl;

        return NewNode;
    }    
}

//memasukkan data ke dalam pohon
addressNode InsertElmt(BinTree NodeParent, infotype x)
{
    if(x >= NodeParent->info)//jika data lebih besar atau sama dengan data akar maka jalankan InsertRight
    {
        return InsertRight(NodeParent,x);
    }
    else//jika data lebih kecil dari data akar maka jalankan InsertLeft
    {
        return InsertLeft(NodeParent, x);
    }
}

void preOrder(BinTree T)
{
    if (T == Nil){
        return;
    }
    else
    {
        cout << Root(T) <<" ";
        preOrder(Left(T));
        preOrder(Right(T));
    }
    
}

/*
      Visualisasi
          _
          8         Level 1
      _       _
      2       9     Level 2
   _     _       _  
   1     4       9  Level 3
*/

int main()
{
    BinTree node2,node3,node4,node5,node6;//deklarasi tiap tiap node/element

    //pohon
    CreateRoot(8);//akar utama (tingkat paling atas)
    node2 = InsertElmt(root,2);//tingkat 2 child sebelah kiri dari parent 8
    node3 = InsertElmt(root,9);//tingkat 2 child sebelah kanan dari parent 8
    
    //sub pohon
    node4 = InsertElmt(node2,4);//tingkat 3 child sebelah kanan dari parent 2
    node5 = InsertElmt(node2,1);//tingkat 3 child sebelah kiri dari parent 2
    node6 = InsertElmt(node3,9);//tingkat 2 child sebelah kanan dari parent 9

    cout << endl;
    cout << "Pre Order: " ; preOrder(root);

}
