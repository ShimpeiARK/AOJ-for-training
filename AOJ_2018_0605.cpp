#include <iostream>
using namespace std;
static const int MAX =100;
static const int INFTY =(1<<21);
static const int WHITE =0;
static const int GRAY =1;
static const int BLACK =2;

int n, M[MAX][MAX];

int dijkstra(){
  int minv;
  int d[MAX],color[MAX];

  for(int i=0;i<n;i++){
    d[i]=INFTY;
    color[i]=WHITE;
  }
  d[0]=0;
  color[0]=GRAY;
  while(1){
    minv=INFTY;
    int u=-1;
    for(int i=0;i<n;i++){
      if(minv>d[i] && color[i] !=BLACK){
        u=i;
        minv=d[i];
      }
    }
    if(u==-1)break;
    color[u]=BLACK;
    for(int v=0;v<n;v++){
      if(color[v] != BLACK && M[u][v]!=INFTY){
        if(d[v]> d[u]+M[u][v]){
          d[v]=d[u]+M[u][v];
          color[v]=GRAY;
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    cout << i << " " << (d[i]==INFTY? -1:d[i]) << endl;
  }
}

int main(){
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      M[i][j]=INFTY;
    }
  }
  int k,c,u,v;
  for(int i=0;i<n;i++){
    cin >> u >> k;
    for(int j=0;j<k;j++){
      cin >> v >> c;
      M[u][v]=c;
    }
  }

  dijkstra();
  return 0;
}

==========探索技=================
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

struct Node{
  int key; /*値とボンド*/
  Node *right, *left, *parent;
};

Node *root, *NIL;

Node *find(Node* u,int k){
  while(u!=NIL && k!= u->key){
    if(k < u->key) u=u->left;
    else u=u->right;
  }
  return u;
}

void insert(int k){
  Node *y=NIL;
  Node *x=root;
  Node *z;

  z =(Node *)malloc(sizeof(Node));
  z->key=k;
  z->left=NIL;
  z->right=NIL;

  while(x!=NIL){
    y=x;
    if(z->key < x->key){
      x=x->left;
    }else {
      x=x->right;
    }
  }
  z->parent=y;

  if(y==NIL){
    root =z;
  } else{
    if(z->key < y->key){
      y->left =z;
    }else{
      y->right =z;
    }
  }
}

void Inorder(Node *u){
  if(u==NIL) return;
  Inorder(u->left);
  printf(" %d", u->key );
  Inorder(u->right);
}

void preorder(Node *u){
  if(u==NIL) return;
  printf(" %d", u->key );
  preorder(u->left);
  preorder(u->right);
}

int main(){
  int n,i,x;
  string com;

  scanf("%d",&n );
  for(i=0;i<n;i++){
    cin >> com;
    if(com[0]=='f'){
      scanf("%d", &x );
      Node *t=find(root,x);
      if(t!=NIL)printf("yes\n");
      else printf("no\n");
      continue;
    }
    if(com=="insert"){
      scanf("%d",&x );
      insert(x);
    } else if (com=="print"){
      Inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    }
  }
  return 0;
}

===========================

void print(map<string,int>T){
  map<string,int>:: iterator it;
  cout << T.size() << endl;
  for(it=T.begin();it!=T.end();it++){
    pair<string,int> item=*it;
    cout << item.first << "-->" << item.second << endl;
  }
}

int main(){
  map<string,int> T;
  T["red"]=32;
  print(T);
}
===========================
void print(set<int> S){
  cout << S.size() << ":";
  for( set<int>::iterator it = S.begin();it!=S.end();it++){
    cout << " " << (*it);
  }
  cout << endl;
}

int main(){
  set<int> S;
  S.insert(10);
  S.insert(110);
  S.insert(102);
  print(S);

  if(S.find(19)==S.end()) cout << "NO";
  return 0;
}
===========================
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
#define MAX 100000

int parent(int i){return i/2;}
int left(int i){return i*2;}
int right(int i){return i*2+1;}

int main(){
  int H,i,A[MAX+1];
  cin>>H;
  for(int i=1;i<=H;i++){
    cin>> A[i];
  }
  for(int i=1;i<=H;i++){
    cout << "node " << i << ": key = " << A[i] << ", ";
    if(parent(i)>=1) cout << "parent key = " << A[parent(i)] <<", ";
    if(left(i)<=H) cout << "left key = " << A[left(i)] <<", ";
    if(right(i)<=H) cout << "right key = " << A[right(i)] <<", ";
    cout << endl;
  }
  return 0;
}
===========================
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
#define MAX 20000000

int H,A[MAX+1];

int parent(int i){return i/2;}
int left(int i){return i*2;}
int right(int i){return i*2+1;}

void maxheapify(int i){
  int l, r ,largest;
  l=2*i;
  r=2*i+1;

  if(l<=H && A[l]>A[i])largest=l;
  else largest=i;
  if(r<=H && A[r]>A[largest])largest=r;

  if(largest !=i){
    swap(A[i],A[largest]);
    maxheapify(largest);
  }
}

int main(){
  cin>>H;
  for(int i=1;i<=H;i++){
    cin>> A[i];
  }
  for(int i=H/2;i>=1;i--) maxheapify(i);
  for(int i=1;i<=H;i++){
    cout << " " << A[i];
  }
  cout << endl;
  return 0;
}
===========================
#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 20000000
#define INFTY (1<<30)

int H,A[MAX+1];

void maxheapify(int i){
  int l, r ,largest;
  l=2*i;
  r=2*i+1;

  if(l<=H && A[l]>A[i])largest=l;
  else largest=i;
  if(r<=H && A[r]>A[largest])largest=r;

  if(largest !=i){
    swap(A[i],A[largest]);
    maxheapify(largest);
  }
}

int extract(){
  int maxv;
  if(H<1) return -INFTY;
  maxv=A[1];
  A[1]=A[H];
  H--;
  maxheapify(1);
  return maxv;
}

void increaseKey(int i,int key){
  if(key<A[i])return;
  A[i]=key;
  while(i>1 && A[i/2]<A[i]){
    swap(A[i],A[i/2]);
    i/=2;
  }
}

void insert(int key){
  H++;
  A[H]= -INFTY;
  increaseKey(H,key);
}

int main(){
  int key;
  char com[10];
  while(1){
    scanf("%s",com);
    if(com[0]=='e' && com[1]=='n') break;
    if(com[0]=='i'){
      scanf("%d",&key);
      insert(key);
    }else{
      printf("%d\n",extract());
    }
  }
  return 0;
}

===========================
===========================
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
#define MAX 100000

int main(){
  int n; cin >> n;
  int F[50];
  F[0]=F[1]=1;
  for(int i=2;i<=n;i++)F[i]=F[i-1]+F[i-2];
  cout << F[n] << endl;
  return 0;
}

===========================
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define MAX 100000

static const int N =1000;

int lcs(string X,string Y){
  int c[N+1][N+1];
  int m=X.size();
  int n=Y.size();
  int ans=0;
  X= ' '+X;
  Y= ' '+Y;
  for(int i;i<=m;i++)c[i][0]=0;
  for(int j;j<=n;j++)c[0][j]=0;

  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(X[i]==Y[j]){
        c[i][j]=c[i-1][j-1]+1;
      }
      else{
        c[i][j]=max(c[i-1][j],c[i][j-1]);
      }
      ans=max(ans,c[i][j]);
    }

  }
  return ans;
}

