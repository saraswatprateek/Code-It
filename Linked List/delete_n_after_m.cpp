//Prateek Saraswat
#include <iostream> 
#include <iterator> 
#include <map>
#include <vector>

#define ll long long int
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

struct node {
	int data;
	struct node *next;
};

struct node* getNode(int data) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->data=data;
	return temp;
}

struct node* create_ll(struct node* head, int data) {
	struct node* temp = getNode(data);

	if(head==NULL) {
		head=temp;
	}
	else {
		struct node* p=head;
		while(p->next!=NULL) {
			p=p->next;
		}
		p->next=temp;
	}
	return head;
}

void traverse(struct node* head) {
	struct node *temp=head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

struct node* reverse(struct node* head) {
	struct node* prev=NULL,*p=head,*next=p->next;

	while(p!=NULL) {
		next=p->next;
		p->next=prev;
		prev=p;
		p=next;
	}
	head=prev;
	return head;
}

struct node* func(struct node* head, int n, int m) {
	struct node* curr=head;
	while(curr!=NULL) {
		int cnt=1;
		while(curr!=NULL && cnt<m) {
			curr=curr->next;
			cnt++;
		}

		struct node* temp=curr;
		if(curr!=NULL)
		curr=curr->next;
		cnt=0;
		while(curr!=NULL && cnt<n) {
			curr=curr->next;
			cnt++;
		}
		if(curr!=NULL)
		temp->next=curr;

	}
	return head;
}

int main() {
	quick;
	//code
	struct node* head=NULL;
	int n;     //size of linked list
	cin>>n;
	for(int i=0;i<n;i++) {
		int x;  cin>>x;
		head=create_ll(head,x);
	}
	traverse(head);
	
	int x,y;
	cin>>x>>y;
	head=func(head,x,y);
	traverse(head);

	return 0;
}