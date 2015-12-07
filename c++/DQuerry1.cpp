#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node *L;
    node *R;
    node();
    node(int, node*, node*);
};

node :: node()
{
    val = 0;
    L = NULL;
    R = NULL;
}

node :: node(int a,node *b,node *c)
{
    val = a;
    L = b;
    R = c;
}
node *null;

int arr[30010];
int n;
node *tree[60010];
map<int,int> mp;

void input()
{
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
        scanf("%d", &arr[i]);
}

node* build_pst(node *parent,int LEFT,int RIGHT,int V,int toAdd)
{
    int MID;
    node *trav;
    trav = new node(0,null,null);
    if(LEFT < RIGHT)
    {

        MID = (LEFT + RIGHT)>>1;
        if(V <= MID)
        {
            trav->L = build_pst(parent->L, LEFT, MID, V, toAdd);
            trav->R = parent->R;
        }
        else
        {
            trav->L = parent->L;
            trav->R = build_pst(parent->R, MID + 1, RIGHT, V, toAdd);
        }
        trav->val = trav->L->val + trav->R->val;
        return trav;
    }
    if(LEFT == RIGHT)
    {
        trav->val = parent->val + toAdd;
        return trav;
    }
    delete trav;
    return null;
}


// void test(node *trav,int LEFT,int RIGHT)
// {
//     if(LEFT < RIGHT)
//     {
//        cout<< LEFT << "\t" << RIGHT << "\t" << trav->val << "\n";
//        int MID = (LEFT + RIGHT) >> 1;
//        test(trav->L, LEFT, MID);
//        test(trav->R, MID + 1, RIGHT);
//     }
//     else if(LEFT == RIGHT)
//     {
//        cout<< LEFT << "\t" << RIGHT << "\t" << trav->val << "\n";
//     }
// }

int query(node *trav,int LEFT,int RIGHT,int val)
{
    if(LEFT < RIGHT)
    {
        int MID;
        MID = (LEFT + RIGHT)>>1;
        if(val <= MID)
            return query(trav->L, LEFT, MID, val) + trav->R->val;
        else
            return query(trav->R, MID + 1, RIGHT, val);
    }

    if(LEFT == RIGHT)
    {
        return trav->val;
    }

    return 0;
}

int main()
{
    null = new node;
    null->L = null;
    null->R = null;
    input();
    int idx;
    tree[0] = null;
    for(int i = 0;i <= 2*n;i++)
    {
        tree[i] = null;
    }
    for(int i = 1;i <= n;i++)
    {
        if(mp.find(arr[i]) == mp.end())
        {
            tree[2*i] = build_pst(tree[2*(i-1)], 1, n, i, 1);
        }
        else
        {
            tree[2*i - 1] = build_pst(tree[2*(i-1)], 1, n, mp[arr[i]], -1);
            tree[2*i] = build_pst(tree[2*i-1], 1, n, i, 1);
        }
        mp[arr[i]] = i;
    }

    int q, l, r;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", query(tree[2*r], 1, n, l));
    }
    return 0;
}