int main(){
  string s1,s2;
  int n; cin >> n;
  for(int i=0;i<n;i++){
    cin >> s1>> s2;
    cout << lcs(s1,s2) << endl;
  }
  return 0;
}
===========================
===========================
===========================
===========================
===========================
===========================
===========================
===========================
===========================
#include <iostream>
using namespace std;
static const int MAX =100;
static const int INFTY =(1<<21);
static const int WHITE =0;
static const int GRAY =1;
static const int BLACK =2;

int n, M[MAX][MAX];

int prim(){
  int u,minv;
  int d[MAX],p[MAX],color[MAX];

  for(int i=0;i<n;i++){
    d[i]=INFTY;
    p[i]=-1;
    color[i]=WHITE;
  }
  d[0]=0;

  while(1){
    minv=INFTY;
    u=-1;
    for(int i=0;i<n;i++){
      if(minv>d[i] && color[i] !=BLACK){
        u=i;
        minv=d[i];
      }
    }
    if(u==-1)break;
    color[u]=BLACK;
    for(int v=0;v<n;v++){
      if(color[v] != BLACK && M[u][v]!=INFTY){
        if(d[v]>M[u][v]){
          d[v]=M[u][v];
          p[v]=u;
        }
      }
    }
  }
  int sum=0;
  for(int i=0;i<n;i++){
    if(p[i]!=-1)sum+=M[i][p[i]];
  }
  return sum;
}

int main(){
  cin >> n;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    int e; cin >> e;
    M[i][j]= (e==-1)? INFTY:e;
    }
  }

  cout << prim() << endl;
}
===========================
===========================
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 100000

static const int N =100;
static const int INFTY =(1<<21);
int n,M[N][N];
int d[N];

void bfs(int s){
  queue<int> q;
  q.push(s);
  for(int i=0;i<n;i++) d[i]=INFTY;
  d[s]=0;
  int u;
  while(!q.empty()){
    u=q.front();
    q.pop();
    for(int v=0;v<n;v++){
      if(d[v]!=INFTY)continue;
      if(M[u][v]==1){
        d[v]=d[u]+1;
        q.push(v);
      }
    }
  }
  for(int i=0;i<n;i++){
    cout << i+1 << " " << ((d[i]==INFTY)? (-1):d[i])<< endl;
  }
}

