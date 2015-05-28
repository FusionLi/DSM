#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

static struct statistic *NewNode(int width){
	
	struct statistic* head = malloc (sizeof(struct statistic));
	head->width = width;
        head->count = 1;
	head->next = NULL;
	return head;
}

static struct statistic *Find(struct statistic* head, int width){
	struct statistic* curNode = head;

	while (curNode != NULL && curNode->width != width){
		curNode = curNode->next;
	}
	
	return curNode;
}

void Update(struct statistic** head, int width) {
    if (*head == NULL) {
        struct statistic* firstNode = NewNode(width);
	*head = firstNode;
        return;
    }
    struct statistic* updateNode = Find(*head, width);
    if (updateNode == NULL) {
        updateNode = NewNode(width);
        struct statistic** curNode = head;
        while ((*curNode)->next != NULL) {
            curNode = &((*curNode)->next);
        }
       (*curNode)->next = updateNode;
    } else {
        updateNode->count += 1;
    }
}

void Destroy(struct statistic* head){
	
	struct statistic* curNode = head;
        struct statistic* temp = curNode;
	while (curNode->next != NULL) {
            curNode = curNode->next;
            free(temp);
            temp = curNode;
        }	
        free(curNode);
}

//mode: 1:write into a file 0:print on screen
void Print(struct statistic* head, FILE* outputFile, int mode) {
    struct statistic* curNode = head;
    while (curNode != NULL) {
        if (mode == 0) {
            printf("Width is: %d and Count is: %d\n",curNode->width, curNode->count);
	}
	else {
	    fprintf(outputFile, "%d\t%d\n",curNode->width,curNode->count);
	}
        curNode = curNode->next;
    }
}


