//Prateek Saraswat
//Pairwise swap elements of a given linked list by changing links
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

struct node* pairwise_swap(struct node* head) {
	struct node* next_to_swap=head;
	struct node* prev=NULL;

	while(next_to_swap!=NULL) {
		struct node* curr=next_to_swap;
		if(curr->next==NULL) {
			next_to_swap=NULL;
			continue;
		}else {
			struct node* next=curr->next;
			if(prev==NULL) {
				curr->next=next->next;
				next->next=curr;
				next_to_swap=curr->next;
				prev=curr;
				head=next;
			}
			else {
				prev->next=next;
				curr->next=next->next;
				next->next=curr;
				next_to_swap=curr->next;
				prev=curr;
			}
		}
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
	head=pairwise_swap(head);
	traverse(head);
	return 0;
}