int main(){
  int u,k,v;
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) M[i][j]=0;
  }

  for(int i=0;i<n;i++){
    cin >>u>>k;
    u--;
    for(int j=0;j<k;j++){
      cin >> v;
      v--;
      M[u][v]=1;
    }
  }
  bfs(0);
  return 0;
}

===========================
static const int N=100;
static const int WHITE=0;
static const int GRAY=1;
static const int BLACK=2;

int n, M[N][N];
int color[N],d[N],f[N],tt;
int nt[N];

int next(int u){
  for(int v=nt[u]; v<n; v++){
    nt[u]=v+1;
    if(M[u][v]) return v;
  }
  return -1;
}

void dfs_visit(int r){
  for(int i=0;i<n;i++) nt[i]=0;
  stack<int> S;
  S.push(r);
  color[r]=GRAY;
  d[r]=++tt;
  while( !S.empty() ){
    int u=S.top();
    int v=next(u);
    if( v!=-1 ){
      if(color[v]==WHITE){
        color[v]=GRAY;
        d[v]=++tt;
        S.push(v);
      }
    }else{
        S.pop();
        color[u]=BLACK;
        f[u]=++tt;
    }
  }
}

void dfs(){
  for(int i=0;i<n;i++){
    color[i]=WHITE;
    nt[i]=0;
  }
  tt=0;

  for(int u=0;u<n;u++){
    if(color[u]==WHITE) dfs_visit(u);
  }
  for(int i=0;i<n;i++){
    cout << i+1 << " " << d[i] << " " << f[i] << endl;
  }
}

int main(){
  int u,k,v;
  cin >> n;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      M[i][j]=0;
    }
  }

  for(int i=0;i<n;i++){
    cin >> u >> k;
    u--;
    for(int j=0;j<k;j++){
      cin >> v;
      v--;
      M[u][v]=1;
    }
  }
  dfs();
  return 0;
}
===========================

int main(){
  int n;
  cin >>n;
  int A[n+2][n+2]={0};
  int t,k,l;
  for(int i=1;i<=n;i++){
    cin >> t >> k;
    for(int j=1;j<=k;j++){
      cin >> l;
      A[i][l]=1;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(j-1) cout << " ";
      cout << A[i][j];
    }
    cout << endl;
  }
  return 0;
}
===========================
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

static const int MAX =100000;
static const int NIL=-1;

int n;
vector<int> G[MAX];
int color[MAX];

void dfs(int r,int c){
  stack<int> S;
  S.push(r);
  color[r]=c;
  while(!S.empty()){
    int u=S.top();
    S.pop();
    for(int i=0;i<G[u].size();i++){
      int v=G[u][i];
        if(color[v]==NIL){
        color[v]=c;
        S.push(v);
        }
    }
  }
}

void assignColor(){
  int id=1;
  for(int i=0;i<n;i++) color[i]=NIL;
  for(int u=0;u<n;u++){
    if(color[u]==NIL)dfs(u,id++);
  }
}

int main (){
  int s,t,m,q;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }

  assignColor();
  cin >>q;
  for(int i=0;i<q;i++){
    cin >> s >> t;
    if(color[s]==color[t]){
      cout <<"yes"<< endl;
    }else{
      cout << "no" <<endl;
    }
  }

  return 0;
}
===========================
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define MAX 100000

static const int N =100;

int main(){
  int n,p[N+1],m[N+1][N+1];
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >>p[i-1]>>p[i];
  }
  for(int i=1;i<=n;i++)m[i][i]=0;

  for(int l=2;l<=n;l++){
    for(int i=1;i<=n-l+1;i++){
      int j=i+l-1;
      m[i][j]=(1<<21);
      for(int k=i;k<=j-1;k++){
        m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
      }
    }
  }
  cout << m[1][n] << endl;
  return 0;
}


===========================
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 100000

static const int N =100;
static const int INFTY =(1<<21);
int n,M[N][N];
int d[N];

void bfs(int s){
  queue<int> q;
  q.push(s);
  for(int i=0;i<n;i++) d[i]=INFTY;
  d[s]=0;
  int u;
  while(!q.empty()){
    u=q.front();
    q.pop();
    for(int v=0;v<n;v++){
      if(d[v]!=INFTY)continue;
      if(M[u][v]==1){
        d[v]=d[u]+1;
        q.push(v);
      }
    }
  }
  for(int i=0;i<n;i++){
    cout << i+1 << " " << ((d[i]==INFTY)? (-1):d[i])<< endl;
  }
}

int main(){
  int u,k,v;
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) M[i][j]=0;
  }

  for(int i=0;i<n;i++){
    cin >>u>>k;
    u--;
    for(int j=0;j<k;j++){
      cin >> v;
      v--;
      M[u][v]=1;
    }
  }
  bfs(0);
  return 0;
}

