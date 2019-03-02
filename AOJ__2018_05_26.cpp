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
#define MAX 100000
int A[MAX],n;

int partition(int p,int r){
  int i,j,x,t;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j]<=x){
      i++;
      t=A[i];A[i]=A[j];A[j]=t;
    }
  }
  t=A[i+1];A[i+1]=A[r];A[r]=t;
  return i+1;
}

int main(){
  cin >> n;
  int q;
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  q=partition(0,n-1);
  for(int i=0;i<n;i++){
    if(i) cout << " ";
    if(i==q) cout << "[";
    cout << A[i];
    if(i==q) cout << "]";
  }
  cout << endl;
  return 0;
}


==========AOJ=================
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
using ll = long long;
map <int ,int> mpa,mpb;

int main (){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans=0;
  for(int i=0;i<N;i++){
  }

  cout << ans << endl;
  return 0;
}
===========================
int main (){
  int N;
  cin >> N;
  int R[N+2];
  int ans=-9999999999999;
  for(int i=0;i<N;i++){
    cin >> R[i];
  }
  int min_a=R[0];
  for(int i=1;i<N;i++){
    ans=max(R[i]-min_a,ans);
    min_a=min(min_a,R[i]);
  }

  cout << ans << endl;
  return 0;
}
===========================

int a[100];
int n;

void trace(int N){
  for(int i=0;i<N;i++){
    cout << a[i];
    if(i!=N-1){
      cout << " ";
    }
  }
  cout << endl;
}

void insertionSort(int N){
  for(int i=1;i<N;i++){
    int v=a[i];
    int j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    trace(N);
  }
}

