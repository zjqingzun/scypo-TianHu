import sys

def show_menu():
    print("\n=== To-Do List Manager ===")
    print("1. View to-do list")
    print("2. Add new task")
    print("3. Delete task")
    print("4. Exit")

def main():
    todo_list = []
    
    while True:
        show_menu()
        choice = input("Select an option (1-4): ")
        
        if choice == "1":
            if not todo_list:
                print("To-do list is empty!")
            else:
                print("\nTo-do List:")
                for i, task in enumerate(todo_list, 1):
                    print(f"{i}. {task}")
                    
        elif choice == "2":
            task = input("Enter new task: ")
            todo_list.append(task)
            print(f"Added: {task}")
            
        elif choice == "3":
            if not todo_list:
                print("No tasks to delete!")
            else:
                print("\nTo-do List:")
                for i, task in enumerate(todo_list, 1):
                    print(f"{i}. {task}")
                try:
                    index = int(input("Enter task number to delete: ")) - 1
                    if 0 <= index < len(todo_list):
                        removed_task = todo_list.pop(index)
                        print(f"Deleted: {removed_task}")
                    else:
                        print("Invalid task number!")
                except ValueError:
                    print("Please enter a number!")
                    
        elif choice == "4":
            print("Goodbye!")
            sys.exit(0)
            
        else:
            print("Invalid choice! Please select 1-4.")

if __name__ == "__main__":
    main()