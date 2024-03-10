#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Task
 {
    char title[100];
    char description[500];
    char dueDate[15];
    int priority;
    int isCompleted;
    struct Task *next;
};

typedef struct Task Task;

Task *head = NULL;

void addTask() 
{
    Task *newTask = (Task *)malloc(sizeof(Task)); //allocating a new memory.
    if (newTask == NULL)
	{
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter task title: ");
    scanf("%s", newTask->title);
    printf("Enter task description: ");
    scanf("%s", newTask->description);
    printf("Enter due date: ");
    scanf("%s", newTask->dueDate);
    printf("Enter priority (1-5): ");
    scanf("%d", &newTask->priority);
    newTask->isCompleted = 0; // it represent that the task is not completed.
    newTask->next = head;
    head = newTask;

    printf("Task added successfully.\n");
}

void viewTasks() 
{
    Task *current = head;
    if (current == NULL) //checking that the linked list is empty.
	{
        printf("No tasks found.\n");
        return;
    }

    printf("Task List:\n");
    while (current != NULL) 
	{
        printf("Title: %s\n", current->title);
        printf("Description: %s\n", current->description);
        printf("Due Date: %s\n", current->dueDate);
        printf("Priority: %d\n", current->priority);
        printf("Status: %s\n", current->isCompleted ? "PENDING" : "COMPLETED");
        printf("--------------------\n");
        current = current->next;
    }
}

void updateTask() 
{
    // implementation for updating a task
 
    char searchTitle[100];
    printf("Enter the title of the task to update: ");
    scanf("%s", searchTitle);

    Task *current = head;
    while (current != NULL) 
    {
        if (strcmp(current->title, searchTitle) == 0) //for checking that the title of the current task matches the 'search title'.
        {
            printf("Enter updated task title: ");
            scanf("%s", current->title);
            printf("Enter updated task description: ");
            scanf("%s", current->description);
            printf("Enter updated due date: ");
            scanf("%s", current->dueDate);
            printf("Enter updated priority (1-5): ");
            scanf("%d", &current->priority);

            printf("Task updated successfully.\n");
            return; // Exit the function after updating
        }
        current = current->next;
    }

    printf("Task with title '%s' not found.\n", searchTitle);
}


void deleteTask() 
{
    // Implementation for deleting a task
       char searchTitle[100];
    printf("Enter the title of the task to delete: ");
    scanf("%s", searchTitle);

    Task *current = head;
    Task *prev = NULL; //prev term is used to track the previous node while traversing the list.

    while (current != NULL) 
    {
        if (strcmp(current->title, searchTitle) == 0) 
        {
            if (prev == NULL) 
            {
                // The task to be deleted is the head node
                head = current->next;
            } 
            else 
            {
            	          // Connect the previous task's next to the task after the current
                prev->next = current->next;
            }

            free(current); // Free memory for the deleted task
            printf("Task deleted successfully.\n");
            return; // Exit the function after deleting
        }

        prev = current;
        current = current->next;
    }

    printf("Task with title '%s' not found.\n", searchTitle);
}


int main() 
{
    int choice;

    do 
	{
        printf("\nTask Manager Application\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Update Task\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                updateTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                printf("Exiting the application.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } 
	while (choice != 5);
	return 0;
}

