/* Structure that holds co-ordinates that correspond to the position on a cartesian graph */
typedef struct
{
	int x;
	int y;
}Coord;

typedef struct
{
    int health;
    int cost;
    char icon;
    float speed;
    float movement;
    int moveBefore;
    Coord location;
} Gangster;

typedef Gangster Item;

/* Structure that is the node of a linked list */
typedef struct ListNodeTag
{
	Item * item;
	struct ListNodeTag *next;
}ListNode;

/* Structure that is the starting point to a list */
typedef struct
{
	int size;
	ListNode *head;
}List;