int main (){
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  trace(n);
  insertionSort(n);
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

void trace(int a, int n){
  for(int i=0;i<n;i++){
    if(i) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

int bubbleSort(int a, int n){
  int cnt=0;
  int flag=1;
  int v=0;
  while(flag){
    int i=0;
    flag=0;
    for(int j=n-1;i+1<=j;j--){
      if(a[j]<a[j-1]){
        v=a[j];
        a[j]=a[j-1];
        a[j-1]=v;
        cnt++;
        flag=1;
      }
    }
    i++;
  }
  return cnt;
}

int main (){
  int N;
  cin >> N;
  int B[N];
  for(int i=0;i<N;i++){
    cin >> B[i];
  }
  int ans = bubbleSort(B, N);
  trace(B, N);
  cout << ans << endl;
  return 0;
}
===========================

void trace(int a[], int n){
  for(int i=0;i<n;i++){
    if(i) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

int selectionSort(int A[], int n){
  int minv=0;
  int cnt=0;
  for(int i=0;i<n;i++){
    minv=i;
    for(int j=i;j<n;j++){
      if(A[minv]>A[j]){
        minv=j;
      }
    }
    swap(A[i],A[minv]);
    if(i!=minv) cnt++;
  }
  return cnt;
}

int main (){
  int N;
  cin >> N;
  int B[N];
  int ans=0;
  for(int i=0;i<N;i++){
    cin >> B[i];
  }
  ans=selectionSort(B,N);
  trace(B,N);
  cout << ans << endl;
  return 0;
}
===========================
struct Card{ char suit, value;};

void trace(struct Card A[], int n){
  for(int i=0;i<n;i++){
    if(i) cout << " ";
    cout << A[i].suit << A[i].value;
  }
  cout << endl;
}

int selectionSort(struct Card A[], int n){
  int minv=0;
  int cnt=0;
  for(int i=0;i<n;i++){
    minv=i;
    for(int j=i;j<n;j++){
      if(A[minv].value > A[j].value){
        minv=j;
      }
    }
    swap(A[i],A[minv]);
    if(i!=minv) cnt++;
  }
  return cnt;
}

int bubbleSort(struct Card A[], int n){
  int cnt=0;
  int flag=1;
  int v=0;
  while(flag){
    int i=0;
    flag=0;
    for(int j=n-1;i+1<=j;j--){
      if(A[j].value < A[j-1].value){
        Card t=A[j];A[j]=A[j-1];A[j-1]=t;
        cnt++;
        flag=1;
      }
    }
    i++;
  }
  return cnt;
}

bool isStable(struct Card C1[], struct Card C2[], int n){
  for(int i=0;i<n;i++){
    if(C1[i].suit !=C2[i].suit) return false;
  }
  return true;
}

int main (){
  Card C1[100],C2[100];
  int N;
  char ch;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> C1[i].suit >> C1[i].value;
  }
  for(int i=0;i<N;i++) C2[i]=C1[i];

  bubbleSort(C1,N);
  selectionSort(C2,N);

  trace(C1,N);
  cout << "Stable" << endl;

  trace(C2,N);
  if(isStable(C1,C2,N)){
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }
  return 0;
}
===========================
nt top, S[1000];

void push(int x){
  S[++top]=x;
}

int pop(){
  top--;
  return S[top+1];
}

int main (){
  int a,b;
  top=0;
  char s[100];
  while(scanf("%s", s ) !=EOF){
    if(s[0]=='+'){
      b=pop();
      a=pop();
      push(a+b);
    }
    else if(s[0]=='-'){
      b=pop();
      a=pop();
      push(a-b);
    }
    else if(s[0]=='*'){
      b=pop();
      a=pop();
      push(a*b);
    }
    else{
      push(atoi(s));
    }
  }
  printf("%d\n", pop());
  return 0;
}


===========================
#define LEN 100005

typedef struct pp{
  char name[100];
  int t;
} P;

P Q[LEN];
int head, tail, n;

void enqueue(P x){
  Q[tail]=x;
  tail=(tail+1)%LEN;
}

P dequeue(){
  P x=Q[head];
  head=(head+1)%LEN;
  return x;
}

int min(int a, int b){
  return a<b?a:b;
}

int main(){
  int elaps=0;
  int i,q,c;
  P u;
  scanf("%d %d", &n,&q);

  for(int i=1;i<=n;i++){
    scanf("%s",Q[i].name);
    scanf("%d",&Q[i].t);
  }
  head =1, tail=1+n;

  while(head!=tail){
    u=dequeue();
    c=min(q,u.t);
    u.t-=c;
    elaps+=c;
    if(u.t>0)enqueue(u);
    else{
      printf("%s %d\n", &u.name,elaps);
    }
  }
  return 0;
}
===========================
int search(int A[], int n, int key){
  int i=0;
  while(A[i] !=key){
    i++;
    if(i==n){
      return 0;
    }
  }
  return i !=n;
}

int main (){
  int N;
  cin >> N;
  int A[1000001];
  for(int i=0;i<N;i++){
    cin >> A[i];
  }

  int q;
  cin >> q;
  int t,ans;
  for(int i=0;i<q;i++){
    cin >> t;
    if(search(A,N,t)){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
===========================

int A[100002], n;

int search(int z){
  int co=0;
  int left=0;
  int right=n;
    while(left<right){
      int mid=(left+right)/2;
      if(A[mid]==z) return 1;
      if(A[mid]>z) right=mid;
      else if(A[mid]<z) left=mid+1;
    }
  return 0;
}

int main (){
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  int q,t;
  cin >> q;
  int ans=0;
  for(int i=0;i<q;i++){
    cin >> t;
    if (search(t)) ans++;
  }
  cout << ans << endl;
  return 0;
}

===========================

#define M 1046527
#define NIL (-1)
#define L 14

char H[M][L];

int getChar(char ch){
  if(ch=='A') return 1;
  else if(ch=='C') return 2;
  else if(ch=='G') return 3;
  else if(ch=='T') return 4;
  else return 0;
}
long long getKey(char str[]){
  long long sum=0,p=1;
  for(int i=0;i<strlen(str);i++){
    sum+=p*(getChar(str[i]));
    p*=5;
  }
  return sum;
}

int h1(int key){return key%M;}
int h2(int key){return 1+(key%(M-1));}

int find(char str[]){
  long long key,i,h;
  key=getKey(str);
  for(i=0;;i++){
    h=(h1(key)+i*h2(key))%M;
    if(strcmp(H[h],str)==0) return 1;
    else if(strlen(H[h])==0) return 0;
  }
  return 0;
}

int insert(char str[]){
  long long key, i, h;
  key=getKey(str);
  for(i=0;;i++){
    h=(h1(key)+i*h2(key))%M;
    if(strcmp(H[h],str)==0) return 1;
    else if(strlen(H[h])==0){
      strcpy(H[h],str);
      return 0;
    }
  }
  return 0;
}

int main (){
  int i, n,h;
  char str[L],com[9];
  for(int i=0;i<M;i++) H[i][0]= '\0';
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> com >> str;
    if(com[0]=='i'){
      insert(str);
    } else{
      if(find(str)){
        cout << "yes" << endl;
      }
      else{
        cout << "no" << endl;
      }
    }
  }
  return 0;
}
===========================
int N ,A[51];

int solve(int i, int m){
  if(m==0) return 1;
  if(i>=N) return 0;
  int ans=solve(i+1, m) || solve(i+1, m-A[i]);
  return ans;
}

int main(){
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  int q,t;
  cin >> q;
  for(int i=0;i<q;i++){
    cin >> t;
    if(solve(0,t)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
===========================
struct Point{double x,y;};

void koch(int n, Point a, Point b){
  if(n==0) return;
  Point s, t, u;
  double th=M_PI*60.0/180.0;

  s.x=(2.0*a.x+1.0*b.x)/3.0;
  s.y=(2.0*a.y+1.0*b.y)/3.0;
  t.x=(1.0*a.x+2.0*b.x)/3.0;
  t.y=(1.0*a.y+2.0*b.y)/3.0;
  u.x=(t.x-s.x)*cos(th)-(t.y-s.y)*sin(th)+s.x;
  u.y=(t.x-s.x)*sin(th)+(t.y-s.y)*cos(th)+s.y;

  koch(n-1,a,s);
  printf("%.8f %.8f\n", s.x, s.y);
  koch(n-1,s,u);
  printf("%.8f %.8f\n", u.x, u.y);
  koch(n-1,u,t);
  printf("%.8f %.8f\n", t.x, t.y);
  koch(n-1,t,b);
}

int main(){
  int n;
  cin >> n;
  Point  a, b;
  a.x=0;
  a.y=0;
  b.x=100;
  b.y=0;

  printf("%.8f", "%.8f\n", &a.x, &a.y);
  //koch(n,a,b);
  printf("%.8f", "%.8f\n", b.x, b.y);
  return 0;
}
===========================
#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;
map <int ,int> mpa,mpb;
#define MAX 500000
#define SENTINEL 2000000000

int n;
int cnt;
int L[MAX/2+2], R[MAX/2+2];

void merge(int A[],int left, int mid, int right){
  int n1=mid-left;
  int n2=right-mid;
  for(int i=0;i<n1;i++) L[i]=A[left+i];
  for(int i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1] = R[n2] = SENTINEL;
  int i=0,j=0;
  for(int k=left;k<right;k++) {
    cnt++;
    if(L[i]<=R[j]){
      A[k]=L[i++];
    }else{
      A[k]=R[j++];
    }
  }
}

void mergeSort(int A[], int left, int right){
  if(left +1 < right ) {
    int mid =(left +right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid ,right);
    merge(A, left, mid, right);
  }
}

int main (){
  cin >> n;
  int A[500002];
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  mergeSort(A, 0, n);

  for(int i=0;i<n;i++){
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;
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
#define MAX 100000

int A[MAX],n;

int partition(int p,int r){
  int i,j,x,t;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j]<=x){
      i++;
      t=A[i];A[i]=A[j];A[j]=t;
    }
  }
  t=A[i+1];A[i+1]=A[r];A[r]=t;
  return i+1;
}

int main(){
  cin >> n;
  int q;
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  q=partition(0,n-1);
  for(int i=0;i<n;i++){
    if(i) cout << " ";
    if(i==q) cout << "[";
    cout << A[i];
    if(i==q) cout << "]";
  }
  cout << endl;
  return 0;
}
===========================
===========================
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
using ll = long long;
map <int ,int> mpa,mpb;

int main (){
  int N;
  cin >> N;
  int ans=100000000;
  int a=0;
  int t;
  for(int i=1;i<N;i++){
    t=0;
    a=i;
    int b=N-i;
    while(a>0){
      t+=a%10;
      a/=10;
    }
    while(b>0){
      t+=b%10;
      b/=10;
    }
    ans=min(ans,t);
  }
  cout << ans << endl;
}


===========================
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
#define MAX 500000
#define SENTINEL 2000000000

int A[MAX],n;
int cnt;
int L[MAX/2+2], R[MAX/2+2];

struct Card{ char suit, value;};

void trace(struct Card A[], int n){
  for(int i=0;i<n;i++){
    if(i) cout << " ";
    cout << A[i].suit << A[i].value;
  }
  cout << endl;
}

void merge(struct A[],int left, int mid, int right){
  int n1=mid-left;
  int n2=right-mid;
  for(int i=0;i<n1;i++) L[i]=A[left+i];
  for(int i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1] = R[n2] = SENTINEL;
  int i=0,j=0;
  for(int k=left;k<right;k++) {
    cnt++;
    if(L[i]<=R[j]){
      A[k]=L[i++];
    }else{
      A[k]=R[j++];
    }
  }
}

void mergeSort(struct A[], int left, int right){
  if(left +1 < right ) {
    int mid =(left +right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid ,right);
    merge(A, left, mid, right);
  }
}

int partition(strcut Card A[],int p,int r){
  int i,j;
  struct Card t,x;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j]<=x){
      i++;
      t=A[i];A[i]=A[j];A[j]=t;
    }
  }
  t=A[i+1];A[i+1]=A[r];A[r]=t;
  return i+1;
}

void quickSort(struct Card A[],int p,int r){
  int q;
  if(p<r){
    q=partition(A,n,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}

int main (){
  cin >> n;
  int A[500002];
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  mergeSort(A, 0, n);

  for(int i=0;i<n;i++){
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}

===========================
#include <stdio.h>
#include <stdlib.h>
#define VMAX 100000
#define MAX 200000001

int main (){
  unsigned short *A,*B;
  int C[VMAX+1]={0};
  int n,i,j;
  scanf("%d",&n);

  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);

  //for(i=0;i<=VMAX;i++) C[i]=0;
  for(i=1;i<=n;i++) {
    scanf("%hu", &A[i]);
    C[A[i]]++;
  }
  for(i=1;i<=VMAX;i++) C[i]=C[i]+C[i-1];
  for(j=1;j<=n;j++) {
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<=n;i++) {
    if(i>1)  printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");
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
===========================
===========================
===========================
===========================
===========================
===========================
===========================
===========================
===========================
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
using ll = long long;
map <int ,int> mpa,mpb;

int main (){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans=0;
  int l_count[27]={0};
  int r_count[27]={0};
  for(int i=0;i<N;i++){
    r_count[S[i]-'a']++;
  }
  int k;
  for(int i=0;i<N;i++){
    k=0;
    l_count[S[i]-'a']++;
    r_count[S[i]-'a']--;
    for(int j=97;j<=122;j++){
      if(l_count[j-'a'] >0 && r_count[j-'a']>0) {
        k++;
      }
    }
    ans=max(ans,k);
  }
  cout << ans << endl;
  return 0;
}