===========================
#include <cstdio>
#define MAX 10005
#define NIL -1

typedef struct pp{int p,l,r;} Node;
Node T[MAX];
int n;

/*先行巡回*/

void preParse(int u){
  if(u==NIL) return;
  printf(" %d",u);
  preParse(T[u].l);
  preParse(T[u].r);
}

void inParse(int u){
  if(u==NIL) return;
  inParse(T[u].l);
  printf(" %d",u);
  inParse(T[u].r);
}

void postParse(int u){
  if(u==NIL) return;
  postParse(T[u].l);
  postParse(T[u].r);
  printf(" %d",u);
}

int main(){
  int i,v,l,r,root;
  scanf("%d", &n);
  for(i=0;i<n;i++) T[i].p=NIL;
  for(i=0;i<n;i++){
    scanf("%d %d %d", &v, &l, &r);
    T[v].l=l;
    T[v].r=r;
    if(l!=NIL) T[l].p=v;
    if(r!=NIL) T[r].p=v;
  }

  for(i=0;i<n;i++) if(T[i].p==NIL) root =i;
  printf("Preorder\n");
  preParse(root);
  printf("\n");
  printf("Inorder\n");
  inParse(root);
  printf("\n");
  printf("Postorder\n");
  postParse(root);
  printf("\n");

  return 0;
}

==========完全二分木=================
#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;
map <int ,int> mpa,mpb;
#define MAX 10005
#define NIL -1

struct Node {int parent,left,right;};

Node T[MAX];
int n, D[MAX],H[MAX];

void setDepth(int u, int d){
  if(u == NIL) return;
  D[u] = d;
  setDepth(T[u].left,d+1);
  setDepth(T[u].right,d+1);
}

int setHigh(int u){
  int h1=0, h2=0;
  if(T[u].left != NIL) h1=setHigh(T[u].left)+1;
  if(T[u].right != NIL) h2=setHigh(T[u].right)+1;

  return H[u]=(h1>h2 ? h1:h2);
}

int getSibling(int u){
  if(T[u].parent==NIL) return NIL;
  if(T[T[u].parent].left !=u && T[T[u].parent].left !=NIL)
    return T[T[u].parent].left;
  if(T[T[u].parent].right !=u && T[T[u].parent].right !=NIL)
    return T[T[u].parent].right;
  return NIL;
}

void print(int u){
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].parent);
  printf("sibling = %d, ", getSibling(u));
  int deg=0;
  if(T[u].left!=NIL) deg++;
  if(T[u].right!=NIL) deg++;
  printf("degree = %d, ", deg);
  printf("depth = %d, ", D[u]);
  printf("height = %d, ", H[u]);

  if(T[u].parent==NIL){
    printf("root\n");
  }else if(T[u].left==NIL && T[u].right==NIL ){
    printf("leaf\n");
  }else{
    printf("internal node\n");
  }
}

int main(){
  int v,l,r,root=0;
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++) T[i].parent=NIL;//初期化

  for(i=0;i<n;i++){
  scanf("%d %d %d",&v,&l,&r);
  T[v].left=l;
  T[v].right=r;
  if(l !=NIL) T[l].parent=v;
  if(r !=NIL) T[r].parent=v;
  }

  for(i=0;i<n;i++) if(T[i].parent==NIL) root=i;

  setDepth(root,0);
  setHigh(root);

  for(i=0;i<n;i++) print(i);

  return 0;
}
===========================
#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;
map <int ,int> mpa,mpb;
#define MAX 100005
#define NIL -1

struct Node {int p,l,r;};

Node T[MAX];
int n, D[MAX];

void print(int u){
  int i ,c;
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].p << ", ";
  cout << "depth = " << D[u] << ", ";
  if(T[u].p==NIL) cout << "root, ";
  else if(T[u].l==NIL) cout << "leaf, ";
  else cout << "internal node, ";

  cout << "[";
  for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r){
    if(i) cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}

int rec(int u,int p){
  D[u]=p;
  if(T[u].r !=NIL) rec(T[u].r,p);//深さを入れてく
  if(T[u].l !=NIL) rec(T[u].l,p+1);
}

int main(){
  int i,j,d,v,c,l,r;
  cin >> n;
  for(i=0;i<n;i++) T[i].p=T[i].l=T[i].r =NIL;//初期化

  for(i=0;i<n;i++){
    cin >> v >> d;
    for(j=0;j<d;j++){
      cin >> c;
      if(j==0) T[v].l=c;
      else T[l].r=c;
      l=c;
      T[c].p=v;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].p==NIL) r=i;
  }
  rec(r,0);
  for(i=0;i<n;i++) print(i);

  return 0;
}


==========AOJ=================
